// DuoXuanDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "DuoXuanDlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DuoXuanDlg dialog


DuoXuanDlg::DuoXuanDlg(CWnd* pParent /*=NULL*/)
	: CDialog(DuoXuanDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(DuoXuanDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	i=1;
}


void DuoXuanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DuoXuanDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DuoXuanDlg, CDialog)
	//{{AFX_MSG_MAP(DuoXuanDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DuoXuanDlg message handlers

void DuoXuanDlg::OnButton1() 
{
	i--;
	if(i>0)
	{
	showTest(i);
	clearAnswer();
	showPerTest(i);
	}else
	{
	MessageBox("已经是第一题了！");
	}
}

void DuoXuanDlg::OnButton2() 
{
	if(exText(i))
	{
		updateExamInfo(i);
	}else
	{
		insertExamInfo(i);
	}
	i++;
	showTest(i);
}

bool DuoXuanDlg::exText(int i)
{
	CString sql;
	sql.Format("select answer from tb_examinfo where id=%d and [subject]='%s'",i,subject);
//	MessageBox(sql);
	ADOConn	m_ado;
	m_ado.OnInitADOConn();
	_RecordsetPtr m_pRs;
	m_pRs=m_ado.GetRecordSet((_bstr_t)sql);
	while(!m_pRs->adoEOF) 
	{	
	m_ado.ExitConn();
	return true;
	}
	return false;
}

void DuoXuanDlg::updateExamInfo(int i)
{
	CString sql;
	sql.Format("update tb_examinfo set answer='%s' where id=%d and subject='%s'",answer,i,subject);	
	ADOConn m_ado;
	m_ado.OnInitADOConn();
	if(m_ado.ExecuteSQL((_bstr_t)sql))
	{
		m_ado.ExitConn();
	}
}

void DuoXuanDlg::clearAnswer()
{
	CButton *checka=(CButton*)GetDlgItem(IDC_CHECK1);
	CButton *checkb=(CButton*)GetDlgItem(IDC_CHECK2);
	CButton *checkc=(CButton*)GetDlgItem(IDC_CHECK3);
	CButton *checkd=(CButton*)GetDlgItem(IDC_CHECK4);	
	checka->SetCheck(false);
	checkb->SetCheck(false);
	checkc->SetCheck(false);
	checkd->SetCheck(false);
}

void DuoXuanDlg::showTest(int i)
{
	CString sql;
	sql.Format("select * from tb_test where subject='%s'and [id]=%d and leixing='%s'",subject,i,"多选题");
//	MessageBox(sql);
	ADOConn m_ado;
	_RecordsetPtr m_pRs;
	m_ado.OnInitADOConn();
	m_pRs=m_ado.GetRecordSet((_bstr_t)sql);
	while(!m_pRs->adoEOF)
	{
//	MessageBox(sql);
	question=(char *)(_bstr_t)m_pRs->GetCollect("question");
	answera=(char *)(_bstr_t)m_pRs->GetCollect("answera");
	answerb=(char *)(_bstr_t)m_pRs->GetCollect("answerb");	
	answerc=(char *)(_bstr_t)m_pRs->GetCollect("answerc");
	answerd=(char *)(_bstr_t)m_pRs->GetCollect("answerd");
	rightanswer=(char *)(_bstr_t)m_pRs->GetCollect("rightanswer");
//	MessageBox(i+" ."+answerc);
	CString str;
	str.Format("第%d题",i);
	GetDlgItem(IDC_STATIC2)->SetWindowText(str+question);
	GetDlgItem(IDC_CHECK1)->SetWindowText("A."+answera);
	GetDlgItem(IDC_CHECK2)->SetWindowText("B."+answerb);
	GetDlgItem(IDC_CHECK3)->SetWindowText("C."+answerc);
	GetDlgItem(IDC_CHECK4)->SetWindowText("D."+answerd);
	m_pRs->MoveNext();
	}
	clearAnswer();
	m_ado.ExitConn();
}

