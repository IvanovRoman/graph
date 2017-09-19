// MyGraphDlg.h : header file
//

#if !defined(AFX_MYGRAPHDLG_H__0AED2C0A_00CA_471D_9C01_D4F2771B7FAD__INCLUDED_)
#define AFX_MYGRAPHDLG_H__0AED2C0A_00CA_471D_9C01_D4F2771B7FAD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyGraphDlg dialog

class CMyGraphDlg : public CDialog
{
// Construction
public:
	CPen*	m_pen;
	CMyGraphDlg(CWnd* pParent = NULL);	// standard constructor
	void CMyGraphDlg::Drawrect(CDC *pDC, int x);
	void CMyGraphDlg::Redraw();

	void CMyGraphDlg::OnDraw(CDC* dc);

	BOOL CMyGraphDlg::Draw(CDC* pDC, const CRect& bounds);

	CBitmap* pbmp;
	CDC* memDC;

// Dialog Data
	//{{AFX_DATA(CMyGraphDlg)
	enum { IDD = IDD_MYGRAPH_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyGraphDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyGraphDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYGRAPHDLG_H__0AED2C0A_00CA_471D_9C01_D4F2771B7FAD__INCLUDED_)
