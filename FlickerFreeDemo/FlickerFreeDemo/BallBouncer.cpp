// BallBouncer.cpp : implementation file
//

#include "stdafx.h"
#include "FlickerFreeDemo.h"
#include "BallBouncer.h"
#include "BufferDC.h"


DWORD dwPrimeNumbers[] =
{
	984351257,       984351281,       984351283,       984351287,      
	984351317,       984351331,       984351371,       984351419,      
	984351451,       984351461,       984351497,       984351499,      
	3298751279,      3298751293,      3298751297,      3298751347 ,     
	3298751381,      3298751387,      3298751399,      3298751437,      
	3298751453,      3298751461,      3298751497,      3298751507,      
	3298751527,      3298751531,      3298751551,      3298751591,      
	3298751639,      3298751647,      3298751657,      3298751699,
	984351839,       984351847,       984351877,       984351883,      
	984351889,       984351923,       984351931,       984351997,      
	984352013,       984352027,       984352043  
};


// CBallBouncer

IMPLEMENT_DYNAMIC(CBallBouncer, CStatic)

CBallBouncer::CBallBouncer()
{
	m_bFlickerFree = FALSE;
	m_uiBallSpeed  = 1;

	m_szNextPoint.x = m_szNextPoint.y = 0;
	m_szNextPos.x   = m_szNextPos.y   = 0;

	m_bStarted = FALSE;
}

CBallBouncer::~CBallBouncer()
{
}


BEGIN_MESSAGE_MAP(CBallBouncer, CStatic)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


void CBallBouncer::SetFlickerFree( BOOL bFlicker )
{
	m_bFlickerFree = bFlicker;
}

void CBallBouncer::SetSpeed( UINT uiSpeed )
{
	m_uiBallSpeed = uiSpeed;

	if (m_bStarted)
	{
		KillTimer(1001);
		SetTimer(1001,150 / (m_uiBallSpeed < 10 ? m_uiBallSpeed : 10), NULL);
	}
}

void CBallBouncer::Start()
{
	m_bStarted = TRUE;
	SetTimer(1001,150 / (m_uiBallSpeed < 10 ? m_uiBallSpeed : 10), NULL);
}

void CBallBouncer::Stop()
{
	KillTimer(1001);
	m_bStarted = FALSE;

	Invalidate();
}

// CBallBouncer message handlers

