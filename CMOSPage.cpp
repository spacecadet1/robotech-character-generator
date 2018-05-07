// CMOSPage.cpp : implementation file
//

#include "stdafx.h"
#include "Robotech.h"
#include "CMOSPage.h"
#include "CParser.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMOSPage dialog
using namespace std;

CMOSPage::CMOSPage(CWnd* pParent /*=NULL*/)
	: CDialog(CMOSPage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMOSPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	bMOS = false;
	mos_score = 0;
}


void CMOSPage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMOSPage)
	DDX_Control(pDX, IDC_LIMIT, m_limit);
	DDX_Control(pDX, IDC_SELECT, m_select);
	DDX_Control(pDX, IDC_LIST2, m_list2);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMOSPage, CDialog)
	//{{AFX_MSG_MAP(CMOSPage)
	ON_BN_CLICKED(IDC_SELECT, OnSelect)
	ON_BN_CLICKED(IDC_ADD2, OnAdd)
	ON_BN_CLICKED(IDC_REMOVE2, OnRemove)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMOSPage message handlers

void CMOSPage::OnSelect() 
{
	// TODO: Add your control notification handler code here
	
	CString text; OCCSet occset; SkillSet skillset;
	if((numSec<1))
	{
		if(bMOS==false)
		{
			MessageBox("This OCC does not have secondary or MOS skills");
			return;
		}
	}

	m_list1.ResetContent();
	m_list2.ResetContent();
	m_select.SetWindowText("Refresh");

	occset.m_strFilter = condition;
	occset.Open();
	
	if(bMOS == true)
	{
		
		CSelectDlg dlg;
		if(dlg.DoModal(true)== IDOK)
		{
			if(dlg.result != "")
			{
				mos_skills.RemoveAll();
				mos = dlg.result;
				MOSSet mosset; CParser parser;
				mosset.m_strFilter = "MOS='"+ mos + "'";
				mosset.Open();
				mos_score = mosset.m_Bonus;
				parser.ChopString(mosset.m_Skills);
				parser.GetData(mos_skills);
				skillset.m_strFilter = mosset.m_Select;
				skillset.Open();
				while(!skillset.IsEOF())
				{
					int idx=m_list1.AddString(skillset.m_Skill);
					m_list1.SetItemData( idx, skillset.m_ID); 
					skillset.MoveNext();
				}

				text.Format("%d", mosset.m_Limit);
				limit = mosset.m_Limit;
				m_limit.SetWindowText(text);

				
			}
		}
	}
	else
	{		
		
		skillset.m_strFilter = "("+occset.m_Other + ") AND NOT( " + occset.m_OCC_Skills + " )";
		skillset.Open();
		while(!skillset.IsEOF())
		{
			int idx=m_list1.AddString(skillset.m_Skill);
			m_list1.SetItemData( idx, skillset.m_ID); 
			skillset.MoveNext();
		}
		text.Format("%d", numSec);
		limit = numSec;
		m_limit.SetWindowText(text);
	}
	
		
}

void CMOSPage::SetOCC(CString occ)
{
	if(m_occ == occ)
		return;
	else
	{
		m_list1.ResetContent();
		m_list2.ResetContent();
		m_select.SetWindowText("Select");
		m_limit.SetWindowText("0");
	}

	OCCSet occset;
	condition=occset.m_strFilter = "OCC = '"+ occ +"'";
	occset.Open();
	if (occset.m_MOS == TRUE)
		bMOS= true;
	else
		bMOS = false;

	
	if(occset.m_NumSecondary>0)
		numSec=occset.m_NumSecondary;
	else
		numSec=0;
	
	m_occ = occ;

}

void CMOSPage::OnAdd() 
{
	// TODO: Add your control notification handler code here
	int i=-1;
	i = m_list1.GetCurSel();
	if ((i == -1) || (limit == 0))
		return;
	CString text; int idx;
	m_list1.GetText( i, text );

	int ix = m_list1.GetItemData(i);
	if(bMOS==true)
		mos_skills[ix] = mos_score;
	
	idx = m_list2.AddString(text);
	m_list2.SetItemData(idx, m_list1.GetItemData(i) );
	m_list1.DeleteString(i);

	

	UpdateLimit(FALSE); 

	UpdateData(FALSE);
	
}

