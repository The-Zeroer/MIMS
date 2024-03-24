#pragma once
#include "afxdialogex.h"


// Tab3 对话框

class Tab3 : public CDialogEx
{
	DECLARE_DYNAMIC(Tab3)

public:
	Tab3(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Tab3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
