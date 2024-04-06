#pragma once
#include "afxdialogex.h"


// Alt2Dlg 对话框

class Alt2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Alt2Dlg)

public:
	Alt2Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Alt2Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ALT2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeComboalt2username();
	virtual BOOL OnInitDialog();
	CComboBox m_alt2username;
	CButton m_checkalt1;
	CButton m_checkalt2;
	CButton m_checkalt3;
	CButton m_checkalt4;
	CButton m_checkalt5;
	CButton m_checkalt6;
	CButton m_checkalt7;
	CButton m_checkalt8;
	CButton m_checkalt9;
	CButton m_checkalt10;
	afx_msg void OnBnClickedOk();
};
