#pragma once
#include "afxdialogex.h"


// Add1Dlg 对话框

class Add1Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Add1Dlg)

public:
	Add1Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Add1Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_add1id;
	CString m_add1name;
	CString m_add1type;
	CString m_add1price;
	CString m_add1descr;
	void OnBnClickedButtonadd1ok();
	afx_msg void OnBnClickedButtonadd1cancel();
	virtual void OnCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
