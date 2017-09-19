// flicker_freeView.cpp : implementation of the CFlicker_freeView class
//

#include "stdafx.h"
#include "flicker_free.h"

#include "flicker_freeDoc.h"
#include "flicker_freeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define REFRESH_RATE 33
#define REFRESH_TIMER_ID 1

/////////////////////////////////////////////////////////////////////////////
// CFlicker_freeView

IMPLEMENT_DYNCREATE(CFlicker_freeView, CFormView)

BEGIN_MESSAGE_MAP(CFlicker_freeView, CFormView)
	//{{AFX_MSG_MAP(CFlicker_freeView)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BTN_START, OnBtnStart)
	ON_BN_CLICKED(IDC_BTN_END, OnBtnEnd)
	ON_WM_TIMER()
    ON_WM_ERASEBKGND()
    ON_WM_NCPAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlicker_freeView construction/destruction

CFlicker_freeView::CFlicker_freeView()
	: CFormView(CFlicker_freeView::IDD)
{
	//{{AFX_DATA_INIT(CFlicker_freeView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CFlicker_freeView::~CFlicker_freeView()
{
}

void CFlicker_freeView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFlicker_freeView)
	DDX_Control(pDX, IDC_DRAW_AREA, m_staticDrawArea);
	//}}AFX_DATA_MAP
}

BOOL CFlicker_freeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CFlicker_freeView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

    // my attributes initialization

    // get the drawing area
    m_staticDrawArea.GetWindowRect(&m_rectDraw);
    ScreenToClient(&m_rectDraw);
    m_rectDraw.left += 2;
    m_rectDraw.right -= 2;
    m_rectDraw.top += 8;
    m_rectDraw.bottom -= 2;

    m_nX = 0;
    m_nY = 0;

    m_bMyDraw = FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// CFlicker_freeView diagnostics

#ifdef _DEBUG
void CFlicker_freeView::AssertValid() const
{
	CFormView::AssertValid();
}

void CFlicker_freeView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CFlicker_freeDoc* CFlicker_freeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFlicker_freeDoc)));
	return (CFlicker_freeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFlicker_freeView message handlers

void CFlicker_freeView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
    int nRet;

    // create memory dc
    CDC dcMem;
    nRet = dcMem.CreateCompatibleDC(&dc);
    if ( nRet == 0 )
        TRACE("Cannot creat memory dc\n");

    // create a compatible bitmap and select it to memory DC
    // so that we can draw on dcMem
    CBitmap bmpMem;
    nRet = bmpMem.CreateCompatibleBitmap(&dc, 
        m_rectDraw.right - m_rectDraw.left,
        m_rectDraw.bottom - m_rectDraw.top);
    if ( nRet == 0 )
        TRACE("Cannot create compatible bitmap.\n");

    // select the bitmap to memory dc
    CBitmap *pOldBmp = (CBitmap *)(dcMem.SelectObject(&bmpMem));

    CPen *pOldPen, redPen;
    CBrush *pOldBrush, yellowBrush;

    // okay, let's draw on dcMem
    if ( m_nX == 0 && m_nY == 0 )
    {
        // when the timer is not running, just draw a plain background in the drawing area
        COLORREF bkgndColor = dc.GetBkColor();
        dcMem.FillSolidRect(0, 0, m_rectDraw.right - m_rectDraw.left, m_rectDraw.bottom - m_rectDraw.top,
            bkgndColor);
    }
    else
    {
        // first, draw a white background
        dcMem.FillSolidRect(0, 0, m_rectDraw.right - m_rectDraw.left, m_rectDraw.bottom - m_rectDraw.top,
                            RGB(255,255,255));

        // create a red pen and a yellow brush
        nRet = redPen.CreatePen(PS_SOLID, 1, RGB(255,0,0));
        if ( nRet == 0 )
            TRACE("Cannot create redPen\n");

        nRet = yellowBrush.CreateSolidBrush(RGB(255,255,0));
        if ( nRet == 0 )
            TRACE("Cannot create yellowBrush\n");

        // select to DC
        pOldPen = dcMem.SelectObject(&redPen);
        pOldBrush = dcMem.SelectObject(&yellowBrush);

        // draw the red cirle
        dcMem.Ellipse(m_nX - 10, m_nY - 10, m_nX + 10, m_nY + 10);
    }

    // done with our sketch, display it on real dc
    CPoint ptOffset; // scroll bar support
    
    ptOffset = GetScrollPosition();
    RECT rect;
    rect = m_rectDraw;
    rect.left -= ptOffset.x;
    rect.right -= ptOffset.x;
    rect.top -= ptOffset.y;
    rect.bottom -= ptOffset.y;
    dc.BitBlt(rect.left,
              rect.top,
              m_rectDraw.right - m_rectDraw.left,
              m_rectDraw.bottom - m_rectDraw.top,
              &dcMem,
              0,
              0, 
              SRCCOPY);

    if ( m_nX || m_nY )
    {
        // restore dc
        dcMem.SelectObject(pOldPen);
        dcMem.SelectObject(pOldBrush);

        // release resources
        redPen.DeleteObject();
        yellowBrush.DeleteObject();
    }

    dcMem.SelectObject(pOldBmp);
    bmpMem.DeleteObject();

    dcMem.DeleteDC();

    m_bMyDraw = FALSE;

	// Do not call CFormView::OnPaint() for painting messages
} // end of OnPaint

