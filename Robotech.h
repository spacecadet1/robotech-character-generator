// Robotech.h : main header file for the ROBOTECH application
//

#if !defined(AFX_ROBOTECH_H__6485DAF0_A9DF_43A6_80AE_B6C4287FF354__INCLUDED_)
#define AFX_ROBOTECH_H__6485DAF0_A9DF_43A6_80AE_B6C4287FF354__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRobotechApp:
// See Robotech.cpp for the implementation of this class
//

#include "SkillSet.h"
#include "OCCSet.h"
#include "RaceSet.h"
#include "MOSSet.h"
#include "BonusSet.h"
#include "CFinalPage.h"	
#include "CPersonalPage.h"	
#include "CSkillPage.h"	
#include "CMOSPage.h"
#include "CSelectDlg.h"
#include "CSkill.h"

class CRobotechApp : public CWinApp
{
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CRobotechApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRobotechApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CRobotechApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROBOTECH_H__6485DAF0_A9DF_43A6_80AE_B6C4287FF354__INCLUDED_)
