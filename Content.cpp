// Content.h : CContent ���ʵ��



// CContent ʵ��

// ���������� 2018��6��5�� ���ڶ�, 15:39

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
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
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
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[Author]"), m_Author);
	RFX_Text(pFX, _T("[Title]"), m_Title);
	RFX_Text(pFX, _T("[Press]"), m_Press);
	RFX_Date(pFX, _T("[Publishtime]"), m_Publishtime);
	RFX_Text(pFX, _T("[Category]"), m_Category);
	RFX_Long(pFX, _T("[ID]"), m_ID);

}
/////////////////////////////////////////////////////////////////////////////
// CContent ���

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


