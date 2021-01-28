// reader.h : Creader ���ʵ��



// Creader ʵ��

// ���������� 2018��6��5�� ���ڶ�, 15:40

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
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
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
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[Stuid]"), m_Stuid);
	RFX_Text(pFX, _T("[Full name]"), m_Fullname);
	RFX_Text(pFX, _T("[Gender]"), m_Gender);

}
/////////////////////////////////////////////////////////////////////////////
// Creader ���

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


