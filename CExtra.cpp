// CExtra.cpp : implementation file
//

#include "stdafx.h"
#include "Robotech.h"
#include "CExtra.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CExtra

IMPLEMENT_DYNAMIC(CExtra, CRecordset)

CExtra::CExtra(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CExtra)
	m_ID = 0;
	m_Info = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CExtra::GetDefaultConnect()
{
	return _T("ODBC;DSN=Robotech");
}

CString CExtra::GetDefaultSQL()
{
	return _T("[Extra]");
}

void CExtra::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CExtra)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[Info]"), m_Info,1000);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CExtra diagnostics

#ifdef _DEBUG
void CExtra::AssertValid() const
{
	CRecordset::AssertValid();
}

void CExtra::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
