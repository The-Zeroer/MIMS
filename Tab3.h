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
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_list3;
	CComboBox m_tab3id;
	CString m_tab3name;
	CString m_tab3type;
	CString m_tab3price;
	CString m_tab3num;
	CString m_tab3descr;
	afx_msg void OnCbnSelchangeCombotab3id();
	afx_msg void OnBnClickedButtontab3inq();
	virtual void OnOK();
	virtual void OnCancel();
	CString m_tab3sumprice;
};
