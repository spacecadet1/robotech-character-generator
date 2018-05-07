// RobotechView.cpp : implementation of the CRobotechView class
//

#include "stdafx.h"
#include "Robotech.h"

#include "RobotechDoc.h"
#include "RobotechView.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRobotechView

IMPLEMENT_DYNCREATE(CRobotechView, CFormView)

BEGIN_MESSAGE_MAP(CRobotechView, CFormView)
	//{{AFX_MSG_MAP(CRobotechView)
	ON_WM_SIZE()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
	ON_MESSAGE(WM_USER_DOC, RecordAttributes)
	ON_MESSAGE(WM_USER_OCC,SetOCC)
	ON_MESSAGE(WM_USER_REFRESH, RefreshView)
	
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRobotechView construction/destruction

CRobotechView::CRobotechView()
	: CFormView(CRobotechView::IDD)
{
	//{{AFX_DATA_INIT(CRobotechView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CRobotechView::~CRobotechView()
{
}

void CRobotechView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRobotechView)
	DDX_Control(pDX, IDC_TAB1, m_tab);
	//}}AFX_DATA_MAP
}

BOOL CRobotechView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CRobotechView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	//TabSetup here
	static bool Once=false;
	if( !Once )
	{
		Once = true;
		m_tab.InsertItem(0, "Personal");
		m_tab.InsertItem(1, "Skills" );
		m_tab.InsertItem(2, "MOS/Secondary Skills");
		m_tab.InsertItem(3, "Final");
		

		CRect Rect;
		m_tab.GetItemRect(0, &Rect);

		personalpage.Create(IDD_PERSONAL, &m_tab);
		personalpage.SetWindowPos(0, Rect.left+2, Rect.bottom+2, 0, 0, SWP_NOSIZE|SWP_NOZORDER );
		personalpage.ShowWindow(SW_NORMAL);
		

		skillpage.Create(IDD_SKILLS, &m_tab);
		skillpage.SetWindowPos(0, Rect.left+2, Rect.bottom+2, 0, 0, SWP_NOSIZE|SWP_NOZORDER );
		skillpage.ShowWindow(SW_HIDE);
		
		mospage.Create(IDD_MOS, &m_tab);
		mospage.SetWindowPos(0, Rect.left+2, Rect.bottom+2, 0, 0, SWP_NOSIZE|SWP_NOZORDER);
		mospage.ShowWindow(SW_HIDE);

		finalpage.Create(IDD_FINAL, &m_tab);
		finalpage.SetWindowPos(0, Rect.left+2, Rect.bottom+2, 0, 0, SWP_NOSIZE|SWP_NOZORDER );
		finalpage.ShowWindow(SW_HIDE); 
		AssignPtrs();
			
		
	}

}

/////////////////////////////////////////////////////////////////////////////
// CRobotechView printing

BOOL CRobotechView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	
	if(m_tab.GetCurSel() != 3)
	{
		m_tab.SetCurSel(3);
		personalpage.ShowWindow(SW_HIDE);
		skillpage.ShowWindow(SW_HIDE);
		mospage.ShowWindow(SW_HIDE);
		finalpage.ShowWindow(SW_SHOW);
	}
		
	TransferData();action="";  tag = -1;
	return DoPreparePrinting(pInfo);
	
	
	//return TRUE;
}

