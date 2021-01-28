// View_1.h : CView_1 ������

#pragma once

// ���������� 2018��6��5�� ���ڶ�, 15:53

class CView_1 : public CRecordset
{
public:
	CView_1(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CView_1)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	CStringW	m_Stuid;
	CStringW	m_Fullname;
	CStringW	m_Author;
	CStringW	m_Title;
	CStringW	m_Category;
	CTime	m_BorrowingTime;
	BOOL	m_Ifreturn;
	CTime	m_returntime;
	long	m_ReaderID;
	long	m_BookID;

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


