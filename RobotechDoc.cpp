// RobotechDoc.cpp : implementation of the CRobotechDoc class
//

#include "stdafx.h"
#include "Robotech.h"

#include "RobotechDoc.h"
#include "CExtra.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRobotechDoc

IMPLEMENT_DYNCREATE(CRobotechDoc, CDocument)

BEGIN_MESSAGE_MAP(CRobotechDoc, CDocument)
	//{{AFX_MSG_MAP(CRobotechDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRobotechDoc construction/destruction

CRobotechDoc::CRobotechDoc()
{
	// TODO: add one-time construction code here
	IQ=0;
	ME =0;
	MA=0;
	PS=0;
	PP=0;
	PE=0;
	PB=0;
	SPD=0;
	IsShowing = FALSE;
	
}

CRobotechDoc::~CRobotechDoc()
{
	//TRACE("There are %d\n", skills->GetCount());
	
}

BOOL CRobotechDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	//AfxMessageBox("hello");
	//SetTitle("[New] |");
	
	

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRobotechDoc serialization

void CRobotechDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		//Call SaveData()
		SaveData();
		ar<<IQ<<ME<<MA<<PS<<PP<<PE<<PB<<SPD;
		ar<<name<<race<<OCC<<alignment<<level<<hitpts;
		ar<<levelpts<<MOS<<mosstring<<skillstring<<userskillstring;
		
	}
	else
	{
		// TODO: add loading code here
		ar>>IQ>>ME>>MA>>PS>>PP>>PE>>PB>>SPD;
		ar>>name>>race>>OCC>>alignment>>level>>hitpts;
		ar>>levelpts>>MOS>>mosstring>>skillstring>>userskillstring;
		
		if(IsShowing)
			LoadData();
	
	}
	
}

/////////////////////////////////////////////////////////////////////////////
// CRobotechDoc diagnostics

#ifdef _DEBUG
void CRobotechDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRobotechDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRobotechDoc commands




void CRobotechDoc::AddSkill(CSkill skill)
{
	skills.AddTail(skill);
}

void CRobotechDoc::ClearSkills()
{
	skills.RemoveAll();
}

CString CRobotechDoc::GetExtra(int id)
{
	CExtra extra;
	extra.m_strFilter.Format("ID = %i", id);
	extra.Open();
	return extra.m_Info;

}

void CRobotechDoc::AssignBonus()
{
	notes.RemoveAll();
	BonusSet bonusset;
	if (IQ >16)
	{
		BonusSet bonusset;
		bonusset.m_strFilter.Format("Score = %i", IQ);
		bonusset.Open();
		int b=bonusset.m_IQ;
		for (int i=0; i< skills.GetCount(); i++)
		{
			POSITION pos = skills.FindIndex(i);
			CSkill buffer = skills.GetAt(pos);
			if(buffer.level > 0)
			{
				buffer.level += b;
				skills.SetAt(pos, buffer);

			}

		}

		CString text; text.Format("Percentile skills recieved a + %i bonus", b);
		notes.AddTail(text);
		bonusset.Close();
	}
	if (ME >16)
	{
		BonusSet bonusset;
		bonusset.m_strFilter.Format("Score =%i", ME);
		bonusset.Open();
		int b=bonusset.m_ME;
		CString text; text.Format("Save vs. Psionic/Insanity + %i", b);
		notes.AddTail(text);
		bonusset.Close();

	}
	if (MA > 16)
	{
		BonusSet bonusset;
		bonusset.m_strFilter.Format("Score= %i", MA);
		bonusset.Open();
		int b = bonusset.m_MA;
		CString text; text.Format("Trust/Intimidate %i", b);
		notes.AddTail(text + '%');
		bonusset.Close();
	}
	if (PS >16)
	{
		BonusSet bonusset;
		bonusset.m_strFilter.Format("Score= %i", PS);
		bonusset.Open();
		int b = bonusset.m_PS;
		CString text; text.Format("Hand to Hand Damage + %i",b);
		notes.AddTail(text);
		bonusset.Close();
	}
	if (PP>16)
	{
		BonusSet bonusset;
		bonusset.m_strFilter.Format("Score= %i", PP);
		bonusset.Open();
		int b = bonusset.m_PP;
		CString text; text.Format("Parry, Dodge & Strike + %i",b);
		notes.AddTail(text);
		bonusset.Close();
	}
	if (PE >16)
	{
		BonusSet bonusset;
		bonusset.m_strFilter.Format("Score= %i", PE);
		bonusset.Open();
		CString text;
		text = "Save vs Coma & Death/ Save vs Poison :" + bonusset.m_PE;
		notes.AddTail(text);
		bonusset.Close();
		
	}
	if (PB >16)
	{
		BonusSet bonusset;
		bonusset.m_strFilter.Format("Score= %i", PB);
		bonusset.Open();
		int b = bonusset.m_PB;
		CString text; text.Format("Charm & Impress %i",b);
		notes.AddTail(text +"%");
		bonusset.Close();
	}
	

}

CSkill CRobotechDoc::GetSkill(int i)
{
	POSITION pos = skills.FindIndex(i);
	CSkill buffer = skills.GetAt(pos);
	return buffer;
}

int CRobotechDoc::SkillCount()
{
	return skills.GetCount();
}

CString CRobotechDoc::GetNotes(int index)
{
	POSITION pos = notes.FindIndex(index);
	return notes.GetAt(pos);
}

int CRobotechDoc::GetNotesCount()
{
	return notes.GetCount();
}

void CRobotechDoc::GetPagePtrs(CFinalPage &fpage, CMOSPage &mpage, CPersonalPage &ppage, CSkillPage &spage)
{
	finalpage = &fpage;
	mospage = &mpage;
	personalpage = &ppage;
	skillpage = &spage;

}

void CRobotechDoc::SaveData()
{
	name=personalpage->GetName();
	alignment = personalpage->GetAlignment();
	race = personalpage->GetRace();

	skillstring = skillpage->GetSavedSkills();
	userskillstring = skillpage->GetSavedUserSkills();


	hitpts = finalpage->GetHP();
	level = finalpage->GetExpLevel();
	levelpts=finalpage->GetLevels();

	MOS = mospage->GetMOS();
	mosstring = mospage->GetSavedMOSSkills();

	


}

void CRobotechDoc::LoadData()
{
	
	personalpage->SetAttributes(IQ,ME,MA,PS,PP,PE,PB,SPD);
	personalpage->SetName(name);
	personalpage->SetAlignment(alignment);
	personalpage->SetRace(race);
	personalpage->SetOCC(OCC);

	skillpage->SetSavedSkills(skillstring);
	skillpage->SetSavedUserSkills(userskillstring);
	
	finalpage->SetLevels(levelpts);
	finalpage->SetExpLevel(level);
	
	mospage->SetMOS(MOS);
	mospage->SetSavedMOSSkills(mosstring);
	
		
}



void CRobotechDoc::ResetDocument()
{
	IQ=0;
	ME =0;
	MA=0;
	PS=0;
	PP=0;
	PE=0;
	PB=0;
	SPD=0;
	skills.RemoveAll();
	mosstring="";
	skillstring="";
	userskillstring="";
	SDC=0;
	name="";
	level=0;
	levelpts="";
	hitpts=0;
	alignment="";

}



void CRobotechDoc::SetTitle(LPCTSTR lpszTitle) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CDocument::SetTitle(lpszTitle);
}
