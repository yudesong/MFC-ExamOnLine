// ExamOnlineDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "ExamOnlineDlg.h"
#include "ADOConn.h"
#include "ChoceSubject.h"
#include "ZhuCeDlg.h"
#include "FindPasswdDlg.h"
#include "ManagerDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExamOnlineDlg dialog

CExamOnlineDlg::CExamOnlineDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExamOnlineDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExamOnlineDlg)
	m_name = _T("");
	m_passwd = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExamOnlineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExamOnlineDlg)
	DDX_Control(pDX, IDC_COMBO1, m_sel);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_passwd);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CExamOnlineDlg, CDialog)
	//{{AFX_MSG_MAP(CExamOnlineDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_COMMAND(ID_MENUITEM32772, OnMenuitem32772)
	ON_COMMAND(ID_MENUITEM32773, OnMenuitem32773)
	ON_COMMAND(ID_MENUITEM32774, OnMenuitem32774)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExamOnlineDlg message handlers

BOOL CExamOnlineDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
		
	

	/*
	CString str;
	int i=0;
	while(i<m_sel.GetCount())
	{
		m_sel.GetLBText(i,str);
		if(str=="普通用户") break;
		else i++;
	}
	*/

	m_sel.SetCurSel(1);
//	m_sel.GetCount();

	
	/*
	m_sel.SetCurSel(0);
	m_sel.EnableWindow(false);
	*/

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CExamOnlineDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CExamOnlineDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CExamOnlineDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CExamOnlineDlg::OnButton1() 
{


	//	CManagerDlg dlg;
		
	//	CExamOnlineDlg::OnCancel();
		
	//	dlg.DoModal();
	//	MessageBox("aa");


	//绑定数据到编辑框
	UpdateData();
	CString le;
	CString sql;
	//获得下拉列表中的数据
	m_sel.GetLBText(m_sel.GetCurSel(),le);
	if(m_name.IsEmpty() || m_passwd.IsEmpty())
	{
		AfxMessageBox("用户名或密码不能为空！");
	}
	
	if(le=="普通用户")
	{
		sql="select * from tb_user where username='"+m_name+"'"+"and [passwd]='"+m_passwd+"'"+" and leixing='"+le+"'";
	}

	if(le=="管理员")
	{
		sql="select * from tb_manager where name='"+m_name+"'"+"and [passwd]='"+m_passwd+"'";
	}

	_RecordsetPtr m_pRs;
	ADOConn m_ado;
	m_ado.OnInitADOConn();
	m_pRs=m_ado.GetRecordSet((_bstr_t)sql);
	if(m_pRs->adoEOF)
	{
		AfxMessageBox("用户名或密码错误！");
	}else
	{
//		AfxMessageBox("bad!");
		if(le=="管理员")
		{
		m_ado.ExitConn();
		CManagerDlg dlg;
		CExamOnlineDlg::OnCancel();
		dlg.DoModal();
		}
		if(le=="普通用户")
		{
		m_ado.ExitConn();
		CChoceSubject dlg;
		CExamOnlineDlg::OnCancel();
		dlg.DoModal();
		}
	}

}

void CExamOnlineDlg::OnMenuitem32772() 
{
	// TODO: Add your command handler code here
	CZhuCeDlg dlg;
//	CExamOnlineDlg::OnCancel();
	dlg.DoModal();
}


void CExamOnlineDlg::OnMenuitem32773() 
{
	CFindPasswdDlg dlg;
	dlg.DoModal();
}

void CExamOnlineDlg::OnMenuitem32774() 
{
	CExamOnlineDlg::OnCancel();
}

void CExamOnlineDlg::OnButton2() 
{
	CExamOnlineDlg::OnCancel();	
}