void CRobotechView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: add extra initialization before printing
	//pDC->SetMapMode( MM_HIENGLISH );
	/*CRobotechDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	
	pDoc->OnBeginPrinting(pDC, pInfo);*/

	int max_pages;
	pDC->SetMapMode( MM_HIENGLISH );
	LOGFONT lfTitle;
	::ZeroMemory(&lfTitle, sizeof(lfTitle));
	lfTitle.lfHeight = 260;
	lfTitle.lfWeight = FW_BOLD;
	strcpy(lfTitle.lfFaceName, "JuliusBlack"); //change to something else if you like;
	TitleFont.CreateFontIndirect(&lfTitle);

	LOGFONT lfHeader;
	::ZeroMemory(&lfHeader, sizeof(lfHeader));
	lfHeader.lfHeight = 160;
	lfHeader.lfWeight = FW_SEMIBOLD;
	//lfHeader.lfUnderline = TRUE;
	strcpy(lfHeader.lfFaceName, "Verdana");
	HeaderFont.CreateFontIndirect(&lfHeader);

	LOGFONT lfBody;
	::ZeroMemory(&lfBody, sizeof(lfBody));
	lfBody.lfHeight = 160;
	lfBody.lfWeight = FW_REGULAR;
	strcpy(lfBody.lfFaceName, "Verdana");
	BodyFont.CreateFontIndirect(&lfBody);

	LOGFONT lfSubBody;
	::ZeroMemory(&lfSubBody, sizeof(lfSubBody));
	lfSubBody.lfHeight = 120;
	lfSubBody.lfWeight = FW_REGULAR;
	lfSubBody.lfItalic = TRUE;
	strcpy(lfSubBody.lfFaceName, "Verdana");
	SubBodyFont.CreateFontIndirect(&lfSubBody);

	LOGFONT lfSign;
	::ZeroMemory(&lfSign, sizeof(lfSign));
	lfSign.lfHeight = 120;
	lfSign.lfWeight = FW_BOLD;
	strcpy(lfSign.lfFaceName, "Verdana");
	SignFont.CreateFontIndirect(&lfSign);

	CPageSetupDialog Tmp(PSD_RETURNDEFAULT|PSD_INTHOUSANDTHSOFINCHES);
	Tmp.DoModal();
	left = Tmp.m_psd.rtMargin.left - Tmp.m_psd.rtMinMargin.left;
	top = -(Tmp.m_psd.rtMargin.top - Tmp.m_psd.rtMinMargin.top);
	right = Tmp.m_psd.ptPaperSize.x - Tmp.m_psd.rtMargin.right - Tmp.m_psd.rtMinMargin.left;
	bottom = -(Tmp.m_psd.ptPaperSize.y - Tmp.m_psd.rtMargin.bottom - Tmp.m_psd.rtMinMargin.top);

	//TRACE(" Number of pages === %i \n", 
	//CalculateLines(pDC));
	max_pages=CalculateLines(pDC);
	pInfo->SetMaxPage(max_pages);

	//CFormView::OnBeginPrinting(pDC, pInfo);
	if(pInfo->m_bPreview)
	{
		AfxGetMainWnd()->ShowWindow(SW_SHOWMAXIMIZED);
		pInfo->m_nNumPreviewPages = max_pages;
	}
	

}

void CRobotechView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: add cleanup after printing
	//CRobotechDoc* pDoc = GetDocument();
	//ASSERT_VALID(pDoc);

	//pDoc->OnEndPrinting(pDC, pInfo);
	TitleFont.DeleteObject();
	BodyFont.DeleteObject();
	SubBodyFont.DeleteObject();
	HeaderFont.DeleteObject();
	SignFont.DeleteObject();
	tag = -1;
	action = "";

	//CFormView::OnEndPrinting(pDC, pInfo);
}

void CRobotechView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: add customized printing code here
	//CRobotechDoc* pDoc = GetDocument();
	//ASSERT_VALID(pDoc);

	//pDC->SetMapMode( MM_HIENGLISH );
	//pDoc->OnPrint(pDC,pInfo);

	//
	
	if(pInfo->m_nCurPage==1)
		PrintHeader(pDC, pInfo);
	PrintBody(pDC, pInfo);
	PrintFooter(pDC, pInfo);

	//CFormView::OnPrint(pDC, pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CRobotechView diagnostics

#ifdef _DEBUG
void CRobotechView::AssertValid() const
{
	CFormView::AssertValid();
}

void CRobotechView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRobotechDoc* CRobotechView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRobotechDoc)));
	return (CRobotechDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRobotechView message handlers

void CRobotechView::OnSize(UINT nType, int cx, int cy) 
{
	CFormView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	if( m_tab.GetSafeHwnd() )
		m_tab.SetWindowPos( 0, 0, 0, cx, cy, SWP_NOZORDER|SWP_NOMOVE );
	
	
}

void CRobotechView::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here

	int Index = m_tab.GetCurSel();

	personalpage.ShowWindow( Index == 0? SW_SHOW:SW_HIDE);

	skillpage.ShowWindow(Index == 1 ? SW_SHOW:SW_HIDE);

	mospage.ShowWindow(Index == 2 ? SW_SHOW:SW_HIDE);

	finalpage.ShowWindow(Index == 3 ? SW_SHOW:SW_HIDE);

	
	
	*pResult = 0;
}

