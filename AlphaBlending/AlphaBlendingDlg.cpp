// AlphaBlendingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AlphaBlending.h"
#include "AlphaBlendingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAlphaBlendingDlg dialog

CAlphaBlendingDlg::CAlphaBlendingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAlphaBlendingDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAlphaBlendingDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAlphaBlendingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAlphaBlendingDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAlphaBlendingDlg, CDialog)
	//{{AFX_MSG_MAP(CAlphaBlendingDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAlphaBlendingDlg message handlers

BOOL CAlphaBlendingDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAlphaBlendingDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

#define GetR(pixel)	(((pixel) & 0x00ff0000) >> 16)
#define GetG(pixel)	(((pixel) & 0x0000ff00) >>  8)
#define GetB(pixel)	 ((pixel) & 0x000000ff)

void CAlphaBlendingDlg::OnPaint() 
{
	CPaintDC dc(this);
	BITMAP bmpX,bmpY;
    
	CBitmap bmp1,bmp2;
	bmp2.LoadBitmap(IDB_BITMAP2);
	bmp1.LoadBitmap(IDB_BITMAP1);

	bmp1.GetBitmap(&bmpX);
	UINT* bmpBuffer=(UINT*)GlobalAlloc(GPTR,bmpX.bmWidthBytes*bmpX.bmHeight);
	bmp1.GetBitmapBits(bmpX.bmWidthBytes*bmpX.bmHeight,bmpBuffer);

	CDC memdc;
	memdc.CreateCompatibleDC(&dc);
	memdc.SelectObject(bmp1);
	dc.BitBlt(10,10,bmpX.bmWidthBytes,bmpX.bmHeight ,&memdc,0,0,SRCCOPY);

	bmp2.GetBitmap(&bmpY);
	UINT* bmpBuffer2=(UINT*)GlobalAlloc(GPTR,bmpY.bmWidthBytes*bmpY.bmHeight);
	bmp2.GetBitmapBits(bmpY.bmWidthBytes*bmpY.bmHeight,bmpBuffer2);

	memdc.SelectObject(bmp2);
	dc.BitBlt(200,10,bmpX.bmWidthBytes,bmpX.bmHeight ,&memdc,0,0,SRCCOPY);

	int nSize = bmpY.bmWidth*bmpY.bmHeight;
	double blend = 0.5;

	for (int i=0; i<nSize; i++)
	{
		int abR = (int) (GetR(bmpBuffer[i]) * blend + (1-blend) * GetR(bmpBuffer2[i]));
		int abG = (int) (GetG(bmpBuffer[i]) * blend + (1-blend) * GetG(bmpBuffer2[i]));
		int abB = (int) (GetB(bmpBuffer[i]) * blend + (1-blend) * GetB(bmpBuffer2[i]));

		bmpBuffer2[i] = RGB(abB, abG, abR);
	}

	bmp2.SetBitmapBits(bmpX.bmWidthBytes*bmpX.bmHeight, bmpBuffer2);

	memdc.SelectObject(bmp2);
	dc.BitBlt(390,10,bmpX.bmWidthBytes,bmpX.bmHeight ,&memdc,0,0,SRCCOPY);

	GlobalFree((HGLOBAL)bmpBuffer);
	GlobalFree((HGLOBAL)bmpBuffer2);
	memdc.DeleteDC();
		  
	if (IsIconic())
	{
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CAlphaBlendingDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
