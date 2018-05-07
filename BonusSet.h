#if !defined(AFX_BONUSSET_H__2C24CCAF_2B2F_47FF_A11D_E777A89410CA__INCLUDED_)
#define AFX_BONUSSET_H__2C24CCAF_2B2F_47FF_A11D_E777A89410CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BonusSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// BonusSet recordset

class BonusSet : public CRecordset
{
public:
	BonusSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(BonusSet)

// Field/Param Data
	//{{AFX_FIELD(BonusSet, CRecordset)
	long	m_Score;
	long	m_IQ;
	long	m_ME;
	long	m_MA;
	long	m_PS;
	long	m_PP;
	CString	m_PE;
	long	m_PB;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(BonusSet)
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

#endif // !defined(AFX_BONUSSET_H__2C24CCAF_2B2F_47FF_A11D_E777A89410CA__INCLUDED_)
