// MenuDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LasVegasMFC.h"
#include "MenuDlg.h"
#include "afxdialogex.h"
#include "PNameDlg.h"
#include "LasVegasMFCDoc.h"
#include "Player.h"
#include "Casino.h"
#include "Bill.h"

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
	static TCHAR BASED_CODE szFilter[] = _T("LasVegas Save (*.lvs)|*.lvs|")_T("All Files (*.*)|*.*||");
	CFileDialog dlg(TRUE, _T("lvs"), _T("LasVegas Save"), OFN_HIDEREADONLY, szFilter);
	if (IDOK == dlg.DoModal())
	{
		CString strPathName = dlg.GetPathName();
		CFile fp;
		CFileException e;
		if (!fp.Open(strPathName, CFile::modeRead, &e)) {
			e.ReportError();
			return;
		}

		CArchive ar(&fp, CArchive::load);
		
		ar >> pDoc->round;

		pDoc->player1->Serialize(ar);
		pDoc->player2->Serialize(ar);
		pDoc->player3->Serialize(ar);
		pDoc->player4->Serialize(ar);
		pDoc->player5->Serialize(ar);

		pDoc->casino1->Serialize(ar);
		pDoc->casino2->Serialize(ar);
		pDoc->casino3->Serialize(ar);
		pDoc->casino4->Serialize(ar);
		pDoc->casino5->Serialize(ar);
		pDoc->casino6->Serialize(ar);

		pDoc->billDeck->Serialize(ar);
	}
}


void CMenuDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	static TCHAR BASED_CODE szFilter[] = _T("LasVegas Save (*.lvs)|*.lvs|")_T("All Files (*.*)|*.*||");
	CFileDialog dlg(FALSE, _T("lvs"), _T("LasVegas Save"), OFN_HIDEREADONLY, szFilter);
	if (IDOK == dlg.DoModal())
	{
		CString strPathName = dlg.GetPathName();

		CFile fp;
		CFileException e;
		if (!fp.Open(strPathName, CFile::modeWrite | CFile::modeCreate, &e)) {
			e.ReportError();
			return;
		}

		CArchive ar(&fp, CArchive::store);

		if (pDoc->round == 0) {
			pDoc->round = 4;
		}
		else {
			pDoc->round = pDoc->round - 1;
		}

		ar << (pDoc->round);

		pDoc->player1->Serialize(ar);
		pDoc->player2->Serialize(ar);
		pDoc->player3->Serialize(ar);
		pDoc->player4->Serialize(ar);
		pDoc->player5->Serialize(ar);

		pDoc->casino1->Serialize(ar);
		pDoc->casino2->Serialize(ar);
		pDoc->casino3->Serialize(ar);
		pDoc->casino4->Serialize(ar);
		pDoc->casino5->Serialize(ar);
		pDoc->casino6->Serialize(ar);

		pDoc->billDeck->Serialize(ar);
	}
}


void CMenuDlg::OnBnClickedExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	exit(0);
}


void CMenuDlg::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	
	CPNameDlg dlg;

	dlg.m_str1 = pDoc->player1->name;
	dlg.m_str2 = pDoc->player2->name;
	dlg.m_str3 = pDoc->player3->name;
	dlg.m_str4 = pDoc->player4->name;
	dlg.m_str5 = pDoc->player5->name;
	
	if (IDOK == dlg.DoModal()) {
		pDoc->player1->name = dlg.m_str1;
		pDoc->player2->name = dlg.m_str2;
		pDoc->player3->name = dlg.m_str3;
		pDoc->player4->name = dlg.m_str4;
		pDoc->player5->name = dlg.m_str5;
	}

	CDialog::OnOK();
}
