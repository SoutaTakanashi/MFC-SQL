
// MFCApplication8Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication8.h"
#include "MFCApplication8Dlg.h"
#include "afxdialogex.h"
#include <string>
#include "reader.h"
#include "Book.h"
#include "Content.h"
#include "Borrowinginformation.h"
#include "View_1.h"
#include "MyDlg.h "
#include "MyDlg1.h "
#include "MyDlg3.h "


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication8Dlg 对话框



CMFCApplication8Dlg::CMFCApplication8Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MFCAPPLICATION8_DIALOG, pParent)
	, Stuid(_T(""))
	, m_nNum(_T(""))

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	b = 0;
}

void CMFCApplication8Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Stuid);
	DDV_MaxChars(pDX, Stuid, 30);
	DDX_Control(pDX, IDC_LIST2, m_List);
}

BEGIN_MESSAGE_MAP(CMFCApplication8Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication8Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication8Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication8Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication8Dlg::OnBnClickedButton5)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCApplication8Dlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CMFCApplication8Dlg::OnEnChangeEdit3)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER1, &CMFCApplication8Dlg::OnDtnDatetimechangeDatetimepicker1)

	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CMFCApplication8Dlg::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication8Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication8Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDCANCEL, &CMFCApplication8Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication8Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFCApplication8Dlg 消息处理程序

BOOL CMFCApplication8Dlg::OnInitDialog()
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
	m_List.InsertColumn(1, _T("Stuid"), LVCFMT_CENTER, rect.Width() / 7, 1);
	m_List.InsertColumn(2, _T("name"), LVCFMT_CENTER, rect.Width() / 7, 2);
	m_List.InsertColumn(3, _T("Author"), LVCFMT_CENTER, rect.Width() / 7, 3);
	m_List.InsertColumn(4, _T("Title"), LVCFMT_CENTER, rect.Width() / 7, 4);
	m_List.InsertColumn(5, _T("Category"), LVCFMT_CENTER, rect.Width() / 7, 5);
	m_List.InsertColumn(6, _T("BorrowingTime"), LVCFMT_CENTER, rect.Width() / 7, 6);
	m_List.InsertColumn(7, _T("Ifreturn"), LVCFMT_CENTER, rect.Width() / 7, 7);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication8Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication8Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication8Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication8Dlg::OnBnClickedButton1()//按学号查询 学生信息
{
	m_List.DeleteAllItems();
	CString m_edit1;
	GetDlgItemText(IDC_EDIT1, m_edit1);
	CString t_sql;
	t_sql.Format(L"select * from view_1 where Stuid = '%s'", m_edit1);
	CView_1 *t_user = new CView_1(&((CMFCApplication8App*)AfxGetApp())->m_database);
	if (!t_user->Open(AFX_DB_USE_DEFAULT_TYPE, t_sql))
	{
		MessageBox(_T("打开用户表失败！"));
	}
	if (t_user->GetRecordCount() != 0)
	{
		//遍历t_user表  
		for(int i=0; t_user->IsEOF() != 1;i++)
		 {
			//MessageBox(t_user->m_Fullname);
			int j = 1;
			m_List.InsertItem(i,        (CString)t_user->m_Stuid);
			m_List.SetItemText(i, j++, (CString)t_user->m_Fullname);
			m_List.SetItemText(i, j++, (CString)t_user->m_Author);
			m_List.SetItemText(i, j++, (CString)t_user->m_Title);
			m_List.SetItemText(i, j++, (CString)t_user->m_Category);
			CString strDate;
			strDate = t_user->m_BorrowingTime.Format("%Y-%m-%d %H:%M:%S");
			m_List.SetItemText(i, j++, strDate);
			CString strValue;
			if (t_user->m_Ifreturn == true )
			{
				strValue = "true";
			}
			else
			{
				strValue = "false";
			}
			m_List.SetItemText(i, j++, strValue);
			t_user->MoveNext();
		} //while (t_user->IsEOF() != 1);
	}
}

	
	// TODO: 在此添加控件通知处理程序代码






void CMFCApplication8Dlg::OnBnClickedButton3()
{
	m_List.DeleteAllItems();
	CString m_edit2;
	GetDlgItemText(IDC_EDIT2, m_edit2);
	CString t_sql;
	t_sql.Format(L"select * from View_1 where [Full name]='%s'", m_edit2);
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
			t_user->MoveNext();
		} //while (t_user->IsEOF() != 1);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication8Dlg::OnBnClickedButton4()
{

	CString m_edit3;
	GetDlgItemText(IDC_EDIT3, m_edit3);
	CString t_sql1;
	CDatabase db;
	db.Open(_T("tushuguanli"), false, false, _T("ODBC;DSN=tushuguanli"), false);
	t_sql1.Format(L"exec del_jakljf %s", m_edit3);
	try
	{
		db.ExecuteSQL(t_sql1);
	}
	catch (CDBException* pe)
	{
		pe->ReportError();
		pe->Delete();
	}
	MessageBox(_T("删除成功"));

}


void CMFCApplication8Dlg::OnBnClickedButton5()
{
	CMyDlg dlg;
	//dlg1.Create(IDD_DIALOG2);
	//dlg1.ShowWindow(SW_SHOW);
	dlg.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication8Dlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
void CMFCApplication8Dlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}






void CMFCApplication8Dlg::OnDtnDatetimechangeDatetimepicker1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


BOOL CAboutDlg::OnInitDialog()
{
	


	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}











void CMFCApplication8Dlg::OnLbnSelchangeList1()
{

}


void CMFCApplication8Dlg::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CMFCApplication8Dlg::OnBnClickedButton6()
{
	CMyDlg1 dlg1;
	//dlg1.Create(IDD_DIALOG2);
	//dlg1.ShowWindow(SW_SHOW);
		dlg1.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication8Dlg::OnBnClickedButton7()
{
	MyDlg3 dlg2;
	//dlg1.Create(IDD_DIALOG2);
	//dlg1.ShowWindow(SW_SHOW);
	dlg2.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCApplication8Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialog::OnCancel();
}


void CMFCApplication8Dlg::OnBnClickedButton2()
{
	m_List.DeleteAllItems();
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

