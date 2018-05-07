#if !defined(AFX_CEXTRA_H__0AA2F89C_A148_490F_B287_F3E6058FEA3E__INCLUDED_)
#define AFX_CEXTRA_H__0AA2F89C_A148_490F_B287_F3E6058FEA3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CExtra.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExtra recordset

class CExtra : public CRecordset
{
public:
	CExtra(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CExtra)

// Field/Param Data
	//{{AFX_FIELD(CExtra, CRecordset)
	long	m_ID;
	CString	m_Info;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExtra)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CEXTRA_H__0AA2F89C_A148_490F_B287_F3E6058FEA3E__INCLUDED_)
