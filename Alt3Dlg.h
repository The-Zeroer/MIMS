#pragma once
#include "afxdialogex.h"


// ALT3Dlg 对话框

class Alt3Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Alt3Dlg)

public:
	Alt3Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Alt3Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ALT3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_passworld1;
	CString m_passworld2;
	CString m_passworld3;
	afx_msg void OnBnClickedOk();
};
