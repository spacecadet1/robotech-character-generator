#if !defined(AFX_CSKILLPAGE_H__06BD81B5_A97F_4760_9C86_987C58DD5EAC__INCLUDED_)
#define AFX_CSKILLPAGE_H__06BD81B5_A97F_4760_9C86_987C58DD5EAC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CSkillPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSkillPage dialog

class CSkillPage : public CDialog
{
// Construction
public:
	void ResetPage();
	CString GetSavedUserSkills();
	CString GetSavedSkills();
	void PopulateWithData( CString occ );
	void SetSavedUserSkills( CString userskillstring );
	void SetSavedSkills( CString skillstring);
	void RemoveAllUserSkills();
	int GetUserSkillCount();
	int GetUserSkill( int index );
	void AddUserSkill(int skillindex);
	CString GetName();
	CString GetOCC();
	int GetID( int index );
	int GetListBoxCount();
	
	void UpdateLimit( BOOL );
	void SetOCC( CString occ);
	CString OCC;
	CSkillPage(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSkillPage)
	enum { IDD = IDD_SKILLS };
	CListBox	m_list2;
	CStatic	m_limit;
	CStatic	m_occ;
	CButton	m_bt;
	CListBox	m_list1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSkillPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSkillPage)
	afx_msg void OnView();
	afx_msg void OnAdd();
	afx_msg void OnRemove();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CList<int, int&> userskills;
	int limit;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSKILLPAGE_H__06BD81B5_A97F_4760_9C86_987C58DD5EAC__INCLUDED_)