afx_msg void CBallBouncer::OnPaint()
{
	if (m_bFlickerFree)
	{
		CBufferDC dc(this);

		dc.SetMapMode(MM_TEXT);
		dc.SetBkMode(TRANSPARENT);
		dc.SetBkColor(GetSysColor(COLOR_BTNFACE));

		RECT rc = { 0 };
		GetClientRect(&rc);

		CBrush br;
		br.CreateSysColorBrush(COLOR_BTNFACE);
		dc.FillRect(&rc, &br);

		if (m_bStarted)
		{
			RECT gRc = rc;
			int w = gRc.right - gRc.left;
			w = w - ((w - m_szNextPos.x) * 2);

			int h = gRc.bottom - gRc.top;
			h = h - ((h - m_szNextPos.y) * 2);

			if (m_szNextPos.x > (gRc.right - gRc.left) / 2)
			{
				gRc.left += w;
			}
			else if (m_szNextPos.x < (gRc.right - gRc.left) / 2)
			{
				gRc.right += w;
			}

			if (m_szNextPos.y > (gRc.bottom - gRc.top) / 2)
			{
				gRc.top += h;
			}
			else if (m_szNextPos.y < (gRc.bottom - gRc.top) / 2)
			{
				gRc.bottom += h;
			}

			if (gRc.left < 1)
			{
				gRc.left = 1;
			}
			if (gRc.top < 1)
			{
				gRc.top = 1;
			}
			if (gRc.right < 1)
			{
				gRc.right = 1;
			}
			if (gRc.bottom < 1)
			{
				gRc.bottom = 1;
			}

			CPen pen;
			pen.CreatePen(PS_DOT,1,RGB(0x66,0x66,0xaa));
			dc.SelectObject(pen);

			RECT rc2 = rc;
			MakeSquareFromRect(&gRc);
			RadialGradientFill(&dc, &gRc, RGB(40,40,40), ::GetSysColor(COLOR_BTNFACE));

			CBrush ball;
			ball.CreateSolidBrush(RGB(0,0,255));
			dc.SelectObject(&ball);

			RECT rcB = { 0, 0, 6, 6 };
			RECT rcP = { 0, 0, 16, 16 };

			if (m_szNextPos.x - 3 > 0 && m_szNextPos.x + 3 <= rc.right)
			{
				rcB.left  = m_szNextPos.x - 3;
				rcB.right = rcB.left + 6;
			}
			else if (m_szNextPos.x + 3 > rc.right)
			{
				rcB.left  = rc.right - 6;
				rcB.right = rc.right;
			}

			if (m_szNextPos.y - 3 > 0 && m_szNextPos.y + 3 <= rc.bottom)
			{
				rcB.top    = m_szNextPos.y - 3;
				rcB.bottom = rcB.top + 6;
			}
			else if (m_szNextPos.y + 3 > rc.bottom)
			{
				rcB.top    = rc.bottom - 6;
				rcB.bottom = rc.bottom;
			}

			if (m_szNextPoint.x - 8 > 0 && m_szNextPoint.x + 8 <= rc.right)
			{
				rcP.left  = m_szNextPoint.x - 8;
				rcP.right = rcP.left + 16;
			}
			else if (m_szNextPoint.x + 8 > rc.right)
			{
				rcP.left  = rc.right - 16;
				rcP.right = rc.right;
			}

			if (m_szNextPoint.y - 8 > 0 && m_szNextPoint.y + 8 <= rc.bottom)
			{
				rcP.top    = m_szNextPoint.y - 8;
				rcP.bottom = rcP.top + 16;
			}
			else if (m_szNextPoint.y + 8 > rc.bottom)
			{
				rcP.top    = rc.bottom - 16;
				rcP.bottom = rc.bottom;
			}

			dc.Ellipse(&rcB);

			CPen pen2;
			pen2.CreatePen(PS_SOLID,2,RGB(255,0,0));
			dc.SelectObject(pen2);

			CBrush cbPt;
			cbPt.CreateSolidBrush(RGB(255,0,0));
			dc.SelectObject(cbPt);

			dc.FillRect(&rcP,&cbPt);

			dc.SelectObject(br);

			rcP.left   += 3;
			rcP.right  -= 3;
			rcP.top    += 3;
			rcP.bottom -= 3;

			dc.FillRect(&rcP,&br);

			dc.MoveTo(rcP.left + 5, rcP.top);
			dc.LineTo(rcP.left + 5, rcP.bottom);
			dc.MoveTo(rcP.left, rcP.top + 5);
			dc.LineTo(rcP.right, rcP.top + 5);
		}
		else
		{
			CString str = _T("Click start to start the bouncer.");
			CSize sz = dc.GetTextExtent(str);

			dc.TextOut((rc.right - sz.cx) / 2, (rc.bottom - sz.cy) / 2, str);
		}
	}
	else
	{
		CPaintDC dc(this);

		dc.SetMapMode(MM_TEXT);
		dc.SetBkMode(TRANSPARENT);
		dc.SetBkColor(GetSysColor(COLOR_BTNFACE));

		RECT rc = { 0 };
		GetClientRect(&rc);

		CBrush br;
		br.CreateSysColorBrush(COLOR_BTNFACE);
		dc.FillRect(&rc, &br);

		if (m_bStarted)
		{
			RECT gRc = rc;
			int w = gRc.right - gRc.left;
			w = w - ((w - m_szNextPos.x) * 2);

			int h = gRc.bottom - gRc.top;
			h = h - ((h - m_szNextPos.y) * 2);

			if (m_szNextPos.x > (gRc.right - gRc.left) / 2)
			{
				gRc.left += w;
			}
			else if (m_szNextPos.x < (gRc.right - gRc.left) / 2)
			{
				gRc.right += w;
			}

			if (m_szNextPos.y > (gRc.bottom - gRc.top) / 2)
			{
				gRc.top += h;
			}
			else if (m_szNextPos.y < (gRc.bottom - gRc.top) / 2)
			{
				gRc.bottom += h;
			}

			if (gRc.left < 1)
			{
				gRc.left = 1;
			}
			if (gRc.top < 1)
			{
				gRc.top = 1;
			}
			if (gRc.right < 1)
			{
				gRc.right = 1;
			}
			if (gRc.bottom < 1)
			{
				gRc.bottom = 1;
			}

			CPen pen;
			pen.CreatePen(PS_DOT,1,RGB(0x66,0x66,0xaa));
			dc.SelectObject(pen);

			RECT rc2 = rc;
			MakeSquareFromRect(&gRc);
			RadialGradientFill(&dc, &gRc, RGB(40,40,40), ::GetSysColor(COLOR_BTNFACE));

			CBrush ball;
			ball.CreateSolidBrush(RGB(0,0,255));
			dc.SelectObject(&ball);

			RECT rcB = { 0, 0, 6, 6 };
			RECT rcP = { 0, 0, 16, 16 };

			if (m_szNextPos.x - 3 > 0 && m_szNextPos.x + 3 <= rc.right)
			{
				rcB.left  = m_szNextPos.x - 3;
				rcB.right = rcB.left + 6;
			}
			else if (m_szNextPos.x + 3 > rc.right)
			{
				rcB.left  = rc.right - 6;
				rcB.right = rc.right;
			}

			if (m_szNextPos.y - 3 > 0 && m_szNextPos.y + 3 <= rc.bottom)
			{
				rcB.top    = m_szNextPos.y - 3;
				rcB.bottom = rcB.top + 6;
			}
			else if (m_szNextPos.y + 3 > rc.bottom)
			{
				rcB.top    = rc.bottom - 6;
				rcB.bottom = rc.bottom;
			}

			if (m_szNextPoint.x - 8 > 0 && m_szNextPoint.x + 8 <= rc.right)
			{
				rcP.left  = m_szNextPoint.x - 8;
				rcP.right = rcP.left + 16;
			}
			else if (m_szNextPoint.x + 8 > rc.right)
			{
				rcP.left  = rc.right - 16;
				rcP.right = rc.right;
			}

			if (m_szNextPoint.y - 8 > 0 && m_szNextPoint.y + 8 <= rc.bottom)
			{
				rcP.top    = m_szNextPoint.y - 8;
				rcP.bottom = rcP.top + 16;
			}
			else if (m_szNextPoint.y + 8 > rc.bottom)
			{
				rcP.top    = rc.bottom - 16;
				rcP.bottom = rc.bottom;
			}

			dc.Ellipse(&rcB);

			CPen pen2;
			pen2.CreatePen(PS_SOLID,2,RGB(255,0,0));
			dc.SelectObject(pen2);

			CBrush cbPt;
			cbPt.CreateSolidBrush(RGB(255,0,0));
			dc.SelectObject(cbPt);

			dc.FillRect(&rcP,&cbPt);

			dc.SelectObject(br);

			rcP.left   += 3;
			rcP.right  -= 3;
			rcP.top    += 3;
			rcP.bottom -= 3;

			dc.FillRect(&rcP,&br);

			dc.MoveTo(rcP.left + 5, rcP.top);
			dc.LineTo(rcP.left + 5, rcP.bottom);
			dc.MoveTo(rcP.left, rcP.top + 5);
			dc.LineTo(rcP.right, rcP.top + 5);
		}
		else
		{
			CString str = _T("Click start to start the bouncer.");
			CSize sz = dc.GetTextExtent(str);

			dc.TextOut((rc.right - sz.cx) / 2, (rc.bottom - sz.cy) / 2, str);
		}
	}
}

