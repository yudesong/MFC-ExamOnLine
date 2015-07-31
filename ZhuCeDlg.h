#if !defined(AFX_ZHUCEDLG_H__85E594CA_DC49_4B79_BF69_0EF2AC421DD0__INCLUDED_)
#define AFX_ZHUCEDLG_H__85E594CA_DC49_4B79_BF69_0EF2AC421DD0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ZhuCeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CZhuCeDlg dialog

class CZhuCeDlg : public CDialog
{
// Construction
public:
	CZhuCeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CZhuCeDlg)
	enum { IDD = IDD_DIALOG9 };
	CComboBox	m_question;
	CComboBox	m_age;
	CString	m_name;
	CString	m_passwd;
	CString	m_passwd1;
	CString	m_answer;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CZhuCeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CZhuCeDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZHUCEDLG_H__85E594CA_DC49_4B79_BF69_0EF2AC421DD0__INCLUDED_)
