// MenuDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LasVegasMFC.h"
#include "MenuDlg.h"
#include "afxdialogex.h"


// CMenuDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMenuDlg, CDialog)

CMenuDlg::CMenuDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MENU, pParent)
{

}

CMenuDlg::~CMenuDlg()
{
}

void CMenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STR, m_str);
}


BEGIN_MESSAGE_MAP(CMenuDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON2, &CMenuDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CMenuDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDEXIT, &CMenuDlg::OnBnClickedExit)
END_MESSAGE_MAP()


// CMenuDlg 메시지 처리기입니다.


BOOL CMenuDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CString str;
	str.Format(_T("LAS VEGAS"));

	CFont font;
	font.CreateFont(1000, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, _T("Georgia"));
	m_str.SetFont(&font);
	m_str.SetWindowText(str);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CMenuDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog dlg(TRUE);
	if (dlg.DoModal() == IDOK)
	{
	}
}


void CMenuDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog dlg(FALSE);
	if (dlg.DoModal() == IDOK)
	{
	}
}


void CMenuDlg::OnBnClickedExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	exit(0);
}
