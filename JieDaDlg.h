#if !defined(AFX_JIEDADLG_H__E6951191_5740_41EE_ADAB_43EB6EF7FF55__INCLUDED_)
#define AFX_JIEDADLG_H__E6951191_5740_41EE_ADAB_43EB6EF7FF55__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// JieDaDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// JieDaDlg dialog

class JieDaDlg : public CDialog
{
// Construction
public:
	int i;
	CString subject;



	JieDaDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(JieDaDlg)
	enum { IDD = IDD_DIALOG8 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(JieDaDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(JieDaDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JIEDADLG_H__E6951191_5740_41EE_ADAB_43EB6EF7FF55__INCLUDED_)
