#pragma once


// CPNameDlg ��ȭ �����Դϴ�.

class CPNameDlg : public CDialog
{
	DECLARE_DYNAMIC(CPNameDlg)

public:
	CPNameDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CPNameDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PNAMEDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_str1;
	CString m_str2;
	CString m_str3;
	CString m_str4;
	CString m_str5;
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
};
