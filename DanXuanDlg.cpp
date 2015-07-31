// DanXuanDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "DanXuanDlg.h"
#include "ADOConn.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DanXuanDlg dialog


DanXuanDlg::DanXuanDlg(CWnd* pParent /*=NULL*/)
	: CDialog(DanXuanDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(DanXuanDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	i=1;

}


void DanXuanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DanXuanDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DanXuanDlg, CDialog)
	//{{AFX_MSG_MAP(DanXuanDlg)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DanXuanDlg message handlers

BOOL DanXuanDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	showTest(i);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DanXuanDlg::OnButton2() 
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

void DanXuanDlg::showTest(int i)
{
	CString sql;
	sql.Format("select * from tb_test where subject='%s'and [id]=%d and leixing='单选题'",subject,i);
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
//	MessageBox(i+" ."+answerd);
	CString str;
	str.Format("第%d题",i);
	GetDlgItem(IDC_STATIC2)->SetWindowText(str+question);
	GetDlgItem(IDC_RADIO1)->SetWindowText("A."+answera);
	GetDlgItem(IDC_RADIO2)->SetWindowText("B."+answerb);
	GetDlgItem(IDC_RADIO3)->SetWindowText("C."+answerc);
	GetDlgItem(IDC_RADIO4)->SetWindowText("D."+answerd);
	m_pRs->MoveNext();
	}
	clearAnswer();
	m_ado.ExitConn();
}

void DanXuanDlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	answer="A";
}

void DanXuanDlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	answer="B";
}

void DanXuanDlg::OnRadio3() 
{
	// TODO: Add your control notification handler code here
	answer="C";
}

void DanXuanDlg::OnRadio4() 
{
	// TODO: Add your control notification handler code here
	answer="D";
}

bool DanXuanDlg::insertExamInfo(int i)
{
	CString sql;
	sql.Format("insert into tb_examinfo values(%d,'%s','%s','%s','%s')",i,subject,question,answer,rightanswer);	
	ADOConn m_ado;
	m_ado.OnInitADOConn();
	if(m_ado.ExecuteSQL((_bstr_t)sql))
	{
		m_ado.ExitConn();
		return true;
	}	
	return false;
}

void DanXuanDlg::showPerTest(int i)
{
	CButton *checka=(CButton *)GetDlgItem(IDC_RADIO1);
	CButton *checkb=(CButton *)GetDlgItem(IDC_RADIO2);
	CButton *checkc=(CButton *)GetDlgItem(IDC_RADIO3);
	CButton *checkd=(CButton *)GetDlgItem(IDC_RADIO4);
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
	if(per_answer=="A")
	{
//	MessageBox(per_answer);
	checka->SetCheck(true);
	checkb->SetCheck(false);
	checkc->SetCheck(false);
	checkd->SetCheck(false);
	}

	if(per_answer=="B")
	{
//	MessageBox(per_answer);
	checka->SetCheck(false);
	checkb->SetCheck(true);
	checkc->SetCheck(false);
	checkd->SetCheck(false);
	}

	if(per_answer=="C")
	{
//	MessageBox(per_answer);
	checka->SetCheck(false);
	checkb->SetCheck(false);
	checkc->SetCheck(true);
	checkd->SetCheck(false);
	}

	if(per_answer=="D")
	{
//	MessageBox(per_answer);
	checka->SetCheck(false);
	checkb->SetCheck(false);
	checkc->SetCheck(false);
	checkd->SetCheck(true);
	}
}

void DanXuanDlg::OnButton1() 
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

void DanXuanDlg::clearAnswer()
{
	CButton *checka=(CButton*)GetDlgItem(IDC_RADIO1);
	CButton *checkb=(CButton*)GetDlgItem(IDC_RADIO2);
	CButton *checkc=(CButton*)GetDlgItem(IDC_RADIO3);
	CButton *checkd=(CButton*)GetDlgItem(IDC_RADIO4);	
	checka->SetCheck(false);
	checkb->SetCheck(false);
	checkc->SetCheck(false);
	checkd->SetCheck(false);
}

bool DanXuanDlg::exText(int i)
{
	CString sql;
	sql.Format("select answer from tb_examinfo where id=%d and [subject]='%s'",i,subject);
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

void DanXuanDlg::updateExamInfo(int i)
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
