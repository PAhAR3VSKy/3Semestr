#include "stdafx.h" // в более новых версиях Visual Studio эта строчка не нужна
#include "SameGame.h"

#include "SameGameDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CSameGameDoc
IMPLEMENT_DYNCREATE(CSameGameDoc, CDocument)
BEGIN_MESSAGE_MAP(CSameGameDoc, CDocument)
END_MESSAGE_MAP()

// Создание CSameGameDoc
CSameGameDoc::CSameGameDoc()
{
}

// Уничтожение CSameGameDoc
CSameGameDoc::~CSameGameDoc()
{
}

BOOL CSameGameDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// Установка (или сброс) параметров доски
	m_board.SetupBoard();

	return TRUE;
}