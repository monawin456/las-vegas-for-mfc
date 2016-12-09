// DiceDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LasVegasMFC.h"
#include "DiceDlg.h"
#include "afxdialogex.h"
#include "Player.h"
#include "LasVegasMFCDoc.h"

// CDiceDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDiceDlg, CDialog)

CDiceDlg::CDiceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DICEDLG, pParent)
{

}

CDiceDlg::~CDiceDlg()
{
}

void CDiceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STR, m_str);
	DDX_Control(pDX, IDC_STR2, m_str2);
	DDX_Control(pDX, IDC_PIC1, m_pic1);
	DDX_Control(pDX, IDC_PIC2, m_pic2);
	DDX_Control(pDX, IDC_PIC3, m_pic3);
	DDX_Control(pDX, IDC_PIC4, m_pic4);
	DDX_Control(pDX, IDC_PIC5, m_pic5);
	DDX_Control(pDX, IDC_PIC6, m_pic6);
	DDX_Control(pDX, IDC_PIC7, m_pic7);
	DDX_Control(pDX, IDC_PIC8, m_pic8);
	DDX_Control(pDX, IDC_BUTTON1, m_b1);
	DDX_Control(pDX, IDC_BUTTON2, m_b2);
	DDX_Control(pDX, IDC_BUTTON3, m_b3);
	DDX_Control(pDX, IDC_BUTTON4, m_b4);
	DDX_Control(pDX, IDC_BUTTON5, m_b5);
	DDX_Control(pDX, IDC_BUTTON6, m_b6);
	DDX_Control(pDX, IDC_BUTTON7, m_br);
}


BEGIN_MESSAGE_MAP(CDiceDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON2, &CDiceDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CDiceDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CDiceDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDiceDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CDiceDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CDiceDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CDiceDlg::OnBnClickedButton7)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDiceDlg 메시지 처리기입니다.




void CDiceDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_b) {
		num = 1;
		if (id == 1) {
			if (pDoc->player1->num1 != 0)
			{
				m_n = TRUE;
				pDoc->player1->Selection(num, pDoc->casino1);
			}
		}
		else if (id == 2) {
			if (pDoc->player2->num1 != 0) 
			{
				m_n = TRUE;
				pDoc->player2->Selection(num, pDoc->casino1);
			}
		}
		else if (id == 3) {
			if (pDoc->player3->num1 != 0)
			{
				m_n = TRUE;
				pDoc->player3->Selection(num, pDoc->casino1);
			}
		}
		else if (id == 4) {
			if (pDoc->player4->num1 != 0)
			{
				m_n = TRUE;
				pDoc->player4->Selection(num, pDoc->casino1);
			}
		}
		else if (id == 5) {
			if (pDoc->player5->num1 != 0)
			{
				m_n = TRUE;
				pDoc->player5->Selection(num, pDoc->casino1);
			}
		}
		if(m_n)
		EndDialog(IDCLOSE);
	}
}

void CDiceDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_b) {
		num = 2;
		if (id == 1) {
			if (pDoc->player1->num2 != 0)
			{
				m_n = TRUE;
				pDoc->player1->Selection(num, pDoc->casino2);
			}
		}
		else if (id == 2) {
			if (pDoc->player2->num2 != 0)
			{
				m_n = TRUE;
				pDoc->player2->Selection(num, pDoc->casino2);
			}
		}
		else if (id == 3) {
			if (pDoc->player3->num2 != 0)
			{
				m_n = TRUE;
				pDoc->player3->Selection(num, pDoc->casino2);
			}
		}
		else if (id == 4) {
			if (pDoc->player4->num2 != 0)
			{
				m_n = TRUE;
				pDoc->player4->Selection(num, pDoc->casino2);
			}
		}
		else if (id == 5) {
			if (pDoc->player5->num2 != 0)
			{
				m_n = TRUE;
				pDoc->player5->Selection(num, pDoc->casino2);
			}
		}
		if (m_n)
			EndDialog(IDCLOSE);
	}
}


void CDiceDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_b) {
		num = 3;
		if (id == 1) {
			if (pDoc->player1->num3 != 0) {
				m_n = TRUE;
				pDoc->player1->Selection(num, pDoc->casino3);
			}

		}
		else if (id == 2) {
			if (pDoc->player2->num3 != 0) {
				m_n = TRUE;
				pDoc->player2->Selection(num, pDoc->casino3);
			}
		}
		else if (id == 3) {
			if (pDoc->player3->num3 != 0) {
				m_n = TRUE;
				pDoc->player3->Selection(num, pDoc->casino3);
			}
		}
		else if (id == 4) {
			if (pDoc->player4->num3 != 0) {
				m_n = TRUE;
				pDoc->player4->Selection(num, pDoc->casino3);
			}
		}
		else if (id == 5) {
			if (pDoc->player5->num3 != 0) {
				m_n = TRUE;
				pDoc->player5->Selection(num, pDoc->casino3);
			}
		}
		if(m_n)
		EndDialog(IDCLOSE);
	}
}


void CDiceDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_b) {
		num = 4;
		if (id == 1) {
			if (pDoc->player1->num4 != 0)
			{
				m_n = TRUE;
				pDoc->player1->Selection(num, pDoc->casino4);
			}
		}
		else if (id == 2) {
			if (pDoc->player2->num4 != 0)
			{
				m_n = TRUE;
				pDoc->player2->Selection(num, pDoc->casino4);
			}
		}
		else if (id == 3) {
			if (pDoc->player3->num4 != 0)
			{
				m_n = TRUE;
				pDoc->player3->Selection(num, pDoc->casino4);
			}
		}
		else if (id == 4) {
			if (pDoc->player4->num4 != 0)
			{
				m_n = TRUE;
				pDoc->player4->Selection(num, pDoc->casino4);
			}
		}
		else if (id == 5) {
			if (pDoc->player5->num4 != 0)
			{
				m_n = TRUE;
				pDoc->player5->Selection(num, pDoc->casino4);
			}
		}
		if(m_n)
		EndDialog(IDCLOSE);
	}
}


void CDiceDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_b) {
		num = 5;
		if (id == 1) {
			if (pDoc->player1->num5 != 0)
			{
				m_n = TRUE;
				pDoc->player1->Selection(num, pDoc->casino5);
			}
		}
		else if (id == 2) {
			if (pDoc->player2->num5 != 0)
			{
				m_n = TRUE;
				pDoc->player2->Selection(num, pDoc->casino5);
			}
		}
		else if (id == 3) {
			if (pDoc->player3->num5 != 0)
			{
				m_n = TRUE;
				pDoc->player3->Selection(num, pDoc->casino5);
			}
		}
		else if (id == 4) {
			if (pDoc->player4->num5 != 0)
			{
				m_n = TRUE;
				pDoc->player4->Selection(num, pDoc->casino5);
			}
		}
		else if (id == 5) {
			if (pDoc->player5->num5 != 0)
			{
				m_n = TRUE;
				pDoc->player5->Selection(num, pDoc->casino5);
			}
		}
		if(m_n)
		EndDialog(IDCLOSE);
	}
}


void CDiceDlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_b) {
		num = 6;
		if (id == 1) {
			if (pDoc->player1->num6 != 0)
			{
				m_n = TRUE;
				pDoc->player1->Selection(num, pDoc->casino6);
			}
		}
		else if (id == 2) {
			if (pDoc->player2->num6 != 0)
			{
				m_n = TRUE;
				pDoc->player2->Selection(num, pDoc->casino6);
			}
		}
		else if (id == 3) {
			if (pDoc->player3->num6 != 0)
			{
				m_n = TRUE;
				pDoc->player3->Selection(num, pDoc->casino6);
			}
		}
		else if (id == 4) {
			if (pDoc->player4->num6 != 0)
			{
				m_n = TRUE;
				pDoc->player4->Selection(num, pDoc->casino6);
			}
		}
		else if (id == 5) {
			if (pDoc->player5->num6 != 0)
			{
				m_n = TRUE;
				pDoc->player5->Selection(num, pDoc->casino6);
			}
		}
		if(m_n)
		EndDialog(IDCLOSE);
	}
}


