// ExamOnline.h : main header file for the EXAMONLINE application
//

#if !defined(AFX_EXAMONLINE_H__811DB41A_BF9B_4A2A_AD8F_94D31FAB70BC__INCLUDED_)
#define AFX_EXAMONLINE_H__811DB41A_BF9B_4A2A_AD8F_94D31FAB70BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CExamOnlineApp:
// See ExamOnline.cpp for the implementation of this class
//

class CExamOnlineApp : public CWinApp
{
public:
	CExamOnlineApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExamOnlineApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CExamOnlineApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXAMONLINE_H__811DB41A_BF9B_4A2A_AD8F_94D31FAB70BC__INCLUDED_)