LRESULT CRobotechView::RecordAttributes(WPARAM wParam, LPARAM lParam )
{
	int id;
	int value;
	
	CRobotechDoc* pDoc = GetDocument();

	ASSERT_VALID(pDoc);
	id = (int)lParam;
	value = (int)wParam;

	//test.Format("%d", value);
	//AfxMessageBox(id);
	
	if(id == 1)
		pDoc->IQ = value;

	if(id == 2)
		pDoc->ME= value;

	if(id == 3)
		pDoc->MA = value;

	if(id == 4)
		pDoc->PS = value;

	if(id == 5)
		pDoc->PP = value;

	if(id == 6)
		pDoc->PE = value;

	if(id == 7)
		pDoc->PB = value;

	if(id == 8)
		pDoc->SPD = value;

	
	return 0;
}

LRESULT CRobotechView::SetOCC(WPARAM wParam, LPARAM lParam)
{

	CRobotechDoc* pDoc = GetDocument();

	ASSERT_VALID(pDoc);

	CString *text;
	text = (CString*)lParam;

	pDoc->OCC = *text;

	skillpage.SetOCC(*text);
	mospage.SetOCC(*text);


	delete text;


	return 0;

}



void CRobotechView::AssignPtrs()
{
	CRobotechDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	personalpage.SetAccessView(this);
	finalpage.SetDlgPtrs(skillpage,personalpage,mospage);
	pDoc->GetPagePtrs(finalpage, mospage, personalpage, skillpage);
		
	if(pDoc->race != "")
	{
		pDoc->LoadData();
	}
	pDoc->IsShowing = TRUE;

	//TRACE("This is GetExtra: %s \n", pDoc->GetExtra(1000));
}

void CRobotechView::TransferData()
{
	CRobotechDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OCC = skillpage.GetOCC();
	pDoc->name = personalpage.GetName();
	pDoc->hitpts = finalpage.GetHP();
	pDoc->SDC = personalpage.GetSDC();
	pDoc->alignment = personalpage.GetAlignment();
	pDoc->level = finalpage.GetExpLevel();
	pDoc->race = personalpage.GetRace();
	
	pDoc->ClearSkills();
	for(int i=0; i< finalpage.GetSkillCount(); i++)
	{
		CSkill temp;
		temp = finalpage.GetSkill(i);
		pDoc->AddSkill(temp);
	}

	pDoc->AssignBonus();
}


void CRobotechView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	//CRobotechDoc* pDoc = GetDocument();
	//ASSERT_VALID(pDoc);

	//pDoc->OnPrepareDC(pDC, pInfo);
	if( pInfo)
	{
		pDC->SetMapMode( MM_HIENGLISH );
		//pInfo->m_bContinuePrinting=TRUE;
		
	}
	
	//CFormView::OnPrepareDC(pDC, pInfo);
}

void CRobotechView::PrintHeader(CDC* pDC, CPrintInfo* pInfo)
{
	
	CRobotechDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	Y = top;
	pDC->SelectObject(&TitleFont);
	pDC->MoveTo(left, top);
	pDC->LineTo(right, top);

	text = pDoc->name + " - " + pDoc->OCC;
	textsize = pDC->GetTextExtent(text);
	height = textsize.cy;
	Y += textsize.cy + 50;
	pDC->TextOut(left, Y, text);
	


}

