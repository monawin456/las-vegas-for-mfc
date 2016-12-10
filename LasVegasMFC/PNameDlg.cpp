// PNameDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "LasVegasMFC.h"
#include "PNameDlg.h"
#include "afxdialogex.h"
#include "LasVegasMFCDoc.h"

// CPNameDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CPNameDlg, CDialog)

CPNameDlg::CPNameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_PNAMEDLG, pParent)
	, m_str1(_T(""))
	, m_str2(_T(""))
	, m_str3(_T(""))
	, m_str4(_T(""))
	, m_str5(_T(""))
{

}

CPNameDlg::~CPNameDlg()
{
}

void CPNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str1);
	DDV_MaxChars(pDX, m_str1, 10);
	DDX_Text(pDX, IDC_EDIT3, m_str2);
	DDV_MaxChars(pDX, m_str2, 10);
	DDX_Text(pDX, IDC_EDIT2, m_str3);
	DDV_MaxChars(pDX, m_str3, 10);
	DDX_Text(pDX, IDC_EDIT4, m_str4);
	DDV_MaxChars(pDX, m_str4, 10);
	DDX_Text(pDX, IDC_EDIT5, m_str5);
	DDV_MaxChars(pDX, m_str5, 10);
}


BEGIN_MESSAGE_MAP(CPNameDlg, CDialog)
END_MESSAGE_MAP()


// CPNameDlg 메시지 처리기입니다.
