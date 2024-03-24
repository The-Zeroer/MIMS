﻿#pragma once
#include "afxdialogex.h"


// Tab1 对话框

class Tab1 : public CDialogEx
{
	DECLARE_DYNAMIC(Tab1)

public:
	Tab1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Tab1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton11();
	CListCtrl m_list1;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButtonadd1();
	afx_msg void OnBnClickedButtondel1();
	afx_msg void OnBnClickedButtonalt1();
};