void CRobotechView::PrintBody(CDC* pDC, CPrintInfo* pInfo)
{
	
	CRobotechDoc* pDoc = GetDocument(); int i; int ix; int j;
	int width = right-left;
	ASSERT_VALID(pDoc);

	if(pInfo->m_nCurPage >1)
	{
		
		Y = top-100;
		if(action== "WP")
			goto wp;
		if(action == "NOTES1")
			goto notes1;
		if(action == "NOTES2" || action == "NOTES3")
			goto notes2;
	}	

	pDC->SelectObject(&HeaderFont);
	text = "Hit Points:";
	textsize = pDC->GetTextExtent(text);
	Y = top-100;
	pDC->TextOut(left, Y, text);

	pDC->SelectObject(&BodyFont);
	text.Format("%i", pDoc->hitpts);
	X =left+ textsize.cx+10;
	pDC->TextOut(X, Y, text); textsize = pDC->GetTextExtent(text);

	pDC->SelectObject(&HeaderFont);
	text = "SDC:"; X += textsize.cx +40;
	pDC->TextOut(X, Y, text);
	textsize = pDC->GetTextExtent(text);

	pDC->SelectObject(&BodyFont);
	text.Format("%i", pDoc->SDC); X += textsize.cx +10;
	pDC->TextOut(X, Y, text);

	pDC->SelectObject(&HeaderFont);
	text = "Race:";
	Y -=textsize.cy;
	textsize = pDC->GetTextExtent(text);
	pDC->TextOut(left, Y, text);

	pDC->SelectObject(&BodyFont);
	text = pDoc->race;
	pDC->TextOut(left +20+ textsize.cx, Y, text);

	pDC->SelectObject(&HeaderFont);
	text = "Alignment:";
	Y -= textsize.cy;
	textsize = pDC->GetTextExtent(text);
	pDC->TextOut(left, Y, text);

	pDC->SelectObject(&BodyFont);
	text = pDoc->alignment;
	pDC->TextOut(left +20+ textsize.cx, Y, text);

	pDC->SelectObject(&HeaderFont);
	text = "IQ:";
	Y -= textsize.cy;
	textsize = pDC->GetTextExtent(text);
	pDC->TextOut(left, Y, text);

	pDC->SelectObject(&BodyFont);
	text.Format("%i", pDoc->IQ);
	X = left +20+ textsize.cx;
	pDC->TextOut(X, Y, text);

	pDC->SelectObject(&HeaderFont);
	text = "PP:"; X += 20 + textsize.cx;
	pDC->TextOut(X, Y, text);
	textsize = pDC->GetTextExtent(text);

	pDC->SelectObject(&BodyFont);
	text.Format("%i", pDoc->PP);
	X += textsize.cx + 20;
	pDC->TextOut(X, Y, text);

	pDC->SelectObject(&HeaderFont);
	text = "ME:";
	Y -= textsize.cy;
	textsize = pDC->GetTextExtent(text);
	pDC->TextOut(left, Y, text);

	pDC->SelectObject(&BodyFont);
	text.Format("%i", pDoc->ME);
	X = left +20+ textsize.cx;
	pDC->TextOut(X, Y, text);

	pDC->SelectObject(&HeaderFont);
	text = "PE:"; X += 20 + textsize.cx;
	pDC->TextOut(X, Y, text);
	textsize = pDC->GetTextExtent(text);

	pDC->SelectObject(&BodyFont);
	text.Format("%i", pDoc->PE);
	X += textsize.cx + 20;
	pDC->TextOut(X, Y, text);

	pDC->SelectObject(&HeaderFont);
	text = "MA:";
	Y -= textsize.cy;
	textsize = pDC->GetTextExtent(text);
	pDC->TextOut(left, Y, text);

	pDC->SelectObject(&BodyFont);
	text.Format("%i", pDoc->MA);
	X = left +20+ textsize.cx;
	pDC->TextOut(X, Y, text);

	pDC->SelectObject(&HeaderFont);
	text = "PB:"; X += 20 + textsize.cx;
	pDC->TextOut(X, Y, text);
	textsize = pDC->GetTextExtent(text);

	pDC->SelectObject(&BodyFont);
	text.Format("%i", pDoc->PB);
	X += textsize.cx + 20;
	pDC->TextOut(X, Y, text);

	pDC->SelectObject(&HeaderFont);
	text = "PS:";
	Y -= textsize.cy;
	textsize = pDC->GetTextExtent(text);
	pDC->TextOut(left, Y, text);

	pDC->SelectObject(&BodyFont);
	text.Format("%i", pDoc->PS);
	X = left +20+ textsize.cx;
	pDC->TextOut(X, Y, text);

	pDC->SelectObject(&HeaderFont);
	text = "SPD:"; X += 20 + textsize.cx;
	pDC->TextOut(X, Y, text);
	textsize = pDC->GetTextExtent(text);

	pDC->SelectObject(&BodyFont);
	text.Format("%i", pDoc->SPD);
	X += textsize.cx + 20;
	pDC->TextOut(X, Y, text);

	pDC->SelectObject(&HeaderFont);
	text = "Age:";
	Y -= textsize.cy;
	pDC->TextOut(left, Y, text);

	text = "Weight:";
	Y -= textsize.cy;
	pDC->TextOut(left, Y, text);
	textsize = pDC->GetTextExtent(text);
	text = "Height: ";
	pDC->TextOut(left + textsize.cx+ 400, Y, text);

	text = "Disposition:";
	Y -= textsize.cy;
	pDC->TextOut(left, Y, text);
	textsize = pDC->GetTextExtent(text);

	text = "Level of Experience:";
	Y -= textsize.cy*2;
	pDC->TextOut(left, Y, text);
	textsize = pDC->GetTextExtent(text);

	pDC->SelectObject(&BodyFont);
	text.Format("%i", pDoc->level);
	pDC->TextOut(left + textsize.cx +20, Y, text);

	pDC->SelectObject(&HeaderFont);
	text = "Skills:";
	Y -= textsize.cy;
	pDC->TextOut(left, Y, text);
	textsize = pDC->GetTextExtent(text);

	pDC->SelectObject(&BodyFont);
	Y -= textsize.cy;

	for(i=0; i< pDoc->SkillCount();i++)
	{
		CSkill buffer = pDoc->GetSkill(i);
		if(buffer.category != "WP")
		{
			if(buffer.increment >0)
				text.Format("%s:  %i +%i",buffer.skill, buffer.level, buffer.increment);
			else
			{				
				text.Format("%s ", buffer.skill);
			}
			pDC->TextOut(left , Y, text);
			textsize=pDC->GetTextExtent(text);
			Y -= textsize.cy;
		}
	}
	height = textsize.cy;
wp:
	//Weapon Profeciencies
	pDC->SelectObject(&HeaderFont);
	text = "WP:";
	Y -= textsize.cy;
	pDC->TextOut(left, Y, text);
	textsize = pDC->GetTextExtent(text);

	
	Y -= textsize.cy;

	for(ix=0; ix< pDoc->SkillCount(); ix++)
	{
		CSkill buffer = pDoc->GetSkill(ix);
		if((buffer.category == "WP") && (pInfo->m_nCurPage ==1))
		{
			pDC->SelectObject(&BodyFont);
			text.Format("%s",buffer.skill);
			pDC->TextOut(left , Y, text);
			CString subtext = pDoc->GetExtra(buffer.index);
			pDC->SelectObject(&SubBodyFont);
			textsize = pDC->GetTextExtent(subtext);
			Y -=height;
			pDC->TextOut(left, Y, subtext);
			textsize=pDC->GetTextExtent(text);
			Y -= height;
			
		}
		else if((pInfo->m_nCurPage >1)&&(buffer.category == "WP"))
		{
			if(ix> tag)
			{
				pDC->SelectObject(&BodyFont);
				text.Format("%s",buffer.skill);
				pDC->TextOut(left , Y, text);
				CString subtext = pDoc->GetExtra(buffer.index);
				pDC->SelectObject(&SubBodyFont);
				textsize = pDC->GetTextExtent(subtext);
				Y -=height;
				pDC->TextOut(left, Y, subtext);
				textsize=pDC->GetTextExtent(text);
				Y -= height;
			}
		}
		//check Y here
		if(Y< -9000)
		{
			action = "WP";
			tag = ix;
			return;
		}
	}
	//put "notes:"
notes1:
	pDC->SelectObject(&HeaderFont);
	text = "Notes:";
	Y -= textsize.cy;
	pDC->TextOut(left, Y, text);
	textsize = pDC->GetTextExtent(text);

	Y -= textsize.cy; 

	for(j=0; j< pDoc->SkillCount(); j++)
	{
		CSkill buffer = pDoc->GetSkill(j);
		CString extra = pDoc->GetExtra(buffer.index);
		if((buffer.category != "WP")&&(extra !="") &&(pInfo->m_nCurPage ==1))
		{
			pDC->SelectObject(&BodyFont);
			//text = buffer.skill +" ";
			if((buffer.level >0)&&( buffer.increment<1))
				text.Format("%s +(%i)", buffer.skill, buffer.level);
			else
				text = buffer.skill;
			textsize=pDC->GetTextExtent(text);
			pDC->TextOut(left, Y, text);
			Y -= height;
			pDC->SelectObject(&SubBodyFont);
			//text = pDoc->GetExtra(buffer.index);
			text = extra;
			textsize = pDC->GetTextExtent(text);
			if( textsize.cx > width)
			{
				//TRACE("\n Parsing... \n");
				//call a parseing function
				CStringList textlist; //int p;
				int textw = textsize.cx;
				while(textw > width)
				{
					int px = text.Find(" ", 124);
					
					if(px < 0)
					{
						px = text.Find(",", 124);
						if(px < 0)
							px = text.Find(";", 124);
						px++;
					}
				

					textlist.AddTail(text.Left(px));
					text = text.Mid(px);
					CSize tempsize = pDC->GetTextExtent(text);
					textw = tempsize.cx;

				}
				//print
				//TRACE("\n Here is the printing \n");
				 CSize smllprnt;
				for(int b =0; b< textlist.GetCount(); b++)
				{
					POSITION ps = textlist.FindIndex(b);
					CString temptxt = textlist.GetAt(ps);
					pDC->TextOut(left, Y, temptxt);
					smllprnt = pDC->GetTextExtent(temptxt);
					Y -=smllprnt.cy; 
				}
				pDC->TextOut(left, Y, text);
				//Y -=smllprnt.cy;
			}
			else
				pDC->TextOut(left, Y-20, text);

			Y -= height;
			
		}
		else if ((pInfo->m_nCurPage >1)&&(buffer.category != "WP") &&(extra !=""))
		{
			if(j> tag)
			{
				pDC->SelectObject(&BodyFont);
			//text = buffer.skill +" ";
				if((buffer.level >0)&&( buffer.increment<1))
					text.Format("%s +(%i)", buffer.skill, buffer.level);
				else
					text = buffer.skill;
			textsize=pDC->GetTextExtent(text);
			pDC->TextOut(left, Y, text);
			Y -= height;
			pDC->SelectObject(&SubBodyFont);
			//text = pDoc->GetExtra(buffer.index);
			text = extra;
			textsize = pDC->GetTextExtent(text);
			if( textsize.cx > width)
			{
				//TRACE("\n Parsing... \n");
				//call a parseing function
				CStringList textlist; //int p;
				int textw = textsize.cx;
				while(textw > width)
				{
					int px = text.Find(" ", 124);
					
					if(px < 0)
					{
						px = text.Find(",", 124);
						if(px < 0)
							px = text.Find(";", 124);
						px++;
					}
				

					textlist.AddTail(text.Left(px));
					text = text.Mid(px);
					CSize tempsize = pDC->GetTextExtent(text);
					textw = tempsize.cx;

				}
				//print
				//TRACE("\n Here is the printing \n");
				 CSize smllprnt;
				for(int b =0; b< textlist.GetCount(); b++)
				{
					POSITION ps = textlist.FindIndex(b);
					CString temptxt = textlist.GetAt(ps);
					pDC->TextOut(left, Y, temptxt);
					smllprnt = pDC->GetTextExtent(temptxt);
					Y -=smllprnt.cy; 
				}
				pDC->TextOut(left, Y, text);
				//Y -=smllprnt.cy;
			}
			else
				pDC->TextOut(left, Y-20, text);

			Y -= height;

			}
		}
		if(Y < -9000)
		{
			tag = j;
			action = "NOTES1";
			return;
		}
	}
	Y-=20;
notes2:
	if(Y < -9000)
	{
		tag = -1;
		action = "NOTES2";
		return;
		
	}
	for(ix=0; ix<pDoc->GetNotesCount(); ix++)
	{
		
		if(pInfo->m_nCurPage ==1)
		{
			text = "* "+ pDoc->GetNotes(ix);
			pDC->SelectObject(&BodyFont);
			textsize = pDC->GetTextExtent(text);
			pDC->TextOut(left, Y, text);
			Y -= textsize.cy;
		}
		else if (pInfo->m_nCurPage >1)
		{
			if(ix > tag)
			{
				text = "* "+ pDoc->GetNotes(ix);
				pDC->SelectObject(&BodyFont);
				textsize = pDC->GetTextExtent(text);
				pDC->TextOut(left, Y, text);
				Y -= textsize.cy;

			}
		}
		if(Y < -9000)
		{
			tag = ix;
			action = "NOTES3";			
			return;
		}

	}

}

