// flicker_freeView.h : interface of the CFlicker_freeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FLICKER_FREEVIEW_H__3EDC970D_F259_4228_9007_1529D301547D__INCLUDED_)
#define AFX_FLICKER_FREEVIEW_H__3EDC970D_F259_4228_9007_1529D301547D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFlicker_freeView : public CFormView
{
protected: // create from serialization only
	CFlicker_freeView();
	DECLARE_DYNCREATE(CFlicker_freeView)

public:
	//{{AFX_DATA(CFlicker_freeView)
	enum { IDD = IDD_FLICKER_FREE_FORM };
	CButton	m_staticDrawArea;
	//}}AFX_DATA

// Attributes
public:
	CFlicker_freeDoc* GetDocument();

// my attributes /////////
public:
    RECT m_rectDraw;
    int  m_nX; 
    int  m_nY;
    BOOL m_bMyDraw; // the flag for EraseBkgnd
// end of my attributes //
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlicker_freeView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFlicker_freeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFlicker_freeView)
	afx_msg void OnPaint();
	afx_msg void OnBtnStart();
	afx_msg void OnBtnEnd();
	afx_msg void OnTimer(UINT nIDEvent);
    afx_msg BOOL OnEraseBkgnd(CDC *pDC);
    afx_msg void OnNcPaint( );
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in flicker_freeView.cpp
inline CFlicker_freeDoc* CFlicker_freeView::GetDocument()
   { return (CFlicker_freeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLICKER_FREEVIEW_H__3EDC970D_F259_4228_9007_1529D301547D__INCLUDED_)
