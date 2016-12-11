#pragma once
#include "afxwin.h"


// CMenuDlg 대화 상자입니다.
class CLasVegasMFCDoc;

class CMenuDlg : public CDialog
{
	DECLARE_DYNAMIC(CMenuDlg)

public:
	CMenuDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMenuDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MENU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
