// BonusSet.cpp : implementation file
//

#include "stdafx.h"
#include "Robotech.h"
#include "BonusSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// BonusSet

IMPLEMENT_DYNAMIC(BonusSet, CRecordset)

BonusSet::BonusSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(BonusSet)
	m_Score = 0;
	m_IQ = 0;
	m_ME = 0;
	m_MA = 0;
	m_PS = 0;
	m_PP = 0;
	m_PE = _T("");
	m_PB = 0;
	m_nFields = 8;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString BonusSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Robotech");
}

CString BonusSet::GetDefaultSQL()
{
	return _T("[Bonus]");
}

void BonusSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(BonusSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[Score]"), m_Score);
	RFX_Long(pFX, _T("[IQ]"), m_IQ);
	RFX_Long(pFX, _T("[ME]"), m_ME);
	RFX_Long(pFX, _T("[MA]"), m_MA);
	RFX_Long(pFX, _T("[PS]"), m_PS);
	RFX_Long(pFX, _T("[PP]"), m_PP);
	RFX_Text(pFX, _T("[PE]"), m_PE);
	RFX_Long(pFX, _T("[PB]"), m_PB);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// BonusSet diagnostics

#ifdef _DEBUG
void BonusSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void BonusSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