afx_msg void CBallBouncer::OnTimer( UINT_PTR nIDEvent )
{
	if (nIDEvent == 1001)
	{
		if (m_szNextPos.x == m_szNextPoint.x &&
			m_szNextPos.y == m_szNextPoint.y)
		{
			RECT rc;
			GetClientRect(&rc);
			GetRandomPoint(&rc, &m_szNextPoint);
		}

		int x = m_szNextPoint.x;
		int y = m_szNextPoint.y;

		if (x > m_szNextPos.x)
		{
			m_szNextPos.x++;
		}
		else if (x < m_szNextPos.x)
		{
			m_szNextPos.x--;
		}

		if (y > m_szNextPos.y)
		{
			m_szNextPos.y++;
		}
		else if (y < m_szNextPos.y)
		{
			m_szNextPos.y--;
		}

		Invalidate();
	}
}

afx_msg void CBallBouncer::OnLButtonDown( UINT nFlags, CPoint point )
{
	m_szNextPoint.x = point.x;
	m_szNextPoint.y = point.y;

	Invalidate();
}

void CBallBouncer::OnDraw( LPDRAWITEMSTRUCT lpDraw )
{

}

void CBallBouncer::PreSubclassWindow()
{
	ModifyStyle(0, BS_OWNERDRAW | SS_NOTIFY);
}

