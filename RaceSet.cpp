// RaceSet.cpp : implementation file
//

#include "stdafx.h"
#include "Robotech.h"
#include "RaceSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RaceSet

IMPLEMENT_DYNAMIC(RaceSet, CRecordset)

RaceSet::RaceSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(RaceSet)
	m_Race = _T("");
	m_IQx = 0;
	m_IQ_ = 0;
	m_IQx_ = 0;
	m_MEx = 0;
	m_ME_ = 0;
	m_MEx_ = 0;
	m_MAx = 0;
	m_MA_ = 0;
	m_MAx_ = 0;
	m_PSx = 0;
	m_PS_ = 0;
	m_PSx_ = 0;
	m_PPx = 0;
	m_PP_ = 0;
	m_PPx_ = 0;
	m_PEx = 0;
	m_PE_ = 0;
	m_PEx_ = 0;
	m_PBx = 0;
	m_PB_ = 0;
	m_PBx_ = 0;
	m_SPDx = 0;
	m_SPD_ = 0;
	m_SPDx_ = 0;
	m_nFields = 25;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString RaceSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Robotech");
}

CString RaceSet::GetDefaultSQL()
{
	return _T("[Race]");
}

void RaceSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(RaceSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[Race]"), m_Race);
	RFX_Long(pFX, _T("[IQx]"), m_IQx);
	RFX_Long(pFX, _T("[IQ+]"), m_IQ_);
	RFX_Long(pFX, _T("[IQx+]"), m_IQx_);
	RFX_Long(pFX, _T("[MEx]"), m_MEx);
	RFX_Long(pFX, _T("[ME+]"), m_ME_);
	RFX_Long(pFX, _T("[MEx+]"), m_MEx_);
	RFX_Long(pFX, _T("[MAx]"), m_MAx);
	RFX_Long(pFX, _T("[MA+]"), m_MA_);
	RFX_Long(pFX, _T("[MAx+]"), m_MAx_);
	RFX_Long(pFX, _T("[PSx]"), m_PSx);
	RFX_Long(pFX, _T("[PS+]"), m_PS_);
	RFX_Long(pFX, _T("[PSx+]"), m_PSx_);
	RFX_Long(pFX, _T("[PPx]"), m_PPx);
	RFX_Long(pFX, _T("[PP+]"), m_PP_);
	RFX_Long(pFX, _T("[PPx+]"), m_PPx_);
	RFX_Long(pFX, _T("[PEx]"), m_PEx);
	RFX_Long(pFX, _T("[PE+]"), m_PE_);
	RFX_Long(pFX, _T("[PEx+]"), m_PEx_);
	RFX_Long(pFX, _T("[PBx]"), m_PBx);
	RFX_Long(pFX, _T("[PB+]"), m_PB_);
	RFX_Long(pFX, _T("[PBx+]"), m_PBx_);
	RFX_Long(pFX, _T("[SPDx]"), m_SPDx);
	RFX_Long(pFX, _T("[SPD+]"), m_SPD_);
	RFX_Long(pFX, _T("[SPDx+]"), m_SPDx_);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// RaceSet diagnostics

#ifdef _DEBUG
void RaceSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void RaceSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