void CRobotechView::PrintFooter(CDC* pDC, CPrintInfo* pInfo)
{
	
	pDC->SelectObject(&SignFont);
	text = "made with Robotech(tm) Character Builder";
	pDC->TextOut(left+400, bottom-120, text);

	pDC->SetMapMode(MM_LOENGLISH);
	CBitmap pic;
	pic.LoadBitmap(IDB_BITMAP2);
	CDC mem;
	mem.CreateCompatibleDC(pDC);
	mem.SelectObject(&pic);

	BITMAP bmp;
	pic.GetBitmap(&bmp);
	int x = bmp.bmWidth;
	int y = bmp.bmHeight;
	
	
	pDC->BitBlt(75, -1000, x, y, &mem, 0,0, SRCCOPY);

}

void CRobotechView::OnEndPrintPreview(CDC* pDC, CPrintInfo* pInfo, POINT point, CPreviewView* pView) 
{
	// TODO: Add your specialized code here and/or call the base class
	//pView->ShowWindow(SW_NORMAL);
	AfxGetMainWnd()->ShowWindow(SW_NORMAL);
	
	CFormView::OnEndPrintPreview(pDC, pInfo, point, pView);
}


int CRobotechView::CalculateLines(CDC *pDC)
{
	CRobotechDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	
	CSize reg, tiny;
	int skillcount=0, infocount=0; int marker = top-100;
	int i; float pages;

	skillcount = pDoc->SkillCount()+17;

	for(i=0; i< pDoc->SkillCount(); i++)
	{
		CSkill buffer = pDoc->GetSkill(i); 
		if((buffer.category != "WP") && (buffer.increment < 1))
		{
			skillcount++;
			CString temp=pDoc->GetExtra(buffer.index);
			infocount += (int)ceil( temp.GetLength()/124);
			
		}

		else if (buffer.category == "WP")
		{
			skillcount++;
			CString temp = pDoc->GetExtra(buffer.index);
			infocount += (int)ceil(temp.GetLength()/124);
		}
		

	}

	pDC->SelectObject(&BodyFont); reg = pDC->GetTextExtent("Hy");
	marker-=skillcount*reg.cy;
	pDC->SelectObject(&SubBodyFont); tiny = pDC->GetTextExtent("Hy");
	marker-= infocount*tiny.cy;
		
	pages = float(marker)/float(-9000);
	
	return (int)ceil(pages);
}




