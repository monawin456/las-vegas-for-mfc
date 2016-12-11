// ResultDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "LasVegasMFC.h"
#include "ResultDlg.h"
#include "afxdialogex.h"
#include "Player.h"
#include "LasVegasMFCDoc.h"

// CResultDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CResultDlg, CDialog)

CResultDlg::CResultDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_RESULT, pParent)
	, m_str1(_T(""))
	, m_str2(_T(""))
	, m_str3(_T(""))
	, m_str4(_T(""))
	, m_str5(_T(""))
{

}

CResultDlg::~CResultDlg()
{
}

void CResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STR1, m_str1);
	DDX_Text(pDX, IDC_STR2, m_str2);
	DDX_Text(pDX, IDC_STR3, m_str3);
	DDX_Text(pDX, IDC_STR4, m_str4);
	DDX_Text(pDX, IDC_STR5, m_str5);
}


BEGIN_MESSAGE_MAP(CResultDlg, CDialog)
END_MESSAGE_MAP()


// CResultDlg �޽��� ó�����Դϴ�.


BOOL CResultDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	Player * result[5];
	result[0] = pDoc->player1;
	result[1] = pDoc->player2;
	result[2] = pDoc->player3;
	result[3] = pDoc->player4;
	result[4] = pDoc->player5;
	Player * tmp;
	for(int i = 0; i < 5; i++)
		if (result[i] -> GetMoney() > result[i + 1] -> GetMoney())
		{
			tmp = result[i+1];
			result[i + 1] = result[i];
			result[i] = tmp;
		}
	m_str1.Format(_T("1 : %s	$ %d"), result[0]->name, result[0]->GetMoney());
	m_str2.Format(_T("2 : %s	$ %d"), result[1]->name, result[1]->GetMoney());
	m_str3.Format(_T("3 : %s	$ %d"), result[2]->name, result[2]->GetMoney());
	m_str4.Format(_T("4 : %s	$ %d"), result[3]->name, result[3]->GetMoney());
	m_str5.Format(_T("5 : %s	$ %d"), result[4]->name, result[4]->GetMoney());

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
