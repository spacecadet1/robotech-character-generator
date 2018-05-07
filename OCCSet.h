#if !defined(AFX_OCCSET_H__B2832299_BA2C_403D_A87E_D792321B5DFD__INCLUDED_)
#define AFX_OCCSET_H__B2832299_BA2C_403D_A87E_D792321B5DFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OCCSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// OCCSet recordset

class OCCSet : public CRecordset
{
public:
	OCCSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(OCCSet)

// Field/Param Data
	//{{AFX_FIELD(OCCSet, CRecordset)
	CString	m_OCC;
	CString	m_OCC_Skills;
	CString	m_Other;
	long	m_NumSecondary;
	BOOL	m_MOS;
	CString	m_Bonus;
	long	m_SDC;
	long	m_NumOther;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(OCCSet)
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

#endif // !defined(AFX_OCCSET_H__B2832299_BA2C_403D_A87E_D792321B5DFD__INCLUDED_)
