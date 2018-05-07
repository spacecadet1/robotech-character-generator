#if !defined(AFX_SKILLSET_H__C636D9C1_B015_4E5B_A2C3_C706C8396C00__INCLUDED_)
#define AFX_SKILLSET_H__C636D9C1_B015_4E5B_A2C3_C706C8396C00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SkillSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SkillSet recordset

class SkillSet : public CRecordset
{
public:
	SkillSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(SkillSet)

// Field/Param Data
	//{{AFX_FIELD(SkillSet, CRecordset)
	long	m_ID;
	CString	m_Skill;
	CString	m_Category;
	long	m_Base;
	long	m_Experience;
	CString	m_Keywords;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SkillSet)
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

#endif // !defined(AFX_SKILLSET_H__C636D9C1_B015_4E5B_A2C3_C706C8396C00__INCLUDED_)
