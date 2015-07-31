#if !defined(AFX_CHOCESUBJECT_H__069285E1_AF9C_4882_B833_F4C2D6C18E72__INCLUDED_)
#define AFX_CHOCESUBJECT_H__069285E1_AF9C_4882_B833_F4C2D6C18E72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChoceSubject.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChoceSubject dialog

class CChoceSubject : public CDialog
{
// Construction
public:
	CChoceSubject(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChoceSubject)
	enum { IDD = IDD_DIALOG1 };
	CComboBox	m_sub;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChoceSubject)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChoceSubject)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHOCESUBJECT_H__069285E1_AF9C_4882_B833_F4C2D6C18E72__INCLUDED_)
