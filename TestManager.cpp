// TestManager.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "TestManager.h"
#include "ADOConn.h"
#include "TestModify.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestManager dialog


CTestManager::CTestManager(CWnd* pParent /*=NULL*/)
	: CDialog(CTestManager::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestManager)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CTestManager::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestManager)
	DDX_Control(pDX, IDC_COMBO1, m_subject);
	DDX_Control(pDX, IDC_EDIT1, m_testid);
	DDX_Control(pDX, IDC_LIST1, m_testlist);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestManager, CDialog)
	//{{AFX_MSG_MAP(CTestManager)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestManager message handlers

BOOL CTestManager::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
		m_testlist.SetExtendedStyle(LVS_EX_FLATSB   //扁平风格显示滚动条
		|LVS_EX_FULLROWSELECT					//允许整行选中
		|LVS_EX_HEADERDRAGDROP					//允许整列拖动
		|LVS_EX_ONECLICKACTIVATE				//单击选中项
		|LVS_EX_GRIDLINES						//画出网格线
		);	
	m_testlist.InsertColumn(0,"题号",LVCFMT_LEFT,50,0);
	m_testlist.InsertColumn(1,"科目",LVCFMT_LEFT,100,1);
	m_testlist.InsertColumn(2,"类型",LVCFMT_LEFT,60,2);
	m_testlist.InsertColumn(3,"试题",LVCFMT_LEFT,300,3);
	m_testlist.InsertColumn(4,"答案A",LVCFMT_LEFT,200,4);
	m_testlist.InsertColumn(5,"答案B",LVCFMT_LEFT,200,5);
	m_testlist.InsertColumn(6,"答案C",LVCFMT_LEFT,200,6);
	m_testlist.InsertColumn(7,"答案D",LVCFMT_LEFT,200,7);
	m_testlist.InsertColumn(8,"正确答案",LVCFMT_LEFT,80,8);
	m_testlist.InsertColumn(9,"分值",LVCFMT_LEFT,60,9);
//	MessageBox("test");
	insertItem();
	insertSubject();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTestManager::insertItem()
{
	ADOConn m_ado;
	m_ado.OnInitADOConn();
	CString sql="select id,subject,leixing,question,answera,answerb,answerc,answerd,rightanswer,score from tb_test order by subject";
	_RecordsetPtr m_ptr;
	m_ptr=m_ado.GetRecordSet((_bstr_t)sql);
	while(!m_ptr->adoEOF)
	{
		CString id =(char *)(_bstr_t)m_ptr->GetCollect("id");
		CString subject =(char *)(_bstr_t)m_ptr->GetCollect("subject");
		CString leixing =(char *)(_bstr_t)m_ptr->GetCollect("leixing");
		CString question =(char *)(_bstr_t)m_ptr->GetCollect("question");
		CString answera =(char *)(_bstr_t)m_ptr->GetCollect("answera");
		CString answerb =(char *)(_bstr_t)m_ptr->GetCollect("answerb");
		CString answerc =(char *)(_bstr_t)m_ptr->GetCollect("answerc");
		CString answerd =(char *)(_bstr_t)m_ptr->GetCollect("answerd");
		CString rightanswer =(char *)(_bstr_t)m_ptr->GetCollect("rightanswer");
		CString score =(char *)(_bstr_t)m_ptr->GetCollect("score");
		int index=m_testlist.GetItemCount();
		m_testlist.InsertItem(index,"");
		m_testlist.SetItemText(index,0,id);
	
		m_testlist.SetItemText(index,1,subject);
		m_testlist.SetItemText(index,2,leixing);
		m_testlist.SetItemText(index,3,question);
		m_testlist.SetItemText(index,4,answera);		
		m_testlist.SetItemText(index,5,answerb);
		m_testlist.SetItemText(index,6,answerc);
		m_testlist.SetItemText(index,7,answerd);
		m_testlist.SetItemText(index,8,rightanswer);
		m_testlist.SetItemText(index,9,score);
	
	  m_ptr->MoveNext();
	}
	m_ado.ExitConn();
}

