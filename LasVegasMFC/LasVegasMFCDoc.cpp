
// LasVegasMFCDoc.cpp : implementation of the CLasVegasMFCDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "LasVegasMFC.h"
#endif

#include "LasVegasMFCDoc.h"
#include "Player.h"
#include "Casino.h"
#include "Bill.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CLasVegasMFCDoc

IMPLEMENT_DYNCREATE(CLasVegasMFCDoc, CDocument)

BEGIN_MESSAGE_MAP(CLasVegasMFCDoc, CDocument)
END_MESSAGE_MAP()


// CLasVegasMFCDoc construction/destruction

CLasVegasMFCDoc::CLasVegasMFCDoc()
{
	// TODO: add one-time construction code here

}

CLasVegasMFCDoc::~CLasVegasMFCDoc()
{
}

BOOL CLasVegasMFCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	srand((unsigned)time(NULL));

	player1 = new Player(1);
	player2 = new Player(2);
	player3 = new Player(3);
	player4 = new Player(4);
	player5 = new Player(5);

	casino1 = new Casino();
	casino2 = new Casino();
	casino3 = new Casino();
	casino4 = new Casino();
	casino5 = new Casino();
	casino6 = new Casino();

	billDeck = new BillDeck();

	player1->name = _T("Player1");
	player2->name = _T("Player2");
	player3->name = _T("Player3");
	player4->name = _T("Player4");
	player5->name = _T("Player5");

	round = 0;

	casino1->resetCasino();
	casino1->pDoc = this;
	casino2->resetCasino();
	casino2->pDoc = this;
	casino3->resetCasino();
	casino3->pDoc = this;
	casino4->resetCasino();
	casino4->pDoc = this;
	casino5->resetCasino();
	casino5->pDoc = this;
	casino6->resetCasino();
	casino6->pDoc = this;

	billDeck->resetDeck();
	
	while (TRUE) {
		casino1->addBill(billDeck->getBill());
		if (casino1->getTotalPrice() >= 50000) {
			break;
		}
	}
	while (TRUE) {
		casino2->addBill(billDeck->getBill());
		if (casino2->getTotalPrice() >= 50000) {
			break;
		}
	}
	while (TRUE) {
		casino3->addBill(billDeck->getBill());
		if (casino3->getTotalPrice() >= 50000) {
			break;
		}
	}
	while (TRUE) {
		casino4->addBill(billDeck->getBill());
		if (casino4->getTotalPrice() >= 50000) {
			break;
		}
	}
	while (TRUE) {
		casino5->addBill(billDeck->getBill());
		if (casino5->getTotalPrice() >= 50000) {
			break;
		}
	}
	while (TRUE) {
		casino6->addBill(billDeck->getBill());
		if (casino6->getTotalPrice() >= 50000) {
			break;
		}
	}

	continueCheck = FALSE;
	saveCheck = FALSE;
	// (SDI documents will reuse this document)

	return TRUE;
}




// CLasVegasMFCDoc serialization

void CLasVegasMFCDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar << (round);

		player1->Serialize(ar);
		player2->Serialize(ar);
		player3->Serialize(ar);
		player4->Serialize(ar);
		player5->Serialize(ar);

		casino1->Serialize(ar);
		casino2->Serialize(ar);
		casino3->Serialize(ar);
		casino4->Serialize(ar);
		casino5->Serialize(ar);
		casino6->Serialize(ar);

		billDeck->Serialize(ar);
	}
	else
	{
		// TODO: add loading code here
		ar >> round;

		player1->Serialize(ar);
		player2->Serialize(ar);
		player3->Serialize(ar);
		player4->Serialize(ar);
		player5->Serialize(ar);

		casino1->Serialize(ar);
		casino2->Serialize(ar);
		casino3->Serialize(ar);
		casino4->Serialize(ar);
		casino5->Serialize(ar);
		casino6->Serialize(ar);

		billDeck->Serialize(ar);
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CLasVegasMFCDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CLasVegasMFCDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CLasVegasMFCDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CLasVegasMFCDoc diagnostics

#ifdef _DEBUG
void CLasVegasMFCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLasVegasMFCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CLasVegasMFCDoc commands
