// ZhuCeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "ZhuCeDlg.h"
#include "ADOConn.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CZhuCeDlg dialog


CZhuCeDlg::CZhuCeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CZhuCeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CZhuCeDlg)
	m_name = _T("");
	m_passwd = _T("");
	m_passwd1 = _T("");
	m_answer = _T("");
	//}}AFX_DATA_INIT
}


void CZhuCeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZhuCeDlg)
	DDX_Control(pDX, IDC_COMBO3, m_question);
	DDX_Control(pDX, IDC_COMBO2, m_age);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_passwd);
	DDX_Text(pDX, IDC_EDIT3, m_passwd1);
	DDX_Text(pDX, IDC_EDIT4, m_answer);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CZhuCeDlg, CDialog)
	//{{AFX_MSG_MAP(CZhuCeDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZhuCeDlg message handlers

void CZhuCeDlg::OnOK() 
{
	UpdateData();
	if(m_name.IsEmpty() || m_passwd1.IsEmpty() || m_passwd.IsEmpty() || m_answer.IsEmpty())
	{
		MessageBox("不能有空项！");
	}else
	{
		if(m_passwd1!=m_passwd)
		{
			MessageBox("两次密码不一致！");
			m_passwd1="";
		}else
		{
			int i,j;
			CString sex;
			CButton *man=(CButton *)GetDlgItem(IDC_RADIO1);
			CButton *woman=(CButton *)GetDlgItem(IDC_RADIO2);
			if(man->GetState()==1)
			{
				sex="男";
			}
			if(woman->GetState()==1)
			{
				sex="女";
			}
			i=m_age.GetCurSel();
			j=m_question.GetCurSel();
			CString age,question;
			m_age.GetLBText(i,age);
			m_question.GetLBText(j,question);
			int age1=atoi(age);
//			MessageBox(m_name+m_passwd);
//			MessageBox(sex);
			CString sql;
			sql.Format("insert into tb_user(username,passwd,age,sex,question,answer) values('%s','%s',%d,'%s','%s','%s')",m_name,m_passwd,age1,sex,question,m_answer);
//			MessageBox(sql);
			ADOConn m_ado;
			m_ado.OnInitADOConn();
			if(m_ado.ExecuteSQL((_bstr_t)sql))
			{
				MessageBox("注册成功！");
			}
			m_ado.ExitConn();
			CZhuCeDlg::OnCancel();
		}
	}

}

BOOL CZhuCeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
//	CButton *man=(CButton *)GetDlgItem(IDC_RADIO1);
//	CButton *woman=(CButton *)GetDlgItem(IDC_RADIO2);	


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
