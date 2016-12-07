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
	BOOL m_n;
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
	CStatic m_pic1;
	CStatic m_pic2;
	CStatic m_pic3;
	CStatic m_pic4;
	CStatic m_pic5;
	CStatic m_pic6;
	CStatic m_pic7;
	CStatic m_pic8;

	CDC memDC;
	
	CRect rect;
	
	CBitmap rd1;
	CBitmap rd2;
	CBitmap rd3;
	CBitmap rd4;
	CBitmap rd5;
	CBitmap rd6;
	CBitmap rdq;
	
	CBitmap wd1;
	CBitmap wd2;
	CBitmap wd3;
	CBitmap wd4;
	CBitmap wd5;
	CBitmap wd6;
	CBitmap wdq;

	CBitmap gd1;
	CBitmap gd2;
	CBitmap gd3;
	CBitmap gd4;
	CBitmap gd5;
	CBitmap gd6;
	CBitmap gdq;

	CBitmap bd1;
	CBitmap bd2;
	CBitmap bd3;
	CBitmap bd4;
	CBitmap bd5;
	CBitmap bd6;
	CBitmap bdq;

	CBitmap kd1;
	CBitmap kd2;
	CBitmap kd3;
	CBitmap kd4;
	CBitmap kd5;
	CBitmap kd6;
	CBitmap kdq;

	BITMAP bmpinfo;
	
	afx_msg void OnPaint();
};
