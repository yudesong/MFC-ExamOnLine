// TestModify.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "TestModify.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestModify dialog


CTestModify::CTestModify(CWnd* pParent /*=NULL*/)
	: CDialog(CTestModify::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestModify)
	m_question = _T("");
	m_answera = _T("");
	m_answerb = _T("");
	m_answerc = _T("");
	m_answerd = _T("");
	m_rightanswer = _T("");
	m_score = _T("");
	m_id = _T("");
	//}}AFX_DATA_INIT
}


void CTestModify::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestModify)
	DDX_Control(pDX, IDC_COMBO4, m_leixing);
	DDX_Control(pDX, IDC_COMBO1, m_subject);
	DDX_Text(pDX, IDC_EDIT2, m_question);
	DDX_Text(pDX, IDC_EDIT5, m_answera);
	DDX_Text(pDX, IDC_EDIT6, m_answerb);
	DDX_Text(pDX, IDC_EDIT7, m_answerc);
	DDX_Text(pDX, IDC_EDIT8, m_answerd);
	DDX_Text(pDX, IDC_EDIT9, m_rightanswer);
	DDX_Text(pDX, IDC_EDIT10, m_score);
	DDX_Text(pDX, IDC_EDIT1, m_id);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTestModify, CDialog)
	//{{AFX_MSG_MAP(CTestModify)
	ON_BN_CLICKED(IDOK2, OnOk2)
	ON_BN_CLICKED(IDUPDATE, OnUpdate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestModify message handlers

BOOL CTestModify::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	insertItem();



	if(boolean==true)
	{	
	int i=0,j=0;

	while(i<m_subject.GetCount())
	{
		CString str;
		m_subject.GetLBText(i,str);
		if(str==subject) break;
		else i++;
	}
	m_subject.SetCurSel(i);
	
	while(j<m_leixing.GetCount())
	{
		CString str;
		m_leixing.GetLBText(j,str);
		if(str==leixing)  break;
		else j++;
	}
	m_leixing.SetCurSel(j);
	}



	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTestModify::insertItem()
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
	
	m_leixing.AddString("单选题");
	m_leixing.AddString("多选题");
	m_leixing.AddString("解答题");
}

void CTestModify::OnOK() 
{
	UpdateData(true);
	CString subject,leixing;
	m_subject.GetLBText(m_subject.GetCurSel(),subject);
	m_leixing.GetLBText(m_leixing.GetCurSel(),leixing);
	CString sql;
	sql.Format("insert into tb_test values(%d,'%s','%s','%s','%s','%s','%s','%s','%s',%d)",atoi(m_id),subject,leixing,m_question,m_answera,m_answerb,m_answerc,m_answerd,m_rightanswer,atoi(m_score));
	ADOConn m_ado;
	m_ado.OnInitADOConn();
	if(m_ado.ExecuteSQL((_bstr_t)sql))
	{
		CDialog::OnCancel();
	}else
	{
		MessageBox("添加试题失败！");
	}
	m_ado.ExitConn();
	CDialog::OnOK();
}

void CTestModify::OnOk2() 
{
	CDialog::OnCancel();
}

//DEL void CTestModify::sureEnable(int i)
//DEL {
//DEL 
//DEL }

//修改试题


void CTestModify::OnUpdate() 
{
	UpdateData(true);
	CString subject,leixing;
	m_subject.GetLBText(m_subject.GetCurSel(),subject);
	m_leixing.GetLBText(m_leixing.GetCurSel(),leixing);
	CString sql;
	sql.Format("update tb_test set leixing='%s',question='%s',answera='%s',answerb='%s',answerc='%s',answerd='%s',rightanswer='%s',score=%d where id=%d and subject='%s'",leixing,m_question,m_answera,m_answerb,m_answerc,m_answerd,m_rightanswer,atoi(m_score),atoi(m_id),subject);
	ADOConn m_ado;
	m_ado.OnInitADOConn();
	if(m_ado.ExecuteSQL((_bstr_t)sql))
	{
		CDialog::OnCancel();
	}else
	{
		MessageBox("修改试题失败！");
	}
	m_ado.ExitConn();
}
