// ManagerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "ManagerDlg.h"
#include "UserManager.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CManagerDlg dialog


CManagerDlg::CManagerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CManagerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CManagerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CManagerDlg)
	DDX_Control(pDX, IDC_TAB1, m_manager);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CManagerDlg, CDialog)
	//{{AFX_MSG_MAP(CManagerDlg)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManagerDlg message handlers

BOOL CManagerDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_manager.InsertItem(0,"用户管理");
	m_manager.InsertItem(1,"科目管理");
	m_manager.InsertItem(2,"试题管理");
	m_manager.InsertItem(3,"考试管理");

	user_manager=new CUserManager;
	sub_manager=new CSubjectManager;
	test_manager=new CTestManager;
	examinfo_manager=new CExamInfoManager;

	user_manager->Create(IDD_DIALOG11,&m_manager);
	sub_manager->Create(IDD_DIALOG12,&m_manager);
	test_manager->Create(IDD_DIALOG13,&m_manager);
	examinfo_manager->Create(IDD_DIALOG14,&m_manager);

	user_manager->CenterWindow();
	user_manager->ShowWindow(SW_SHOW);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CManagerDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	int index=m_manager.GetCurSel();
	switch(index)
	{
	case 0:
			user_manager->CenterWindow();
			user_manager->ShowWindow(SW_SHOW);
			sub_manager->ShowWindow(SW_HIDE);
			test_manager->ShowWindow(SW_HIDE);
			examinfo_manager->ShowWindow(SW_HIDE);
			break;
	case 1:
			sub_manager->CenterWindow();
			sub_manager->ShowWindow(SW_SHOW);
			user_manager->ShowWindow(SW_HIDE);
			test_manager->ShowWindow(SW_HIDE);
			examinfo_manager->ShowWindow(SW_HIDE);
			break;
	case 2:

			test_manager->CenterWindow();
			test_manager->ShowWindow(SW_SHOW);
			user_manager->ShowWindow(SW_HIDE);
			sub_manager->ShowWindow(SW_HIDE);
			examinfo_manager->ShowWindow(SW_HIDE);
			break;
	case 3:
			examinfo_manager->CenterWindow();
			examinfo_manager->ShowWindow(SW_SHOW);
			user_manager->ShowWindow(SW_HIDE);
			sub_manager->ShowWindow(SW_HIDE);
			test_manager->ShowWindow(SW_HIDE);
			break;
	}
	*pResult = 0;
}