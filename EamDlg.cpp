// EamDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "EamDlg.h"
#include "DanXuanDlg.h"
#include "DuoXuanDlg.h"
#include "JieDaDlg.h"
#include "EamInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEamDlg dialog


CEamDlg::CEamDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEamDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEamDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEamDlg)
	DDX_Control(pDX, IDC_STATIC2, m_second);
	DDX_Control(pDX, IDC_STATIC1, m_time);
	DDX_Control(pDX, IDC_TAB1, m_title);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEamDlg, CDialog)
	//{{AFX_MSG_MAP(CEamDlg)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEamDlg message handlers

BOOL CEamDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_title.InsertItem(0,"单选题",0);
	m_title.InsertItem(1,"多选题",1);
	m_title.InsertItem(2,"解答题",2);
	
	danlg=new DanXuanDlg;
	duolg=new DuoXuanDlg;
	jiedlg=new JieDaDlg;
	
	danlg->subject=subject;
	duolg->subject=subject;
//	jiedlg->subject=subject;

	danlg->Create(IDD_DIALOG6,&m_title);
	duolg->Create(IDD_DIALOG7,&m_title);
	jiedlg->Create(IDD_DIALOG8,&m_title);
	danlg->CenterWindow();
	danlg->ShowWindow(SW_SHOW);

	flag=true;
	count=0;
	second=0;
	SetTimer(1,1000,NULL);//此为一个定时器
	// TODO: Add extra initialization here
//	MessageBox(subject);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEamDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int index=m_title.GetCurSel();	
	switch(index)
	{
	case 0:
			danlg->CenterWindow();
			danlg->ShowWindow(SW_SHOW);
			duolg->ShowWindow(SW_HIDE);
			jiedlg->ShowWindow(SW_HIDE);
			break;
	case 1:
			duolg->CenterWindow();
			duolg->ShowWindow(SW_SHOW);
			danlg->ShowWindow(SW_HIDE);
			jiedlg->ShowWindow(SW_HIDE);
			break;
	case 2:
			jiedlg->CenterWindow();
			jiedlg->ShowWindow(SW_SHOW);
			danlg->ShowWindow(SW_HIDE);
			duolg->ShowWindow(SW_HIDE);
			break;
	}
	*pResult = 0;
}

void CEamDlg::OnButton1() 
{
		CEamInfo dlg;
		CEamDlg::OnCancel();
		dlg.DoModal();
}

void CEamDlg::OnTimer(UINT nIDEvent) 
{
	if(nIDEvent==1)
	{
		CString str_second,str_time;
		if(second>=60) 
		{
			second=0;
			count++;
		}
		if(second>=0 && second<=9)
		{
			str_second.Format("0%d",second);
		}
		if(second>=10)
		{
			str_second.Format("%d",second);
		}
		if(count>=0 && count<=9)
		{
			str_time.Format("0%d",count);
		}
		if(count>=10)
		{
			str_time.Format("%d",count);
		}
//		str_time.Format("0%d",count);
		m_second.SetWindowText(str_second);
		m_time.SetWindowText(str_time);
		second++;
	}

	CDialog::OnTimer(nIDEvent);
}

void CEamDlg::OnButton4() 
{	
	if(MessageBox("真的要退出吗？","系统提示",MB_OKCANCEL|MB_ICONQUESTION)!=IDOK)
	return;
	CDialog::OnCancel();
	CEamDlg::OnCancel();
	
}

void CEamDlg::OnButton3() 
{
	if(flag)
	{
	GetDlgItem(IDC_BUTTON3)->SetWindowText("开始");
	KillTimer(1);
	flag=false;
	}else
	{
	GetDlgItem(IDC_BUTTON3)->SetWindowText("暂停");
	SetTimer(1,1000,NULL);//此为一个定时器
	flag=true;
	}
}
