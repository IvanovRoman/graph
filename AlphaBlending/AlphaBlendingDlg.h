// AlphaBlendingDlg.h : header file
//

#if !defined(AFX_ALPHABLENDINGDLG_H__731C071E_3638_43B5_9D22_C52347BDBA19__INCLUDED_)
#define AFX_ALPHABLENDINGDLG_H__731C071E_3638_43B5_9D22_C52347BDBA19__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAlphaBlendingDlg dialog

class CAlphaBlendingDlg : public CDialog
{
// Construction
public:
	CAlphaBlendingDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAlphaBlendingDlg)
	enum { IDD = IDD_ALPHABLENDING_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAlphaBlendingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	// Generated message map functions
	//{{AFX_MSG(CAlphaBlendingDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALPHABLENDINGDLG_H__731C071E_3638_43B5_9D22_C52347BDBA19__INCLUDED_)