BOOL CFlicker_freeView::OnEraseBkgnd(CDC *pDC)
{
    if ( m_bMyDraw )
        return TRUE;
    else
        return CFormView::OnEraseBkgnd(pDC);
} // end of OnEraseBkgnd


void CFlicker_freeView::OnBtnStart() 
{
    //random seed
    srand( (unsigned)time( NULL ) );

    m_nX = rand();
    m_nY = rand();
    // normalize them to be inside the draw area
    m_nX = (int)( (m_nX + 1) * 1.0 / RAND_MAX * (m_rectDraw.right - m_rectDraw.left));
    m_nY = (int)( (m_nY + 1) * 1.0 / RAND_MAX * (m_rectDraw.bottom - m_rectDraw.top));

	SetTimer(REFRESH_TIMER_ID, REFRESH_RATE, NULL);
} // end of OnBtnStart

void CFlicker_freeView::OnBtnEnd() 
{
	// TODO: Add your control notification handler code here
	KillTimer(REFRESH_TIMER_ID);

    m_nX = 0;
    m_nY = 0;

    m_bMyDraw = FALSE;

    
    CPoint ptOffset; // scroll bar support
    
    ptOffset = GetScrollPosition();
    RECT rect;
    rect = m_rectDraw;
    rect.left -= ptOffset.x;
    rect.right -= ptOffset.x;
    rect.top -= ptOffset.y;
    rect.bottom -= ptOffset.y;

    InvalidateRect(&rect);
} // end of OnBtnEnd

void CFlicker_freeView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if ( nIDEvent == REFRESH_TIMER_ID )
    {
        static int nDeltaX = 10, nDeltaY = 10;
        int width = m_rectDraw.right - m_rectDraw.left;
        int height = m_rectDraw.bottom - m_rectDraw.top;
        // update m_nX and m_nY
        m_nX += nDeltaX;
        if ( m_nX < 10 )
        {
            m_nX = 11;
            nDeltaX = 10;
        }
        else if ( m_nX > (width - 10))
        {
            m_nX = width-11;
            nDeltaX = -10;
        }
        m_nY += nDeltaY;
        if ( m_nY < 10 )
        {
            m_nY = 11;
            nDeltaY = 10;
        }
        else if ( m_nY > (height - 10))
        {
            m_nY = height-11;
            nDeltaY = -10;
        }
        // update the display
        m_bMyDraw = TRUE;
        CPoint ptOffset; // scroll bar support
        ptOffset = GetScrollPosition();
        RECT rect;
        rect = m_rectDraw;
        rect.left -= ptOffset.x;
        rect.right -= ptOffset.x;
        rect.top -= ptOffset.y;
        rect.bottom -= ptOffset.y;
        InvalidateRect(&rect);
    }
	CFormView::OnTimer(nIDEvent);
}

void CFlicker_freeView::OnNcPaint()
{
    m_bMyDraw = FALSE; // you can comment out this line of code
                       // and see what will happen, after you press the "Start" button
                       //     then resize the window. have fun!
    CWnd::OnNcPaint();
}
