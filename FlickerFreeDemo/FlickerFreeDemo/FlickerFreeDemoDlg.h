// FlickerFreeDemoDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "ballbouncer.h"


// CFlickerFreeDemoDlg dialog
class CFlickerFreeDemoDlg : public CDialog
{
// Construction
public:
	CFlickerFreeDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_FLICKERFREEDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_checkFlicker;
	CBallBouncer m_bouncer1;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCheck1();
	CComboBox m_listSpeed;
	afx_msg void OnCbnSelchangeCombo1();
	CButton m_btnStart;
	CButton m_btnStop;
};
