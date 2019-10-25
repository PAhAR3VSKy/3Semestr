
// SameGameView.h: интерфейс класса CSameGameView
//

#pragma once


class CSameGameView : public CView
{
protected:
	CSameGameView();
	DECLARE_DYNCREATE(CSameGameView)

	// Атрибуты
public:
	CSameGameDoc* GetDocument() const;

	// Переопределения
public:
	virtual void OnDraw(CDC* pDC);  // переопределяем, чтобы нарисовать этот View
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

	// Реализация
public:

	void ResizeWindow();

	virtual ~CSameGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Генерируем функцию сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG // версия debug в SameGameView.cpp
inline CSameGameDoc* CSameGameView::GetDocument() const
{
	return reinterpret_cast<CSameGameDoc*>(m_pDocument);
}
#endif

