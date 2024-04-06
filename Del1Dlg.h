#pragma once
#include "afxdialogex.h"


// Del1Dlg 对话框

class Del1Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Del1Dlg)

public:
	Del1Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Del1Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEL1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox m_del1id;
	CString m_del1name;
	CString m_del1type;
	afx_msg void OnCbnSelchangeCombodel1id();
	afx_msg void OnBnClickedOk();
	virtual void OnCancel();
};
