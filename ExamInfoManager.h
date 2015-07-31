#if !defined(AFX_EXAMINFOMANAGER_H__BC12FF64_1367_4E77_A1C3_AA901274A41C__INCLUDED_)
#define AFX_EXAMINFOMANAGER_H__BC12FF64_1367_4E77_A1C3_AA901274A41C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExamInfoManager.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CExamInfoManager dialog

class CExamInfoManager : public CDialog
{
// Construction
public:
	CExamInfoManager(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CExamInfoManager)
	enum { IDD = IDD_DIALOG14 };
	CListCtrl	m_examinfolist;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExamInfoManager)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExamInfoManager)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXAMINFOMANAGER_H__BC12FF64_1367_4E77_A1C3_AA901274A41C__INCLUDED_)
