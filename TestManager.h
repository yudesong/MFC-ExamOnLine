#if !defined(AFX_TESTMANAGER_H__A453DCC2_9F06_4598_B185_34CEEEA2770C__INCLUDED_)
#define AFX_TESTMANAGER_H__A453DCC2_9F06_4598_B185_34CEEEA2770C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestManager.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTestManager dialog

class CTestManager : public CDialog
{
// Construction
public:
	void insertSubject();
	CTestManager(CWnd* pParent = NULL);   // standard constructor
	void insertItem();
// Dialog Data
	//{{AFX_DATA(CTestManager)
	enum { IDD = IDD_DIALOG13 };
	CComboBox	m_subject;
	CEdit	m_testid;
	CListCtrl	m_testlist;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestManager)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTestManager)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTMANAGER_H__A453DCC2_9F06_4598_B185_34CEEEA2770C__INCLUDED_)
