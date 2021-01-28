// View_1.h : CView_1 类的实现



// CView_1 实现

// 代码生成在 2018年6月5日 星期二, 15:53

#include "stdafx.h"
#include "View_1.h"
IMPLEMENT_DYNAMIC(CView_1, CRecordset)

CView_1::CView_1(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_Stuid = L"";
	m_Fullname = L"";
	m_Author = L"";
	m_Title = L"";
	m_Category = L"";
	m_BorrowingTime;
	m_Ifreturn = FALSE;
	m_returntime;
	m_ReaderID = 0;
	m_BookID = 0;
	m_nFields = 10;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CView_1::GetDefaultConnect()
{
	return _T("DSN=tushuguanli;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=WIN10-707310258;DATABASE=tushuguanli");
}

CString CView_1::GetDefaultSQL()
{
	return _T("[dbo].[View_1]");
}

void CView_1::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[Stuid]"), m_Stuid);
	RFX_Text(pFX, _T("[Full name]"), m_Fullname);
	RFX_Text(pFX, _T("[Author]"), m_Author);
	RFX_Text(pFX, _T("[Title]"), m_Title);
	RFX_Text(pFX, _T("[Category]"), m_Category);
	RFX_Date(pFX, _T("[BorrowingTime]"), m_BorrowingTime);
	RFX_Bool(pFX, _T("[Ifreturn]"), m_Ifreturn);
	RFX_Date(pFX, _T("[returntime]"), m_returntime);
	RFX_Long(pFX, _T("[ReaderID]"), m_ReaderID);
	RFX_Long(pFX, _T("[BookID]"), m_BookID);

}
/////////////////////////////////////////////////////////////////////////////
// CView_1 诊断

#ifdef _DEBUG
void CView_1::AssertValid() const
{
	CRecordset::AssertValid();
}

void CView_1::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


