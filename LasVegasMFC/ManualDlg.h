#pragma once
#include "afxwin.h"


// CManualDlg dialog

class CManualDlg : public CDialog
{
	DECLARE_DYNAMIC(CManualDlg)

public:
	CManualDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CManualDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MANUALDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_pic;
	CButton m_left;
	CButton m_right;
	int page;
	afx_msg void OnPaint();
	afx_msg void OnBnClickedManualLeftbutton();
	afx_msg void OnBnClickedManualRightbutton();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	CString m_str;
};
