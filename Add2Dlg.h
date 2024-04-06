#pragma once
#include "afxdialogex.h"


// Add2Dlg 对话框

class Add2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Add2Dlg)

public:
	Add2Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Add2Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString m_add2username;
	CString m_add2passworld1;
	CString m_add2passworld2;
	CButton m_checkadd1;
	CButton m_checkadd2;
	CButton m_checkadd3;
	CButton m_checkadd4;
	CButton m_checkadd5;
	CButton m_checkadd6;
	CButton m_checkadd7;
	CButton m_checkadd8;
	CButton m_checkadd9;
	CButton m_checkadd10;
	afx_msg void OnBnClickedOk();
};
