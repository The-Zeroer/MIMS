#pragma once
#include "afxdialogex.h"


// Tab4 对话框

class Tab4 : public CDialogEx
{
	DECLARE_DYNAMIC(Tab4)

public:
	Tab4(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Tab4();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtontab4user();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBnClickedButtontab4altposswarld();
};