BOOL CDiceDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_b = FALSE;
	m_n = FALSE;
	m_str.SetWindowText(name);

	memDC.CreateCompatibleDC(m_pic1.GetWindowDC());
	m_pic1.GetClientRect(&rect);

	rd1.LoadBitmap(ID_RED_DICE_1);
	rd2.LoadBitmap(ID_RED_DICE_2);
	rd3.LoadBitmap(ID_RED_DICE_3);
	rd4.LoadBitmap(ID_RED_DICE_4);
	rd5.LoadBitmap(ID_RED_DICE_5);
	rd6.LoadBitmap(ID_RED_DICE_6);
	rdq.LoadBitmap(ID_RED_DICE_Q);

	wd1.LoadBitmap(ID_WHITE_DICE_1);
	wd2.LoadBitmap(ID_WHITE_DICE_2);
	wd3.LoadBitmap(ID_WHITE_DICE_3);
	wd4.LoadBitmap(ID_WHITE_DICE_4);
	wd5.LoadBitmap(ID_WHITE_DICE_5);
	wd6.LoadBitmap(ID_WHITE_DICE_6);
	wdq.LoadBitmap(ID_WHITE_DICE_Q);

	gd1.LoadBitmap(ID_GREEN_DICE_1);
	gd2.LoadBitmap(ID_GREEN_DICE_2);
	gd3.LoadBitmap(ID_GREEN_DICE_3);
	gd4.LoadBitmap(ID_GREEN_DICE_4);
	gd5.LoadBitmap(ID_GREEN_DICE_5);
	gd6.LoadBitmap(ID_GREEN_DICE_6);
	gdq.LoadBitmap(ID_GREEN_DICE_Q);

	bd1.LoadBitmap(ID_BLUE_DICE_1);
	bd2.LoadBitmap(ID_BLUE_DICE_2);
	bd3.LoadBitmap(ID_BLUE_DICE_3);
	bd4.LoadBitmap(ID_BLUE_DICE_4);
	bd5.LoadBitmap(ID_BLUE_DICE_5);
	bd6.LoadBitmap(ID_BLUE_DICE_6);
	bdq.LoadBitmap(ID_BLUE_DICE_Q);

	kd1.LoadBitmap(ID_BLACK_DICE_1);
	kd2.LoadBitmap(ID_BLACK_DICE_2);
	kd3.LoadBitmap(ID_BLACK_DICE_3);
	kd4.LoadBitmap(ID_BLACK_DICE_4);
	kd5.LoadBitmap(ID_BLACK_DICE_5);
	kd6.LoadBitmap(ID_BLACK_DICE_6);
	kdq.LoadBitmap(ID_BLACK_DICE_Q);
	
	rd1.GetBitmap(&bmpinfo);

	


	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDiceDlg::OnBnClickedButton7()
{
	
	CString str;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if ((id == 1) && (m_b == FALSE))
	{
		pDoc->player1->Rolling();
		for (int i = 0; i < 8; i++) {
			dice[i] = pDoc->player1->GetDice(i);
		}
		pDoc->player1->GetDice(str);
		m_str2.SetWindowText(str);
		//
		if (dice[0] == 1)
		{
			memDC.SelectObject(&rd1);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[0] == 2)
		{
			memDC.SelectObject(&rd2);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[0] == 3)
		{
			memDC.SelectObject(&rd3);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[0] == 4)
		{
			memDC.SelectObject(&rd4);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[0] == 5)
		{
			memDC.SelectObject(&rd5);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}


		if (dice[0] == 6)
		{
			memDC.SelectObject(&rd6);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}

		//
		if (dice[1] == 1)
		{
			memDC.SelectObject(&rd1);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 2)
		{
			memDC.SelectObject(&rd2);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 3)
		{
			memDC.SelectObject(&rd3);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 4)
		{
			memDC.SelectObject(&rd4);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 5)
		{
			memDC.SelectObject(&rd5);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 6)
		{
			memDC.SelectObject(&rd6);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		//
		if (dice[2] == 1)
		{
			memDC.SelectObject(&rd1);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 2)
		{
			memDC.SelectObject(&rd2);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 3)
		{
			memDC.SelectObject(&rd3);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 4)
		{
			memDC.SelectObject(&rd4);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 5)
		{
			memDC.SelectObject(&rd5);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 6)
		{
			memDC.SelectObject(&rd6);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		//

		if (dice[3] == 1)
		{
			memDC.SelectObject(&rd1);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 2)
		{
			memDC.SelectObject(&rd2);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 3)
		{
			memDC.SelectObject(&rd3);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 4)
		{
			memDC.SelectObject(&rd4);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 5)
		{
			memDC.SelectObject(&rd5);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 6)
		{
			memDC.SelectObject(&rd6);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		//

		if (dice[4] == 1)
		{
			memDC.SelectObject(&rd1);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 2)
		{
			memDC.SelectObject(&rd2);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 3)
		{
			memDC.SelectObject(&rd3);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 4)
		{
			memDC.SelectObject(&rd4);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 5)
		{
			memDC.SelectObject(&rd5);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 6)
		{
			memDC.SelectObject(&rd6);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}

		//
		if (dice[5] == 1)
		{
			memDC.SelectObject(&rd1);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 2)
		{
			memDC.SelectObject(&rd2);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 3)
		{
			memDC.SelectObject(&rd3);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 4)
		{
			memDC.SelectObject(&rd4);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 5)
		{
			memDC.SelectObject(&rd5);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 6)
		{
			memDC.SelectObject(&rd6);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
//

		if (dice[6] == 1)
		{
			memDC.SelectObject(&rd1);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 2)
		{
			memDC.SelectObject(&rd2);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 3)
		{
			memDC.SelectObject(&rd3);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 4)
		{
			memDC.SelectObject(&rd4);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 5)
		{
			memDC.SelectObject(&rd5);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 6)
		{
			memDC.SelectObject(&rd6);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}

//
		if (dice[7] == 1)
		{
			memDC.SelectObject(&rd1);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 2)
		{
			memDC.SelectObject(&rd2);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 3)
		{
			memDC.SelectObject(&rd3);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 4)
		{
			memDC.SelectObject(&rd4);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 5)
		{
			memDC.SelectObject(&rd5);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 6)
		{
			memDC.SelectObject(&rd6);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}


		

	}
	else if ((id == 2) && (m_b == FALSE))
	{
		pDoc->player2->Rolling();
		for (int i = 0; i < 8; i++)
			dice[i] = pDoc->player2->GetDice(i);
		pDoc->player2->GetDice(str);
		m_str2.SetWindowText(str);

		//
		if (dice[0] == 1)
		{
			memDC.SelectObject(&wd1);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[0] == 2)
		{
			memDC.SelectObject(&wd2);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[0] == 3)
		{
			memDC.SelectObject(&wd3);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[0] == 4)
		{
			memDC.SelectObject(&wd4);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[0] == 5)
		{
			memDC.SelectObject(&wd5);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}


		if (dice[0] == 6)
		{
			memDC.SelectObject(&wd6);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}

		//
		if (dice[1] == 1)
		{
			memDC.SelectObject(&wd1);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 2)
		{
			memDC.SelectObject(&wd2);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 3)
		{
			memDC.SelectObject(&wd3);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 4)
		{
			memDC.SelectObject(&wd4);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 5)
		{
			memDC.SelectObject(&wd5);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 6)
		{
			memDC.SelectObject(&wd6);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		//
		if (dice[2] == 1)
		{
			memDC.SelectObject(&wd1);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 2)
		{
			memDC.SelectObject(&wd2);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 3)
		{
			memDC.SelectObject(&wd3);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 4)
		{
			memDC.SelectObject(&wd4);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 5)
		{
			memDC.SelectObject(&wd5);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 6)
		{
			memDC.SelectObject(&wd6);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		//

		if (dice[3] == 1)
		{
			memDC.SelectObject(&wd1);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 2)
		{
			memDC.SelectObject(&wd2);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 3)
		{
			memDC.SelectObject(&wd3);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 4)
		{
			memDC.SelectObject(&wd4);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 5)
		{
			memDC.SelectObject(&wd5);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 6)
		{
			memDC.SelectObject(&wd6);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		//

		if (dice[4] == 1)
		{
			memDC.SelectObject(&wd1);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 2)
		{
			memDC.SelectObject(&wd2);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 3)
		{
			memDC.SelectObject(&wd3);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 4)
		{
			memDC.SelectObject(&wd4);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 5)
		{
			memDC.SelectObject(&wd5);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 6)
		{
			memDC.SelectObject(&wd6);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}

		//
		if (dice[5] == 1)
		{
			memDC.SelectObject(&wd1);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 2)
		{
			memDC.SelectObject(&wd2);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 3)
		{
			memDC.SelectObject(&wd3);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 4)
		{
			memDC.SelectObject(&wd4);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 5)
		{
			memDC.SelectObject(&wd5);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 6)
		{
			memDC.SelectObject(&wd6);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		//

		if (dice[6] == 1)
		{
			memDC.SelectObject(&wd1);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 2)
		{
			memDC.SelectObject(&wd2);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 3)
		{
			memDC.SelectObject(&wd3);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 4)
		{
			memDC.SelectObject(&wd4);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 5)
		{
			memDC.SelectObject(&wd5);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 6)
		{
			memDC.SelectObject(&wd6);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}

		//
		if (dice[7] == 1)
		{
			memDC.SelectObject(&wd1);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 2)
		{
			memDC.SelectObject(&wd2);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 3)
		{
			memDC.SelectObject(&wd3);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 4)
		{
			memDC.SelectObject(&wd4);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 5)
		{
			memDC.SelectObject(&wd5);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 6)
		{
			memDC.SelectObject(&wd6);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}


	}
	else if ((id == 3) && (m_b == FALSE))
	{
		pDoc->player3->Rolling();
		for (int i = 0; i < 8; i++)
			dice[i] = pDoc->player3->GetDice(i);
		pDoc->player3->GetDice(str);
		m_str2.SetWindowText(str);

		//
		if (dice[0] == 1)
		{
			memDC.SelectObject(&gd1);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[0] == 2)
		{
			memDC.SelectObject(&gd2);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[0] == 3)
		{
			memDC.SelectObject(&gd3);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[0] == 4)
		{
			memDC.SelectObject(&gd4);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[0] == 5)
		{
			memDC.SelectObject(&gd5);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}


		if (dice[0] == 6)
		{
			memDC.SelectObject(&gd6);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}

		//
		if (dice[1] == 1)
		{
			memDC.SelectObject(&gd1);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 2)
		{
			memDC.SelectObject(&gd2);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 3)
		{
			memDC.SelectObject(&gd3);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 4)
		{
			memDC.SelectObject(&gd4);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 5)
		{
			memDC.SelectObject(&gd5);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 6)
		{
			memDC.SelectObject(&gd6);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		//
		if (dice[2] == 1)
		{
			memDC.SelectObject(&gd1);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 2)
		{
			memDC.SelectObject(&gd2);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 3)
		{
			memDC.SelectObject(&gd3);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 4)
		{
			memDC.SelectObject(&gd4);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 5)
		{
			memDC.SelectObject(&gd5);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 6)
		{
			memDC.SelectObject(&gd6);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		//

		if (dice[3] == 1)
		{
			memDC.SelectObject(&gd1);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 2)
		{
			memDC.SelectObject(&gd2);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 3)
		{
			memDC.SelectObject(&gd3);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 4)
		{
			memDC.SelectObject(&gd4);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 5)
		{
			memDC.SelectObject(&gd5);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 6)
		{
			memDC.SelectObject(&gd6);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		//

		if (dice[4] == 1)
		{
			memDC.SelectObject(&gd1);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 2)
		{
			memDC.SelectObject(&gd2);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 3)
		{
			memDC.SelectObject(&gd3);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 4)
		{
			memDC.SelectObject(&gd4);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 5)
		{
			memDC.SelectObject(&gd5);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 6)
		{
			memDC.SelectObject(&gd6);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}

		//
		if (dice[5] == 1)
		{
			memDC.SelectObject(&gd1);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 2)
		{
			memDC.SelectObject(&gd2);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 3)
		{
			memDC.SelectObject(&gd3);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 4)
		{
			memDC.SelectObject(&gd4);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 5)
		{
			memDC.SelectObject(&gd5);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 6)
		{
			memDC.SelectObject(&gd6);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		//

		if (dice[6] == 1)
		{
			memDC.SelectObject(&gd1);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 2)
		{
			memDC.SelectObject(&gd2);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 3)
		{
			memDC.SelectObject(&gd3);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 4)
		{
			memDC.SelectObject(&gd4);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 5)
		{
			memDC.SelectObject(&gd5);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 6)
		{
			memDC.SelectObject(&gd6);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}

		//
		if (dice[7] == 1)
		{
			memDC.SelectObject(&gd1);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 2)
		{
			memDC.SelectObject(&gd2);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 3)
		{
			memDC.SelectObject(&gd3);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 4)
		{
			memDC.SelectObject(&gd4);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 5)
		{
			memDC.SelectObject(&gd5);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 6)
		{
			memDC.SelectObject(&gd6);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}

	}
	else if ((id == 4) && (m_b == FALSE))
	{
		pDoc->player4->Rolling();
		for (int i = 0; i < 8; i++)
			dice[i] = pDoc->player4->GetDice(i);
		pDoc->player4->GetDice(str);
		m_str2.SetWindowText(str);

		//
		if (dice[0] == 1)
		{
			memDC.SelectObject(&bd1);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[0] == 2)
		{
			memDC.SelectObject(&bd2);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[0] == 3)
		{
			memDC.SelectObject(&bd3);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[0] == 4)
		{
			memDC.SelectObject(&bd4);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[0] == 5)
		{
			memDC.SelectObject(&bd5);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}


		if (dice[0] == 6)
		{
			memDC.SelectObject(&bd6);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}

		//
		if (dice[1] == 1)
		{
			memDC.SelectObject(&bd1);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 2)
		{
			memDC.SelectObject(&bd2);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 3)
		{
			memDC.SelectObject(&bd3);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 4)
		{
			memDC.SelectObject(&bd4);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 5)
		{
			memDC.SelectObject(&bd5);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 6)
		{
			memDC.SelectObject(&bd6);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		//
		if (dice[2] == 1)
		{
			memDC.SelectObject(&bd1);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 2)
		{
			memDC.SelectObject(&bd2);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 3)
		{
			memDC.SelectObject(&bd3);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 4)
		{
			memDC.SelectObject(&bd4);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 5)
		{
			memDC.SelectObject(&bd5);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 6)
		{
			memDC.SelectObject(&bd6);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		//

		if (dice[3] == 1)
		{
			memDC.SelectObject(&bd1);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 2)
		{
			memDC.SelectObject(&bd2);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 3)
		{
			memDC.SelectObject(&bd3);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 4)
		{
			memDC.SelectObject(&bd4);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 5)
		{
			memDC.SelectObject(&bd5);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 6)
		{
			memDC.SelectObject(&bd6);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		//

		if (dice[4] == 1)
		{
			memDC.SelectObject(&bd1);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 2)
		{
			memDC.SelectObject(&bd2);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 3)
		{
			memDC.SelectObject(&bd3);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 4)
		{
			memDC.SelectObject(&bd4);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 5)
		{
			memDC.SelectObject(&bd5);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 6)
		{
			memDC.SelectObject(&bd6);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}

		//
		if (dice[5] == 1)
		{
			memDC.SelectObject(&bd1);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 2)
		{
			memDC.SelectObject(&bd2);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 3)
		{
			memDC.SelectObject(&bd3);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 4)
		{
			memDC.SelectObject(&bd4);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 5)
		{
			memDC.SelectObject(&bd5);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 6)
		{
			memDC.SelectObject(&bd6);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		//

		if (dice[6] == 1)
		{
			memDC.SelectObject(&bd1);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 2)
		{
			memDC.SelectObject(&bd2);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 3)
		{
			memDC.SelectObject(&bd3);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 4)
		{
			memDC.SelectObject(&bd4);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 5)
		{
			memDC.SelectObject(&bd5);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 6)
		{
			memDC.SelectObject(&bd6);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}

		//
		if (dice[7] == 1)
		{
			memDC.SelectObject(&bd1);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 2)
		{
			memDC.SelectObject(&bd2);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 3)
		{
			memDC.SelectObject(&bd3);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 4)
		{
			memDC.SelectObject(&bd4);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 5)
		{
			memDC.SelectObject(&bd5);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 6)
		{
			memDC.SelectObject(&bd6);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}

	}
	else if ((id == 5) && (m_b == FALSE))
	{
		pDoc->player5->Rolling();
		for (int i = 0; i < 8; i++)
			dice[i] = pDoc->player5->GetDice(i);
		pDoc->player5->GetDice(str);
		m_str2.SetWindowText(str);

		//
		if (dice[0] == 1)
		{
			memDC.SelectObject(&kd1);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[0] == 2)
		{
			memDC.SelectObject(&kd2);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[0] == 3)
		{
			memDC.SelectObject(&kd3);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[0] == 4)
		{
			memDC.SelectObject(&kd4);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[0] == 5)
		{
			memDC.SelectObject(&kd5);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}


		if (dice[0] == 6)
		{
			memDC.SelectObject(&kd6);
			m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}

		//
		if (dice[1] == 1)
		{
			memDC.SelectObject(&kd1);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 2)
		{
			memDC.SelectObject(&kd2);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 3)
		{
			memDC.SelectObject(&kd3);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 4)
		{
			memDC.SelectObject(&kd4);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 5)
		{
			memDC.SelectObject(&kd5);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[1] == 6)
		{
			memDC.SelectObject(&kd6);
			m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		//
		if (dice[2] == 1)
		{
			memDC.SelectObject(&kd1);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 2)
		{
			memDC.SelectObject(&kd2);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 3)
		{
			memDC.SelectObject(&kd3);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 4)
		{
			memDC.SelectObject(&kd4);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 5)
		{
			memDC.SelectObject(&kd5);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[2] == 6)
		{
			memDC.SelectObject(&kd6);
			m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		//

		if (dice[3] == 1)
		{
			memDC.SelectObject(&kd1);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 2)
		{
			memDC.SelectObject(&kd2);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 3)
		{
			memDC.SelectObject(&kd3);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 4)
		{
			memDC.SelectObject(&kd4);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 5)
		{
			memDC.SelectObject(&kd5);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[3] == 6)
		{
			memDC.SelectObject(&kd6);
			m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		//

		if (dice[4] == 1)
		{
			memDC.SelectObject(&kd1);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 2)
		{
			memDC.SelectObject(&kd2);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 3)
		{
			memDC.SelectObject(&kd3);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 4)
		{
			memDC.SelectObject(&kd4);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 5)
		{
			memDC.SelectObject(&kd5);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[4] == 6)
		{
			memDC.SelectObject(&kd6);
			m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}

		//
		if (dice[5] == 1)
		{
			memDC.SelectObject(&kd1);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 2)
		{
			memDC.SelectObject(&kd2);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 3)
		{
			memDC.SelectObject(&kd3);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 4)
		{
			memDC.SelectObject(&kd4);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 5)
		{
			memDC.SelectObject(&kd5);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[5] == 6)
		{
			memDC.SelectObject(&kd6);
			m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		//

		if (dice[6] == 1)
		{
			memDC.SelectObject(&kd1);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 2)
		{
			memDC.SelectObject(&kd2);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 3)
		{
			memDC.SelectObject(&kd3);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 4)
		{
			memDC.SelectObject(&kd4);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 5)
		{
			memDC.SelectObject(&kd5);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[6] == 6)
		{
			memDC.SelectObject(&kd6);
			m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}

		//
		if (dice[7] == 1)
		{
			memDC.SelectObject(&kd1);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 2)
		{
			memDC.SelectObject(&kd2);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 3)
		{
			memDC.SelectObject(&kd3);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 4)
		{
			memDC.SelectObject(&kd4);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 5)
		{
			memDC.SelectObject(&kd5);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}
		if (dice[7] == 6)
		{
			memDC.SelectObject(&kd6);
			m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		}

	}
	
	if ((id == 1)) {
		if (pDoc->player1->num1 != 0)
			m_b1.EnableWindow(TRUE);
		if (pDoc->player1->num2 != 0)
			m_b2.EnableWindow(TRUE);
		if (pDoc->player1->num3 != 0)
			m_b3.EnableWindow(TRUE);
		if (pDoc->player1->num4 != 0)
			m_b4.EnableWindow(TRUE);
		if (pDoc->player1->num5 != 0)
			m_b5.EnableWindow(TRUE);
		if (pDoc->player1->num6 != 0)
			m_b6.EnableWindow(TRUE);
	}
	else if ((id == 2)) {
		if (pDoc->player2->num1 != 0)
			m_b1.EnableWindow(TRUE);
		if (pDoc->player2->num2 != 0)
			m_b2.EnableWindow(TRUE);
		if (pDoc->player2->num3 != 0)
			m_b3.EnableWindow(TRUE);
		if (pDoc->player2->num4 != 0)
			m_b4.EnableWindow(TRUE);
		if (pDoc->player2->num5 != 0)
			m_b5.EnableWindow(TRUE);
		if (pDoc->player2->num6 != 0)
			m_b6.EnableWindow(TRUE);
	}
	else if ((id == 3)) {
		if (pDoc->player3->num1 != 0)
			m_b1.EnableWindow(TRUE);
		if (pDoc->player3->num2 != 0)
			m_b2.EnableWindow(TRUE);
		if (pDoc->player3->num3 != 0)
			m_b3.EnableWindow(TRUE);
		if (pDoc->player3->num4 != 0)
			m_b4.EnableWindow(TRUE);
		if (pDoc->player3->num5 != 0)
			m_b5.EnableWindow(TRUE);
		if (pDoc->player3->num6 != 0)
			m_b6.EnableWindow(TRUE);
	}
	else if ((id == 4)) {
		if (pDoc->player4->num1 != 0)
			m_b1.EnableWindow(TRUE);
		if (pDoc->player4->num2 != 0)
			m_b2.EnableWindow(TRUE);
		if (pDoc->player4->num3 != 0)
			m_b3.EnableWindow(TRUE);
		if (pDoc->player4->num4 != 0)
			m_b4.EnableWindow(TRUE);
		if (pDoc->player4->num5 != 0)
			m_b5.EnableWindow(TRUE);
		if (pDoc->player4->num6 != 0)
			m_b6.EnableWindow(TRUE);
	}
	else if ((id == 5)) {
		if (pDoc->player5->num1 != 0)
			m_b1.EnableWindow(TRUE);
		if (pDoc->player5->num2 != 0)
			m_b2.EnableWindow(TRUE);
		if (pDoc->player5->num3 != 0)
			m_b3.EnableWindow(TRUE);
		if (pDoc->player5->num4 != 0)
			m_b4.EnableWindow(TRUE);
		if (pDoc->player5->num5 != 0)
			m_b5.EnableWindow(TRUE);
		if (pDoc->player5->num6 != 0)
			m_b6.EnableWindow(TRUE);
	}

	m_br.EnableWindow(FALSE);
	m_b = TRUE;
}


void CDiceDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.

	if (id == 1) {
		memDC.SelectObject(&rdq);
		m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
	}
	else if (id == 2) {
		memDC.SelectObject(&wdq);
		m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
	}
	else if (id == 3) {
		memDC.SelectObject(&gdq);
		m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
	}
	else if (id == 4) {
		memDC.SelectObject(&bdq);
		m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
	}
	else if (id == 5) {
		memDC.SelectObject(&kdq);
		m_pic1.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic2.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic3.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic4.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic5.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic6.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic7.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
		m_pic8.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
	}
}
	


