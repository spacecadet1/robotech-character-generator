#if !defined(AFX_CMOSPAGE_H__D3F2FF28_3AEA_43CA_8EF2_9B42D520B342__INCLUDED_)
#define AFX_CMOSPAGE_H__D3F2FF28_3AEA_43CA_8EF2_9B42D520B342__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CMOSPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMOSPage dialog

class CMOSPage : public CDialog
{
// Construction
public:
	void ResetPage();
	CString GetSavedMOSSkills();
	void SetSavedMOSSkills( CString mosstring );
	void SetMOS( CString MOS );
	void CopyMOSBonus(CMap <int, int&, int, int&> &input);
	bool IsMOS();
	int GetID( int index );
	CString GetMOS();
	CString mos;
	int GetListBoxCount();
	void UpdateLimit(BOOL x);
	void SetOCC(CString occ);
	CMOSPage(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMOSPage)
	enum { IDD = IDD_MOS };
	CStatic	m_limit;
	CButton	m_select;
	CListBox	m_list2;
	CListBox	m_list1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMOSPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMOSPage)
	afx_msg void OnSelect();
	afx_msg void OnAdd();
	afx_msg void OnRemove();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int mos_score;
	int limit;
	CString condition;
	CString m_occ;
	int numSec;
	bool bMOS;
	CMap <int, int&, int, int&> mos_skills;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMOSPAGE_H__D3F2FF28_3AEA_43CA_8EF2_9B42D520B342__INCLUDED_)
