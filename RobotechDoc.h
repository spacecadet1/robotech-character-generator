// RobotechDoc.h : interface of the CRobotechDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBOTECHDOC_H__34ADCCB5_9B33_4E8D_8596_064CCF00C7B0__INCLUDED_)
#define AFX_ROBOTECHDOC_H__34ADCCB5_9B33_4E8D_8596_064CCF00C7B0__INCLUDED_

#include "CSkill.h"	// Added by ClassView
#include "CFinalPage.h"	// Added by ClassView
#include "CMOSPage.h"	// Added by ClassView
#include "CPersonalPage.h"	// Added by ClassView
#include "CSkillPage.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRobotechDoc : public CDocument
{
protected: // create from serialization only
	CRobotechDoc();
	DECLARE_DYNCREATE(CRobotechDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRobotechDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void SetTitle(LPCTSTR lpszTitle);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRobotechDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	//CList <int, int&> indexlist1;
	//CList <int, int&> indexlist2;
	CList <CSkill, CSkill&> skills;

// Generated message map functions
protected:
	//{{AFX_MSG(CRobotechDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	int hitpts;
	int SDC,level;
	CString race;
	CString name;
	CString OCC, alignment;
public:
	void ResetDocument();
	BOOL IsShowing;
	void LoadData();
	void SaveData();
	
	void GetPagePtrs( CFinalPage &fpage, CMOSPage& mpage, CPersonalPage& ppage, CSkillPage& spage);
	
	int GetNotesCount();
	CString GetNotes(int index);
	CString GetExtra( int id );
	int SkillCount();
	CSkill GetSkill( int i);
	void AssignBonus();
	void ClearSkills();
	void AddSkill( CSkill skill );
	void AssignSkillList(CList <CSkill, CSkill&> &list);
	
	int IQ,ME,MA,PS,PP,PE,PB,SPD;
	
private:
	CString key;
	CString userskillstring;
	CString skillstring;
	CString mosstring;
	CString MOS;
	CString levelpts;
	CSkillPage* skillpage;
	CPersonalPage* personalpage;
	CFinalPage* finalpage;
	CMOSPage* mospage;
	CStringList notes;
	
	
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROBOTECHDOC_H__34ADCCB5_9B33_4E8D_8596_064CCF00C7B0__INCLUDED_)
