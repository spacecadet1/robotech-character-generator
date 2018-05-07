// SkillSet.cpp : implementation file
//

#include "stdafx.h"
#include "Robotech.h"
#include "SkillSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SkillSet

IMPLEMENT_DYNAMIC(SkillSet, CRecordset)

SkillSet::SkillSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(SkillSet)
	m_ID = 0;
	m_Skill = _T("");
	m_Category = _T("");
	m_Base = 0;
	m_Experience = 0;
	m_Keywords = _T("");
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString SkillSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Robotech");
}

CString SkillSet::GetDefaultSQL()
{
	return _T("[Skills]");
}

void SkillSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(SkillSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[Skill]"), m_Skill);
	RFX_Text(pFX, _T("[Category]"), m_Category);
	RFX_Long(pFX, _T("[Base]"), m_Base);
	RFX_Long(pFX, _T("[Experience]"), m_Experience);
	RFX_Text(pFX, _T("[Keywords]"), m_Keywords);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// SkillSet diagnostics

#ifdef _DEBUG
void SkillSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void SkillSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
