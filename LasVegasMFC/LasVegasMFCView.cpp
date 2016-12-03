
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

	for (int i = 0; i < 3; i++) {
		pDoc->casino1->resetCasino();
		pDoc->casino2->resetCasino();
		pDoc->casino3->resetCasino();
		pDoc->casino4->resetCasino();
		pDoc->casino5->resetCasino();
		pDoc->casino6->resetCasino();

		pDoc->billDeck->resetDeck();

		while (TRUE) {
			pDoc->casino1->addBill(pDoc->billDeck->getBill());
			if (pDoc->casino1->getTotalPrice() > 50000) {
				break;
			}
		}
		while (TRUE) {
			pDoc->casino2->addBill(pDoc->billDeck->getBill());
			if (pDoc->casino2->getTotalPrice() > 50000) {
				break;
			}
		}
		while (TRUE) {
			pDoc->casino3->addBill(pDoc->billDeck->getBill());
			if (pDoc->casino3->getTotalPrice() > 50000) {
				break;
			}
		}
		while (TRUE) {
			pDoc->casino4->addBill(pDoc->billDeck->getBill());
			if (pDoc->casino4->getTotalPrice() > 50000) {
				break;
			}
		}
		while (TRUE) {
			pDoc->casino5->addBill(pDoc->billDeck->getBill());
			if (pDoc->casino5->getTotalPrice() > 50000) {
				break;
			}
		}
		while (TRUE) {
			pDoc->casino6->addBill(pDoc->billDeck->getBill());
			if (pDoc->casino6->getTotalPrice() > 50000) {
				break;
			}
		}

		while (pDoc->player1->diceEmpty() || pDoc->player2->diceEmpty() || pDoc->player3->diceEmpty() || pDoc->player4->diceEmpty() || pDoc->player5->diceEmpty()) {
			if (pDoc->player1->diceEmpty()) {
				CDiceDlg dlg1;
				dlg1.name = pDoc->player1->name;
				dlg1.pDoc = pDoc;
				dlg1.id = 1;
				dlg1.DoModal();
			}

			if (pDoc->player2->diceEmpty()) {
				CDiceDlg dlg2;
				dlg2.name = pDoc->player2->name;
				dlg2.pDoc = pDoc;
				dlg2.id = 2;
				dlg2.DoModal();
			}

			if (pDoc->player3->diceEmpty()) {
				CDiceDlg dlg3;
				dlg3.name = pDoc->player3->name;
				dlg3.pDoc = pDoc;
				dlg3.id = 3;
				dlg3.DoModal();
			}

			if (pDoc->player4->diceEmpty()) {
				CDiceDlg dlg4;
				dlg4.name = pDoc->player4->name;
				dlg4.pDoc = pDoc;
				dlg4.id = 4;
				dlg4.DoModal();
			}

			if (pDoc->player5->diceEmpty()) {
				CDiceDlg dlg5;
				dlg5.name = pDoc->player5->name;
				dlg5.pDoc = pDoc;
				dlg5.id = 5;
				dlg5.DoModal();
			}
		}
	}

	/*
	Player player1(1);
	Casino casino1;
	BillDeck billdeck;
	billdeck.resetDeck();
	casino1.addBill(billdeck.getBill());

	player1.Rolling();

	CString str;
	player1.GetDice(str);
	pDC->TextOut(10, 10, str);
	player1.Selection(4, &casino1);
	player1.GetDice(str);
	pDC->TextOut(10, 100, str);

	CString str1;
	CString str2;
	casino1.printInfo(str1, str2);

	pDC->TextOut(10, 200, str1);
	pDC->TextOut(10, 300, str2);
	CString name1(_T("황정태"));
	CDiceDlg dlg;
	dlg.name = name1;
	dlg.DoModal();
	*/
}
