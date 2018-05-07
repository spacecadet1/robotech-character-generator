// CSkillPage.cpp : implementation file
//

#include "stdafx.h"
#include "Robotech.h"
#include "CSkillPage.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSkillPage dialog

using namespace std;

CSkillPage::CSkillPage(CWnd* pParent /*=NULL*/)
	: CDialog(CSkillPage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSkillPage)
	//}}AFX_DATA_INIT
}


void CSkillPage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSkillPage)
	DDX_Control(pDX, IDC_LIST2, m_list2);
	DDX_Control(pDX, IDC_LIMIT, m_limit);
	DDX_Control(pDX, IDC_OCC, m_occ);
	DDX_Control(pDX, IDC_VIEW, m_bt);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSkillPage, CDialog)
	//{{AFX_MSG_MAP(CSkillPage)
	ON_BN_CLICKED(IDC_VIEW, OnView)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_REMOVE, OnRemove)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSkillPage message handlers

void CSkillPage::OnView() 
{
	// TODO: Add your control notification handler code here
	CString text;
	m_occ.GetWindowText(text);
	if(text == "[Select OCC]")
		return;

	PopulateWithData(text);
	

	
}

void CSkillPage::SetOCC(CString occ)
{
	CString text;
	m_occ.GetWindowText(text);
	if(text != occ)
	{
		m_occ.SetWindowText(occ);
		m_list1.ResetContent();
		m_list2.ResetContent();
		RemoveAllUserSkills();
	}
	

}

void CSkillPage::OnAdd() 
{
	// TODO: Add your control notification handler code here
	int i=-1;
	i = m_list1.GetCurSel();
	if ((i == -1) || (limit == 0))
		return;
	CString text; int idx;
	m_list1.GetText( i, text );
	
	idx = m_list2.AddString(text);
	m_list2.SetItemData(idx, m_list1.GetItemData(i) );
	

	m_list1.DeleteString(i);

	UpdateLimit(FALSE); 

	UpdateData(FALSE);


	
}

void CSkillPage::OnRemove() 
{
	// TODO: Add your control notification handler code here
	int i=-1;
	i = m_list2.GetCurSel();
	if(i == -1)
		return;

	CString text; int idx;
	m_list2.GetText(i, text );
	
	idx = m_list1.AddString(text);
	m_list1.SetItemData(idx, m_list2.GetItemData(i));

	m_list2.DeleteString(i);
	

	UpdateLimit(TRUE);

	UpdateData(FALSE);
	
}

void CSkillPage::UpdateLimit(BOOL x)
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



void CSkillPage::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	// TODO: Add your message handler code here
	if(!bShow)
		return;

	CString text;
	m_occ.GetWindowText(text);
	if(text == "[Select OCC]")
		return;

	if(m_list2.GetCount() > 0)
		return;

	PopulateWithData(text);
	
	
}

int CSkillPage::GetListBoxCount()
{
	int count =m_list2.GetCount();
	return count;
}

int CSkillPage::GetID(int index)
{
	int x=m_list2.GetItemData(index);
	return x;

}

CString CSkillPage::GetOCC()
{
	CString text;
	m_occ.GetWindowText(text);
	if(text == "[Select OCC]")
	{
		//MessageBox("Please select an OCC");
		return "none";
		//return;
	}
	else
		return text;
}

void CSkillPage::AddUserSkill(int skillindex)
{
	userskills.AddTail(skillindex);
}

int CSkillPage::GetUserSkill(int index)
{
	POSITION pos = userskills.FindIndex(index);
	return userskills.GetAt(pos);
}

int CSkillPage::GetUserSkillCount()
{
	return userskills.GetCount();
}

void CSkillPage::RemoveAllUserSkills()
{
	userskills.RemoveAll();
}

void CSkillPage::SetSavedSkills(CString skillstring)
{
	TRACE("\n %s \n",skillstring);
	skillstring.TrimLeft(); skillstring.TrimRight();
	if(skillstring == "")
		return;
	CList<int, int&> temp;
	char* token; char* str;
	string x = skillstring;
	strcpy(str, x.c_str());
	token = strtok(str, " ");
	while(token != NULL)
	{
		int t = atoi(token);
		temp.AddTail(t);
		token = strtok(NULL," ");
	}	
	//adjust GUI
	CString text; m_occ.GetWindowText(text);
	PopulateWithData(text);

	//add item to listbox2
	//remove item from listbox1
	for(int i=0; i<temp.GetCount(); i++)
	{
		POSITION pos = temp.FindIndex(i);
		int id = temp.GetAt(pos);
		TRACE("\n The ID is %i\n", id);
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

void CSkillPage::SetSavedUserSkills(CString userskillstring)
{
	userskillstring.TrimLeft(); userskillstring.TrimRight();
	if(userskillstring == "")
		return;
	CList<int, int&> temp;
	char* token; char* str;
	string x = userskillstring;
	strcpy( str, x.c_str());
	token = strtok(str, " ");
	while(token != NULL)
	{
		int t = atoi(token);
		temp.AddTail(t);
		token = strtok(NULL, " ");
	}
	
	userskills.RemoveAll();
	for(int i=0; i<temp.GetCount(); i++)
	{
		POSITION pos = temp.FindIndex(i);
		int y = temp.GetAt(pos);
		userskills.AddTail(y);
	}
}

void CSkillPage::PopulateWithData(CString occ)
{
	CString condition; int idx;

	m_list1.ResetContent();
	m_list2.ResetContent();

	OCCSet occset; SkillSet skillset;
	occset.m_strFilter = "OCC='"+occ+"'";
	occset.Open();
	occ.Format("%d", occset.m_NumOther);
	limit = occset.m_NumOther;
	m_limit.SetWindowText(occ);
	
	
	condition = "("+occset.m_Other + ") AND NOT( " + occset.m_OCC_Skills+")";

	skillset.m_strFilter = condition;
	skillset.Open();
	while(!skillset.IsEOF())
	{
		idx=m_list1.AddString(skillset.m_Skill);
		m_list1.SetItemData( idx, skillset.m_ID); 
		skillset.MoveNext();
	}

}

CString CSkillPage::GetSavedSkills()
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

CString CSkillPage::GetSavedUserSkills()
{
	CString temp = " ";
	for(int i=0; i<userskills.GetCount(); i++)
	{
		POSITION pos = userskills.FindIndex(i);
		int buf = userskills.GetAt(pos);
		CString text; text.Format("%i ", buf);
		temp += text;

	}
	return temp;
}

void CSkillPage::ResetPage()
{
	RemoveAllUserSkills();
	m_list1.ResetContent();
	m_list2.ResetContent();
	m_occ.SetWindowText("[Select OCC]");
	limit = 0;
	m_limit.SetWindowText("0");
	OCC = "";


}
