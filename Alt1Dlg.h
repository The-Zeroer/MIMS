#pragma once
#include "afxdialogex.h"


// Alt1Dlg 对话框

class Alt1Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Alt1Dlg)

public:
	Alt1Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Alt1Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ALT1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_alt1id;
	CString m_alt1name;
	CString m_alt1type;
	CString m_alt1price;
	CString m_alt1descr;
	afx_msg void OnCbnSelchangeComboalt1id();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	virtual void OnCancel();
};
