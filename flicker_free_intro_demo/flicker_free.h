// flicker_free.h : main header file for the FLICKER_FREE application
//

#if !defined(AFX_FLICKER_FREE_H__19CA9E4C_61D3_4742_9065_A09605FECE3E__INCLUDED_)
#define AFX_FLICKER_FREE_H__19CA9E4C_61D3_4742_9065_A09605FECE3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFlicker_freeApp:
// See flicker_free.cpp for the implementation of this class
//

class CFlicker_freeApp : public CWinApp
{
public:
	CFlicker_freeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlicker_freeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFlicker_freeApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLICKER_FREE_H__19CA9E4C_61D3_4742_9065_A09605FECE3E__INCLUDED_)
