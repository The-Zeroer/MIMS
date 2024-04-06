#pragma once
#include "afxdialogex.h"


// Out2Dlg 对话框

class Out2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Out2Dlg)

public:
	Out2Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Out2Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OUT2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeComboout2id();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CComboBox m_out2id;
	CString m_out2name;
	CString m_out2type;
	CString m_out2num;
	virtual void OnCancel();
};
