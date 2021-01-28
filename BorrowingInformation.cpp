// BorrowingInformation.h : CBorrowingInformation ���ʵ��



// CBorrowingInformation ʵ��

// ���������� 2018��6��5�� ���ڶ�, 15:39

#include "stdafx.h"
#include "BorrowingInformation.h"
IMPLEMENT_DYNAMIC(CBorrowingInformation, CRecordset)

CBorrowingInformation::CBorrowingInformation(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_BookID = 0;
	m_ReaderID = 0;
	m_BorrowingTime;
	m_Ifreturn = FALSE;
	m_returntime;
	m_nFields = 5;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CBorrowingInformation::GetDefaultConnect()
{
	return _T("DSN=tushuguanli;Trusted_Connection=Yes;APP=Microsoft\x00ae Visual Studio\x00ae;WSID=WIN10-707310258;DATABASE=tushuguanli");
}

CString CBorrowingInformation::GetDefaultSQL()
{
	return _T("[dbo].[BorrowingInformation]");
}

void CBorrowingInformation::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[BookID]"), m_BookID);
	RFX_Long(pFX, _T("[ReaderID]"), m_ReaderID);
	RFX_Date(pFX, _T("[BorrowingTime]"), m_BorrowingTime);
	RFX_Bool(pFX, _T("[Ifreturn]"), m_Ifreturn);
	RFX_Date(pFX, _T("[returntime]"), m_returntime);

}
/////////////////////////////////////////////////////////////////////////////
// CBorrowingInformation ���

#ifdef _DEBUG
void CBorrowingInformation::AssertValid() const
{
	CRecordset::AssertValid();
}

void CBorrowingInformation::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