LRESULT CRobotechView::RefreshView(WPARAM wParam, LPARAM lParam)
{
	if(m_tab.GetCurSel() != 0)
	{
		m_tab.SetCurSel(0);
		personalpage.ShowWindow(SW_SHOW);
		skillpage.ShowWindow(SW_HIDE);
		mospage.ShowWindow(SW_HIDE);
		finalpage.ShowWindow(SW_HIDE);
	}
	return 0;

}

void CRobotechView::OnFileNew() 
{
	// TODO: Add your command handler code here
	//MessageBox("Hello");
	if(MessageBox("Do you want to reset? If so save the current document and then reset",
		"New Character?",MB_ICONQUESTION | MB_YESNO)==IDNO)
		return;
	CRobotechDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->ResetDocument(); //pDoc->DeleteContents();
	//pDoc->SetTitle("[New] |");
	pDoc->OnNewDocument();

	if(m_tab.GetCurSel() != 0)
	{
		m_tab.SetCurSel(0);
		personalpage.ShowWindow(SW_SHOW);
		skillpage.ShowWindow(SW_HIDE);
		mospage.ShowWindow(SW_HIDE);
		finalpage.ShowWindow(SW_HIDE);
	}

	personalpage.ResetPage();
	skillpage.ResetPage();
	mospage.ResetPage();
	finalpage.ResetPage();
	
}
