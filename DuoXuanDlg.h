#if !defined(AFX_DUOXUANDLG_H__4D08C9A9_ED48_4975_A9CC_3762BB960EA7__INCLUDED_)
#define AFX_DUOXUANDLG_H__4D08C9A9_ED48_4975_A9CC_3762BB960EA7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DuoXuanDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DuoXuanDlg dialog

class DuoXuanDlg : public CDialog
{
// Construction
public:
	CString getAnswer();
	bool insertExamInfo(int i);
	void showPerTest(int i);
	void showTest(int i);
	void clearAnswer();
	int i;
	CString answer;
	CString subject;
	CString question,answera,answerb,answerc,answerd,rightanswer;
	void updateExamInfo(int i);
	bool exText(int i);
	DuoXuanDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DuoXuanDlg)
	enum { IDD = IDD_DIALOG7 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DuoXuanDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DuoXuanDlg)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DUOXUANDLG_H__4D08C9A9_ED48_4975_A9CC_3762BB960EA7__INCLUDED_)
