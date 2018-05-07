#if !defined(AFX_CPERSONALPAGE_H__C749BAB7_B1AD_4A96_91FB_E17483E12254__INCLUDED_)
#define AFX_CPERSONALPAGE_H__C749BAB7_B1AD_4A96_91FB_E17483E12254__INCLUDED_


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CPersonalPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPersonalPage dialog

class CPersonalPage : public CDialog
{
// Construction
public:
	void ResetPage();
	//void Test();
	void SetAlignment( CString alignment );
	void SetOCC( CString OCC );
	void SetRace(CString race);
	void SetName( CString name );
	void SetAttributes( int iq, int me, int ma, int ps, int pp, int pe, int pb, int spd);
	CString GetRace();
	int GetSDC();
	CString GetName();
	CString GetAlignment();
	int GetPE();
	void SetOCC();
	CView* m_pView;
	void SetAccessView( CWnd* pWnd);
	CPersonalPage(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPersonalPage)
	enum { IDD = IDD_PERSONAL };
	CEdit	m_name;
	CComboBox	m_align;
	CEdit	m_SPD;
	CEdit	m_PB;
	CEdit	m_PE;
	CEdit	m_PP;
	CEdit	m_PS;
	CEdit	m_MA;
	CEdit	m_ME;
	CEdit	m_IQ;
	CEdit	m_sdc;
	CComboBox	m_cbOCC;
	CComboBox	m_racebox;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPersonalPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPersonalPage)
	afx_msg void OnRoll();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelOCC();
	afx_msg void OnSelRace();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SelectOCC( CString data );
	
	
	void ClearAttributes();
	int GetAttributeScore( int x, int y, int z);
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CPERSONALPAGE_H__C749BAB7_B1AD_4A96_91FB_E17483E12254__INCLUDED_)
