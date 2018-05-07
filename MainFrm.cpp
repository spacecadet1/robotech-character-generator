// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Robotech.h"

#include "MainFrm.h"
#include "CSplash.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ROBO_HELP, OnHelp)
	ON_COMMAND(ROBO_HELPTOPIC, OnHelptopic)
	//}}AFX_MSG_MAP
	// Global help commands
		
	//ON_COMMAND(ID_HELP_FINDER, CFrameWnd::OnHelpFinder)
	//ON_COMMAND(ID_HELP, CFrameWnd::OnHelp)
	//ON_COMMAND(ID_CONTEXT_HELP, CFrameWnd::OnContextHelp)
	//ON_COMMAND(ID_DEFAULT_HELP, CFrameWnd::OnHelpFinder)
	//ON_MESSAGE(WM_USER_DOC, RecordAttributes)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
	//m_wndToolBar.GetToolBarCtrl().EnableButton(1,FALSE);
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME)) //IDR_TOOLBAR1
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	//CMenu *pMenu = GetMenu();
	m_wndToolBar.SetButtonText(0,"New");
	m_wndToolBar.SetButtonText(1,"Open");
	m_wndToolBar.SetButtonText(2,"Save");
	m_wndToolBar.SetButtonText(8, "Print");
	m_wndToolBar.SetButtonText(10, "About");
	m_wndToolBar.SetButtonText(11, "Help");
	m_wndToolBar.SetSizes(CSize(48,48),CSize(40,19));
	
	
	//m_wndToolBar.GetToolBarCtrl().EnableButton(0, FALSE);
	//m_wndToolBar.Invalidate();
	//pMenu->EnableMenuItem(ID_FILE_NEW,MF_GRAYED);
	//m_wndToolBar.SetSizes(CSize(48,42),CSize(40,19));
	//m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	//EnableDocking(CBRS_ALIGN_ANY);
	//DockControlBar(&m_wndToolBar);

	

	// CG: The following line was added by the Splash Screen component.
	CSplashWnd::ShowSplashScreen(this);
	
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style &=~(WS_MAXIMIZEBOX);
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	//cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
	//	| WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;FWS_PREFIXTITLE|
	
	
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnHelp() 
{
	// TODO: Add your command handler code here
	//free((void*)m_pszHelpFilePath);
	::WinHelp(AfxGetMainWnd()->m_hWnd,_tcsdup(_T("Robotech.hlp")), HELP_CONTENTS, NULL);
	
}

void CMainFrame::OnHelptopic() 
{
	// TODO: Add your command handler code here
	//free((void*)m_pszHelpFilePath);
	::WinHelp(AfxGetMainWnd()->m_hWnd,_tcsdup(_T("Robotech.hlp")), HELP_CONTENTS, NULL);
}
