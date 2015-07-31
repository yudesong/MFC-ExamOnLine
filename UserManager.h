#if !defined(AFX_USERMANAGER_H__583E5E89_D599_4230_BFFE_118529D623A7__INCLUDED_)
#define AFX_USERMANAGER_H__583E5E89_D599_4230_BFFE_118529D623A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserManager.h : header file
//


/////////////////////////////////////////////////////////////////////////////
// CUserManager dialog

class CUserManager : public CDialog
{
// Construction
public:
	void insertItem();
	CUserManager(CWnd* pParent = NULL);   // standard constructor


// Dialog Data
	//{{AFX_DATA(CUserManager)
	enum { IDD = IDD_DIALOG11 };
	CListCtrl	m_userlist;
	CString	m_finduser;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserManager)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserManager)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERMANAGER_H__583E5E89_D599_4230_BFFE_118529D623A7__INCLUDED_)
