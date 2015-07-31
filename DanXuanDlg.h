#if !defined(AFX_DANXUANDLG_H__80ECEA86_3815_4CD2_BBD9_E9DB14E0A77B__INCLUDED_)
#define AFX_DANXUANDLG_H__80ECEA86_3815_4CD2_BBD9_E9DB14E0A77B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DanXuanDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DanXuanDlg dialog

class DanXuanDlg : public CDialog
{
// Construction
public:
	void updateExamInfo(int i);
	bool exText(int i);
	void clearAnswer();
	int i;
	CString answer;
	CString subject;
	DanXuanDlg(CWnd* pParent = NULL);   // standard constructor
	CString question,answera,answerb,answerc,answerd,rightanswer;
	void showTest(int i);
	bool insertExamInfo(int i);
	void showPerTest(int i);
// Dialog Data
	//{{AFX_DATA(DanXuanDlg)
	enum { IDD = IDD_DIALOG6 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DanXuanDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DanXuanDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton2();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnRadio4();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DANXUANDLG_H__80ECEA86_3815_4CD2_BBD9_E9DB14E0A77B__INCLUDED_)
