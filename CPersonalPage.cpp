// CPersonalPage.cpp : implementation file
//

#include "stdafx.h"
#include "Robotech.h"
#include "CPersonalPage.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPersonalPage dialog


CPersonalPage::CPersonalPage(CWnd* pParent /*=NULL*/)
	: CDialog(CPersonalPage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPersonalPage)
	//}}AFX_DATA_INIT
}


void CPersonalPage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPersonalPage)
	DDX_Control(pDX, IDC_NAME, m_name);
	DDX_Control(pDX, IDC_DISP, m_align);
	DDX_Control(pDX, IDC_EDIT9, m_SPD);
	DDX_Control(pDX, IDC_EDIT8, m_PB);
	DDX_Control(pDX, IDC_EDIT7, m_PE);
	DDX_Control(pDX, IDC_EDIT6, m_PP);
	DDX_Control(pDX, IDC_EDIT5, m_PS);
	DDX_Control(pDX, IDC_EDIT4, m_MA);
	DDX_Control(pDX, IDC_EDIT3, m_ME);
	DDX_Control(pDX, IDC_EDIT2, m_IQ);
	DDX_Control(pDX, IDC_SDC, m_sdc);
	DDX_Control(pDX, IDC_OCC, m_cbOCC);
	DDX_Control(pDX, IDC_RACE, m_racebox);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPersonalPage, CDialog)
	//{{AFX_MSG_MAP(CPersonalPage)
	ON_BN_CLICKED(IDC_ROLL, OnRoll)
	ON_CBN_SELCHANGE(IDC_OCC, OnSelOCC)
	ON_CBN_SELCHANGE(IDC_RACE, OnSelRace)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPersonalPage message handlers

void CPersonalPage::OnRoll() 
{
	// TODO: Add your control notification handler code here
	CString data; int x;
	m_racebox.GetWindowText(data);
	if (data == "")
		return;
	srand((unsigned)time(NULL));
	RaceSet raceset;
	raceset.m_strFilter = "Race='"+ data + "'";
	raceset.Open();

	x = GetAttributeScore((int)raceset.m_IQx,(int)raceset.m_IQ_,(int)raceset.m_IQx_);
	data.Format("%d",x);
	m_IQ.SetWindowText(data);
	m_pView->SendMessage(WM_USER_DOC, x, 1);

	x =GetAttributeScore((int)raceset.m_MEx,(int)raceset.m_ME_,(int)raceset.m_MEx_);
	data.Format("%d",x);
	m_ME.SetWindowText(data);
	m_pView->SendMessage(WM_USER_DOC, x, 2);

	x=GetAttributeScore((int)raceset.m_MAx,(int)raceset.m_MA_,(int)raceset.m_MAx_);
	data.Format("%d",x);
	m_MA.SetWindowText(data);
	m_pView->SendMessage(WM_USER_DOC, x, 3);

	x=GetAttributeScore((int)raceset.m_PSx,(int)raceset.m_PS_,(int)raceset.m_PSx_);
	data.Format("%d",x);
	m_PS.SetWindowText(data);
	m_pView->SendMessage(WM_USER_DOC, x, 4);

	x=GetAttributeScore((int)raceset.m_PPx,(int)raceset.m_PP_,(int)raceset.m_PPx_);
	data.Format("%d",x);
	m_PP.SetWindowText(data);
	m_pView->SendMessage(WM_USER_DOC,x, 5);

	x=GetAttributeScore((int)raceset.m_PEx,(int)raceset.m_PE_,(int)raceset.m_PEx_);
	data.Format("%d",x);
	m_PE.SetWindowText(data);
	m_pView->SendMessage(WM_USER_DOC, x, 6);

	x=GetAttributeScore((int)raceset.m_PBx,(int)raceset.m_PB_,(int)raceset.m_PBx_);
	data.Format("%d",x);
	m_PB.SetWindowText(data);
	m_pView->SendMessage(WM_USER_DOC, x, 7);

	x=GetAttributeScore((int)raceset.m_SPDx,(int)raceset.m_SPD_,(int)raceset.m_SPDx_);
	data.Format("%d",x);
	m_SPD.SetWindowText(data);
	m_pView->SendMessage(WM_USER_DOC,x, 8);

	//SetOCC();
	//TRACE("\nTest is %i \n", atoi("Test"));

	

}

