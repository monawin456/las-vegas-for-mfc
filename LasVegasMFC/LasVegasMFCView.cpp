
// LasVegasMFCView.cpp : implementation of the CLasVegasMFCView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "LasVegasMFC.h"
#endif

#include "LasVegasMFCDoc.h"
#include "LasVegasMFCView.h"
#include "Player.h"
#include "Casino.h"
#include "Bill.h"
#include "Dice.h"
#include "DiceDlg.h"
#include "MenuDlg.h"
#include "ResultDlg.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLasVegasMFCView

IMPLEMENT_DYNCREATE(CLasVegasMFCView, CFormView)

BEGIN_MESSAGE_MAP(CLasVegasMFCView, CFormView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_VIEW_MENU, &CLasVegasMFCView::OnViewMenu)
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()

// CLasVegasMFCView construction/destruction

CLasVegasMFCView::CLasVegasMFCView()
	: CFormView(IDD_LASVEGASMFC_FORM)
{
	// TODO: add construction code here

}

CLasVegasMFCView::~CLasVegasMFCView()
{
}

void CLasVegasMFCView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CLasVegasMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CLasVegasMFCView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	//ResizeParentToFit();

	rollingButtonCheck = FALSE;

	for (int i = 0; i < 6; i++) {
		pCasino[i].x = 0;
		pCasino[i].y = 0;
	}

	GetClientRect(&clientRect);

	CMenuDlg dlg;
	dlg.pDoc = GetDocument();
	dlg.DoModal();

	GetDocument()->continueCheck = TRUE;
	GetDocument()->saveCheck = TRUE;

	for (int i = 0; i < 4; i++) {
		playerCheck[i] = FALSE;
	}
}


// CLasVegasMFCView diagnostics

#ifdef _DEBUG
void CLasVegasMFCView::AssertValid() const
{
	CFormView::AssertValid();
}

