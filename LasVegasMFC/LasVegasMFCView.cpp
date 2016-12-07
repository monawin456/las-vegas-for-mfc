
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


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLasVegasMFCView

IMPLEMENT_DYNCREATE(CLasVegasMFCView, CFormView)

BEGIN_MESSAGE_MAP(CLasVegasMFCView, CFormView)
	ON_WM_LBUTTONDOWN()
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

	srand((unsigned)time(NULL));
	rgnCheck = TRUE;

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
	CRect clientRect;
	GetClientRect(&clientRect);

	// init rgn
	if (rgnCheck) {
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

		pCasino[0] = { 0, (clientRect.Height() / 10) + (clientRect.Height() / 30) };
		pCasino[1] = { 0, (clientRect.Height() / 10)*3 + (clientRect.Height() / 30)*2 };
		pCasino[2] = { 0, (clientRect.Height() / 10)*5 + (clientRect.Height() / 30)*3 };

		rgnCheck = FALSE;
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

	// Game Start
	if (pDoc->round == 0) {
		pDC->FillRgn(&playerRgn[0], &orangeBrush);
		pDC->FillRgn(&playerRgn[1], &greenBrush);
		pDC->FillRgn(&playerRgn[2], &blueBrush);
		pDC->FillRgn(&playerRgn[3], &purpleBrush);

		pDC->SetBkColor(orangeRGB);
		pDC->DrawText(pDoc->player2->name, playerRect[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		pDC->SetBkColor(greenRGB);
		pDC->DrawText(pDoc->player3->name, playerRect[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		pDC->SetBkColor(blueRGB);
		pDC->DrawText(pDoc->player4->name, playerRect[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		pDC->SetBkColor(purpleRGB);
		pDC->DrawText(pDoc->player5->name, playerRect[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		for (int i = 0; i < 4; i++) {
			pDC->FrameRgn(&playerRgn[i], &blackBrush, 1, 1);
		}

		pDC->FillRgn(&mainPlayerRgn, &redBrush);
		pDC->SetBkColor(redRGB);
		pDC->DrawText(pDoc->player1->name, mainPlayerRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else if (pDoc->round == 1) {
		pDC->FillRgn(&playerRgn[0], &redBrush);
		pDC->FillRgn(&playerRgn[1], &greenBrush);
		pDC->FillRgn(&playerRgn[2], &blueBrush);
		pDC->FillRgn(&playerRgn[3], &purpleBrush);

		pDC->SetBkColor(redRGB);
		pDC->DrawText(pDoc->player1->name, playerRect[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		pDC->SetBkColor(greenRGB);
		pDC->DrawText(pDoc->player3->name, playerRect[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		pDC->SetBkColor(blueRGB);
		pDC->DrawText(pDoc->player4->name, playerRect[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		pDC->SetBkColor(purpleRGB);
		pDC->DrawText(pDoc->player5->name, playerRect[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		for (int i = 0; i < 4; i++) {
			pDC->FrameRgn(&playerRgn[i], &blackBrush, 1, 1);
		}

		pDC->FillRgn(&mainPlayerRgn, &orangeBrush);
		pDC->SetBkColor(orangeRGB);
		pDC->DrawText(pDoc->player2->name, mainPlayerRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else if (pDoc->round == 2) {
		pDC->FillRgn(&playerRgn[0], &redBrush);
		pDC->FillRgn(&playerRgn[1], &orangeBrush);
		pDC->FillRgn(&playerRgn[2], &blueBrush);
		pDC->FillRgn(&playerRgn[3], &purpleBrush);

		pDC->SetBkColor(redRGB);
		pDC->DrawText(pDoc->player1->name, playerRect[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		pDC->SetBkColor(orangeRGB);
		pDC->DrawText(pDoc->player2->name, playerRect[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		pDC->SetBkColor(blueRGB);
		pDC->DrawText(pDoc->player4->name, playerRect[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		pDC->SetBkColor(purpleRGB);
		pDC->DrawText(pDoc->player5->name, playerRect[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		for (int i = 0; i < 4; i++) {
			pDC->FrameRgn(&playerRgn[i], &blackBrush, 1, 1);
		}

		pDC->FillRgn(&mainPlayerRgn, &greenBrush);
		pDC->SetBkColor(greenRGB);
		pDC->DrawText(pDoc->player3->name, mainPlayerRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else if (pDoc->round == 3) {
		pDC->FillRgn(&playerRgn[0], &redBrush);
		pDC->FillRgn(&playerRgn[1], &orangeBrush);
		pDC->FillRgn(&playerRgn[2], &greenBrush);
		pDC->FillRgn(&playerRgn[3], &purpleBrush);

		pDC->SetBkColor(redRGB);
		pDC->DrawText(pDoc->player1->name, playerRect[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		pDC->SetBkColor(orangeRGB);
		pDC->DrawText(pDoc->player2->name, playerRect[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		pDC->SetBkColor(greenRGB);
		pDC->DrawText(pDoc->player3->name, playerRect[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		pDC->SetBkColor(purpleRGB);
		pDC->DrawText(pDoc->player5->name, playerRect[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		for (int i = 0; i < 4; i++) {
			pDC->FrameRgn(&playerRgn[i], &blackBrush, 1, 1);
		}

		pDC->FillRgn(&mainPlayerRgn, &blueBrush);
		pDC->SetBkColor(blueRGB);
		pDC->DrawText(pDoc->player4->name, mainPlayerRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}
	else if (pDoc->round == 4) {
		pDC->FillRgn(&playerRgn[0], &redBrush);
		pDC->FillRgn(&playerRgn[1], &orangeBrush);
		pDC->FillRgn(&playerRgn[2], &greenBrush);
		pDC->FillRgn(&playerRgn[3], &blueBrush);

		pDC->SetBkColor(redRGB);
		pDC->DrawText(pDoc->player1->name, playerRect[0], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		pDC->SetBkColor(orangeRGB);
		pDC->DrawText(pDoc->player2->name, playerRect[1], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		pDC->SetBkColor(greenRGB);
		pDC->DrawText(pDoc->player3->name, playerRect[2], DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		pDC->SetBkColor(blueRGB);
		pDC->DrawText(pDoc->player4->name, playerRect[3], DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		for (int i = 0; i < 4; i++) {
			pDC->FrameRgn(&playerRgn[i], &blackBrush, 1, 1);
		}

		pDC->FillRgn(&mainPlayerRgn, &purpleBrush);
		pDC->SetBkColor(purpleRGB);
		pDC->DrawText(pDoc->player5->name, mainPlayerRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	}

	pDC->FrameRgn(&mainPlayerRgn, &blackBrush, 1, 1);

	pDC->FillRgn(&rollingButtonRgn, &whiteBrush);
	pDC->SetBkColor(whiteRGB);
	pDC->DrawText(_T("Rolling!!"), rollingButtonRect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	pDC->FrameRgn(&rollingButtonRgn, &blackBrush, 1, 1);
}


void CLasVegasMFCView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CLasVegasMFCDoc *pDoc = (CLasVegasMFCDoc *)GetDocument();

	CDiceDlg dlg;

	if (rollingButtonRgn.PtInRegion(point) && (pDoc -> round == 0)) {
		dlg.name = pDoc->player1->name;
		dlg.pDoc = pDoc;
		dlg.id = 1;
		dlg.DoModal();
	}
	else if (rollingButtonRgn.PtInRegion(point) && (pDoc->round == 1)) {
		dlg.name = pDoc->player2->name;
		dlg.pDoc = pDoc;
		dlg.id = 2;
		dlg.DoModal();
	}
	else if (rollingButtonRgn.PtInRegion(point) && (pDoc->round == 2)) {
		dlg.name = pDoc->player3->name;
		dlg.pDoc = pDoc;
		dlg.id = 3;
		dlg.DoModal();
	}
	else if (rollingButtonRgn.PtInRegion(point) && (pDoc->round == 3)) {
		dlg.name = pDoc->player4->name;
		dlg.pDoc = pDoc;
		dlg.id = 4;
		dlg.DoModal();
	}
	else if (rollingButtonRgn.PtInRegion(point) && (pDoc->round == 4)) {
		dlg.name = pDoc->player5->name;
		dlg.pDoc = pDoc;
		dlg.id = 5;
		dlg.DoModal();
	}

	pDoc->round = (pDoc->round + 1) % 5;

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

	if ((pDoc->round == 4) && !(pDoc->player5->diceEmpty())) {
		pDoc->round = (pDoc->round + 1) % 5;
	}

	Invalidate();

	if (!(pDoc->player1->diceEmpty() || pDoc->player2->diceEmpty() || pDoc->player3->diceEmpty() || pDoc->player4->diceEmpty() || pDoc->player5->diceEmpty())) {
		AfxMessageBox(_T("End"));
	}

	//CFormView::OnLButtonDown(nFlags, point);
}
