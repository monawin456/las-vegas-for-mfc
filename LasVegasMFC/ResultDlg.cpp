// ResultDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LasVegasMFC.h"
#include "ResultDlg.h"
#include "afxdialogex.h"
#include "Player.h"
#include "LasVegasMFCDoc.h"

// CResultDlg 대화 상자입니다.

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
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CResultDlg 메시지 처리기입니다.


BOOL CResultDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	Player * result[5];
	result[0] = pDoc->player1;
	result[1] = pDoc->player2;
	result[2] = pDoc->player3;
	result[3] = pDoc->player4;
	result[4] = pDoc->player5;
	Player * tmp;
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 5; j++)
		{
			if (result[i]->GetMoney() < result[j]->GetMoney())
			{
				tmp = result[j];
				result[j] = result[i];
				result[i] = tmp;
			}
		}
	m_str1.Format(_T("(1) %s	$ %d"), result[0]->name, result[0]->GetMoney());
	m_str2.Format(_T("(2) %s	$ %d"), result[1]->name, result[1]->GetMoney());
	m_str3.Format(_T("(3) %s	$ %d"), result[2]->name, result[2]->GetMoney());
	m_str4.Format(_T("(4) %s	$ %d"), result[3]->name, result[3]->GetMoney());
	m_str5.Format(_T("(5) %s	$ %d"), result[4]->name, result[4]->GetMoney());

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL CResultDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: Add your message handler code here and/or call default
	if (nHitTest == HTCLIENT) {
		::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
	}
	return TRUE;

	//return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
