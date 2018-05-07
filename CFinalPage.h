#if !defined(AFX_CFINALPAGE_H__5BF3EEC5_9D28_44BB_95D7_1E7A1E5A125F__INCLUDED_)
#define AFX_CFINALPAGE_H__5BF3EEC5_9D28_44BB_95D7_1E7A1E5A125F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CFinalPage.h : header file
//
#include "CSkillPage.h"
#include "CMOSPage.h"
#include "CPersonalPage.h"
#include "CSkill.h"
#include "CParser.h"	// Added by ClassView

/////////////////////////////////////////////////////////////////////////////
// CFinalPage dialog

class CFinalPage : public CDialog
{
// Construction
public:
	void ResetPage();
	void SetLevels( CString hplevels);
	CString GetLevels();
	void SetExpLevel( int level );
	void SetHP(int hp);
	int GetExpLevel();
	int GetHP();
	int GetSkillCount();
	CSkill GetSkill (int index);
	CList<CSkill, CSkill&> skills;
	
	void AddBonusToSkill();
	void LevelSkills( int newLevel);
	void LowerSkills(int newLevel);
	void RaiseSkills( int newLevel);
	void FillListView();
	void PostLevel( int level);
	void AssignHP( int newLevel );
	void FillHitPointArray();
	void SetDlgPtrs( CSkillPage& skillpage, CPersonalPage& personalpage, CMOSPage& mospage);
	CFinalPage(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFinalPage)
	enum { IDD = IDD_FINAL };
	CStatic	m_txtHP;
	CStatic	m_txtLevel;
	CListCtrl	m_listbox;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFinalPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	
	CMOSPage* p_mospage;
	CPersonalPage* p_personalpage;
	CSkillPage* p_skillpage;

	// Generated message map functions
	//{{AFX_MSG(CFinalPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnViewer();
	afx_msg void OnUp();
	afx_msg void OnDown();
	afx_msg void OnNewskill();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void FillSkillArray();
	int currentLevel;
	CSkillPage* y;
	int levels [20];
	
	CMap <int, int&, int, int&> bonus;
	CMap <int , int&, int, int&> mosbonus;
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CFINALPAGE_H__5BF3EEC5_9D28_44BB_95D7_1E7A1E5A125F__INCLUDED_)
