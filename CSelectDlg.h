#if !defined(AFX_CSELECTDLG_H__F8C4F4DD_7AAC_4CD1_9971_222605EFF401__INCLUDED_)
#define AFX_CSELECTDLG_H__F8C4F4DD_7AAC_4CD1_9971_222605EFF401__INCLUDED_

#include "MOSSet.h"	// Added by ClassView
#include "SkillSet.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CSelectDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSelectDlg dialog

class CSelectDlg : public CDialog
{
// Construction
public:
	void SetDlgType( bool choice );
	CString result;
	CSelectDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSelectDlg)
	enum { IDD = IDD_SELECT };
	CComboBox	m_cbSelect;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelectDlg)
	public:
	virtual int DoModal(bool choice);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSelectDlg)
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	bool m_choice;
	//CStringList skills;
	//CList<long,&long> items;
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSELECTDLG_H__F8C4F4DD_7AAC_4CD1_9971_222605EFF401__INCLUDED_)
