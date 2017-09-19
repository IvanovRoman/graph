// flicker_freeDoc.cpp : implementation of the CFlicker_freeDoc class
//

#include "stdafx.h"
#include "flicker_free.h"

#include "flicker_freeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFlicker_freeDoc

IMPLEMENT_DYNCREATE(CFlicker_freeDoc, CDocument)

BEGIN_MESSAGE_MAP(CFlicker_freeDoc, CDocument)
	//{{AFX_MSG_MAP(CFlicker_freeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlicker_freeDoc construction/destruction

CFlicker_freeDoc::CFlicker_freeDoc()
{
	// TODO: add one-time construction code here

}

CFlicker_freeDoc::~CFlicker_freeDoc()
{
}

BOOL CFlicker_freeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CFlicker_freeDoc serialization

void CFlicker_freeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CFlicker_freeDoc diagnostics

#ifdef _DEBUG
void CFlicker_freeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFlicker_freeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFlicker_freeDoc commands
