// View_1.h : CView_1 ���ʵ��



// CView_1 ʵ��

// ���������� 2018��6��5�� ���ڶ�, 15:53

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
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
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
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
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
// CView_1 ���

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


