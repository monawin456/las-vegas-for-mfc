#pragma once
#include "afxwin.h"


// CDiceDlg ��ȭ �����Դϴ�.
class CLasVegasMFCDoc;

class CDiceDlg : public CDialog
{
	DECLARE_DYNAMIC(CDiceDlg)

public:
	CDiceDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDiceDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DICEDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
