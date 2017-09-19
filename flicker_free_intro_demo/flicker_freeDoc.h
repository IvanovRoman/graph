// flicker_freeDoc.h : interface of the CFlicker_freeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLICKER_FREEDOC_H__05C5C45E_A33E_4AB5_A320_EBE789A7A879__INCLUDED_)
#define AFX_FLICKER_FREEDOC_H__05C5C45E_A33E_4AB5_A320_EBE789A7A879__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFlicker_freeDoc : public CDocument
{
protected: // create from serialization only
	CFlicker_freeDoc();
	DECLARE_DYNCREATE(CFlicker_freeDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlicker_freeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFlicker_freeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFlicker_freeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLICKER_FREEDOC_H__05C5C45E_A33E_4AB5_A320_EBE789A7A879__INCLUDED_)
