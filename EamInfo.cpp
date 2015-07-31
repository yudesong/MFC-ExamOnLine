// EamInfo.cpp : implementation file
//

#include "stdafx.h"
#include "ExamOnline.h"
#include "EamInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEamInfo dialog


CEamInfo::CEamInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CEamInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEamInfo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEamInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEamInfo)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEamInfo, CDialog)
	//{{AFX_MSG_MAP(CEamInfo)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEamInfo message handlers
