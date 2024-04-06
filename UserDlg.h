#pragma once
#include "afxdialogex.h"


// UserDlg 对话框

class UserDlg : public CDialogEx
{
	DECLARE_DYNAMIC(UserDlg)

public:
	UserDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~UserDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonuseradd();
	afx_msg void OnBnClickedButtonuserdel();
	afx_msg void OnBnClickedButtonalt2();
	CListCtrl m_list4;
	virtual BOOL OnInitDialog();
};
