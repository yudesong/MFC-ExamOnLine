// JieDaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "JieDaDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// JieDaDlg dialog


JieDaDlg::JieDaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(JieDaDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(JieDaDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void JieDaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(JieDaDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(JieDaDlg, CDialog)
	//{{AFX_MSG_MAP(JieDaDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// JieDaDlg message handlers
