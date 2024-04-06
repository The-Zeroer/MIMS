
// MIMSDlg.h: 头文件
//
#include "pch.h"
#include "Tab1.h"
#include "Tab2.h"
#include "Tab3.h"
#include "Tab4.h"
#pragma once


// CMIMSDlg 对话框
class CMIMSDlg : public CDialog
{
// 构造
public:
	CMIMSDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MIMS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	Tab1 m_tab1;
	Tab2 m_tab2;
	Tab3 m_tab3;
	Tab4 m_tab4;
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnTcnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult);
};
