#pragma once
#include "afxwin.h"


// CMenuDlg ��ȭ �����Դϴ�.
class CLasVegasMFCDoc;

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
	CLasVegasMFCDoc * pDoc;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedExit();
	virtual void OnOK();
	afx_msg void OnBnClickedButton5();
	CButton m_startbutton;
	afx_msg void OnBnClickedStart();
	CButton m_save;
	CButton m_continue;
	afx_msg void OnBnClickedContinue();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
};