//查询试题
void CTestManager::OnButton1() 
{
	CString id,subject;
	m_testid.GetWindowText(id);
	m_subject.GetLBText(m_subject.GetCurSel(),subject);
	CString sql;
	sql.Format("select * from tb_test where id=%d and subject='%s'",atoi(id),subject);
	ADOConn m_ado;
	m_ado.OnInitADOConn();
	_RecordsetPtr m_pRs;
	m_pRs=m_ado.GetRecordSet((_bstr_t)sql);
	if(!m_pRs->adoEOF)
	{
		m_testlist.DeleteAllItems();
		CString id =(char *)(_bstr_t)m_pRs->GetCollect("id");
		CString subject =(char *)(_bstr_t)m_pRs->GetCollect("subject");
		CString leixing =(char *)(_bstr_t)m_pRs->GetCollect("leixing");
		CString question =(char *)(_bstr_t)m_pRs->GetCollect("question");
		CString answera =(char *)(_bstr_t)m_pRs->GetCollect("answera");
		CString answerb =(char *)(_bstr_t)m_pRs->GetCollect("answerb");
		CString answerc =(char *)(_bstr_t)m_pRs->GetCollect("answerc");
		CString answerd =(char *)(_bstr_t)m_pRs->GetCollect("answerd");
		CString rightanswer =(char *)(_bstr_t)m_pRs->GetCollect("rightanswer");
		CString score =(char *)(_bstr_t)m_pRs->GetCollect("score");
		int index=m_testlist.GetItemCount();
		m_testlist.InsertItem(index,"");
		m_testlist.SetItemText(index,0,id);
	
		m_testlist.SetItemText(index,1,subject);
		m_testlist.SetItemText(index,2,leixing);
		m_testlist.SetItemText(index,3,question);
		m_testlist.SetItemText(index,4,answera);		
		m_testlist.SetItemText(index,5,answerb);
		m_testlist.SetItemText(index,6,answerc);
		m_testlist.SetItemText(index,7,answerd);
		m_testlist.SetItemText(index,8,rightanswer);
		m_testlist.SetItemText(index,9,score);
	    m_pRs->MoveNext();	
	}else
	{
		MessageBox("没有查到该试题！");
	}
	m_ado.ExitConn();
}

void CTestManager::insertSubject()
{
	ADOConn m_ado;
	m_ado.OnInitADOConn();
	CString sql="select * from tb_subject";
	_RecordsetPtr m_pRs;
	m_pRs=m_ado.GetRecordSet((_bstr_t)sql);
	while(!m_pRs->adoEOF)
	{
		CString subject=(char *)(_bstr_t)m_pRs->GetCollect("subject");
		m_subject.AddString(subject);
		m_pRs->MoveNext();
	}
	m_ado.ExitConn();
}

//删除试题
void CTestManager::OnButton2() 
{
	if(MessageBox("真的要删除吗？","系统提示",MB_OKCANCEL|MB_ICONQUESTION)!=IDOK)  return;
	else
	{
	int i=m_testlist.GetSelectionMark();
	CString sql;
	CString id=m_testlist.GetItemText(i,0);
	sql.Format("delete from tb_test where id=%d",atoi(id));
	ADOConn m_ado;
	m_ado.OnInitADOConn();
	if(m_ado.ExecuteSQL((_bstr_t)sql))
	{
			m_testlist.DeleteAllItems();
		//	MessageBox("删除试题成功！");
			insertItem();
	}else
	{
		MessageBox("删除试题失败！");
	}
	m_ado.ExitConn();
	}	
}

//添加试题
void CTestManager::OnButton3() 
{
	CTestModify dlg;
//	dlg.sureEnable(1);
	if(dlg.DoModal()==IDOK)
	{
		m_testlist.DeleteAllItems();
		insertItem();
	}
}

//修改试题
void CTestManager::OnButton4() 
{
	int index=m_testlist.GetSelectionMark();
	CTestModify dlg;
	dlg.m_id=m_testlist.GetItemText(index,0);
	dlg.subject=m_testlist.GetItemText(index,1);
	dlg.leixing=m_testlist.GetItemText(index,2);
	dlg.boolean=true;
	dlg.m_question=m_testlist.GetItemText(index,3);
	dlg.m_answera=m_testlist.GetItemText(index,4);
	dlg.m_answerb=m_testlist.GetItemText(index,5);
	dlg.m_answerc=m_testlist.GetItemText(index,6);
	dlg.m_answerd=m_testlist.GetItemText(index,7);
	dlg.m_rightanswer=m_testlist.GetItemText(index,8);
	dlg.m_score=m_testlist.GetItemText(index,9);
	if(dlg.DoModal())
	{
		m_testlist.DeleteAllItems();
		insertItem();
	}


	
}
