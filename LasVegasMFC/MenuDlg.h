#pragma once
#include "afxwin.h"


// CMenuDlg ��ȭ �����Դϴ�.

class CMenuDlg : public CDialog
{
	DECLARE_DYNAMIC(CMenuDlg)

public:
	CMenuDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMenuDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MENU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_str;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedExit();
};
