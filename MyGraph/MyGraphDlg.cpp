// MyGraphDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyGraph.h"
#include "MyGraphDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyGraphDlg dialog

CMyGraphDlg::CMyGraphDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyGraphDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyGraphDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyGraphDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyGraphDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyGraphDlg, CDialog)
	//{{AFX_MSG_MAP(CMyGraphDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyGraphDlg message handlers
BOOL refresh = true;

BOOL CMyGraphDlg::OnInitDialog()
{
	SetTimer(1, 10, NULL);
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyGraphDlg::Drawrect(CDC *pDC, int x)
{
	
	int width = 2000/10;
	int height = 1000/10;
	int i = 0;
	CDC* dcMem = new CDC;
	dcMem->CreateCompatibleDC(pDC);

	pbmp->CreateCompatibleBitmap(pDC,700,700);

	CBitmap* oldBmp=dcMem->SelectObject(pbmp);
	//Не совсем понятна эта функция, но без нее все рисуется на черном фоне.
	//из msdn понял, что она заливает наш прямоугольник выбранной кистью
	dcMem->PatBlt(0,0,700,700,PATCOPY);
	
	//Рисуем сложные объекты, например, 10 прямоугольников :)
	for (i = 0; i < 10; i++)
		dcMem->FillSolidRect(CRect(	i * width, i * height,
									i * width + width, 
									i * height + height), 
									RGB(120,150,70));
	
	dcMem->Rectangle(200, 200, 300, 300);
	memDC=dcMem;
	//delete memDC; вызываем в деструкторе класса CDemoZoomView

	refresh=false;
}

int x = 0;
void CMyGraphDlg::Redraw()
{
	POINT pt;
	GetCursorPos(&pt);
	x = pt.x;
	CClientDC dc(this);

	Drawrect(&dc, x);
}

void CMyGraphDlg::OnDraw(CDC* dc)
{
	CRect bounds;
	CRect lBounds;
	GetClientRect(&bounds);
	lBounds = bounds;

		CMemDC pDC(dc);
		Draw(pDC, bounds);
		pDC->SetTextColor(RGB(255, 255, 255));
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextAlign(TA_LEFT | TA_TOP);
	//	pDC->TextOut(0, 0, MapMode(pDC->GetMapMode()));

		pDC->Rectangle(200, 200, 300, 300);
}

BOOL CMyGraphDlg::Draw(CDC* pDC, const CRect& bounds) 
{
	CPoint m_loc;
	GetCursorPos(&m_loc);

	CPoint lpPoint = m_loc;

	pDC->DPtoLP(&lpPoint);
	CPen* pOldPen = pDC->SelectObject(m_pen);
	pDC->MoveTo(lpPoint);
	lpPoint = CPoint(m_loc.x+m_loc.x, m_loc.y+m_loc.y);
	pDC->DPtoLP(&lpPoint);
	pDC->LineTo(lpPoint);
	pDC->Rectangle(200, 200, 300, 300);
	pDC->SelectObject(pOldPen);
	return TRUE;
}

void CMyGraphDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyGraphDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyGraphDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnTimer(nIDEvent);
}
