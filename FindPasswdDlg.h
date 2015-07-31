#if !defined(AFX_FINDPASSWDDLG_H__5A6496F2_5A3F_461E_812F_A3A436194C20__INCLUDED_)
#define AFX_FINDPASSWDDLG_H__5A6496F2_5A3F_461E_812F_A3A436194C20__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FindPasswdDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFindPasswdDlg dialog

class CFindPasswdDlg : public CDialog
{
// Construction
public:
	CFindPasswdDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFindPasswdDlg)
	enum { IDD = IDD_DIALOG10 };
	CStatic	m_passwd;
	CStatic	m_msg;
	CStatic	m_question;
	CString	m_name;
	CString	m_answer;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFindPasswdDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFindPasswdDlg)
	virtual void OnOK();
	afx_msg void OnKillfocusEdit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FINDPASSWDDLG_H__5A6496F2_5A3F_461E_812F_A3A436194C20__INCLUDED_)
