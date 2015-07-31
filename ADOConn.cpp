// ADOConn.cpp: implementation of the ADOConn class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ExamOnline.h"
#include "ADOConn.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ADOConn::ADOConn()
{

}

ADOConn::~ADOConn()
{

}

void ADOConn::OnInitADOConn()
{
	::CoInitialize(NULL);
	try
	{
		m_pCon.CreateInstance("ADODB.Connection");
		m_pCon->ConnectionTimeout=3;	
		m_pCon->Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=exam.mdb;Persist Security Info=False","","",adModeUnknown);
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}

}

void ADOConn::ExitConn()
{
	if(m_pRs!=NULL)
		m_pRs->Close();
	m_pCon->Close();
	::CoUninitialize();
}

_RecordsetPtr& ADOConn::GetRecordSet(_bstr_t bstrSQL)
{
	try
	{
		if(m_pCon==NULL) OnInitADOConn();
		m_pRs.CreateInstance("ADODB.Recordset");
		m_pRs->Open(bstrSQL,m_pCon.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);	
	}catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
	return m_pRs;
}

bool ADOConn::ExecuteSQL(_bstr_t bstrSQL)
{
	try
	{
		if(m_pCon==NULL) OnInitADOConn();
		m_pCon->Execute(bstrSQL,NULL,adCmdText);
		return  true;
	}catch(_com_error e)
	{
		AfxMessageBox(e.Description());
		return false;
	}
			
}