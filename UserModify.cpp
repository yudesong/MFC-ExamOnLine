// UserModify.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "UserModify.h"
#include "ADOConn.h"
#include "UserManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserModify dialog


CUserModify::CUserModify(CWnd* pParent /*=NULL*/)
	: CDialog(CUserModify::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserModify)
	//}}AFX_DATA_INIT
}


void CUserModify::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserModify)
	DDX_Control(pDX, IDC_COMBO3, m_question);
	DDX_Control(pDX, IDC_COMBO2, m_age);
	DDX_Control(pDX, IDC_EDIT4, m_answer);
	DDX_Control(pDX, IDC_EDIT2, m_passwd);
	DDX_Control(pDX, IDC_EDIT1, m_name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserModify, CDialog)
	//{{AFX_MSG_MAP(CUserModify)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserModify message handlers

BOOL CUserModify::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	CString sql;
	sql.Format("select * from tb_user where username='%s'",name);
	ADOConn m_ado;
	m_ado.OnInitADOConn();
	_RecordsetPtr m_pRs;
	m_pRs=m_ado.GetRecordSet((_bstr_t)sql);
	while(!m_pRs->adoEOF)
	{
	m_name.SetWindowText((char *)(_bstr_t)m_pRs->GetCollect("username"));
	m_passwd.SetWindowText((char *)(_bstr_t)m_pRs->GetCollect("passwd"));
	CString age,question;
	age=(char *)(_bstr_t)m_pRs->GetCollect("age");
	m_age.SetCurSel(atoi(age)%10);
	question=(char *)(_bstr_t)m_pRs->GetCollect("question");
	if(question="我的QQ号码是多少？") m_question.SetCurSel(0);
	if(question="我是哪里人？") m_question.SetCurSel(1);
	if(question="我喜欢谁？") m_question.SetCurSel(2);
	if(question="我在哪里上学？") m_question.SetCurSel(3);
	m_answer.SetWindowText((char *)(_bstr_t)m_pRs->GetCollect("answer"));
	//	m_age=atoi((char *)(_bstr_t)m_pRs->GetCollect("age"));
	CString sex=(char *)(_bstr_t)m_pRs->GetCollect("sex");
	if(sex=="男") 
	{
		((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(1);
	
	}
	else
	{
		((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(1);
	}
	

	m_pRs->MoveNext();
	}

	m_ado.ExitConn();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CUserModify::OnOK() 
{

	
	CString sql;
	CString name,passwd,sex,question,answer,age;

	CButton *man=(CButton *)GetDlgItem(IDC_RADIO1);
	CButton *woman=(CButton *)GetDlgItem(IDC_RADIO2);

	m_name.GetWindowText(name);
	m_passwd.GetWindowText(passwd);
	if(man->GetCheck()==1) sex="男";
	if(woman->GetCheck()==1) sex="女";
	int i,j;
	i=m_age.GetCurSel();
	j=m_question.GetCurSel();
	m_age.GetLBText(i,age);
	m_question.GetLBText(j,question);
	m_answer.GetWindowText(answer);
	sql.Format("update tb_user set username='%s',passwd='%s',age=%d,sex='%s',question='%s',answer='%s'",name,passwd,atoi(age),sex,question,answer);	
	ADOConn m_ado;
	m_ado.OnInitADOConn();
	if(m_ado.ExecuteSQL((_bstr_t)sql))
	{
	//	MessageBox("修改成功！");
		CUserModify::OnCancel();
	}
	
	CDialog::OnOK();
}
