#pragma once
#include "afxdialogex.h"


// LoginDlg 对话框

class LoginDlg : public CDialog
{
	DECLARE_DYNAMIC(LoginDlg)

public:
	LoginDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~LoginDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString m_username;
	CString m_passworld;
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	CButton m_checklogin;
	afx_msg void OnBnClickedChecklogin();
};
