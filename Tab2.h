#pragma once
#include "afxdialogex.h"


// Tab2 对话框

class Tab2 : public CDialogEx
{
	DECLARE_DYNAMIC(Tab2)

public:
	Tab2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Tab2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list2;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonin2();
	afx_msg void OnBnClickedButtonout2();
	virtual void OnOK();
	virtual void OnCancel();
};
