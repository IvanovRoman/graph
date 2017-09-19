#pragma once


// CBallBouncer

class CBallBouncer : public CStatic
{
	DECLARE_DYNAMIC(CBallBouncer)

public:
	CBallBouncer();
	virtual ~CBallBouncer();

private:
	BOOL m_bFlickerFree;
	UINT m_uiBallSpeed;

	POINT m_szNextPoint;
	POINT m_szNextPos;

	BOOL m_bStarted;

public:
	void Start();
	void Stop();

	void SetFlickerFree(BOOL bFlicker);
	void SetSpeed(UINT uiSpeed);

private:
	void GetRandomPoint(LPCRECT rcBounds, LPPOINT pt);
	void MakeSquareFromRect(LPRECT lpRect);
	void RadialGradientFill(CDC* pDC, LPRECT lpRectBounds, COLORREF cr1, COLORREF cr2);

protected:
	DECLARE_MESSAGE_MAP()
protected:
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	virtual void OnDraw(LPDRAWITEMSTRUCT lpDraw);
	virtual void PreSubclassWindow();
};


