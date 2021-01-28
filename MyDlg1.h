#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CMyDlg1 对话框

class CMyDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDlg1)

public:
	CMyDlg1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMyDlg1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	HICON m_hIcon;
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnEnChangeEdit7();
	afx_msg void OnEnChangeEdit8();
	CListCtrl m_List;
	char b;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
};
