// Book.h : CBook ���ʵ��



// CBook ʵ��

// ���������� 2018��6��5�� ���ڶ�, 15:38

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
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
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
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Long(pFX, _T("[ContentID]"), m_ContentID);
	RFX_Bool(pFX, _T("[Status]"), m_Status);
	RFX_Text(pFX, _T("[Position]"), m_Position);

}
/////////////////////////////////////////////////////////////////////////////
// CBook ���

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


