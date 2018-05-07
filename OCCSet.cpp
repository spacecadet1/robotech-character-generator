// OCCSet.cpp : implementation file
//

#include "stdafx.h"
#include "Robotech.h"
#include "OCCSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// OCCSet

IMPLEMENT_DYNAMIC(OCCSet, CRecordset)

OCCSet::OCCSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(OCCSet)
	m_OCC = _T("");
	m_OCC_Skills = _T("");
	m_Other = _T("");
	m_NumSecondary = 0;
	m_MOS = FALSE;
	m_Bonus = _T("");
	m_SDC = 0;
	m_NumOther = 0;
	m_nFields = 8;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString OCCSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Robotech");
}

CString OCCSet::GetDefaultSQL()
{
	return _T("[OCC]");
}

void OCCSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(OCCSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[OCC]"), m_OCC);
	RFX_Text(pFX, _T("[OCC Skills]"), m_OCC_Skills);
	RFX_Text(pFX, _T("[Other]"), m_Other,1000);
	RFX_Long(pFX, _T("[NumSecondary]"), m_NumSecondary);
	RFX_Bool(pFX, _T("[MOS]"), m_MOS);
	RFX_Text(pFX, _T("[Bonus]"), m_Bonus,1000);
	RFX_Long(pFX, _T("[SDC]"), m_SDC);
	RFX_Long(pFX, _T("[NumOther]"), m_NumOther);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// OCCSet diagnostics

#ifdef _DEBUG
void OCCSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void OCCSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
