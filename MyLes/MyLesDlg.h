// MyLesDlg.h : header file
//

#if !defined(AFX_MYLESDLG_H__85B6A9A2_2091_4B9E_9E3B_8DB2CE034574__INCLUDED_)
#define AFX_MYLESDLG_H__85B6A9A2_2091_4B9E_9E3B_8DB2CE034574__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyLesDlg dialog

class CMyLesDlg : public CDialog
{
// Construction
public:
	CMyLesDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyLesDlg)
	enum { IDD = IDD_MYLES_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyLesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyLesDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYLESDLG_H__85B6A9A2_2091_4B9E_9E3B_8DB2CE034574__INCLUDED_)
