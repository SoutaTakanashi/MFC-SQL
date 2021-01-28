// reader.h : Creader 类的实现



// Creader 实现

// 代码生成在 2018年6月5日 星期二, 15:40

#include "stdafx.h"
#include "reader.h"
IMPLEMENT_DYNAMIC(Creader, CRecordset)

Creader::Creader(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_Stuid = L"";
	m_Fullname = L"";
	m_Gender = "";
	m_nFields = 4;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString Creader::GetDefaultConnect()
{
	return _T("DSN=tushuguanli;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=WIN10-707310258;DATABASE=tushuguanli");
}

CString Creader::GetDefaultSQL()
{
	return _T("[dbo].[reader]");
}

void Creader::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[Stuid]"), m_Stuid);
	RFX_Text(pFX, _T("[Full name]"), m_Fullname);
	RFX_Text(pFX, _T("[Gender]"), m_Gender);

}
/////////////////////////////////////////////////////////////////////////////
// Creader 诊断

#ifdef _DEBUG
void Creader::AssertValid() const
{
	CRecordset::AssertValid();
}

void Creader::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


