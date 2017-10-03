// rotateDrawDlg.cpp : implementation file
//

#include "stdafx.h"
#include "rotateDraw.h"
#include "rotateDrawDlg.h"

#include <math.h>

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
// CRotateDrawDlg dialog

CRotateDrawDlg::CRotateDrawDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRotateDrawDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRotateDrawDlg)
	m_iShapeType = -1;
	m_iAngle = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRotateDrawDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRotateDrawDlg)
	DDX_Control(pDX, IDC_STATIC_DRAW, m_ctlDrawArea);
	DDX_Radio(pDX, IDC_SHAPE_RECTANGLE, m_iShapeType);
	DDX_Text(pDX, IDC_ANGLE, m_iAngle);
	DDV_MinMaxInt(pDX, m_iAngle, 0, 360);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRotateDrawDlg, CDialog)
	//{{AFX_MSG_MAP(CRotateDrawDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_UPDATE, OnBtnUpdate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRotateDrawDlg message handlers

BOOL CRotateDrawDlg::OnInitDialog()
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

    // init control variables
    m_iShapeType = 0;
    m_iAngle = 0;

    UpdateData(FALSE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRotateDrawDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRotateDrawDlg::OnPaint() 
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
        //
        // draw the client based on user selection
        //
        UpdateData(TRUE); // get current dialog item's value

        CPaintDC dc(this); // device context for painting
        HDC hDc = dc.GetSafeHdc();

        // create a black brush for frame border drawing
        HBRUSH blackBrush;
        blackBrush = CreateSolidBrush(RGB(0, 0, 0));

        CRect rect;
        m_ctlDrawArea.GetClientRect(&rect);

        // make a frame which start at the (7, 7)
        rect.top += 7;
        rect.left += 7;

        // draw the frame:
        FrameRect(hDc, 
                  &rect, 
                  blackBrush);

        POINT centerPt;
        centerPt.x = (rect.right - rect.left)/2 ;
        centerPt.y = (rect.bottom - rect.top)/2 ;

        // draw the coordinate system
        dc.MoveTo(centerPt.x, rect.top + 7);
        dc.LineTo(centerPt.x, rect.bottom - 7);

        dc.MoveTo(rect.left + 7, centerPt.y);
        dc.LineTo(rect.right - 7, centerPt.y);

        //
        // rotate the DC
        //
        int nGraphicsMode = SetGraphicsMode(hDc, GM_ADVANCED);
        XFORM xform;
        if ( m_iAngle != 0 )
        {
            double fangle = (double)m_iAngle / 180. * 3.1415926;
            xform.eM11 = (float)cos(fangle);
            xform.eM12 = (float)sin(fangle);
            xform.eM21 = (float)-sin(fangle);
            xform.eM22 = (float)cos(fangle);
            xform.eDx = (float)(centerPt.x - cos(fangle)*centerPt.x + sin(fangle)*centerPt.y);
            xform.eDy = (float)(centerPt.y - cos(fangle)*centerPt.y - sin(fangle)*centerPt.x);

            SetWorldTransform(hDc, &xform);
        }

        // draw a rectangle or ellipse
        if ( m_iShapeType == 0 )
        {
            Rectangle(hDc,
                      centerPt.x - 20,
                      centerPt.y - 30, 
                      centerPt.x + 20,
                      centerPt.y + 30 );
        }
        else
        {
            Ellipse(hDc,
                      centerPt.x - 20,
                      centerPt.y - 30, 
                      centerPt.x + 20,
                      centerPt.y + 30 );
        }

        // draw the rotated coordinate
        dc.MoveTo(centerPt.x, rect.top + 7);
        dc.LineTo(centerPt.x, rect.bottom - 7);

        dc.MoveTo(rect.left + 7, centerPt.y);
        dc.LineTo(rect.right - 7, centerPt.y);


		CDialog::OnPaint();

        // restore the DC
        if ( m_iAngle != 0 )
        {
            xform.eM11 = (float)1.0; 
            xform.eM12 = (float)0;
            xform.eM21 = (float)0;
            xform.eM22 = (float)1.0;
            xform.eDx = (float)0;
            xform.eDy = (float)0;
            
            SetWorldTransform(hDc, &xform);
        }
        SetGraphicsMode(hDc, nGraphicsMode);
        // clean up resources
        DeleteObject(blackBrush);
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRotateDrawDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRotateDrawDlg::OnOK() 
{
	// TODO: Add extra validation here
	if ( GetFocus() != GetDlgItem(IDOK) )
        return;
	CDialog::OnOK();
}

void CRotateDrawDlg::OnBtnUpdate() 
{
	// TODO: Add your control notification handler code here
	// redraw
    InvalidateRect(NULL);
}
