// SubjectModify.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "SubjectModify.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubjectModify dialog


CSubjectModify::CSubjectModify(CWnd* pParent /*=NULL*/)
	: CDialog(CSubjectModify::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSubjectModify)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSubjectModify::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubjectModify)
	DDX_Control(pDX, IDC_EDIT2, m_subect);
	DDX_Control(pDX, IDC_EDIT1, m_subjectid);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubjectModify, CDialog)
	//{{AFX_MSG_MAP(CSubjectModify)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubjectModify message handlers

//修改科目名称
void CSubjectModify::OnButton1() 
{
	CString subject;
	m_subect.GetWindowText(subject);
	ADOConn m_ado;
	CString sql;
	sql.Format("update tb_subject set subject='%s' where id=%d",subject,atoi(id));
	if(m_ado.ExecuteSQL((_bstr_t)sql))
	{
		m_ado.ExitConn();
		CSubjectModify::OnCancel();
	}else
	{
		m_ado.ExitConn();
		CSubjectModify::OnCancel();
		MessageBox("修改科目失败！");
	}
	CDialog::OnOK();
}

BOOL CSubjectModify::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	/*
	CString m_id;
	m_id.Format("%s",id);
	*/
	m_subjectid.SetWindowText(id);
	m_subect.SetWindowText(subject);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSubjectModify::OnButton2() 
{
	CDialog::OnCancel();	
}
