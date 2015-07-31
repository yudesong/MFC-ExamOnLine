// ExamOnlineDlg.h : header file
//

#if !defined(AFX_EXAMONLINEDLG_H__2CF8CC9D_2A2E_476C_BBA6_E9F1BC6CA06F__INCLUDED_)
#define AFX_EXAMONLINEDLG_H__2CF8CC9D_2A2E_476C_BBA6_E9F1BC6CA06F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CExamOnlineDlg dialog

class CExamOnlineDlg : public CDialog
{
// Construction
public:
	CExamOnlineDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CExamOnlineDlg)
	enum { IDD = IDD_EXAMONLINE_DIALOG };
	CComboBox	m_sel;
	CString	m_name;
	CString	m_passwd;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExamOnlineDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CExamOnlineDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnMenuitem32772();
	afx_msg void OnMenuitem32773();
	afx_msg void OnMenuitem32774();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXAMONLINEDLG_H__2CF8CC9D_2A2E_476C_BBA6_E9F1BC6CA06F__INCLUDED_)
