// ADOConn.h: interface for the ADOConn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOCONN_H__1F8B28A8_6B57_497B_AC8A_5CE7C0C58DEA__INCLUDED_)
#define AFX_ADOCONN_H__1F8B28A8_6B57_497B_AC8A_5CE7C0C58DEA__INCLUDED_

#import "C:\\Program Files\\Common Files\\System\\ado\\msado15.dll"no_namespace rename("EOF","adoEOF")

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class ADOConn  
{
public:
	ADOConn();
	virtual ~ADOConn();
	void OnInitADOConn();
	void ExitConn();
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	bool ExecuteSQL(_bstr_t bstrSQL);

private:
	_ConnectionPtr m_pCon;
	_RecordsetPtr m_pRs;
};

#endif // !defined(AFX_ADOCONN_H__1F8B28A8_6B57_497B_AC8A_5CE7C0C58DEA__INCLUDED_)
