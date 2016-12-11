#pragma once


// CResultDlg 대화 상자입니다.
class CLasVegasMFCDoc;
class CResultDlg : public CDialog
{
	DECLARE_DYNAMIC(CResultDlg)

public:
	CResultDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CResultDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RESULT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CLasVegasMFCDoc * pDoc;
	CString m_str1;
	CString m_str2;
	CString m_str3;
	CString m_str4;
	CString m_str5;
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
};
