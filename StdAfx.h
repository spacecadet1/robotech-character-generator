// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__9C7EB624_21C9_4BB0_B6B5_1CF8786062D6__INCLUDED_)
#define AFX_STDAFX_H__9C7EB624_21C9_4BB0_B6B5_1CF8786062D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxtempl.h>

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>			// MFC ODBC database classes
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>			// MFC DAO database classes
#endif // _AFX_NO_DAO_SUPPORT

#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#define WM_USER_DOC WM_USER+1
#define WM_USER_OCC WM_USER+2
#define WM_USER_REFRESH WM_USER+3
//#define WM_USER_ADDINDEX WM_USER+3
//#define WM_USER_REMOVEINDEX WM_USER+4
//#define WM_USER_REMOVEALLINDEX WM_USER+5
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__9C7EB624_21C9_4BB0_B6B5_1CF8786062D6__INCLUDED_)


