#pragma once
#include "afxdialogex.h"


// Del2Dlg 对话框

class Del2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Del2Dlg)

public:
	Del2Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Del2Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEL2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox m_del2username;
	afx_msg void OnBnClickedOk();
};
