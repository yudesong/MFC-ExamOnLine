#if !defined(AFX_MANAGERDLG_H__A9E5D100_B990_4EB1_9658_690DFFD10581__INCLUDED_)
#define AFX_MANAGERDLG_H__A9E5D100_B990_4EB1_9658_690DFFD10581__INCLUDED_



#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ManagerDlg.h : header file
//

#include "UserManager.h"
#include "SubjectManager.h"
#include "TestManager.h"
#include "ExamInfoManager.h"

/////////////////////////////////////////////////////////////////////////////
// CManagerDlg dialog

class CManagerDlg : public CDialog
{
// Construction
public:
	CManagerDlg(CWnd* pParent = NULL);   // standard constructor
	CUserManager *user_manager;
	CSubjectManager *sub_manager;			
	CTestManager *test_manager;
	CExamInfoManager *examinfo_manager;
 // Dialog Data
	//{{AFX_DATA(CManagerDlg)
	enum { IDD = IDD_DIALOG4 };
	CTabCtrl	m_manager;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManagerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CManagerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGERDLG_H__A9E5D100_B990_4EB1_9658_690DFFD10581__INCLUDED_)
