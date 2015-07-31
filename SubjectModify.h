#if !defined(AFX_SUBJECTMODIFY_H__B4FE70B2_78D0_4016_A471_60BE7E71F8B0__INCLUDED_)
#define AFX_SUBJECTMODIFY_H__B4FE70B2_78D0_4016_A471_60BE7E71F8B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubjectModify.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSubjectModify dialog

class CSubjectModify : public CDialog
{
// Construction
public:
	CString subject;
	CString id;
	CSubjectModify(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSubjectModify)
	enum { IDD = IDD_SUBJECTMODIFY_DIALOG };
	CEdit	m_subect;
	CEdit	m_subjectid;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubjectModify)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSubjectModify)
	afx_msg void OnButton1();
	virtual BOOL OnInitDialog();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBJECTMODIFY_H__B4FE70B2_78D0_4016_A471_60BE7E71F8B0__INCLUDED_)
