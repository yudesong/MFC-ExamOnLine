// UserManager.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "UserManager.h"
#include "ADOConn.h"
#include "UserModify.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserManager dialog


CUserManager::CUserManager(CWnd* pParent /*=NULL*/)
	: CDialog(CUserManager::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserManager)
	m_finduser = _T("");
	//}}AFX_DATA_INIT
}


void CUserManager::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserManager)
	DDX_Control(pDX, IDC_LIST1, m_userlist);
	DDX_Text(pDX, IDC_EDIT1, m_finduser);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserManager, CDialog)
	//{{AFX_MSG_MAP(CUserManager)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserManager message handlers

BOOL CUserManager::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_userlist.SetExtendedStyle(LVS_EX_FLATSB   //扁平风格显示滚动条
		|LVS_EX_FULLROWSELECT					//允许整行选中
		|LVS_EX_HEADERDRAGDROP					//允许整列拖动
		|LVS_EX_ONECLICKACTIVATE				//单击选中项
		|LVS_EX_GRIDLINES					//画出网格线
		);	
	m_userlist.InsertColumn(0,"编号",LVCFMT_LEFT,50,0);
	m_userlist.InsertColumn(1,"姓名",LVCFMT_LEFT,60,1);
	m_userlist.InsertColumn(2,"密码",LVCFMT_LEFT,80,2);
	m_userlist.InsertColumn(3,"类型",LVCFMT_LEFT,80,3);
	m_userlist.InsertColumn(4,"年龄",LVCFMT_LEFT,50,4);
	m_userlist.InsertColumn(5,"性别",LVCFMT_LEFT,50,5);
	m_userlist.InsertColumn(6,"密码提示问题",LVCFMT_LEFT,200,6);
	m_userlist.InsertColumn(7,"答案",LVCFMT_LEFT,200,7);
  	insertItem();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CUserManager::insertItem()
{
	ADOConn m_ado;
	m_ado.OnInitADOConn();
	_RecordsetPtr m_pRs;
	CString sql;
	sql="select * from tb_user";
	m_pRs=m_ado.GetRecordSet((_bstr_t)sql);	
	while(!m_pRs->adoEOF)
	{
		CString id,age;
		CString name,passwd,leixing,sex,question,answer;
		id=(char *)(_bstr_t)m_pRs->GetCollect("id");
		name=(char *)(_bstr_t)m_pRs->GetCollect("username");
		passwd=(char *)(_bstr_t)m_pRs->GetCollect("passwd");
		leixing=(char *)(_bstr_t)m_pRs->GetCollect("leixing");
		age=(char *)(_bstr_t)m_pRs->GetCollect("age");
	//	MessageBox(age);
		sex=(char *)(_bstr_t)m_pRs->GetCollect("sex");
		question=(char *)(_bstr_t)m_pRs->GetCollect("question");
		answer=(char *)(_bstr_t)m_pRs->GetCollect("answer");
		int index=m_userlist.GetItemCount();
		m_userlist.InsertItem(index,"");
		m_userlist.SetItemText(index,0,id);
		m_userlist.SetItemText(index,1,name);
		m_userlist.SetItemText(index,2,passwd);
		m_userlist.SetItemText(index,3,leixing);
		m_userlist.SetItemText(index,4,age);		
		m_userlist.SetItemText(index,5,sex);
		m_userlist.SetItemText(index,6,question);
		m_userlist.SetItemText(index,7,answer);
		m_pRs->MoveNext();
	}
	m_ado.ExitConn();
}


//查询用户信息
void CUserManager::OnButton1() 
{
	UpdateData();
	CString sql;
	sql.Format("select * from tb_user where username='%s'",m_finduser);
	ADOConn m_ado;
	m_ado.OnInitADOConn();
	_RecordsetPtr m_pRs;
	m_pRs=m_ado.GetRecordSet((_bstr_t)sql);
	if(!m_pRs->adoEOF)
	{
		m_userlist.DeleteAllItems();
		CString id,age;
		CString name,passwd,leixing,sex,question,answer;
		id=(char *)(_bstr_t)m_pRs->GetCollect("id");
		name=(char *)(_bstr_t)m_pRs->GetCollect("username");
		passwd=(char *)(_bstr_t)m_pRs->GetCollect("passwd");
		leixing=(char *)(_bstr_t)m_pRs->GetCollect("leixing");
		age=(char *)(_bstr_t)m_pRs->GetCollect("age");
		sex=(char *)(_bstr_t)m_pRs->GetCollect("sex");
		question=(char *)(_bstr_t)m_pRs->GetCollect("question");
		answer=(char *)(_bstr_t)m_pRs->GetCollect("answer");
		int index=m_userlist.GetItemCount();
		m_userlist.InsertItem(index,"");
		m_userlist.SetItemText(index,0,id);
		m_userlist.SetItemText(index,1,name);
		m_userlist.SetItemText(index,2,passwd);
		m_userlist.SetItemText(index,3,leixing);
		m_userlist.SetItemText(index,4,age);		
		m_userlist.SetItemText(index,5,sex);
		m_userlist.SetItemText(index,6,question);
		m_userlist.SetItemText(index,7,answer);		
		m_pRs->MoveNext();
	}else
	{
	MessageBox("无此用户!");
	}
	m_ado.ExitConn();	
}

//删除用户信息
void CUserManager::OnButton2() 
{

	if(MessageBox("真的要删除吗？","系统提示",MB_OKCANCEL|MB_ICONQUESTION)!=IDOK)  return;
	else
	{
	int i=m_userlist.GetSelectionMark();
	CString sql;
	CString name=m_userlist.GetItemText(i,1);
	sql.Format("delete from tb_user where username='%s'",name);
	ADOConn m_ado;
	m_ado.OnInitADOConn();
	if(m_ado.ExecuteSQL((_bstr_t)sql))
	{
			m_userlist.DeleteAllItems();
			insertItem();
	}
	m_ado.ExitConn();
	}
}

//修改用户信息
void CUserManager::OnButton3() 
{
	int i=m_userlist.GetSelectionMark();
	CUserModify dlg;
	dlg.name=m_userlist.GetItemText(i,1);
	if(dlg.DoModal()==IDOK)
	{
		m_userlist.DeleteAllItems();
		insertItem();
	}
/*
	CUserModify dlg;
	dlg.m_name=m_userlist.GetItemText(i,1);
	dlg.m_passwd=m_userlist.GetItemText(i,2);
	dlg.m_age=atoi(m_userlist.GetItemText(i,3));
	CString sex=m_userlist.GetItemText(i,4);
	MessageBox("1");
	if(sex=="男")
	{
	((CButton *)GetDlgItem(IDC_RADIO1))->SetState(1);
	MessageBox("2");
	}else
	{
	((CButton *)GetDlgItem(IDC_RADIO2))->SetState(1);
	}
*/


	



}
