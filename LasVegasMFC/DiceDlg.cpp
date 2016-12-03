// DiceDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "LasVegasMFC.h"
#include "DiceDlg.h"
#include "afxdialogex.h"
#include "Player.h"
#include "LasVegasMFCDoc.h"

// CDiceDlg ��ȭ �����Դϴ�.

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


// CDiceDlg �޽��� ó�����Դϴ�.


void CDiceDlg::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_b) {
		num = 2;
		if (id == 1) {
			pDoc->player1->Selection(num, pDoc->casino2);
		}
		else if (id == 2) {
			pDoc->player2->Selection(num, pDoc->casino2);
		}
		else if (id == 3) {
			pDoc->player3->Selection(num, pDoc->casino2);
		}
		else if (id == 4) {
			pDoc->player4->Selection(num, pDoc->casino2);
		}
		else if (id == 5) {
			pDoc->player5->Selection(num, pDoc->casino2);
		}
		EndDialog(IDCLOSE);
	}
}


void CDiceDlg::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_b) {
		num = 1;
		if (id == 1) {
			pDoc->player1->Selection(num, pDoc->casino1);
		}
		else if (id == 2) {
			pDoc->player2->Selection(num, pDoc->casino1);
		}
		else if (id == 3) {
			pDoc->player3->Selection(num, pDoc->casino1);
		}
		else if (id == 4) {
			pDoc->player4->Selection(num, pDoc->casino1);
		}
		else if (id == 5) {
			pDoc->player5->Selection(num, pDoc->casino1);
		}
		EndDialog(IDCLOSE);
	}
}


void CDiceDlg::OnBnClickedButton3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_b) {
		num = 3;
		if (id == 1) {
			pDoc->player1->Selection(num, pDoc->casino3);
		}
		else if (id == 2) {
			pDoc->player2->Selection(num, pDoc->casino3);
		}
		else if (id == 3) {
			pDoc->player3->Selection(num, pDoc->casino3);
		}
		else if (id == 4) {
			pDoc->player4->Selection(num, pDoc->casino3);
		}
		else if (id == 5) {
			pDoc->player5->Selection(num, pDoc->casino3);
		}
		EndDialog(IDCLOSE);
	}
}


void CDiceDlg::OnBnClickedButton4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_b) {
		num = 4;
		if (id == 1) {
			pDoc->player1->Selection(num, pDoc->casino4);
		}
		else if (id == 2) {
			pDoc->player2->Selection(num, pDoc->casino4);
		}
		else if (id == 3) {
			pDoc->player3->Selection(num, pDoc->casino4);
		}
		else if (id == 4) {
			pDoc->player4->Selection(num, pDoc->casino4);
		}
		else if (id == 5) {
			pDoc->player5->Selection(num, pDoc->casino4);
		}
		EndDialog(IDCLOSE);
	}
}


void CDiceDlg::OnBnClickedButton5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_b) {
		num = 5;
		if (id == 1) {
			pDoc->player1->Selection(num, pDoc->casino5);
		}
		else if (id == 2) {
			pDoc->player2->Selection(num, pDoc->casino5);
		}
		else if (id == 3) {
			pDoc->player3->Selection(num, pDoc->casino5);
		}
		else if (id == 4) {
			pDoc->player4->Selection(num, pDoc->casino5);
		}
		else if (id == 5) {
			pDoc->player5->Selection(num, pDoc->casino5);
		}
		EndDialog(IDCLOSE);
	}
}


void CDiceDlg::OnBnClickedButton6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_b) {
		num = 6;
		if (id == 1) {
			pDoc->player1->Selection(num, pDoc->casino6);
		}
		else if (id == 2) {
			pDoc->player2->Selection(num, pDoc->casino6);
		}
		else if (id == 3) {
			pDoc->player3->Selection(num, pDoc->casino6);
		}
		else if (id == 4) {
			pDoc->player4->Selection(num, pDoc->casino6);
		}
		else if (id == 5) {
			pDoc->player5->Selection(num, pDoc->casino6);
		}
		EndDialog(IDCLOSE);
	}
}


BOOL CDiceDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_b = FALSE;
	m_str.SetWindowText(name);
	/*CString str;
	pDoc -> player1 -> Rolling();
	pDoc -> player1 -> GetDice(str);
	m_str2.SetWindowText(str);
	*/
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CDiceDlg::OnBnClickedButton7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if ((id == 1) && (m_b == FALSE))
	{
		pDoc->player1->Rolling();
		for (int i = 0; i < 8; i++)
			dice[i] = pDoc->player1->GetDice(i);
	}
	else if ((id == 2) && (m_b == FALSE))
	{
		pDoc->player2->Rolling();
		for (int i = 0; i < 8; i++)
			dice[i] = pDoc->player2->GetDice(i);
	}
	else if ((id == 3) && (m_b == FALSE))
	{
		pDoc->player3->Rolling();
		for (int i = 0; i < 8; i++)
			dice[i] = pDoc->player3->GetDice(i);
	}
	else if ((id == 4) && (m_b == FALSE))
	{
		pDoc->player4->Rolling();
		for (int i = 0; i < 8; i++)
			dice[i] = pDoc->player4->GetDice(i);
	}
	else if ((id == 5) && (m_b == FALSE))
	{
		pDoc->player5->Rolling();
		for (int i = 0; i < 8; i++)
			dice[i] = pDoc->player5->GetDice(i);
	}
	m_b = TRUE;
}
