// FindPasswdDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "FindPasswdDlg.h"
#include "ADOConn.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFindPasswdDlg dialog


CFindPasswdDlg::CFindPasswdDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFindPasswdDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFindPasswdDlg)
	m_name = _T("");
	m_answer = _T("");
	//}}AFX_DATA_INIT
}


void CFindPasswdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFindPasswdDlg)
	DDX_Control(pDX, IDC_STATIC3, m_passwd);
	DDX_Control(pDX, IDC_STATIC2, m_msg);
	DDX_Control(pDX, IDC_STATIC1, m_question);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT3, m_answer);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFindPasswdDlg, CDialog)
	//{{AFX_MSG_MAP(CFindPasswdDlg)
	ON_EN_KILLFOCUS(IDC_EDIT1, OnKillfocusEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFindPasswdDlg message handlers

void CFindPasswdDlg::OnOK() 
{
	
	UpdateData();
	CString sql;
	sql.Format("select answer,passwd from tb_user where username='%s'",m_name);
	ADOConn m_ado;
	m_ado.OnInitADOConn();
	_RecordsetPtr m_pRs;
	m_pRs=m_ado.GetRecordSet((_bstr_t)sql);
	if(!m_pRs->adoEOF)
	{
	CString passwd,answer;
	answer=(char *)(_bstr_t)m_pRs->GetCollect("answer");
	passwd=(char *)(_bstr_t)m_pRs->GetCollect("passwd");
	if(m_answer!=answer) MessageBox("答案错误！");
	else
	{
		(CStatic*)GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
//		(CStatic*)GetDlgItem(IDC_STATIC3)->SetWindowText(passwd);
		m_passwd.SetWindowText(passwd);
		(CStatic*)GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
	}
	m_pRs->MoveNext();
	}
	m_ado.ExitConn();

//	CDialog::OnOK();
}

void CFindPasswdDlg::OnKillfocusEdit1() 
{
	UpdateData();
	if(m_name.IsEmpty())
	{
		MessageBox("用户名不能为空！");
	}else
	{
		CString sql;
		sql.Format("select question from tb_user where username='%s'",m_name);
		ADOConn m_ado;
		m_ado.OnInitADOConn();
		_RecordsetPtr m_pRs;
		m_pRs=m_ado.GetRecordSet((_bstr_t)sql);
//		MessageBox(m_name);
		if(!m_pRs->adoEOF)
		{
			CString question;
			question=(char *)(_bstr_t)m_pRs->GetCollect("question");
//			MessageBox(question);
			m_question.SetWindowText(question);	
		//	m_pRs->MoveNext();
		}else
		{
		MessageBox("无此用户！");
		}

		m_ado.ExitConn();

	}
}
