
// LasVegasMFC.h : main header file for the LasVegasMFC application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CLasVegasMFCApp:
// See LasVegasMFC.cpp for the implementation of this class
//

class CLasVegasMFCApp : public CWinApp
{
public:
	CLasVegasMFCApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CLasVegasMFCApp theApp;