BOOL CPersonalPage::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	//fill up the race and occ comboboxes
	CString stuff;
	RaceSet raceset; OCCSet occset;
	raceset.Open();
	while ( !raceset.IsEOF())
	{
		stuff = raceset.m_Race;
		m_racebox.AddString(stuff);
		raceset.MoveNext();
	}

	occset.Open();
	while(!occset.IsEOF())
	{
		stuff = occset.m_OCC;
		m_cbOCC.AddString(stuff);
		occset.MoveNext();
	}
	
	
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPersonalPage::OnSelOCC() 
{
	// TODO: Add your control notification handler code here
	CString data;
	int index = m_cbOCC.GetCurSel();

	if(index<0)
		return;
	m_cbOCC.GetLBText(index, data); 

	SelectOCC(data);
	

		
}

int CPersonalPage::GetAttributeScore(int x, int y, int z)
{
	
	int score =0;
	for (int i=0;i< x; i++)
		score += (1+ rand()%6);

	if(score > ((x*6)-x))
		score += (1+rand()%6);
		
	

	score += y;
	
	for(i=0; i< z ; i++)
		score += (1+ rand()%6);

	return score;
		

}

void CPersonalPage::ClearAttributes()
{
	m_IQ.SetWindowText("");
	m_ME.SetWindowText("");
	m_MA.SetWindowText("");
	m_PS.SetWindowText("");
	m_PP.SetWindowText("");
	m_PE.SetWindowText("");
	m_PB.SetWindowText("");
	m_SPD.SetWindowText("");

}

void CPersonalPage::OnSelRace() 
{
	// TODO: Add your control notification handler code here
	ClearAttributes();
	
}

void CPersonalPage::SetAccessView(CWnd *pWnd)
{
	m_pView = (CView*)pWnd;
}

void CPersonalPage::SetOCC()
{
	CString *occ;
	CString text;
	m_cbOCC.GetWindowText(text);
	occ = new CString(text);

	m_pView->SendMessage(WM_USER_OCC,0, (LPARAM)occ);


}

int CPersonalPage::GetPE()
{
	CString text; int value;
	m_PE.GetWindowText(text);
	value = atoi(text);
	return value;
}

CString CPersonalPage::GetAlignment()
{	
	CString text;
	m_align.GetWindowText(text);
	return text;

}

CString CPersonalPage::GetName()
{
	CString text;
	m_name.GetWindowText(text);
	return text;
}

int CPersonalPage::GetSDC()
{
	CString text;
	m_sdc.GetWindowText(text);
	return atoi(text);

}

CString CPersonalPage::GetRace()
{
	CString text;
	m_racebox.GetWindowText(text);
	return text;
}

void CPersonalPage::SetAttributes
(int iq, int me, int ma, int ps, int pp, int pe, int pb, int spd)
{
	CString text;
	text.Format("%i",iq);
	m_IQ.SetWindowText(text);
	text.Format("%i",me);
	m_ME.SetWindowText(text);
	text.Format("%i",ma);
	m_MA.SetWindowText(text);
	text.Format("%i",ps);
	m_PS.SetWindowText(text);
	text.Format("%i",pp);
	m_PP.SetWindowText(text);
	text.Format("%i",pe);
	m_PE.SetWindowText(text);
	text.Format("%i",pb);
	m_PB.SetWindowText(text);
	text.Format("%i",spd);
	m_SPD.SetWindowText(text);

	//Send Message
	m_pView->SendMessage(WM_USER_REFRESH,0,0);

}

void CPersonalPage::SetName(CString name)
{
	m_name.SetWindowText(name);

}

void CPersonalPage::SetRace(CString race)
{
	m_racebox.SelectString(-1,race);
}

void CPersonalPage::SetOCC(CString OCC)
{
	m_cbOCC.SelectString(-1, OCC);
	SelectOCC(OCC);

}

void CPersonalPage::SetAlignment(CString alignment)
{
	m_align.SelectString(-1, alignment);
}

void CPersonalPage::SelectOCC(CString data)
{
	OCCSet occset;
	occset.m_strFilter = "OCC ='" + data+"'" ;
	occset.Open();
	data.Format("%d", occset.m_SDC);
	m_sdc.SetWindowText(data);
	SetOCC();

}



void CPersonalPage::ResetPage()
{
	ClearAttributes();
	m_cbOCC.SetCurSel(-1);
	m_racebox.SetCurSel(-1);
	m_align.SetCurSel(-1);
	m_name.SetWindowText("");
	m_sdc.SetWindowText("");


}
