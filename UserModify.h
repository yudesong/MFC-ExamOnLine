#if !defined(AFX_USERMODIFY_H__A4CF197D_4241_4371_A4C4_7CA7EBD11F55__INCLUDED_)
#define AFX_USERMODIFY_H__A4CF197D_4241_4371_A4C4_7CA7EBD11F55__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserModify.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserModify dialog

class CUserModify : public CDialog
{
// Construction
public:
	CString name;
	CUserModify(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUserModify)
	enum { IDD = IDD_DIALOG15 };
	CComboBox	m_question;
	CComboBox	m_age;
	CEdit	m_answer;
	CEdit	m_passwd;
	CEdit	m_name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserModify)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserModify)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERMODIFY_H__A4CF197D_4241_4371_A4C4_7CA7EBD11F55__INCLUDED_)
