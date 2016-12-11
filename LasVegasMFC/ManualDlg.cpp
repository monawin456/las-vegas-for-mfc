// ManualDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LasVegasMFC.h"
#include "ManualDlg.h"
#include "afxdialogex.h"


// CManualDlg dialog

IMPLEMENT_DYNAMIC(CManualDlg, CDialog)

CManualDlg::CManualDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MANUALDLG, pParent)
	, m_str(_T("1 page"))
{
	page = 0;
}

CManualDlg::~CManualDlg()
{
}

void CManualDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MANUAL_PIC, m_pic);
	DDX_Control(pDX, IDC_MANUAL_LEFTBUTTON, m_left);
	DDX_Control(pDX, IDC_MANUAL_RIGHTBUTTON, m_right);
	DDX_Text(pDX, IDC_MANUAL_STR, m_str);
}


BEGIN_MESSAGE_MAP(CManualDlg, CDialog)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_MANUAL_LEFTBUTTON, &CManualDlg::OnBnClickedManualLeftbutton)
	ON_BN_CLICKED(IDC_MANUAL_RIGHTBUTTON, &CManualDlg::OnBnClickedManualRightbutton)
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()


// CManualDlg message handlers


void CManualDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CDialog::OnPaint() for painting messages

	CBitmap manualBmp[8];
	manualBmp[0].LoadBitmap(IDB_MANUAL_1);
	manualBmp[1].LoadBitmap(IDB_MANUAL_2);
	manualBmp[2].LoadBitmap(IDB_MANUAL_3);
	manualBmp[3].LoadBitmap(IDB_MANUAL_4);
	manualBmp[4].LoadBitmap(IDB_MANUAL_5);
	manualBmp[5].LoadBitmap(IDB_MANUAL_6);
	manualBmp[6].LoadBitmap(IDB_MANUAL_7);
	manualBmp[7].LoadBitmap(IDB_MANUAL_8);

	CRect rect;
	m_pic.GetClientRect(&rect);

	CDC mem;
	mem.CreateCompatibleDC(m_pic.GetWindowDC());

	BITMAP manualBmpInfo;

	if (page == 0) {
		mem.SelectObject(&manualBmp[page]);
		manualBmp[page].GetBitmap(&manualBmpInfo);
		m_pic.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &mem, 0, 0, manualBmpInfo.bmWidth, manualBmpInfo.bmHeight, SRCCOPY);
	}
	else if (page == 1) {
		mem.SelectObject(&manualBmp[page]);
		manualBmp[page].GetBitmap(&manualBmpInfo);
		m_pic.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &mem, 0, 0, manualBmpInfo.bmWidth, manualBmpInfo.bmHeight, SRCCOPY);
	}
	else if (page == 2) {
		mem.SelectObject(&manualBmp[page]);
		manualBmp[page].GetBitmap(&manualBmpInfo);
		m_pic.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &mem, 0, 0, manualBmpInfo.bmWidth, manualBmpInfo.bmHeight, SRCCOPY);
	}
	else if (page == 3) {
		mem.SelectObject(&manualBmp[page]);
		manualBmp[page].GetBitmap(&manualBmpInfo);
		m_pic.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &mem, 0, 0, manualBmpInfo.bmWidth, manualBmpInfo.bmHeight, SRCCOPY);
	}
	else if (page == 4) {
		mem.SelectObject(&manualBmp[page]);
		manualBmp[page].GetBitmap(&manualBmpInfo);
		m_pic.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &mem, 0, 0, manualBmpInfo.bmWidth, manualBmpInfo.bmHeight, SRCCOPY);
	}
	else if (page == 5) {
		mem.SelectObject(&manualBmp[page]);
		manualBmp[page].GetBitmap(&manualBmpInfo);
		m_pic.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &mem, 0, 0, manualBmpInfo.bmWidth, manualBmpInfo.bmHeight, SRCCOPY);
	}
	else if (page == 6) {
		mem.SelectObject(&manualBmp[page]);
		manualBmp[page].GetBitmap(&manualBmpInfo);
		m_pic.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &mem, 0, 0, manualBmpInfo.bmWidth, manualBmpInfo.bmHeight, SRCCOPY);
	}
	else if (page == 7) {
		mem.SelectObject(&manualBmp[page]);
		manualBmp[page].GetBitmap(&manualBmpInfo);
		m_pic.GetWindowDC()->StretchBlt(0, 0, rect.Width(), rect.Height(), &mem, 0, 0, manualBmpInfo.bmWidth, manualBmpInfo.bmHeight, SRCCOPY);
	}
}


void CManualDlg::OnBnClickedManualLeftbutton()
{
	// TODO: Add your control notification handler code here
	if (page == 0) {
		page = 7;
	}
	else {
		page--;
	}
	m_str.Format(_T("%d page"), page + 1);
	UpdateData(FALSE);
	Invalidate();
}


void CManualDlg::OnBnClickedManualRightbutton()
{
	// TODO: Add your control notification handler code here
	if (page == 7) {
		page = 0;
	}
	else {
		page++;
	}
	m_str.Format(_T("%d page"), page + 1);
	UpdateData(FALSE);
	Invalidate();
}


BOOL CManualDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: Add your message handler code here and/or call default
	if (nHitTest == HTCLIENT) {
		::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
	}
	return TRUE;

	//return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
