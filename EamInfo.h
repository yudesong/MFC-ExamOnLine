#if !defined(AFX_EAMINFO_H__7C1EF456_97B8_47B9_809A_FCDA99B221B0__INCLUDED_)
#define AFX_EAMINFO_H__7C1EF456_97B8_47B9_809A_FCDA99B221B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EamInfo.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEamInfo dialog

class CEamInfo : public CDialog
{
// Construction
public:
	CEamInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEamInfo)
	enum { IDD = IDD_DIALOG3 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEamInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEamInfo)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EAMINFO_H__7C1EF456_97B8_47B9_809A_FCDA99B221B0__INCLUDED_)
