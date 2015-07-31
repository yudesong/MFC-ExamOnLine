#if !defined(AFX_TESTMODIFY_H__91462EB3_B668_48D4_BD01_47883132368F__INCLUDED_)
#define AFX_TESTMODIFY_H__91462EB3_B668_48D4_BD01_47883132368F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestModify.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTestModify dialog

class CTestModify : public CDialog
{
// Construction
public:
	void insertItem();
	CTestModify(CWnd* pParent = NULL);   // standard constructor
	CString leixing,subject;
	bool boolean;
// Dialog Data
	//{{AFX_DATA(CTestModify)
	enum { IDD = IDD_TESTMODIFY_DIALOG };
	CComboBox	m_leixing;
	CComboBox	m_subject;
	CString	m_question;
	CString	m_answera;
	CString	m_answerb;
	CString	m_answerc;
	CString	m_answerd;
	CString	m_rightanswer;
	CString	m_score;
	CString	m_id;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestModify)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTestModify)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnOk2();
	afx_msg void OnUpdate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTMODIFY_H__91462EB3_B668_48D4_BD01_47883132368F__INCLUDED_)
