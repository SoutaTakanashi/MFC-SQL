// Book.h : CBook 类的实现



// CBook 实现

// 代码生成在 2018年6月5日 星期二, 15:38

#include "stdafx.h"
#include "Book.h"
IMPLEMENT_DYNAMIC(CBook, CRecordset)

CBook::CBook(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_ContentID = 0;
	m_Status = FALSE;
	m_Position = "";
	m_nFields = 4;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CBook::GetDefaultConnect()
{
	return _T("DSN=tushuguanli;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=WIN10-707310258;DATABASE=tushuguanli");
}

CString CBook::GetDefaultSQL()
{
	return _T("[dbo].[Book]");
}

void CBook::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Long(pFX, _T("[ContentID]"), m_ContentID);
	RFX_Bool(pFX, _T("[Status]"), m_Status);
	RFX_Text(pFX, _T("[Position]"), m_Position);

}
/////////////////////////////////////////////////////////////////////////////
// CBook 诊断

#ifdef _DEBUG
void CBook::AssertValid() const
{
	CRecordset::AssertValid();
}

void CBook::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


