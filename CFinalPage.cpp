// CFinalPage.cpp : implementation file
//

#include "stdafx.h"
#include "Robotech.h"
#include "CFinalPage.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFinalPage dialog

using namespace std;

CFinalPage::CFinalPage(CWnd* pParent /*=NULL*/)
	: CDialog(CFinalPage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFinalPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	currentLevel =1;
	srand((unsigned)time(NULL));
	FillHitPointArray();
}


void CFinalPage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFinalPage)
	DDX_Control(pDX, IDC_HP, m_txtHP);
	DDX_Control(pDX, IDC_LEVEL, m_txtLevel);
	DDX_Control(pDX, IDC_LIST1, m_listbox);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFinalPage, CDialog)
	//{{AFX_MSG_MAP(CFinalPage)
	ON_BN_CLICKED(IDC_VIEWER, OnViewer)
	ON_BN_CLICKED(IDC_UP, OnUp)
	ON_BN_CLICKED(IDC_DOWN, OnDown)
	ON_BN_CLICKED(IDC_NEWSKILL, OnNewskill)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFinalPage message handlers

BOOL CFinalPage::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	m_listbox.InsertColumn(0, "Skill");
	m_listbox.InsertColumn(1, "Per Lvl");
	m_listbox.InsertColumn(2, "Score");
	

	CRect Rect;

	m_listbox.GetClientRect(&Rect);
	m_listbox.SetColumnWidth(0, ((Rect.right * 3)/4)-40);
	m_listbox.SetColumnWidth(1, (Rect.right  /4)/2+10);
	m_listbox.SetColumnWidth(2, (Rect.right  /4)/2+10);

	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void CFinalPage::SetDlgPtrs(CSkillPage& skillpage, CPersonalPage& personalpage,
							CMOSPage& mospage)
{
	p_mospage = &mospage;
	p_personalpage = &personalpage;
	p_skillpage = &skillpage;

}

void CFinalPage::OnViewer() 
{
	// TODO: Add your control notification handler code here
	
	AssignHP(currentLevel); PostLevel(currentLevel);

	
}

void CFinalPage::FillHitPointArray()
{
	
	for (int i=0; i< 20;i++)
		levels[i] = (1+ rand()%6);
		
		
}

void CFinalPage::AssignHP(int newLevel)
{
	
	int input=0;CString temp;
	for (int i=0; i< newLevel ;i++)
	{
		input += levels[i];
		
	}
	
	//if(p_personalpage->GetPE()== 0) return;
	input+= p_personalpage->GetPE();
	
	temp.Format("%i", input);
	m_txtHP.SetWindowText(temp);
		

}

void CFinalPage::OnUp() 
{
	// TODO: Add your control notification handler code here
	currentLevel++;
	if(currentLevel > 20) currentLevel = 20;
	AssignHP(currentLevel);
	PostLevel(currentLevel);
	LevelSkills(currentLevel);
	FillListView();
}

void CFinalPage::OnDown() 
{
	// TODO: Add your control notification handler code here
	currentLevel--;
	if (currentLevel < 1) currentLevel =1;
	AssignHP(currentLevel);
	PostLevel(currentLevel);
	LevelSkills(currentLevel);
	FillListView();
	
}

void CFinalPage::PostLevel(int level)
{
	CString temp; temp.Format("%i",level);
	m_txtLevel.SetWindowText(temp);
}

void CFinalPage::OnNewskill() 
{
	// TODO: Add your control notification handler code here

	/*int count=p_skillpage->GetListBoxCount();
	if (count<1) return;*/

	CSelectDlg dlg;
	if (dlg.DoModal(false)== IDOK)
	{
		if(dlg.result != "")
		{
			CString temp = dlg.result;
			SkillSet skillset; CSkill buffer;
			skillset.m_strFilter = "Skill ='"+temp +"'";
			skillset.Open();

			buffer.index = skillset.m_ID;
			p_skillpage->AddUserSkill(skillset.m_ID);
			buffer.skill = temp;
			buffer.category = skillset.m_Category;
			buffer.increment = skillset.m_Experience;
			buffer.base = skillset.m_Base;
			buffer.level = buffer.base + ((currentLevel-1)* buffer.increment);

			int value;
			if( bonus.Lookup( buffer.index, value)== TRUE)
				buffer.level += value;
			
			skills.AddTail(buffer);
		}
		
	}
	//AddBonusToSkill();

	FillListView();	
}

