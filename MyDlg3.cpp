// MyDlg3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication8.h"
#include "MFCApplication8Dlg.h"

#include "MyDlg3.h"
#include "afxdialogex.h"


// MyDlg3 �Ի���

IMPLEMENT_DYNAMIC(MyDlg3, CDialogEx)

MyDlg3::MyDlg3(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

MyDlg3::~MyDlg3()
{
}

void MyDlg3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDlg3, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT2, &MyDlg3::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT1, &MyDlg3::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &MyDlg3::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT3, &MyDlg3::OnEnChangeEdit3)
END_MESSAGE_MAP()


// MyDlg3 ��Ϣ�������


void MyDlg3::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void MyDlg3::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void MyDlg3::OnBnClickedButton2()
{
	CString m_edit2;
	GetDlgItemText(IDC_EDIT2, m_edit2);
	CString m_edit1;
	GetDlgItemText(IDC_EDIT1, m_edit1);
	CString m_edit3;
	GetDlgItemText(IDC_EDIT3, m_edit3);
	CString t_sql1;
	CDatabase db;
	db.Open(_T("tushuguanli"), false, false, _T("ODBC;DSN=tushuguanli"), false);
	t_sql1.Format(L"exec update_borrowinginfomation_book '%s','%s','%s'",m_edit3, m_edit2, m_edit1);
	try
	{
		db.ExecuteSQL(t_sql1);
	}
	catch (CDBException* pe)
	{
		pe->ReportError();
		pe->Delete();

	}
	MessageBox(L"���³ɹ�");



	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void MyDlg3::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
