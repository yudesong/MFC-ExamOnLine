#if !defined(AFX_SUBJECTMANAGER_H__8AC1C495_96E5_4657_ABC4_9A2BF7B4739B__INCLUDED_)
#define AFX_SUBJECTMANAGER_H__8AC1C495_96E5_4657_ABC4_9A2BF7B4739B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubjectManager.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSubjectManager dialog

class CSubjectManager : public CDialog
{
// Construction
public:
	void insertItem();
	CSubjectManager(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSubjectManager)
	enum { IDD = IDD_DIALOG12 };
	CEdit	m_subject;
	CListCtrl	m_subjectlist;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubjectManager)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSubjectManager)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBJECTMANAGER_H__8AC1C495_96E5_4657_ABC4_9A2BF7B4739B__INCLUDED_)