void CFinalPage::FillSkillArray()
{
	CSkill buffer; CList<int, int&> temp; SkillSet skillset; OCCSet occset;
	CString query;

	CString occ = p_skillpage->GetOCC();
	int count=p_skillpage->GetListBoxCount();

		

	for(int i=0; i< count; i++)
	{
		int x=p_skillpage->GetID(i);
		temp.AddTail(x);
	}

	for(i=0; i< p_skillpage->GetUserSkillCount(); i++)
	{
		int x = p_skillpage->GetUserSkill(i);
		temp.AddTail(x);
	}

	if(occ !="none")
	{
		occset.m_strFilter="OCC='" + occ + "'";
		occset.Open();
		query = occset.m_OCC_Skills;

		skillset.m_strFilter = query;
		skillset.Open();
		while(!skillset.IsEOF())
		{
			int x= skillset.m_ID;
			temp.AddTail(x);
			skillset.MoveNext();
		}
		skillset.Close();
	}

	//add secondary skills here as well but not mos skills
	if(p_mospage->IsMOS()==false)
	{
		count = p_mospage->GetListBoxCount();
		for(int i=0;i< count; i++)
		{
			int x = p_mospage->GetID(i);
			temp.AddTail(x);
		}
	}
	else //add mos skills here

	{
		CMap <int, int&, int, int&> tempmos;
		//CParser parser;
		p_mospage->CopyMOSBonus(tempmos);
		POSITION posi= tempmos.GetStartPosition();
		while(posi != NULL){
			int x, y;
			tempmos.GetNextAssoc(posi, x, y);
			temp.AddTail(x);
			//TRACE("added %i \n", x);
		}
		
	}

	POSITION pos; skills.RemoveAll();
	for(int j=0; j< temp.GetCount(); j++)
	{
		pos = temp.FindIndex(j);
		int id=temp.GetAt(pos);
		
		skillset.m_strFilter.Format("ID=%i", id);
		skillset.Open();

		buffer.index = id;
		buffer.skill = skillset.m_Skill;
		buffer.category = skillset.m_Category;
		buffer.base = skillset.m_Base;
		buffer.increment = skillset.m_Experience;
		buffer.level = buffer.base + ((currentLevel-1)* buffer.increment);

		/*int value;
		if( bonus.Lookup( buffer.index, value)== TRUE)
			buffer.level += value;*/

		skills.AddTail(buffer);	
		skillset.Close();
	}

	

	
}

void CFinalPage::FillListView()
{
	m_listbox.DeleteAllItems();

	POSITION pos; CString text;
	for(int i=0; i< skills.GetCount(); i++)
	{
		pos = skills.FindIndex(i);
		CSkill buffer = skills.GetAt(pos);

		int x = m_listbox.InsertItem(m_listbox.GetItemCount(), buffer.skill);
		
		m_listbox.SetItemData(x, buffer.index);
		text.Format("%d",buffer.increment);
		m_listbox.SetItemText(x, 1, text);
		text.Format("%d",buffer.level);
		m_listbox.SetItemText(x, 2, text);

	}
}


void CFinalPage::LevelSkills(int newLevel)
{
	POSITION pos;
	for(int i=0 ; i<skills.GetCount(); i++)
	{
		pos = skills.FindIndex(i);
		CSkill buffer = skills.GetAt(pos);
		buffer.level = buffer.base + ((newLevel-1)* buffer.increment);

		int value;
		if( bonus.Lookup( buffer.index, value)== TRUE)
			buffer.level += value;

		skills.SetAt(pos, buffer);
	}
}

void CFinalPage::AddBonusToSkill()
{

	OCCSet occset; CString occ; CParser parser;
	occ=p_skillpage->GetOCC();
	occset.m_strFilter = "OCC='"+ occ + "'";
	occset.Open();

	parser.ChopString(occset.m_Bonus);
	parser.GetData(bonus); 
	parser.CleanData();

	
	//get mos bonuses if applicable
	if(p_mospage->IsMOS()) 
	{
		 p_mospage->CopyMOSBonus(mosbonus);
		 POSITION pos = mosbonus.GetStartPosition();
		 while( pos != NULL){
			 int k, i, v;
			 mosbonus.GetNextAssoc(pos, k, i);
			 if( bonus.Lookup(k, v) == TRUE)
			 {
				 
				 bonus[k] = (i>v) ? i:v;
			 }
			 else
				 bonus[k] = i;
		 }
	}
	
	POSITION pos; int value;
	for(int i=0 ; i<skills.GetCount(); i++)
	{
		pos = skills.FindIndex(i);
		CSkill buffer = skills.GetAt(pos);
		
		if( bonus.Lookup( buffer.index, value)== TRUE)
			buffer.level += value;

		skills.SetAt(pos, buffer);
	}
	
}

void CFinalPage::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	// TODO: Add your message handler code here
	if(!bShow)
		return;

	AssignHP(currentLevel);
	PostLevel(currentLevel);	
	FillSkillArray(); 
	AddBonusToSkill();
	FillListView();
	
}



CSkill CFinalPage::GetSkill(int index)
{
	POSITION pos = skills.FindIndex(index);
	CSkill buffer = skills.GetAt(pos);
	return buffer;
}

int CFinalPage::GetSkillCount()
{
	return skills.GetCount();
}

int CFinalPage::GetHP()
{
	CString text;int value;
	m_txtHP.GetWindowText(text);
	value = atoi(text);
	return value;
}

int CFinalPage::GetExpLevel()
{
	return currentLevel;
}

void CFinalPage::SetHP(int hp)
{
	CString text;
	text.Format("%i",hp);
	m_txtHP.SetWindowText(text);

}

void CFinalPage::SetExpLevel(int level)
{
	currentLevel = level;
}

CString CFinalPage::GetLevels()
{
	CString text,temp=" ";
	for (int i=0; i< 20;i++)
	{
		temp.Format("%i ",levels[i]);
		text +=temp;
	}
	return text;
}

void CFinalPage::SetLevels(CString hplevels)
{
	hplevels.TrimLeft();
	hplevels.TrimRight();
	
	CList<int,int&> temp;
	char* token;
	char* str;
	string x = hplevels;
	strcpy(str, x.c_str());
	token = strtok(str," ");
	while(token != NULL)
	{
		int t= atoi(token);
		temp.AddTail(t);
		token = strtok(NULL, " ");
	}

	for(int i=0; i< 20; i++)
	{
		POSITION pos = temp.FindIndex(i);
		levels[i] = temp.GetAt(pos);
	}
	
}

void CFinalPage::ResetPage()
{
	currentLevel = 1;
	FillHitPointArray();

}
