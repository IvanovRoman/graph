// FlickerFreeDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FlickerFreeDemo.h"
#include "FlickerFreeDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CFlickerFreeDemoDlg dialog




CFlickerFreeDemoDlg::CFlickerFreeDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFlickerFreeDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFlickerFreeDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_checkFlicker);
	DDX_Control(pDX, IDC_BOUNCER1, m_bouncer1);
	DDX_Control(pDX, IDC_COMBO1, m_listSpeed);
	DDX_Control(pDX, IDC_BUTTON1, m_btnStart);
	DDX_Control(pDX, IDC_BUTTON2, m_btnStop);
}

BEGIN_MESSAGE_MAP(CFlickerFreeDemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CFlickerFreeDemoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CFlickerFreeDemoDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_CHECK1, &CFlickerFreeDemoDlg::OnBnClickedCheck1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CFlickerFreeDemoDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CFlickerFreeDemoDlg message handlers

BOOL CFlickerFreeDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_checkFlicker.SetCheck(BST_CHECKED);

	m_listSpeed.AddString(_T("1"));
	m_listSpeed.AddString(_T("2"));
	m_listSpeed.AddString(_T("3"));
	m_listSpeed.AddString(_T("4"));
	m_listSpeed.AddString(_T("5"));
	m_listSpeed.AddString(_T("6"));
	m_listSpeed.AddString(_T("7"));
	m_listSpeed.AddString(_T("8"));
	m_listSpeed.AddString(_T("9"));
	m_listSpeed.AddString(_T("10"));

	m_listSpeed.SetCurSel(0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFlickerFreeDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFlickerFreeDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFlickerFreeDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CFlickerFreeDemoDlg::OnBnClickedButton1()
{
	m_bouncer1.Start();

	m_btnStart.EnableWindow(FALSE);
	m_btnStop.EnableWindow(TRUE);
}

void CFlickerFreeDemoDlg::OnBnClickedButton2()
{
	m_bouncer1.Stop();

	m_btnStop.EnableWindow(FALSE);
	m_btnStart.EnableWindow(TRUE);
}

void CFlickerFreeDemoDlg::OnBnClickedCheck1()
{
	m_bouncer1.SetFlickerFree(!((m_checkFlicker.GetState() & 0x0003) == 1));
}

void CFlickerFreeDemoDlg::OnCbnSelchangeCombo1()
{
	CString str;
	m_listSpeed.GetLBText(m_listSpeed.GetCurSel(), str);

	if (str == "1")
	{
		m_bouncer1.SetSpeed(1);
	}
	else if (str == "2")
	{
		m_bouncer1.SetSpeed(2);
	}
	else if (str == "3")
	{
		m_bouncer1.SetSpeed(3);
	}
	else if (str == "4")
	{
		m_bouncer1.SetSpeed(4);
	}
	else if (str == "5")
	{
		m_bouncer1.SetSpeed(5);
	}
	else if (str == "6")
	{
		m_bouncer1.SetSpeed(6);
	}
	else if (str == "7")
	{
		m_bouncer1.SetSpeed(7);
	}
	else if (str == "8")
	{
		m_bouncer1.SetSpeed(8);
	}
	else if (str == "9")
	{
		m_bouncer1.SetSpeed(9);
	}
	else if (str == "10")
	{
		m_bouncer1.SetSpeed(10);
	}
}
