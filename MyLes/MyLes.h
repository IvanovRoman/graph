// MyLes.h : main header file for the MYLES application
//

#if !defined(AFX_MYLES_H__D4D0647F_0A22_42FF_B376_8B50525D18ED__INCLUDED_)
#define AFX_MYLES_H__D4D0647F_0A22_42FF_B376_8B50525D18ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyLesApp:
// See MyLes.cpp for the implementation of this class
//

class CMyLesApp : public CWinApp
{
public:
	CMyLesApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyLesApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyLesApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYLES_H__D4D0647F_0A22_42FF_B376_8B50525D18ED__INCLUDED_)
