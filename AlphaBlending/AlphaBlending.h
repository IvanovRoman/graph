// AlphaBlending.h : main header file for the ALPHABLENDING application
//

#if !defined(AFX_ALPHABLENDING_H__09059124_FB44_4496_8B53_880A0EFC0F58__INCLUDED_)
#define AFX_ALPHABLENDING_H__09059124_FB44_4496_8B53_880A0EFC0F58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAlphaBlendingApp:
// See AlphaBlending.cpp for the implementation of this class
//

class CAlphaBlendingApp : public CWinApp
{
public:
	CAlphaBlendingApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAlphaBlendingApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAlphaBlendingApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALPHABLENDING_H__09059124_FB44_4496_8B53_880A0EFC0F58__INCLUDED_)
