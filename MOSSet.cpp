// MOSSet.cpp : implementation file
//

#include "stdafx.h"
#include "Robotech.h"
#include "MOSSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MOSSet

IMPLEMENT_DYNAMIC(MOSSet, CRecordset)

MOSSet::MOSSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(MOSSet)
	m_MOS = _T("");
	m_Skills = _T("");
	m_Select = _T("");
	m_Bonus = 0;
	m_Limit = 0;
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString MOSSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Robotech");
}

CString MOSSet::GetDefaultSQL()
{
	return _T("[MOS]");
}

void MOSSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(MOSSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[MOS]"), m_MOS);
	RFX_Text(pFX, _T("[Skills]"), m_Skills);
	RFX_Text(pFX, _T("[Select]"), m_Select);
	RFX_Long(pFX, _T("[Bonus]"), m_Bonus);
	RFX_Long(pFX, _T("[Limit]"), m_Limit);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// MOSSet diagnostics

#ifdef _DEBUG
void MOSSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void MOSSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
