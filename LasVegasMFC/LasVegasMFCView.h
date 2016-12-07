
// LasVegasMFCView.h : interface of the CLasVegasMFCView class
//

#pragma once
class CLasVegasMFCDoc;

class Player;
class Casino;
class BillDeck;

class CLasVegasMFCView : public CFormView
{
protected: // create from serialization only
	CLasVegasMFCView();
	DECLARE_DYNCREATE(CLasVegasMFCView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_LASVEGASMFC_FORM };
#endif

// Attributes
public:
	CLasVegasMFCDoc* GetDocument() const;
	BOOL rgnCheck;
	CRgn playerRgn[4];
	CRect playerRect[4];
	CRgn mainPlayerRgn;
	CRect mainPlayerRect;
	CRgn rollingButtonRgn;
	CRect rollingButtonRect;
	CPoint pCasino[6];

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct

// Implementation
public:
	virtual ~CLasVegasMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
	virtual void OnDraw(CDC* /*pDC*/);
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in LasVegasMFCView.cpp
inline CLasVegasMFCDoc* CLasVegasMFCView::GetDocument() const
   { return reinterpret_cast<CLasVegasMFCDoc*>(m_pDocument); }
#endif

