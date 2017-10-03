// rotateDraw.h : main header file for the ROTATEDRAW application
//

#if !defined(AFX_ROTATEDRAW_H__A42741C8_6B14_4794_A7B8_F4A4B7FC0055__INCLUDED_)
#define AFX_ROTATEDRAW_H__A42741C8_6B14_4794_A7B8_F4A4B7FC0055__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRotateDrawApp:
// See rotateDraw.cpp for the implementation of this class
//

class CRotateDrawApp : public CWinApp
{
public:
	CRotateDrawApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRotateDrawApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRotateDrawApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROTATEDRAW_H__A42741C8_6B14_4794_A7B8_F4A4B7FC0055__INCLUDED_)
