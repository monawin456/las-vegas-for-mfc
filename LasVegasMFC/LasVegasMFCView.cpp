
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

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLasVegasMFCView

IMPLEMENT_DYNCREATE(CLasVegasMFCView, CFormView)

BEGIN_MESSAGE_MAP(CLasVegasMFCView, CFormView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_VIEW_MENU, &CLasVegasMFCView::OnViewMenu)
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

	// client rect
	//CRect clientRect;
	//GetClientRect(&clientRect);

	CRgn playerRgn[4];
	CRect playerRect[4];
	CRgn mainPlayerRgn;
	CRect mainPlayerRect;
	CRgn rollingButtonRgn;
	CRect rollingButtonRect;

	// init rgn
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

	// set color
	COLORREF whiteRGB;
	whiteRGB = RGB(255, 255, 255);
	COLORREF blackRGB;
	blackRGB = RGB(0, 0, 0);
	COLORREF redRGB;
	redRGB = RGB(255, 0, 0);
	COLORREF orangeRGB;
	orangeRGB = RGB(255, 175, 0);
	COLORREF greenRGB;
	greenRGB = RGB(0, 255, 0);
	COLORREF blueRGB;
	blueRGB = RGB(0, 0, 255);
	COLORREF purpleRGB;
	purpleRGB = RGB(255, 0, 255);

	CBrush whiteBrush;
	whiteBrush.CreateSolidBrush(whiteRGB);
	CBrush blackBrush;
	blackBrush.CreateSolidBrush(blackRGB);
	CBrush redBrush;
	redBrush.CreateSolidBrush(redRGB);
	CBrush orangeBrush;
	orangeBrush.CreateSolidBrush(orangeRGB);
	CBrush greenBrush;
	greenBrush.CreateSolidBrush(greenRGB);
	CBrush blueBrush;
	blueBrush.CreateSolidBrush(blueRGB);
	CBrush purpleBrush;
	purpleBrush.CreateSolidBrush(purpleRGB);

	/* // set round
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
	*/

	// Game Start
	pDC->SelectStockObject(NULL_PEN);
	pDC->Rectangle(0, 0, clientRect.Width(), clientRect.Height());

	CRgn topBoxRgn;
	topBoxRgn.CreateRectRgn(0, 0, clientRect.Width(), clientRect.Height() / 10);
	pDC->FrameRgn(&topBoxRgn, &blackBrush, 1, 1);

	if (pDoc->round == 0) {
		/*
		pDC->FillRgn(&playerRgn[0], &orangeBrush);
		pDC->FillRgn(&playerRgn[1], &greenBrush);
		pDC->FillRgn(&playerRgn[2], &blueBrush);
		pDC->FillRgn(&playerRgn[3], &purpleBrush);
		*/

		pDC->SetBkColor(whiteRGB);

		//pDC->SetBkColor(orangeRGB);
		pDC->DrawText(pDoc->player2->name, playerRect[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//pDC->SetBkColor(greenRGB);
		pDC->DrawText(pDoc->player3->name, playerRect[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//pDC->SetBkColor(blueRGB);
		pDC->DrawText(pDoc->player4->name, playerRect[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//pDC->SetBkColor(purpleRGB);
		pDC->DrawText(pDoc->player5->name, playerRect[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		/*
		for (int i = 0; i < 4; i++) {
			pDC->FrameRgn(&playerRgn[i], &blackBrush, 1, 1);
		}
		*/

		//pDC->FillRgn(&mainPlayerRgn, &redBrush);
		//pDC->SetBkColor(redRGB);
		pDC->DrawText(pDoc->player1->name, mainPlayerRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else if (pDoc->round == 1) {
		/*
		pDC->FillRgn(&playerRgn[0], &redBrush);
		pDC->FillRgn(&playerRgn[1], &greenBrush);
		pDC->FillRgn(&playerRgn[2], &blueBrush);
		pDC->FillRgn(&playerRgn[3], &purpleBrush);
		*/

		pDC->SetBkColor(whiteRGB);

		//pDC->SetBkColor(redRGB);
		pDC->DrawText(pDoc->player1->name, playerRect[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//pDC->SetBkColor(greenRGB);
		pDC->DrawText(pDoc->player3->name, playerRect[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//pDC->SetBkColor(blueRGB);
		pDC->DrawText(pDoc->player4->name, playerRect[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//pDC->SetBkColor(purpleRGB);
		pDC->DrawText(pDoc->player5->name, playerRect[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		/*
		for (int i = 0; i < 4; i++) {
			pDC->FrameRgn(&playerRgn[i], &blackBrush, 1, 1);
		}
		*/

		//pDC->FillRgn(&mainPlayerRgn, &orangeBrush);
		//pDC->SetBkColor(orangeRGB);
		pDC->DrawText(pDoc->player2->name, mainPlayerRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else if (pDoc->round == 2) {
		/*
		pDC->FillRgn(&playerRgn[0], &redBrush);
		pDC->FillRgn(&playerRgn[1], &orangeBrush);
		pDC->FillRgn(&playerRgn[2], &blueBrush);
		pDC->FillRgn(&playerRgn[3], &purpleBrush);
		*/

		pDC->SetBkColor(whiteRGB);

		//pDC->SetBkColor(redRGB);
		pDC->DrawText(pDoc->player1->name, playerRect[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//pDC->SetBkColor(orangeRGB);
		pDC->DrawText(pDoc->player2->name, playerRect[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//pDC->SetBkColor(blueRGB);
		pDC->DrawText(pDoc->player4->name, playerRect[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//pDC->SetBkColor(purpleRGB);
		pDC->DrawText(pDoc->player5->name, playerRect[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		/*
		for (int i = 0; i < 4; i++) {
			pDC->FrameRgn(&playerRgn[i], &blackBrush, 1, 1);
		}
		*/

		//pDC->FillRgn(&mainPlayerRgn, &greenBrush);
		//pDC->SetBkColor(greenRGB);
		pDC->DrawText(pDoc->player3->name, mainPlayerRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else if (pDoc->round == 3) {
		/*
		pDC->FillRgn(&playerRgn[0], &redBrush);
		pDC->FillRgn(&playerRgn[1], &orangeBrush);
		pDC->FillRgn(&playerRgn[2], &greenBrush);
		pDC->FillRgn(&playerRgn[3], &purpleBrush);
		*/

		pDC->SetBkColor(whiteRGB);

		//pDC->SetBkColor(redRGB);
		pDC->DrawText(pDoc->player1->name, playerRect[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//pDC->SetBkColor(orangeRGB);
		pDC->DrawText(pDoc->player2->name, playerRect[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//pDC->SetBkColor(greenRGB);
		pDC->DrawText(pDoc->player3->name, playerRect[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//pDC->SetBkColor(purpleRGB);
		pDC->DrawText(pDoc->player5->name, playerRect[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		/*
		for (int i = 0; i < 4; i++) {
			pDC->FrameRgn(&playerRgn[i], &blackBrush, 1, 1);
		}
		*/

		//pDC->FillRgn(&mainPlayerRgn, &blueBrush);
		//pDC->SetBkColor(blueRGB);
		pDC->DrawText(pDoc->player4->name, mainPlayerRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else if (pDoc->round == 4) {
		/*
		pDC->FillRgn(&playerRgn[0], &redBrush);
		pDC->FillRgn(&playerRgn[1], &orangeBrush);
		pDC->FillRgn(&playerRgn[2], &greenBrush);
		pDC->FillRgn(&playerRgn[3], &blueBrush);
		*/

		pDC->SetBkColor(whiteRGB);

		//pDC->SetBkColor(redRGB);
		pDC->DrawText(pDoc->player1->name, playerRect[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//pDC->SetBkColor(orangeRGB);
		pDC->DrawText(pDoc->player2->name, playerRect[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//pDC->SetBkColor(greenRGB);
		pDC->DrawText(pDoc->player3->name, playerRect[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//pDC->SetBkColor(blueRGB);
		pDC->DrawText(pDoc->player4->name, playerRect[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		/*
		for (int i = 0; i < 4; i++) {
			pDC->FrameRgn(&playerRgn[i], &blackBrush, 1, 1);
		}
		*/

		//pDC->FillRgn(&mainPlayerRgn, &purpleBrush);
		//pDC->SetBkColor(purpleRGB);
		pDC->DrawText(pDoc->player5->name, mainPlayerRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}

	pDC->FrameRgn(&mainPlayerRgn, &blackBrush, 1, 1);

	pDC->FillRgn(&rollingButtonRgn, &whiteBrush);
	pDC->SetBkColor(whiteRGB);
	DrawBlueText();
	pDC->FrameRgn(&rollingButtonRgn, &blackBrush, 1, 1);

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
	CString playerInfoMoneyStr;

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
	//AfxMessageBox(pDoc->casino1->getCasinoInfo());
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

		AfxMessageBox(_T("End"));
		CResultDlg r_dlg;
		r_dlg.pDoc = GetDocument();
		r_dlg.DoModal();

		pDoc->continueCheck = FALSE;
		CMenuDlg dlg;
		dlg.pDoc = GetDocument();
		dlg.DoModal();
		pDoc->continueCheck = TRUE;
		Invalidate();
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

	//CFormView::OnMouseMove(nFlags, point);
}


void CLasVegasMFCView::DrawBlueText()
{
	CDC* pDC;
	pDC = GetWindowDC();

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
