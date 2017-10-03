// rotateDrawDlg.h : header file
//

#if !defined(AFX_ROTATEDRAWDLG_H__683BCE9A_3BCC_41FD_AA7D_7A806034042E__INCLUDED_)
#define AFX_ROTATEDRAWDLG_H__683BCE9A_3BCC_41FD_AA7D_7A806034042E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRotateDrawDlg dialog

class CRotateDrawDlg : public CDialog
{
// Construction
public:
	CRotateDrawDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRotateDrawDlg)
	enum { IDD = IDD_ROTATEDRAW_DIALOG };
	CButton	m_ctlDrawArea;
	int		m_iShapeType;
	int		m_iAngle;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRotateDrawDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRotateDrawDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnBtnUpdate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROTATEDRAWDLG_H__683BCE9A_3BCC_41FD_AA7D_7A806034042E__INCLUDED_)
