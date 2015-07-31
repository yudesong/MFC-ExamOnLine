// ChoceSubject.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "ChoceSubject.h"
#include "ADOConn.h"
#include "EamDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChoceSubject dialog


CChoceSubject::CChoceSubject(CWnd* pParent /*=NULL*/)
	: CDialog(CChoceSubject::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChoceSubject)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CChoceSubject::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChoceSubject)
	DDX_Control(pDX, IDC_COMBO1, m_sub);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChoceSubject, CDialog)
	//{{AFX_MSG_MAP(CChoceSubject)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChoceSubject message handlers

BOOL CChoceSubject::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
		
	_RecordsetPtr m_pRs;
	ADOConn m_ado;
	m_ado.OnInitADOConn();
	CString sql="select * from tb_subject";
	m_pRs=m_ado.GetRecordSet((_bstr_t)sql);
	while(m_pRs->adoEOF==0)
	{
	CString subject=(char *)(_bstr_t)m_pRs->GetCollect("subject");
	m_sub.AddString(subject);
	m_pRs->MoveNext();
	}
	m_ado.ExitConn();
	m_sub.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CChoceSubject::OnOK() 
{
	UpdateData();
	if(m_sub.GetCurSel()==-1)
	{
		AfxMessageBox("ÇëÑ¡Ôñ¿ÆÄ¿£¡");
	}
	CString sel;
	m_sub.GetLBText(m_sub.GetCurSel(),sel);
//	AfxMessageBox(sel);
	CEamDlg dlg;
	dlg.subject=sel;
	CChoceSubject::OnCancel();
	dlg.DoModal();
}