void CLasVegasMFCView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CLasVegasMFCDoc* CLasVegasMFCView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLasVegasMFCDoc)));
	return (CLasVegasMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CLasVegasMFCView message handlers


void CLasVegasMFCView::OnDraw(CDC* pDC)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CLasVegasMFCDoc *pDoc = (CLasVegasMFCDoc *)GetDocument();

	// set color
	CBrush blackBrush;
	blackBrush.CreateSolidBrush(RGB(0, 0, 0));

	// draw frame
	pDC->SelectStockObject(NULL_PEN);
	pDC->Rectangle(0, 0, clientRect.Width(), clientRect.Height());

	CRgn topBoxRgn;
	topBoxRgn.CreateRectRgn(0, 0, clientRect.Width(), clientRect.Height() / 10);
	pDC->FrameRgn(&topBoxRgn, &blackBrush, 1, 1);

	CRgn mainPlayerRgn;
	mainPlayerRgn.CreateRectRgn(0, clientRect.Height() / 10 * 8, clientRect.Width() / 4, clientRect.Height());
	pDC->FrameRgn(&mainPlayerRgn, &blackBrush, 1, 1);

	CRgn rollingButtonRgn;
	rollingButtonRgn.CreateRectRgn(clientRect.Width() / 4 * 3, clientRect.Height() / 10 * 8, clientRect.Width(), clientRect.Height());
	pDC->FrameRgn(&rollingButtonRgn, &blackBrush, 1, 1);

	// draw text
	DrawBlueText();

	// draw casino
	CBitmap casinoBmp[6];
	casinoBmp[0].LoadBitmap(ID_CASINO_1);
	casinoBmp[1].LoadBitmap(ID_CASINO_2);
	casinoBmp[2].LoadBitmap(ID_CASINO_3);
	casinoBmp[3].LoadBitmap(ID_CASINO_4);
	casinoBmp[4].LoadBitmap(ID_CASINO_5);
	casinoBmp[5].LoadBitmap(ID_CASINO_6);

	BITMAP casinoBmpInfo;
	casinoBmp[0].GetBitmap(&casinoBmpInfo);

	CDC casinoMem;
	casinoMem.CreateCompatibleDC(pDC);

	for (int i = 0; i < 6; i++) {
		casinoMem.SelectObject(&(casinoBmp[i]));
		pDC->StretchBlt(pCasino[i].x, pCasino[i].y, clientRect.Width() / 4, clientRect.Height() / 10 * 2, &casinoMem, 0, 0, casinoBmpInfo.bmWidth, casinoBmpInfo.bmHeight, SRCCOPY);
	}

	pDC->SetBkMode(TRANSPARENT);

	pDC->TextOut(pCasino[0].x + 85, pCasino[0].y + 30, pDoc->casino1->getCasinoInfo1());
	pDC->TextOut(pCasino[0].x + 15, pCasino[0].y + 60, pDoc->casino1->getCasinoInfo2());
	pDC->TextOut(pCasino[0].x + 240, pCasino[0].y + 90, pDoc->casino1->getCasinoInfo3());

	pDC->TextOut(pCasino[1].x + 85, pCasino[1].y + 30, pDoc->casino2->getCasinoInfo1());
	pDC->TextOut(pCasino[1].x + 15, pCasino[1].y + 60, pDoc->casino2->getCasinoInfo2());
	pDC->TextOut(pCasino[1].x + 240, pCasino[1].y + 90, pDoc->casino2->getCasinoInfo3());

	pDC->TextOut(pCasino[2].x + 85, pCasino[2].y + 30, pDoc->casino3->getCasinoInfo1());
	pDC->TextOut(pCasino[2].x + 15, pCasino[2].y + 60, pDoc->casino3->getCasinoInfo2());
	pDC->TextOut(pCasino[2].x + 240, pCasino[2].y + 90, pDoc->casino3->getCasinoInfo3());

	pDC->TextOut(pCasino[3].x + 85, pCasino[3].y + 30, pDoc->casino4->getCasinoInfo1());
	pDC->TextOut(pCasino[3].x + 15, pCasino[3].y + 60, pDoc->casino4->getCasinoInfo2());
	pDC->TextOut(pCasino[3].x + 240, pCasino[3].y + 90, pDoc->casino4->getCasinoInfo3());

	pDC->TextOut(pCasino[4].x + 85, pCasino[4].y + 30, pDoc->casino5->getCasinoInfo1());
	pDC->TextOut(pCasino[4].x + 15, pCasino[4].y + 60, pDoc->casino5->getCasinoInfo2());
	pDC->TextOut(pCasino[4].x + 240, pCasino[4].y + 90, pDoc->casino5->getCasinoInfo3());

	pDC->TextOut(pCasino[5].x + 85, pCasino[5].y + 30, pDoc->casino6->getCasinoInfo1());
	pDC->TextOut(pCasino[5].x + 15, pCasino[5].y + 60, pDoc->casino6->getCasinoInfo2());
	pDC->TextOut(pCasino[5].x + 240, pCasino[5].y + 90, pDoc->casino6->getCasinoInfo3());

	// draw main player info
	pDC->SelectStockObject(BLACK_PEN);

	CRgn playerInfoMoney1Rgn;
	playerInfoMoney1Rgn.CreateRectRgn(clientRect.Width() / 4, clientRect.Height() / 10 * 8 + 10, clientRect.Width() / 2, clientRect.Height() / 10 * 9);
	CRect playerInfoMoney1Rect;
	playerInfoMoney1Rgn.GetRgnBox(playerInfoMoney1Rect);
	pDC->Rectangle(&playerInfoMoney1Rect);
	pDC->DrawText(_T("Money"), &playerInfoMoney1Rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	CRgn playerInfoMoney2Rgn;
	playerInfoMoney2Rgn.CreateRectRgn(clientRect.Width() / 4, clientRect.Height() / 10 * 9, clientRect.Width() / 2, clientRect.Height());
	CRect playerInfoMoney2Rect;
	playerInfoMoney2Rgn.GetRgnBox(playerInfoMoney2Rect);
	pDC->Rectangle(&playerInfoMoney2Rect);

	CRgn playerInfoDice1Rgn;
	playerInfoDice1Rgn.CreateRectRgn(clientRect.Width() / 2, clientRect.Height() / 10 * 8 + 10, clientRect.Width() / 4 * 3, clientRect.Height() / 10 * 9);
	CRect playerInfoDice1Rect;
	playerInfoDice1Rgn.GetRgnBox(playerInfoDice1Rect);
	pDC->Rectangle(&playerInfoDice1Rect);
	pDC->DrawText(_T("Number of Dice"), &playerInfoDice1Rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	CRgn playerInfoDice2Rgn;
	playerInfoDice2Rgn.CreateRectRgn(clientRect.Width() / 2, clientRect.Height() / 10 * 9, clientRect.Width() / 4 * 3, clientRect.Height());
	CRect playerInfoDice2Rect;
	playerInfoDice2Rgn.GetRgnBox(playerInfoDice2Rect);
	pDC->Rectangle(&playerInfoDice2Rect);

	CString playerInfoMoneyStr;
	CString playerInfoDiceStr;

	if (pDoc -> round == 0) {
		playerInfoMoneyStr.Format(_T("%d $"), pDoc->player1->GetMoney());
		pDC->DrawText(playerInfoMoneyStr, &playerInfoMoney2Rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		playerInfoDiceStr.Format(_T("%d"), pDoc->player1->GetDiceNum());
		pDC->DrawText(playerInfoDiceStr, &playerInfoDice2Rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else if (pDoc -> round == 1) {
		playerInfoMoneyStr.Format(_T("%d $"), pDoc->player2->GetMoney());
		pDC->DrawText(playerInfoMoneyStr, &playerInfoMoney2Rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		playerInfoDiceStr.Format(_T("%d"), pDoc->player2->GetDiceNum());
		pDC->DrawText(playerInfoDiceStr, &playerInfoDice2Rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else if (pDoc->round == 2) {
		playerInfoMoneyStr.Format(_T("%d $"), pDoc->player3->GetMoney());
		pDC->DrawText(playerInfoMoneyStr, &playerInfoMoney2Rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		playerInfoDiceStr.Format(_T("%d"), pDoc->player3->GetDiceNum());
		pDC->DrawText(playerInfoDiceStr, &playerInfoDice2Rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else if (pDoc->round == 3) {
		playerInfoMoneyStr.Format(_T("%d $"), pDoc->player4->GetMoney());
		pDC->DrawText(playerInfoMoneyStr, &playerInfoMoney2Rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		playerInfoDiceStr.Format(_T("%d"), pDoc->player4->GetDiceNum());
		pDC->DrawText(playerInfoDiceStr, &playerInfoDice2Rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else if (pDoc->round == 4) {
		playerInfoMoneyStr.Format(_T("%d $"), pDoc->player5->GetMoney());
		pDC->DrawText(playerInfoMoneyStr, &playerInfoMoney2Rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		playerInfoDiceStr.Format(_T("%d"), pDoc->player5->GetDiceNum());
		pDC->DrawText(playerInfoDiceStr, &playerInfoDice2Rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}

	// draw round
	CRgn roundRgn;
	roundRgn.CreateRectRgn(clientRect.Width() / 2 - 60, clientRect.Height() / 12 * 2 - 30, clientRect.Width() / 2 + 60, clientRect.Height() / 12 * 2 + 20);
	CRect roundRect;
	roundRgn.GetRgnBox(&roundRect);
	pDC->Rectangle(&roundRect);
	CString roundStr;
	roundStr.Format(_T("%d Round"), pDoc->mainRound + 1);
	pDC->DrawText(roundStr, &roundRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}


void CLasVegasMFCView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CLasVegasMFCDoc *pDoc = (CLasVegasMFCDoc *)GetDocument();

	CRgn rollingButtonRgn;
	rollingButtonRgn.CreateRectRgn(clientRect.Width() / 4 * 3, clientRect.Height() / 10 * 8, clientRect.Width(), clientRect.Height());

	CDiceDlg dlg;
	if (rollingButtonRgn.PtInRegion(point) && (pDoc -> round == 0)) {
		dlg.name = pDoc->player1->name;
		dlg.pDoc = pDoc;
		dlg.id = 1;
		dlg.DoModal();

		pDoc->round = (pDoc->round + 1) % 5;
		if (pDoc->round == 0) {
			if ((pDoc->round == 0) && !(pDoc->player1->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 1) && !(pDoc->player2->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 2) && !(pDoc->player3->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 3) && !(pDoc->player4->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}
		else if (pDoc->round == 1) {
			if ((pDoc->round == 1) && !(pDoc->player2->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 2) && !(pDoc->player3->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 3) && !(pDoc->player4->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 4) && !(pDoc->player5->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}
		else if (pDoc->round == 2) {
			if ((pDoc->round == 2) && !(pDoc->player3->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 3) && !(pDoc->player4->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 4) && !(pDoc->player5->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 0) && !(pDoc->player1->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}
		else if (pDoc->round == 3) {
			if ((pDoc->round == 3) && !(pDoc->player4->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 4) && !(pDoc->player5->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 0) && !(pDoc->player1->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 1) && !(pDoc->player2->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}
		else if (pDoc->round == 4) {
			if ((pDoc->round == 4) && !(pDoc->player5->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 0) && !(pDoc->player1->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 1) && !(pDoc->player2->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 2) && !(pDoc->player3->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}

		Invalidate();
	}
	else if (rollingButtonRgn.PtInRegion(point) && (pDoc->round == 1)) {
		dlg.name = pDoc->player2->name;
		dlg.pDoc = pDoc;
		dlg.id = 2;
		dlg.DoModal();

		pDoc->round = (pDoc->round + 1) % 5;
		if (pDoc->round == 0) {
			if ((pDoc->round == 0) && !(pDoc->player1->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 1) && !(pDoc->player2->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 2) && !(pDoc->player3->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 3) && !(pDoc->player4->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}
		else if (pDoc->round == 1) {
			if ((pDoc->round == 1) && !(pDoc->player2->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 2) && !(pDoc->player3->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 3) && !(pDoc->player4->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 4) && !(pDoc->player5->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}
		else if (pDoc->round == 2) {
			if ((pDoc->round == 2) && !(pDoc->player3->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 3) && !(pDoc->player4->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 4) && !(pDoc->player5->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 0) && !(pDoc->player1->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}
		else if (pDoc->round == 3) {
			if ((pDoc->round == 3) && !(pDoc->player4->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 4) && !(pDoc->player5->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 0) && !(pDoc->player1->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 1) && !(pDoc->player2->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}
		else if (pDoc->round == 4) {
			if ((pDoc->round == 4) && !(pDoc->player5->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 0) && !(pDoc->player1->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 1) && !(pDoc->player2->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 2) && !(pDoc->player3->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}

		Invalidate();
	}
	else if (rollingButtonRgn.PtInRegion(point) && (pDoc->round == 2)) {
		dlg.name = pDoc->player3->name;
		dlg.pDoc = pDoc;
		dlg.id = 3;
		dlg.DoModal();

		pDoc->round = (pDoc->round + 1) % 5;
		if (pDoc->round == 0) {
			if ((pDoc->round == 0) && !(pDoc->player1->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 1) && !(pDoc->player2->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 2) && !(pDoc->player3->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 3) && !(pDoc->player4->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}
		else if (pDoc->round == 1) {
			if ((pDoc->round == 1) && !(pDoc->player2->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 2) && !(pDoc->player3->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 3) && !(pDoc->player4->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 4) && !(pDoc->player5->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}
		else if (pDoc->round == 2) {
			if ((pDoc->round == 2) && !(pDoc->player3->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 3) && !(pDoc->player4->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 4) && !(pDoc->player5->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 0) && !(pDoc->player1->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}
		else if (pDoc->round == 3) {
			if ((pDoc->round == 3) && !(pDoc->player4->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 4) && !(pDoc->player5->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 0) && !(pDoc->player1->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 1) && !(pDoc->player2->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}
		else if (pDoc->round == 4) {
			if ((pDoc->round == 4) && !(pDoc->player5->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 0) && !(pDoc->player1->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 1) && !(pDoc->player2->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 2) && !(pDoc->player3->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}

		Invalidate();
	}
	else if (rollingButtonRgn.PtInRegion(point) && (pDoc->round == 3)) {
		dlg.name = pDoc->player4->name;
		dlg.pDoc = pDoc;
		dlg.id = 4;
		dlg.DoModal();

		pDoc->round = (pDoc->round + 1) % 5;
		if (pDoc->round == 0) {
			if ((pDoc->round == 0) && !(pDoc->player1->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 1) && !(pDoc->player2->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 2) && !(pDoc->player3->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 3) && !(pDoc->player4->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}
		else if (pDoc->round == 1) {
			if ((pDoc->round == 1) && !(pDoc->player2->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 2) && !(pDoc->player3->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 3) && !(pDoc->player4->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 4) && !(pDoc->player5->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}
		else if (pDoc->round == 2) {
			if ((pDoc->round == 2) && !(pDoc->player3->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 3) && !(pDoc->player4->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 4) && !(pDoc->player5->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 0) && !(pDoc->player1->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}
		else if (pDoc->round == 3) {
			if ((pDoc->round == 3) && !(pDoc->player4->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 4) && !(pDoc->player5->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 0) && !(pDoc->player1->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 1) && !(pDoc->player2->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}
		else if (pDoc->round == 4) {
			if ((pDoc->round == 4) && !(pDoc->player5->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 0) && !(pDoc->player1->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 1) && !(pDoc->player2->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 2) && !(pDoc->player3->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}

		Invalidate();
	}
	else if (rollingButtonRgn.PtInRegion(point) && (pDoc->round == 4)) {
		dlg.name = pDoc->player5->name;
		dlg.pDoc = pDoc;
		dlg.id = 5;
		dlg.DoModal();

		pDoc->round = (pDoc->round + 1) % 5;
		if (pDoc->round == 0) {
			if ((pDoc->round == 0) && !(pDoc->player1->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 1) && !(pDoc->player2->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 2) && !(pDoc->player3->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 3) && !(pDoc->player4->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}
		else if (pDoc->round == 1) {
			if ((pDoc->round == 1) && !(pDoc->player2->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 2) && !(pDoc->player3->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 3) && !(pDoc->player4->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 4) && !(pDoc->player5->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}
		else if (pDoc->round == 2) {
			if ((pDoc->round == 2) && !(pDoc->player3->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 3) && !(pDoc->player4->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 4) && !(pDoc->player5->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 0) && !(pDoc->player1->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}
		else if (pDoc->round == 3) {
			if ((pDoc->round == 3) && !(pDoc->player4->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 4) && !(pDoc->player5->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 0) && !(pDoc->player1->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 1) && !(pDoc->player2->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}
		else if (pDoc->round == 4) {
			if ((pDoc->round == 4) && !(pDoc->player5->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 0) && !(pDoc->player1->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 1) && !(pDoc->player2->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
			if ((pDoc->round == 2) && !(pDoc->player3->diceEmpty())) {
				pDoc->round = (pDoc->round + 1) % 5;
			}
		}

		Invalidate();
	}

	if (!(pDoc->player1->diceEmpty() || pDoc->player2->diceEmpty() || pDoc->player3->diceEmpty() || pDoc->player4->diceEmpty() || pDoc->player5->diceEmpty())) {
		pDoc->casino1->ClosingCasino();
		pDoc->casino2->ClosingCasino();
		pDoc->casino3->ClosingCasino();
		pDoc->casino4->ClosingCasino();
		pDoc->casino5->ClosingCasino();
		pDoc->casino6->ClosingCasino();

		CString roundStr;
		roundStr.Format(_T("%d Round End"), pDoc->mainRound + 1);
		AfxMessageBox(roundStr);

		pDoc->round = 0;
		pDoc->mainRound++;

		pDoc->casino1->resetCasino();
		pDoc->casino2->resetCasino();
		pDoc->casino3->resetCasino();
		pDoc->casino4->resetCasino();
		pDoc->casino5->resetCasino();
		pDoc->casino6->resetCasino();

		while (TRUE) {
			pDoc->casino1->addBill(pDoc->billDeck->getBill());
			if (pDoc->casino1->getTotalPrice() >= 50000) {
				break;
			}
		}
		while (TRUE) {
			pDoc->casino2->addBill(pDoc->billDeck->getBill());
			if (pDoc->casino2->getTotalPrice() >= 50000) {
				break;
			}
		}
		while (TRUE) {
			pDoc->casino3->addBill(pDoc->billDeck->getBill());
			if (pDoc->casino3->getTotalPrice() >= 50000) {
				break;
			}
		}
		while (TRUE) {
			pDoc->casino4->addBill(pDoc->billDeck->getBill());
			if (pDoc->casino4->getTotalPrice() >= 50000) {
				break;
			}
		}
		while (TRUE) {
			pDoc->casino5->addBill(pDoc->billDeck->getBill());
			if (pDoc->casino5->getTotalPrice() >= 50000) {
				break;
			}
		}
		while (TRUE) {
			pDoc->casino6->addBill(pDoc->billDeck->getBill());
			if (pDoc->casino6->getTotalPrice() >= 50000) {
				break;
			}
		}
		pDoc->player1->reset();
		pDoc->player2->reset();
		pDoc->player3->reset();
		pDoc->player4->reset();
		pDoc->player5->reset();

		if (pDoc->mainRound != 3) {
			Invalidate();
		}
		else {
			CResultDlg r_dlg;
			r_dlg.pDoc = GetDocument();
			r_dlg.DoModal();

			pDoc->continueCheck = FALSE;
			pDoc->saveCheck = FALSE;
			CMenuDlg dlg;
			dlg.pDoc = GetDocument();
			dlg.DoModal();
			pDoc->continueCheck = TRUE;
			pDoc->saveCheck = TRUE;
			Invalidate();
		}
	}

	//CFormView::OnLButtonDown(nFlags, point);
}


void CLasVegasMFCView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CRgn rollingButtonRgn;
	rollingButtonRgn.CreateRectRgn(clientRect.Width() / 4 * 3, clientRect.Height() / 10 * 8, clientRect.Width(), clientRect.Height());

	if (rollingButtonRgn.PtInRegion(point) && (rollingButtonCheck == FALSE)) {
		rollingButtonCheck = TRUE;
		DrawBlueText();
	}
	else if (!(rollingButtonRgn.PtInRegion(point)) && (rollingButtonCheck == TRUE)) {
		rollingButtonCheck = FALSE;
		DrawBlueText();
	}

	CRgn playerRgn[4];
	for (int i = 0; i < 4; i++) {
		playerRgn[i].CreateRectRgn(clientRect.Width() / 4 * i, 0, clientRect.Width() / 4 * (i + 1), clientRect.Height() / 10);
	}

	for (int i = 0; i < 4; i++) {
		if (playerRgn[i].PtInRegion(point) && playerCheck[i] == FALSE) {
			playerCheck[i] = TRUE;
			DrawBlueText();
		}
		else if (!(playerRgn[i].PtInRegion(point)) && playerCheck[i] == TRUE) {
			playerCheck[i] = FALSE;
			DrawBlueText();
		}
	}

	//CFormView::OnMouseMove(nFlags, point);
}


void CLasVegasMFCView::DrawBlueText()
{
	CDC* pDC;
	pDC = GetWindowDC();
	CLasVegasMFCDoc *pDoc = (CLasVegasMFCDoc *)GetDocument();
	CMainFrame *mainFrm = (CMainFrame *)AfxGetMainWnd();

	CRgn rollingButtonRgn;
	rollingButtonRgn.CreateRectRgn(clientRect.Width() / 4 * 3, clientRect.Height() / 10 * 8, clientRect.Width(), clientRect.Height());
	CRect rollingButtonRect;
	rollingButtonRgn.GetRgnBox(&rollingButtonRect);

	if (rollingButtonCheck == FALSE) {
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->DrawText(_T("Rolling!!"), rollingButtonRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else if (rollingButtonCheck == TRUE) {
		pDC->SetTextColor(RGB(0, 0, 255));
		pDC->DrawText(_T("Rolling!!"), rollingButtonRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}

	// player area
	CRgn playerRgn[4];
	CRect playerRect[4];
	CRgn mainPlayerRgn;
	CRect mainPlayerRect;
	for (int i = 0; i < 4; i++) {
		playerRgn[i].CreateRectRgn(clientRect.Width() / 4 * i, 0, clientRect.Width() / 4 * (i + 1), clientRect.Height() / 10);
	}
	for (int i = 0; i < 4; i++) {
		playerRgn[i].GetRgnBox(playerRect[i]);
	}
	mainPlayerRgn.CreateRectRgn(0, clientRect.Height() / 10 * 8, clientRect.Width() / 4, clientRect.Height());
	mainPlayerRgn.GetRgnBox(&mainPlayerRect);
	rollingButtonRgn.CreateRectRgn(clientRect.Width() / 4 * 3, clientRect.Height() / 10 * 8, clientRect.Width(), clientRect.Height());
	rollingButtonRgn.GetRgnBox(&rollingButtonRect);
	for (int i = 0; i < 3; i++) {
		pCasino[i] = { 0,clientRect.Height() / 10 * (2 * i + 1) };
		pCasino[i + 3] = { clientRect.Width() / 4 * 3,clientRect.Height() / 10 * (2 * i + 1) };
	}

	CString statusStr[2];
	mainFrm->m_wndStatusBar.SetPaneText(1, _T(""));
	mainFrm->m_wndStatusBar.SetPaneText(2, _T(""));

	if (pDoc->round == 0) {
		if (playerCheck[0] == FALSE) {
			pDC->SetTextColor(RGB(0, 0, 0));
			pDC->DrawText(pDoc->player2->name, playerRect[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else if (playerCheck[0] == TRUE) {
			pDC->SetTextColor(RGB(0, 0, 255));
			pDC->DrawText(pDoc->player2->name, playerRect[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			statusStr[0].Format(_T("Money %d"), pDoc->player2->GetMoney());
			statusStr[1].Format(_T("Num of Dice %d"), pDoc->player2->GetDiceNum());
			mainFrm->m_wndStatusBar.SetPaneText(1, statusStr[0]);
			mainFrm->m_wndStatusBar.SetPaneText(2, statusStr[1]);
			pDC->SetTextColor(RGB(0, 0, 0));
		}
		if (playerCheck[1] == FALSE) {
			pDC->SetTextColor(RGB(0, 0, 0));
			pDC->DrawText(pDoc->player3->name, playerRect[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else if (playerCheck[1] == TRUE) {
			pDC->SetTextColor(RGB(0, 0, 255));
			pDC->DrawText(pDoc->player3->name, playerRect[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			statusStr[0].Format(_T("Money %d"), pDoc->player3->GetMoney());
			statusStr[1].Format(_T("Num of Dice %d"), pDoc->player3->GetDiceNum());
			mainFrm->m_wndStatusBar.SetPaneText(1, statusStr[0]);
			mainFrm->m_wndStatusBar.SetPaneText(2, statusStr[1]);
			pDC->SetTextColor(RGB(0, 0, 0));
		}
		if (playerCheck[2] == FALSE) {
			pDC->SetTextColor(RGB(0, 0, 0));
			pDC->DrawText(pDoc->player4->name, playerRect[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else if (playerCheck[2] == TRUE) {
			pDC->SetTextColor(RGB(0, 0, 255));
			pDC->DrawText(pDoc->player4->name, playerRect[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			statusStr[0].Format(_T("Money %d"), pDoc->player4->GetMoney());
			statusStr[1].Format(_T("Num of Dice %d"), pDoc->player4->GetDiceNum());
			mainFrm->m_wndStatusBar.SetPaneText(1, statusStr[0]);
			mainFrm->m_wndStatusBar.SetPaneText(2, statusStr[1]);
			pDC->SetTextColor(RGB(0, 0, 0));
		}
		if (playerCheck[3] == FALSE) {
			pDC->SetTextColor(RGB(0, 0, 0));
			pDC->DrawText(pDoc->player5->name, playerRect[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else if (playerCheck[3] == TRUE) {
			pDC->SetTextColor(RGB(0, 0, 255));
			pDC->DrawText(pDoc->player5->name, playerRect[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			statusStr[0].Format(_T("Money %d"), pDoc->player5->GetMoney());
			statusStr[1].Format(_T("Num of Dice %d"), pDoc->player5->GetDiceNum());
			mainFrm->m_wndStatusBar.SetPaneText(1, statusStr[0]);
			mainFrm->m_wndStatusBar.SetPaneText(2, statusStr[1]);
			pDC->SetTextColor(RGB(0, 0, 0));
		}
		pDC->DrawText(pDoc->player1->name, mainPlayerRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else if (pDoc->round == 1) {
		if (playerCheck[0] == FALSE) {
			pDC->SetTextColor(RGB(0, 0, 0));
			pDC->DrawText(pDoc->player1->name, playerRect[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else if (playerCheck[0] == TRUE) {
			pDC->SetTextColor(RGB(0, 0, 255));
			pDC->DrawText(pDoc->player1->name, playerRect[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			statusStr[0].Format(_T("Money %d"), pDoc->player1->GetMoney());
			statusStr[1].Format(_T("Num of Dice %d"), pDoc->player1->GetDiceNum());
			mainFrm->m_wndStatusBar.SetPaneText(1, statusStr[0]);
			mainFrm->m_wndStatusBar.SetPaneText(2, statusStr[1]);
			pDC->SetTextColor(RGB(0, 0, 0));
		}
		if (playerCheck[1] == FALSE) {
			pDC->SetTextColor(RGB(0, 0, 0));
			pDC->DrawText(pDoc->player3->name, playerRect[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else if (playerCheck[1] == TRUE) {
			pDC->SetTextColor(RGB(0, 0, 255));
			pDC->DrawText(pDoc->player3->name, playerRect[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			statusStr[0].Format(_T("Money %d"), pDoc->player3->GetMoney());
			statusStr[1].Format(_T("Num of Dice %d"), pDoc->player3->GetDiceNum());
			mainFrm->m_wndStatusBar.SetPaneText(1, statusStr[0]);
			mainFrm->m_wndStatusBar.SetPaneText(2, statusStr[1]);
			pDC->SetTextColor(RGB(0, 0, 0));
		}
		if (playerCheck[2] == FALSE) {
			pDC->SetTextColor(RGB(0, 0, 0));
			pDC->DrawText(pDoc->player4->name, playerRect[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else if (playerCheck[2] == TRUE) {
			pDC->SetTextColor(RGB(0, 0, 255));
			pDC->DrawText(pDoc->player4->name, playerRect[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			statusStr[0].Format(_T("Money %d"), pDoc->player4->GetMoney());
			statusStr[1].Format(_T("Num of Dice %d"), pDoc->player4->GetDiceNum());
			mainFrm->m_wndStatusBar.SetPaneText(1, statusStr[0]);
			mainFrm->m_wndStatusBar.SetPaneText(2, statusStr[1]);
			pDC->SetTextColor(RGB(0, 0, 0));
		}
		if (playerCheck[3] == FALSE) {
			pDC->SetTextColor(RGB(0, 0, 0));
			pDC->DrawText(pDoc->player5->name, playerRect[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else if (playerCheck[3] == TRUE) {
			pDC->SetTextColor(RGB(0, 0, 255));
			pDC->DrawText(pDoc->player5->name, playerRect[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			statusStr[0].Format(_T("Money %d"), pDoc->player5->GetMoney());
			statusStr[1].Format(_T("Num of Dice %d"), pDoc->player5->GetDiceNum());
			mainFrm->m_wndStatusBar.SetPaneText(1, statusStr[0]);
			mainFrm->m_wndStatusBar.SetPaneText(2, statusStr[1]);
			pDC->SetTextColor(RGB(0, 0, 0));
		}
		pDC->DrawText(pDoc->player2->name, mainPlayerRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else if (pDoc->round == 2) {
		if (playerCheck[0] == FALSE) {
			pDC->SetTextColor(RGB(0, 0, 0));
			pDC->DrawText(pDoc->player1->name, playerRect[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else if (playerCheck[0] == TRUE) {
			pDC->SetTextColor(RGB(0, 0, 255));
			pDC->DrawText(pDoc->player1->name, playerRect[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			statusStr[0].Format(_T("Money %d"), pDoc->player1->GetMoney());
			statusStr[1].Format(_T("Num of Dice %d"), pDoc->player1->GetDiceNum());
			mainFrm->m_wndStatusBar.SetPaneText(1, statusStr[0]);
			mainFrm->m_wndStatusBar.SetPaneText(2, statusStr[1]);
			pDC->SetTextColor(RGB(0, 0, 0));
		}
		if (playerCheck[1] == FALSE) {
			pDC->SetTextColor(RGB(0, 0, 0));
			pDC->DrawText(pDoc->player2->name, playerRect[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else if (playerCheck[1] == TRUE) {
			pDC->SetTextColor(RGB(0, 0, 255));
			pDC->DrawText(pDoc->player2->name, playerRect[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			statusStr[0].Format(_T("Money %d"), pDoc->player2->GetMoney());
			statusStr[1].Format(_T("Num of Dice %d"), pDoc->player2->GetDiceNum());
			mainFrm->m_wndStatusBar.SetPaneText(1, statusStr[0]);
			mainFrm->m_wndStatusBar.SetPaneText(2, statusStr[1]);
			pDC->SetTextColor(RGB(0, 0, 0));
		}
		if (playerCheck[2] == FALSE) {
			pDC->SetTextColor(RGB(0, 0, 0));
			pDC->DrawText(pDoc->player4->name, playerRect[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else if (playerCheck[2] == TRUE) {
			pDC->SetTextColor(RGB(0, 0, 255));
			pDC->DrawText(pDoc->player4->name, playerRect[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			statusStr[0].Format(_T("Money %d"), pDoc->player4->GetMoney());
			statusStr[1].Format(_T("Num of Dice %d"), pDoc->player4->GetDiceNum());
			mainFrm->m_wndStatusBar.SetPaneText(1, statusStr[0]);
			mainFrm->m_wndStatusBar.SetPaneText(2, statusStr[1]);
			pDC->SetTextColor(RGB(0, 0, 0));
		}
		if (playerCheck[3] == FALSE) {
			pDC->SetTextColor(RGB(0, 0, 0));
			pDC->DrawText(pDoc->player5->name, playerRect[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else if (playerCheck[3] == TRUE) {
			pDC->SetTextColor(RGB(0, 0, 255));
			pDC->DrawText(pDoc->player5->name, playerRect[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			statusStr[0].Format(_T("Money %d"), pDoc->player5->GetMoney());
			statusStr[1].Format(_T("Num of Dice %d"), pDoc->player5->GetDiceNum());
			mainFrm->m_wndStatusBar.SetPaneText(1, statusStr[0]);
			mainFrm->m_wndStatusBar.SetPaneText(2, statusStr[1]);
			pDC->SetTextColor(RGB(0, 0, 0));
		}
		pDC->DrawText(pDoc->player3->name, mainPlayerRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else if (pDoc->round == 3) {
		if (playerCheck[0] == FALSE) {
			pDC->SetTextColor(RGB(0, 0, 0));
			pDC->DrawText(pDoc->player1->name, playerRect[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else if (playerCheck[0] == TRUE) {
			pDC->SetTextColor(RGB(0, 0, 255));
			pDC->DrawText(pDoc->player1->name, playerRect[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			statusStr[0].Format(_T("Money %d"), pDoc->player1->GetMoney());
			statusStr[1].Format(_T("Num of Dice %d"), pDoc->player1->GetDiceNum());
			mainFrm->m_wndStatusBar.SetPaneText(1, statusStr[0]);
			mainFrm->m_wndStatusBar.SetPaneText(2, statusStr[1]);
			pDC->SetTextColor(RGB(0, 0, 0));
		}
		if (playerCheck[1] == FALSE) {
			pDC->SetTextColor(RGB(0, 0, 0));
			pDC->DrawText(pDoc->player2->name, playerRect[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else if (playerCheck[1] == TRUE) {
			pDC->SetTextColor(RGB(0, 0, 255));
			pDC->DrawText(pDoc->player2->name, playerRect[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			statusStr[0].Format(_T("Money %d"), pDoc->player2->GetMoney());
			statusStr[1].Format(_T("Num of Dice %d"), pDoc->player2->GetDiceNum());
			mainFrm->m_wndStatusBar.SetPaneText(1, statusStr[0]);
			mainFrm->m_wndStatusBar.SetPaneText(2, statusStr[1]);
			pDC->SetTextColor(RGB(0, 0, 0));
		}
		if (playerCheck[2] == FALSE) {
			pDC->SetTextColor(RGB(0, 0, 0));
			pDC->DrawText(pDoc->player3->name, playerRect[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else if (playerCheck[2] == TRUE) {
			pDC->SetTextColor(RGB(0, 0, 255));
			pDC->DrawText(pDoc->player3->name, playerRect[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			statusStr[0].Format(_T("Money %d"), pDoc->player3->GetMoney());
			statusStr[1].Format(_T("Num of Dice %d"), pDoc->player3->GetDiceNum());
			mainFrm->m_wndStatusBar.SetPaneText(1, statusStr[0]);
			mainFrm->m_wndStatusBar.SetPaneText(2, statusStr[1]);
			pDC->SetTextColor(RGB(0, 0, 0));
		}
		if (playerCheck[3] == FALSE) {
			pDC->SetTextColor(RGB(0, 0, 0));
			pDC->DrawText(pDoc->player5->name, playerRect[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else if (playerCheck[3] == TRUE) {
			pDC->SetTextColor(RGB(0, 0, 255));
			pDC->DrawText(pDoc->player5->name, playerRect[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			statusStr[0].Format(_T("Money %d"), pDoc->player5->GetMoney());
			statusStr[1].Format(_T("Num of Dice %d"), pDoc->player5->GetDiceNum());
			mainFrm->m_wndStatusBar.SetPaneText(1, statusStr[0]);
			mainFrm->m_wndStatusBar.SetPaneText(2, statusStr[1]);
			pDC->SetTextColor(RGB(0, 0, 0));
		}
		pDC->DrawText(pDoc->player4->name, mainPlayerRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else if (pDoc->round == 4) {
		if (playerCheck[0] == FALSE) {
			pDC->SetTextColor(RGB(0, 0, 0));
			pDC->DrawText(pDoc->player1->name, playerRect[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else if (playerCheck[0] == TRUE) {
			pDC->SetTextColor(RGB(0, 0, 255));
			pDC->DrawText(pDoc->player1->name, playerRect[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			statusStr[0].Format(_T("Money %d"), pDoc->player1->GetMoney());
			statusStr[1].Format(_T("Num of Dice %d"), pDoc->player1->GetDiceNum());
			mainFrm->m_wndStatusBar.SetPaneText(1, statusStr[0]);
			mainFrm->m_wndStatusBar.SetPaneText(2, statusStr[1]);
			pDC->SetTextColor(RGB(0, 0, 0));
		}
		if (playerCheck[1] == FALSE) {
			pDC->SetTextColor(RGB(0, 0, 0));
			pDC->DrawText(pDoc->player2->name, playerRect[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else if (playerCheck[1] == TRUE) {
			pDC->SetTextColor(RGB(0, 0, 255));
			pDC->DrawText(pDoc->player2->name, playerRect[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			statusStr[0].Format(_T("Money %d"), pDoc->player2->GetMoney());
			statusStr[1].Format(_T("Num of Dice %d"), pDoc->player2->GetDiceNum());
			mainFrm->m_wndStatusBar.SetPaneText(1, statusStr[0]);
			mainFrm->m_wndStatusBar.SetPaneText(2, statusStr[1]);
			pDC->SetTextColor(RGB(0, 0, 0));
		}
		if (playerCheck[2] == FALSE) {
			pDC->SetTextColor(RGB(0, 0, 0));
			pDC->DrawText(pDoc->player3->name, playerRect[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else if (playerCheck[2] == TRUE) {
			pDC->SetTextColor(RGB(0, 0, 255));
			pDC->DrawText(pDoc->player3->name, playerRect[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			statusStr[0].Format(_T("Money %d"), pDoc->player3->GetMoney());
			statusStr[1].Format(_T("Num of Dice %d"), pDoc->player3->GetDiceNum());
			mainFrm->m_wndStatusBar.SetPaneText(1, statusStr[0]);
			mainFrm->m_wndStatusBar.SetPaneText(2, statusStr[1]);
			pDC->SetTextColor(RGB(0, 0, 0));
		}
		if (playerCheck[3] == FALSE) {
			pDC->SetTextColor(RGB(0, 0, 0));
			pDC->DrawText(pDoc->player4->name, playerRect[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else if (playerCheck[3] == TRUE) {
			pDC->SetTextColor(RGB(0, 0, 255));
			pDC->DrawText(pDoc->player4->name, playerRect[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			statusStr[0].Format(_T("Money %d"), pDoc->player4->GetMoney());
			statusStr[1].Format(_T("Num of Dice %d"), pDoc->player4->GetDiceNum());
			mainFrm->m_wndStatusBar.SetPaneText(1, statusStr[0]);
			mainFrm->m_wndStatusBar.SetPaneText(2, statusStr[1]);
			pDC->SetTextColor(RGB(0, 0, 0));
		}
		pDC->DrawText(pDoc->player5->name, mainPlayerRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
}


void CLasVegasMFCView::OnViewMenu()
{
	// TODO: Add your command handler code here
	CMenuDlg dlg;
	dlg.pDoc = GetDocument();
	dlg.DoModal();
	CLasVegasMFCDoc *pDoc = (CLasVegasMFCDoc *)GetDocument();
	Invalidate();
}


BOOL CLasVegasMFCView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: Add your message handler code here and/or call default
	if (nHitTest == HTCLIENT) {
		::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
	}
	return TRUE;

	//return CFormView::OnSetCursor(pWnd, nHitTest, message);
}