void CMOSPage::OnRemove() 
{
	// TODO: Add your control notification handler code here
	int i=-1;
	i = m_list2.GetCurSel();
	if(i == -1)
		return;

	CString text; int idx;
	m_list2.GetText(i, text );
	idx = m_list1.AddString(text);

	int ix = m_list2.GetItemData(i);
	if(bMOS==true)
		mos_skills.RemoveKey(ix);

	m_list1.SetItemData(idx, m_list2.GetItemData(i));
	m_list2.DeleteString(i);

	UpdateLimit(TRUE);

	UpdateData(FALSE);
	
}

void CMOSPage::UpdateLimit(BOOL x)
{
	CString text;
	if(x)
	{
		limit++;
		text.Format("%d", limit);
		m_limit.SetWindowText(text);
	}
	else
	{
		limit--;
		text.Format("%d", limit);
		m_limit.SetWindowText(text);
	}
}



int CMOSPage::GetListBoxCount()
{
	int count =m_list2.GetCount();
	return count;

}

CString CMOSPage::GetMOS()
{
	return mos;
}

int CMOSPage::GetID(int index)
{
	int result=m_list2.GetItemData(index);
	return result;
}

bool CMOSPage::IsMOS()
{
	return bMOS;
}

void CMOSPage::CopyMOSBonus(CMap <int, int&, int, int&> &input)
{
	POSITION pos = mos_skills.GetStartPosition();
	while(pos != NULL)
	{
		int k, i;
		mos_skills.GetNextAssoc( pos, k ,i);
		TRACE("key = %i value = %i\n", k, i);
		input [k] = i;
	}
}

void CMOSPage::SetMOS(CString MOS)
{
	if(MOS !="")
	{
		mos = MOS;
		m_list1.ResetContent();
		m_list2.ResetContent();
		m_select.SetWindowText("Refresh");
	}
	
}

void CMOSPage::SetSavedMOSSkills(CString mosstring)
{
	mosstring.TrimLeft(); mosstring.TrimRight();
	if(mosstring == "")
		return;

	CList<int, int&> temp;
	char* token; char* str;
	string x = mosstring;
	strcpy(str, x.c_str());
	token = strtok(str, " ");
	while(token != NULL)
	{
		int t = atoi(token);
		temp.AddTail(t);
		token = strtok(NULL, " ");
	}

	OCCSet occset; SkillSet skillset;
	occset.m_strFilter = condition;
	occset.Open();

	if (bMOS == true)
	{
		//Setup GUI
		mos_skills.RemoveAll();
		MOSSet mosset; CParser parser;
		mosset.m_strFilter = "MOS='"+ mos +"'";
		mosset.Open();
		mos_score = mosset.m_Bonus;
		parser.ChopString(mosset.m_Skills);
		parser.GetData(mos_skills);
		skillset.m_strFilter = mosset.m_Select;
		skillset.Open();
		while(!skillset.IsEOF())
		{
			int idx = m_list1.AddString(skillset.m_Skill);
			m_list1.SetItemData( idx, skillset.m_ID);
			skillset.MoveNext();
		}
		CString text;
		text.Format("%d", mosset.m_Limit);
		limit = mosset.m_Limit;
		m_limit.SetWindowText(text);
		//Add and Remove items
	}
	else
	{
		//Setup GUI
		skillset.m_strFilter = "("+occset.m_Other + ") AND NOT( " + occset.m_OCC_Skills + " )";
		skillset.Open();
		while(!skillset.IsEOF())
		{
			int idx=m_list1.AddString(skillset.m_Skill);
			m_list1.SetItemData( idx, skillset.m_ID); 
			skillset.MoveNext();
		}
		CString text;
		text.Format("%d", numSec);
		limit = numSec;
		m_limit.SetWindowText(text);

		

	}
	//Add and Remove items
	for(int i=0; i< temp.GetCount(); i++)
	{
		POSITION pos = temp.FindIndex(i);
		int id = temp.GetAt(pos);
		SkillSet skillset;
		skillset.m_strFilter.Format("ID=%i",id);
		skillset.Open();
		CString skill=skillset.m_Skill;
		int idx = m_list2.AddString(skill);
		m_list2.SetItemData(idx, id);
		idx=m_list1.FindString(-1, skill);
		m_list1.DeleteString(idx);
		UpdateLimit(FALSE);
	}

}

CString CMOSPage::GetSavedMOSSkills()
{
	CString temp =" ";
	for(int i=0; i< m_list2.GetCount();i++)
	{
		CString text;
		text.Format("%i ", m_list2.GetItemData(i));
		temp += text;
	}
	return temp;

}

void CMOSPage::ResetPage()
{
	m_list1.ResetContent();
	m_list2.ResetContent();
	limit =0;
	m_limit.SetWindowText("0");



}
