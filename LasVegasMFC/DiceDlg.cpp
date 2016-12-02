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
}


BEGIN_MESSAGE_MAP(CDiceDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON2, &CDiceDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CDiceDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CDiceDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDiceDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CDiceDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CDiceDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CDiceDlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// CDiceDlg 메시지 처리기입니다.


void CDiceDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_b) {
		num = 2;
		EndDialog(IDCLOSE);
	}
}


void CDiceDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_b) {
		num = 1;
		EndDialog(IDCLOSE);
	}
}


void CDiceDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_b) {
		num = 3;
		EndDialog(IDCLOSE);
	}
}


void CDiceDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_b) {
		num = 4;
		EndDialog(IDCLOSE);
	}
}


void CDiceDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_b) {
		num = 5;
		EndDialog(IDCLOSE);
	}
}


void CDiceDlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_b) {
		num = 6;
		EndDialog(IDCLOSE);
	}
}


BOOL CDiceDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_b = FALSE;
	m_str.SetWindowText(name);
	/*CString str;
	pDoc -> player1 -> Rolling();
	pDoc -> player1 -> GetDice(str);
	m_str2.SetWindowText(str);
	*/
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDiceDlg::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_b = TRUE;
	if (id == 1)
	{
		pDoc->player1->Rolling();
		for (int i = 0; i < 8; i++)
			dice[i] = pDoc->player1->GetDice(i);
	}
	else if (id == 2)
	{
		pDoc->player2->Rolling();
		for (int i = 0; i < 8; i++)
			dice[i] = pDoc->player2->GetDice(i);
	}
	else if (id == 2)
	{
		pDoc->player3->Rolling();
		for (int i = 0; i < 8; i++)
			dice[i] = pDoc->player3->GetDice(i);
	}
	else if (id == 2)
	{
		pDoc->player4->Rolling();
		for (int i = 0; i < 8; i++)
			dice[i] = pDoc->player4->GetDice(i);
	}
	else if (id == 5)
	{
		pDoc->player5->Rolling();
		for (int i = 0; i < 8; i++)
			dice[i] = pDoc->player5->GetDice(i);
	}


}
