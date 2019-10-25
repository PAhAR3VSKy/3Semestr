#include "stdafx.h"
#include "SameGame.h"

#include "SameGameDoc.h"
#include "SameGameView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSameGameView
IMPLEMENT_DYNCREATE(CSameGameView, CView)
BEGIN_MESSAGE_MAP(CSameGameView, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// Конструктор CSameGameView 
CSameGameView::CSameGameView()
{
}

// Деструктор CSameGameView 
CSameGameView::~CSameGameView()
{
}

BOOL CSameGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

// Отрисовка игры
void CSameGameView::OnDraw(CDC* pDC) // MFC закомментирует имя аргумента по умолчанию. Раскомментируйте это
{
	// В начале создаём указатель на Document
	CSameGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;


	// Сохраняем текущее состояние контекста устройства
	int nDCSave = pDC->SaveDC();

	// Получаем размеры клиентской области
	CRect rcClient;
	GetClientRect(&rcClient);
	COLORREF clr = pDoc->GetBoardSpace(-1, -1);

	// Сначала отрисовываем фон
	pDC->FillSolidRect(&rcClient, clr);

	// Создаём кисть для рисования
	CBrush br;
	br.CreateStockObject(HOLLOW_BRUSH);
	CBrush* pbrOld = pDC->SelectObject(&br);

	// Рисуем блоки
	for (int row = 0; row < pDoc->GetRows(); row++)
	{
		for (int col = 0; col < pDoc->GetColumns(); col++)
		{

			clr = pDoc->GetBoardSpace(row, col);

			// Вычисляем размер и позицию игрового пространства
			CRect rcBlock;
			rcBlock.top = row * pDoc->GetHeight();
			rcBlock.left = col * pDoc->GetWidth();
			rcBlock.right = rcBlock.left + pDoc->GetWidth();
			rcBlock.bottom = rcBlock.top + pDoc->GetHeight();

			// Заполняем блок соответствующим цветом
			pDC->FillSolidRect(&rcBlock, clr);

			// Рисуем контур
			pDC->Rectangle(&rcBlock);
		}
	}
	// Восстанавливаем контекст устройства
	pDC->RestoreDC(nDCSave);
	br.DeleteObject();
}

// Диагностика CSameGameView
#ifdef _DEBUG
void CSameGameView::AssertValid() const
{
	CView::AssertValid();
}

void CSameGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

// Версия non-debug
CSameGameDoc* CSameGameView::GetDocument() const
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSameGameDoc)));
	return (CSameGameDoc*)m_pDocument;
}
#endif //_DEBUG

void CSameGameView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// Изменяем размеры окна
	ResizeWindow();

}


void CSameGameView::ResizeWindow()
{
	// Создаём указатель на Document
	CSameGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// Получаем размеры клиентской области
	CRect rcClient, rcWindow;
	GetClientRect(&rcClient);
	GetParentFrame()->GetWindowRect(&rcWindow);
	int nWidthDiff = rcWindow.Width() - rcClient.Width();
	int nHeightDiff = rcWindow.Height() - rcClient.Height();

	// Изменяем размеры окна на основе размеров нашей доски
	rcWindow.right = rcWindow.left +
		pDoc->GetWidth() * pDoc->GetColumns() + nWidthDiff;
	rcWindow.bottom = rcWindow.top +
		pDoc->GetHeight() * pDoc->GetRows() + nHeightDiff;

	// Функция MoveWindow() изменяет размер окна фрейма
	GetParentFrame()->MoveWindow(&rcWindow);
}

void CSameGameView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// Вначале создаём указатель на Document
	CSameGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// Получаем индекс строки и столбца элемента, по которому был осуществлён клик мышкой
	int row = point.y / pDoc->GetHeight();
	int col = point.x / pDoc->GetWidth();

	// Удаляем блоки из Document
	int count = pDoc->DeleteBlocks(row, col);

	// Проверяем, было ли удаление блоков
	if (count > 0)
	{
		// Перерисовываем View
		Invalidate();
		UpdateWindow();

		// Проверяем, закончилась ли игра
		if (pDoc->IsGameOver())
		{
			// Получаем количество оставшихся блоков
			int remaining = pDoc->GetRemainingCount();
			CString message;
			message.Format(_T("No more moves left\nBlocks remaining: %d"),
				remaining);

			// Отображаем пользователю результат игры
			MessageBox(message, _T("Game Over"), MB_OK | MB_ICONINFORMATION);
		}
	}
	// OnLButtonDown по умолчанию
	CView::OnLButtonDown(nFlags, point);
}
