// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication8.h"
#include "MFCApplication8Dlg.h"
#include "MyDlg.h"
#include "afxdialogex.h"
#include "View_1.h"


// CMyDlg 对话框

IMPLEMENT_DYNAMIC(CMyDlg, CDialogEx)

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	b = 0;
}

CMyDlg::~CMyDlg()
{
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
}


BEGIN_MESSAGE_MAP(CMyDlg, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CMyDlg::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyDlg::OnBnClickedButton1)
END_MESSAGE_MAP()
BOOL CMyDlg::OnInitDialog()
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
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);
	CRect rect;
	m_List.GetClientRect(&rect);
	m_List.SetExtendedStyle(m_List.GetExtendedStyle() |
		LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_List.InsertColumn(1, _T("Stuid"), LVCFMT_CENTER, rect.Width() / 10, 1);
	m_List.InsertColumn(2, _T("name"), LVCFMT_CENTER, rect.Width() / 10, 2);
	m_List.InsertColumn(3, _T("Author"), LVCFMT_CENTER, rect.Width() / 10, 3);
	m_List.InsertColumn(4, _T("Title"), LVCFMT_CENTER, rect.Width() / 10, 4);
	m_List.InsertColumn(5, _T("Category"), LVCFMT_CENTER, rect.Width() / 10, 5);
	m_List.InsertColumn(6, _T("BorrowingTime"), LVCFMT_CENTER, rect.Width() / 10, 6);
	m_List.InsertColumn(7, _T("Ifreturn"), LVCFMT_CENTER, rect.Width() / 10, 7);
	m_List.InsertColumn(8, _T("returntime"), LVCFMT_CENTER, rect.Width() / 10, 8);
	m_List.InsertColumn(9, _T("ReaderID"), LVCFMT_CENTER, rect.Width() / 10, 9);
	m_List.InsertColumn(10, _T("BookID"), LVCFMT_CENTER, rect.Width() / 10, 10);
	return TRUE;
}


// CMyDlg 消息处理程序


void CMyDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{

	
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CMyDlg::OnBnClickedButton1()
{
	m_List.DeleteAllItems();
	CString t_sql;
	t_sql.Format(L"select stuid,[full name],author,title,category,borrowingtime,ifreturn,returntime,readerid,bookid from reader,borrowinginformation,content ,Book where reader.ID=BorrowingInformation.ReaderID and content.ID=Book.ContentID and BorrowingInformation.BookID=Book.ID");
	CView_1 *t_user = new CView_1(&((CMFCApplication8App*)AfxGetApp())->m_database);
	if (!t_user->Open(AFX_DB_USE_DEFAULT_TYPE, t_sql))
	{
		MessageBox(_T("打开用户表失败！"));
	}
	if (t_user->GetRecordCount() != 0)
	{
		//遍历t_user表  
		for (int i = 0; t_user->IsEOF() != 1; i++)
		{
			//MessageBox(t_user->m_Fullname);
			int j = 1;
			m_List.InsertItem(i, (CString)t_user->m_Stuid);
			m_List.SetItemText(i, j++, (CString)t_user->m_Fullname);
			m_List.SetItemText(i, j++, (CString)t_user->m_Author);
			m_List.SetItemText(i, j++, (CString)t_user->m_Title);
			m_List.SetItemText(i, j++, (CString)t_user->m_Category);
			CString strDate;
			strDate = t_user->m_BorrowingTime.Format("%Y-%m-%d %H:%M:%S");
			m_List.SetItemText(i, j++, strDate);
			CString strValue;
			if (t_user->m_Ifreturn == true)
			{
				strValue = "true";
			}
			else
			{
				strValue = "false";
			}
			m_List.SetItemText(i, j++, strValue);
			CString strDate1;
			strDate1 = t_user->m_returntime.Format("%Y-%m-%d %H:%M:%S");
			m_List.SetItemText(i, j++, strDate1);
			CString s;
			s.Format(_T("%ld"), t_user->m_ReaderID);
			m_List.SetItemText(i, j++, s);
			CString s1;
			s1.Format(_T("%ld"), t_user->m_BookID);
			m_List.SetItemText(i, j++, s1);
			t_user->MoveNext();
		} //while (t_user->IsEOF() != 1);
	}
	// TODO: 在此添加控件通知处理程序代码
}
