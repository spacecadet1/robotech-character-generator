// CSelectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Robotech.h"
#include "CSelectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSelectDlg dialog


CSelectDlg::CSelectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSelectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSelectDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	
}


void CSelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSelectDlg)
	DDX_Control(pDX, IDC_COMBO1, m_cbSelect);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSelectDlg, CDialog)
	//{{AFX_MSG_MAP(CSelectDlg)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelectDlg message handlers

int CSelectDlg::DoModal(bool choice) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_choice = choice;
	
	return CDialog::DoModal();
}

void CSelectDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	CString text;
	m_cbSelect.GetWindowText(text);
	result = text;
	
	
}


void CSelectDlg::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	// TODO: Add your message handler code here
	
	if (m_choice == true)
	{
		MOSSet mosset;
		mosset.Open();
		while(!mosset.IsEOF())
		{
			m_cbSelect.AddString(mosset.m_MOS);
			mosset.MoveNext();
			
		}
	}
	else
	{
		SkillSet skillset;
		skillset.Open();
		while(!skillset.IsEOF())
		{
			int index=m_cbSelect.AddString(skillset.m_Skill);
			m_cbSelect.SetItemData(index, skillset.m_ID);
			skillset.MoveNext();
		}
	}

	
}


