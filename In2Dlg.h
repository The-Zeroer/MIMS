#pragma once
#include "afxdialogex.h"


// In2Dlg 对话框

class In2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(In2Dlg)

public:
	In2Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~In2Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IN2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeComboin2id();
	virtual BOOL OnInitDialog();
	CComboBox m_in2id;
	CString m_in2name;
	CString m_in2type;
	CString m_in2num;
	afx_msg void OnBnClickedOk();
	virtual void OnCancel();
};
