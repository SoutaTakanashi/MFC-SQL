// MyDlg1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication8.h"
#include "MFCApplication8Dlg.h"
#include "MyDlg1.h"
#include "afxdialogex.h"
#include "Content.h"
#include "Book.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMyDlg1 �Ի���

IMPLEMENT_DYNAMIC(CMyDlg1, CDialogEx)


CMyDlg1::CMyDlg1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	b = 0;
}

CMyDlg1::~CMyDlg1()
{
	
}



void CMyDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
}




BEGIN_MESSAGE_MAP(CMyDlg1, CDialog)
	ON_EN_CHANGE(IDC_EDIT1, &CMyDlg1::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyDlg1::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT4, &CMyDlg1::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &CMyDlg1::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT6, &CMyDlg1::OnEnChangeEdit6)
	ON_EN_CHANGE(IDC_EDIT7, &CMyDlg1::OnEnChangeEdit7)
	ON_EN_CHANGE(IDC_EDIT8, &CMyDlg1::OnEnChangeEdit8)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CMyDlg1::OnLvnItemchangedList1)
END_MESSAGE_MAP()

BOOL CMyDlg1::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CRect rect;
	m_List.GetClientRect(&rect);
	m_List.SetExtendedStyle(m_List.GetExtendedStyle() |
		LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_List.InsertColumn(1, _T("ID"), LVCFMT_CENTER, rect.Width() / 4, 1);
	m_List.InsertColumn(2, _T("ContentID"), LVCFMT_CENTER, rect.Width() / 4, 2);
	m_List.InsertColumn(3, _T("Status"), LVCFMT_CENTER, rect.Width() / 4, 3);
	m_List.InsertColumn(4, _T("Positon"), LVCFMT_CENTER, rect.Width() / 4, 4);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}



// CMyDlg1 ��Ϣ�������


void CMyDlg1::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMyDlg1::OnBnClickedButton1()//������
{
	m_List.DeleteAllItems();
	CString m_edit1;
	CString m_edit4;
	CString m_edit5;
	CString m_edit6;
	CString m_edit8;
	GetDlgItemText(IDC_EDIT1, m_edit1);
	GetDlgItemText(IDC_EDIT4, m_edit4);
	GetDlgItemText(IDC_EDIT5, m_edit5);
	GetDlgItemText(IDC_EDIT6, m_edit6);
	GetDlgItemText(IDC_EDIT8, m_edit8);
	CString t_sql1;
	CDatabase db;
	db.Open(_T("tushuguanli"), false, false, _T("ODBC;DSN=tushuguanli"), false);
	t_sql1.Format(L"insert into [Content]([ID],[Author],[Title],[Press],[Category])Values( '%s','%s', '%s', '%s', '%s');" ,m_edit1,m_edit4,m_edit5,m_edit6,m_edit8);
	try 

		{
			db.ExecuteSQL(t_sql1);
		}
	catch (CDBException* pe)
	{
		pe->ReportError();
		pe->Delete();
	
	}
	MessageBox(L"��ӳɹ�");
	CString t_sql;
	t_sql.Format(L"select * from Book");
	CBook *t_user = new CBook(&((CMFCApplication8App*)AfxGetApp())->m_database);
		//CDatabase::ExecuteSQL(AFX_DB_USE_DEFAULT_TYPE, t_sql);
		if (!t_user->Open(AFX_DB_USE_DEFAULT_TYPE, t_sql))
		{
			MessageBox(_T("���û���ʧ�ܣ�"));
		}
		if (t_user->GetRecordCount() != 0)
		{
			//����t_user��  
			for (int i = 0; t_user->IsEOF() != 1; i++)
			{
				int j = 1;
				CString s;
				s.Format(_T("%ld"), t_user->m_ID);
				m_List.InsertItem(i, s);
				CString d;
				d.Format(_T("%ld"), t_user->m_ContentID);
				m_List.SetItemText(i, j++, d); 
				CString strValue;
				if (t_user->m_Status == true)
				{
					strValue = "true";
				}
				else
				{
					strValue = "false";
				}
				m_List.SetItemText(i, j++, strValue);
				m_List.SetItemText(i, j++, (CString)t_user->m_Position);

				t_user->MoveNext();
			}
		
	}
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

	// TODO: �ڴ���ӿؼ�֪ͨ����������


void CMyDlg1::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMyDlg1::OnEnChangeEdit5()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMyDlg1::OnEnChangeEdit6()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMyDlg1::OnEnChangeEdit7()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMyDlg1::OnEnChangeEdit8()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMyDlg1::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}