void CBallBouncer::GetRandomPoint( LPCRECT rcBounds, LPPOINT pt )
{
	UINT arrLen = 43;

	DWORD ticks = GetTickCount();
	DWORD index = ticks % arrLen;

	DWORD prime1 = dwPrimeNumbers[index];
	DWORD prime2 = dwPrimeNumbers[prime1 % arrLen];

	DWORD prime3 = dwPrimeNumbers[prime2 % arrLen];
	DWORD prime4 = dwPrimeNumbers[prime3 % arrLen];

	prime4 *= prime1;
	prime4 += (prime1 * prime2 / 47);

	pt->x = prime3 % (rcBounds->right + 1);
	pt->y = prime4 % (rcBounds->bottom + 1);
}

void CBallBouncer::MakeSquareFromRect( LPRECT lpRect )
{
	int w = lpRect->right  - lpRect->left;
	int h = lpRect->bottom - lpRect->top;

	if (w < h)
	{
		lpRect->top += ((h - w) / 2);
		lpRect->bottom -= ((h - w) / 2);
	}
	else if (w > h)
	{
		lpRect->left += ((w - h) / 2);
		lpRect->right -= ((w - h) / 2);
	}
}

void CBallBouncer::RadialGradientFill( CDC* pDC, LPRECT lpRectBounds, COLORREF cr1, COLORREF cr2 )
{
	long r, g, b;

	r = ((long)((long)GetRValue(cr1)) - ((long)GetRValue(cr2)));
	g = ((long)((long)GetGValue(cr1)) - ((long)GetGValue(cr2)));
	b = ((long)((long)GetBValue(cr1)) - ((long)GetBValue(cr2)));

	int max = (r > 0 ? r : -r) < (g > 0 ? g : -g) && r != 0 ? r : g;
	max = (max > 0 ? max : -max) < (b > 0 ? b : -b) && max != 0 ? max : b;

	if (max < 0)
	{
		max = -max;
	}

	CPen pen, *oldPen;
	pen.CreatePen(PS_SOLID, 2, cr1);
	oldPen = pDC->SelectObject(&pen);

	CBrush cb, *oldCb;
	cb.CreateSolidBrush(cr2);
	oldCb = pDC->SelectObject(&cb);

	if (max == 0)
	{
		pDC->Ellipse(lpRectBounds);

		pDC->SelectObject(oldPen);
		pDC->SelectObject(oldCb);
		return;
	}

	BYTE r1 = GetRValue(cr1);
	BYTE g1 = GetGValue(cr1);
	BYTE b1 = GetBValue(cr1);

	int w = (lpRectBounds->right  - lpRectBounds->left) / 2;
	int h = (lpRectBounds->bottom - lpRectBounds->top)  / 2;

	int wr = w % max;
	int hr = h % max;
	int cr = 0;

	if (wr > 0 || hr > 0)
	{
		cr = wr > hr ? wr : hr;
	}

	w = w / max;
	h = w / max;

	int c = w > h ? w : h;

	for (int i = 0; i < c; i++)
	{
		pDC->Ellipse(lpRectBounds);

		lpRectBounds->left   += 1;
		lpRectBounds->right  -= 1;
		lpRectBounds->top    += 1;
		lpRectBounds->bottom -= 1;
	}

	for (int i = 0; i < max; i++)
	{
		if (r < 0 && r1 < 255)
		{
			r1++;
		}
		else if (r > 0 && r1 > 0)
		{
			r1--;
		}

		if (g < 0 && g1 < 255)
		{
			g1++;
		}
		else if (g > 0 && g1 > 0)
		{
			g1--;
		}

		if (b < 0 && b1 < 255)
		{
			b1++;
		}
		else if (b > 0 && b1 > 0)
		{
			b1--;
		}

		pDC->SelectObject(oldPen);
		pen.DeleteObject();
		pen.CreatePen(PS_SOLID, 2, RGB(r1,g1,b1));

		oldPen = pDC->SelectObject(&pen);

		for (int l = 0; l < c; l++)
		{
			pDC->Ellipse(lpRectBounds);

			lpRectBounds->left   += 1;
			lpRectBounds->right  -= 1;
			lpRectBounds->top    += 1;
			lpRectBounds->bottom -= 1;
		}

		if (cr > 0)
		{
			pDC->Ellipse(lpRectBounds);

			lpRectBounds->left   += 1;
			lpRectBounds->right  -= 1;
			lpRectBounds->top    += 1;
			lpRectBounds->bottom -= 1;

			cr--;
		}
	}

	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldCb);
}