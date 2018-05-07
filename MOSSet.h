#if !defined(AFX_MOSSET_H__8FDC9F28_B08E_4E7C_A352_8E410846C018__INCLUDED_)
#define AFX_MOSSET_H__8FDC9F28_B08E_4E7C_A352_8E410846C018__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MOSSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MOSSet recordset

class MOSSet : public CRecordset
{
public:
	MOSSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(MOSSet)

// Field/Param Data
	//{{AFX_FIELD(MOSSet, CRecordset)
	CString	m_MOS;
	CString	m_Skills;
	CString	m_Select;
	long	m_Bonus;
	long	m_Limit;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MOSSet)
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

#endif // !defined(AFX_MOSSET_H__8FDC9F28_B08E_4E7C_A352_8E410846C018__INCLUDED_)
