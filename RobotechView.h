// RobotechView.h : interface of the CRobotechView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROBOTECHVIEW_H__9F04B6CA_EBA5_4C42_AA08_FC25C68D2713__INCLUDED_)
#define AFX_ROBOTECHVIEW_H__9F04B6CA_EBA5_4C42_AA08_FC25C68D2713__INCLUDED_


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRobotechView : public CFormView
{
protected: // create from serialization only
	CRobotechView();
	DECLARE_DYNCREATE(CRobotechView)

	

public:
	//{{AFX_DATA(CRobotechView)
	enum { IDD = IDD_ROBOTECH_FORM };
	CTabCtrl	m_tab;
	//}}AFX_DATA

// Attributes
public:
	CRobotechDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRobotechView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrintPreview(CDC* pDC, CPrintInfo* pInfo, POINT point, CPreviewView* pView);
	//}}AFX_VIRTUAL

// Implementation
public:
	
	void PrintBody(CDC* pDC,CPrintInfo* pInfo);
	void AssignPtrs();

	virtual ~CRobotechView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	LRESULT RefreshView(WPARAM wParam, LPARAM lParam);
	LRESULT SetOCC(WPARAM wParam, LPARAM lParam);
	LRESULT RecordAttributes(WPARAM wParam, LPARAM lParam);
// Generated message map functions
protected:
	CMOSPage mospage;
	CFinalPage finalpage;
	CSkillPage skillpage;
	CPersonalPage personalpage;
	//{{AFX_MSG(CRobotechView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnFileNew();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	
	int CalculateLines( CDC* pDC);
	bool printflag;
	CString action;
	int tag;
	void PrintFooter(CDC* pDC, CPrintInfo* pInfo);
	void PrintHeader(CDC* pDC, CPrintInfo* pInfo);
	void TransferData();
	CFont TitleFont,HeaderFont, BodyFont, SubBodyFont, SignFont;
	int left, right, bottom, top;
	CString text; CSize textsize; int height,X,Y;
};

#ifndef _DEBUG  // debug version in RobotechView.cpp
inline CRobotechDoc* CRobotechView::GetDocument()
   { return (CRobotechDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROBOTECHVIEW_H__9F04B6CA_EBA5_4C42_AA08_FC25C68D2713__INCLUDED_)
