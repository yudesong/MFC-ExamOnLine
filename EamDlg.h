#if !defined(AFX_EAMDLG_H__49872554_4367_4556_87E9_CF8643314910__INCLUDED_)
#define AFX_EAMDLG_H__49872554_4367_4556_87E9_CF8643314910__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EamDlg.h : header file
//

#include "DanXuanDlg.h"
#include "DuoXuanDlg.h"
#include "JieDaDlg.h"



/////////////////////////////////////////////////////////////////////////////
// CEamDlg dialog

class CEamDlg : public CDialog
{
// Construction
public:
	bool flag;
	int count;
	int second;
	CString subject;
	CEamDlg(CWnd* pParent = NULL);   // standard constructor
	DanXuanDlg *danlg;
	DuoXuanDlg *duolg;
	JieDaDlg *jiedlg;
// Dialog Data
	//{{AFX_DATA(CEamDlg)
	enum { IDD = IDD_DIALOG2 };
	CStatic	m_second;
	CStatic	m_time;
	CTabCtrl	m_title;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEamDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEamDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton1();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButton4();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EAMDLG_H__49872554_4367_4556_87E9_CF8643314910__INCLUDED_)