void DuoXuanDlg::showPerTest(int i)
{
	CButton *checka=(CButton *)GetDlgItem(IDC_CHECK1);
	CButton *checkb=(CButton *)GetDlgItem(IDC_CHECK2);
	CButton *checkc=(CButton *)GetDlgItem(IDC_CHECK3);
	CButton *checkd=(CButton *)GetDlgItem(IDC_CHECK4);
	ADOConn m_ado;
	m_ado.OnInitADOConn();
	CString per_answer;
	CString sql;
	sql.Format("select answer from tb_examinfo where subject='%s' and id=%d",subject,i);
	_RecordsetPtr m_pRs;
	m_pRs=m_ado.GetRecordSet((_bstr_t)sql);
	while(!m_pRs->adoEOF)
	{
	per_answer=(char *)(_bstr_t)m_pRs->GetCollect("answer");
	m_pRs->MoveNext();
	}
	m_ado.ExitConn();
	if(per_answer=="AB")
	{
//	MessageBox(per_answer);
	checka->SetCheck(true);
	checkb->SetCheck(true);
	checkc->SetCheck(false);
	checkd->SetCheck(false);
	}
	if(per_answer=="AC")
	{
//	MessageBox(per_answer);
	checka->SetCheck(true);
	checkb->SetCheck(false);
	checkc->SetCheck(true);
	checkd->SetCheck(false);
	}
	if(per_answer=="AD")
	{
//	MessageBox(per_answer);
	checka->SetCheck(true);
	checkb->SetCheck(false);
	checkc->SetCheck(false);
	checkd->SetCheck(true);
	}

	if(per_answer=="ABC")
	{
//	MessageBox(per_answer);
	checka->SetCheck(true);
	checkb->SetCheck(true);
	checkc->SetCheck(true);
	checkd->SetCheck(false);
	}
	if(per_answer=="ABD")
	{
//	MessageBox(per_answer);
	checka->SetCheck(true);
	checkb->SetCheck(true);
	checkc->SetCheck(false);
	checkd->SetCheck(true);
	}
	if(per_answer=="ACD")
	{
//	MessageBox(per_answer);
	checka->SetCheck(true);
	checkb->SetCheck(false);
	checkc->SetCheck(true);
	checkd->SetCheck(true);
	}

	if(per_answer=="BCD")
	{
//	MessageBox(per_answer);
	checka->SetCheck(false);
	checkb->SetCheck(true);
	checkc->SetCheck(true);
	checkd->SetCheck(true);
	}

	if(per_answer=="ABCD")
	{
//	MessageBox(per_answer);
	checka->SetCheck(true);
	checkb->SetCheck(true);
	checkc->SetCheck(true);
	checkd->SetCheck(true);
	}
}

bool DuoXuanDlg::insertExamInfo(int i)
{
	CString sql,answer1;
	answer1=getAnswer();
	sql.Format("insert into tb_examinfo values(%d,'%s','%s','%s','%s')",i,subject,question,answer1,rightanswer);	
//	MessageBox(sql);
	ADOConn m_ado;
	m_ado.OnInitADOConn();
	if(m_ado.ExecuteSQL((_bstr_t)sql))
	{
		m_ado.ExitConn();
		return true;
	}	
	return false;
}

BOOL DuoXuanDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	showTest(i);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


CString DuoXuanDlg::getAnswer()
{
	CButton *checka=(CButton*)GetDlgItem(IDC_CHECK1);
	CButton *checkb=(CButton*)GetDlgItem(IDC_CHECK2);
	CButton *checkc=(CButton*)GetDlgItem(IDC_CHECK3);
	CButton *checkd=(CButton*)GetDlgItem(IDC_CHECK4);	
	if(checka->GetState()==1 && checkb->GetState()==1) answer="AB";
	if(checka->GetState()==1 && checkc->GetState()==1) answer="AC";
	if(checka->GetState()==1 && checkd->GetState()==1) answer="AD";
	if(checka->GetState()==1 && checkb->GetState()==1 && checkc->GetState()==1) answer="ABC";
	if(checka->GetState()==1 && checkb->GetState()==1 && checkd->GetState()==1) answer="ABD";
	if(checka->GetState()==1 && checkc->GetState()==1 && checkd->GetState()==1) answer="ACD";
	if(checkb->GetState()==1 && checkc->GetState()==1 && checkd->GetState()==1) answer="BCD";
	if(checka->GetState()==1 && checkb->GetState()==1 && checkc->GetState()==1 && checkd->GetState()==1) answer="ABCD";
//	MessageBox(answer);
	return answer;
}
