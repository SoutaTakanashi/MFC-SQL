// Content.h : CContent 类的实现



// CContent 实现

// 代码生成在 2018年6月5日 星期二, 15:39

#include "stdafx.h"
#include "Content.h"
IMPLEMENT_DYNAMIC(CContent, CRecordset)

CContent::CContent(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Author = L"";
	m_Title = L"";
	m_Press = L"";
	m_Publishtime;
	m_Category = L"";
	m_ID = 0;
	m_nFields = 6;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CContent::GetDefaultConnect()
{
	return _T("DSN=tushuguanli;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=WIN10-707310258;DATABASE=tushuguanli");
}

CString CContent::GetDefaultSQL()
{
	return _T("[dbo].[Content]");
}

void CContent::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[Author]"), m_Author);
	RFX_Text(pFX, _T("[Title]"), m_Title);
	RFX_Text(pFX, _T("[Press]"), m_Press);
	RFX_Date(pFX, _T("[Publishtime]"), m_Publishtime);
	RFX_Text(pFX, _T("[Category]"), m_Category);
	RFX_Long(pFX, _T("[ID]"), m_ID);

}
/////////////////////////////////////////////////////////////////////////////
// CContent 诊断

#ifdef _DEBUG
void CContent::AssertValid() const
{
	CRecordset::AssertValid();
}

void CContent::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


