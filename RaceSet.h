#if !defined(AFX_RACESET_H__2CED72A1_D57C_419C_B9F8_0FE3042710DC__INCLUDED_)
#define AFX_RACESET_H__2CED72A1_D57C_419C_B9F8_0FE3042710DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RaceSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// RaceSet recordset

class RaceSet : public CRecordset
{
public:
	RaceSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(RaceSet)

// Field/Param Data
	//{{AFX_FIELD(RaceSet, CRecordset)
	CString	m_Race;
	long	m_IQx;
	long	m_IQ_;
	long	m_IQx_;
	long	m_MEx;
	long	m_ME_;
	long	m_MEx_;
	long	m_MAx;
	long	m_MA_;
	long	m_MAx_;
	long	m_PSx;
	long	m_PS_;
	long	m_PSx_;
	long	m_PPx;
	long	m_PP_;
	long	m_PPx_;
	long	m_PEx;
	long	m_PE_;
	long	m_PEx_;
	long	m_PBx;
	long	m_PB_;
	long	m_PBx_;
	long	m_SPDx;
	long	m_SPD_;
	long	m_SPDx_;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RaceSet)
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

#endif // !defined(AFX_RACESET_H__2CED72A1_D57C_419C_B9F8_0FE3042710DC__INCLUDED_)
