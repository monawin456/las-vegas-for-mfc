#pragma once
#include "afxwin.h"


// CDiceDlg 대화 상자입니다.
class CLasVegasMFCDoc;

class CDiceDlg : public CDialog
{
	DECLARE_DYNAMIC(CDiceDlg)

public:
	CDiceDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CDiceDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DICEDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int num;
	CString name;
	CLasVegasMFCDoc * pDoc;
	BOOL m_b;
	int dice[8];
	int id;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	virtual BOOL OnInitDialog();
	CStatic m_str;
	CStatic m_str2;
	afx_msg void OnBnClickedButton7();
};
