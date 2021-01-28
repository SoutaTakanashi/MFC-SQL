// MyDlg1.cpp : 实现文件
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


// CMyDlg1 对话框

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

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

// TODO: 在此添加额外的初始化代码
	CRect rect;
	m_List.GetClientRect(&rect);
	m_List.SetExtendedStyle(m_List.GetExtendedStyle() |
		LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_List.InsertColumn(1, _T("ID"), LVCFMT_CENTER, rect.Width() / 4, 1);
	m_List.InsertColumn(2, _T("ContentID"), LVCFMT_CENTER, rect.Width() / 4, 2);
	m_List.InsertColumn(3, _T("Status"), LVCFMT_CENTER, rect.Width() / 4, 3);
	m_List.InsertColumn(4, _T("Positon"), LVCFMT_CENTER, rect.Width() / 4, 4);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}



// CMyDlg1 消息处理程序


void CMyDlg1::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMyDlg1::OnBnClickedButton1()//触发器
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
	MessageBox(L"添加成功");
	CString t_sql;
	t_sql.Format(L"select * from Book");
	CBook *t_user = new CBook(&((CMFCApplication8App*)AfxGetApp())->m_database);
		//CDatabase::ExecuteSQL(AFX_DB_USE_DEFAULT_TYPE, t_sql);
		if (!t_user->Open(AFX_DB_USE_DEFAULT_TYPE, t_sql))
		{
			MessageBox(_T("打开用户表失败！"));
		}
		if (t_user->GetRecordCount() != 0)
		{
			//遍历t_user表  
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
	// TODO: 在此添加控件通知处理程序代码
}

	// TODO: 在此添加控件通知处理程序代码


void CMyDlg1::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMyDlg1::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMyDlg1::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMyDlg1::OnEnChangeEdit7()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMyDlg1::OnEnChangeEdit8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMyDlg1::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
