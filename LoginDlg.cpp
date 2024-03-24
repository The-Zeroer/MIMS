// LoginDlg.cpp: 实现文件
//

#include "pch.h"
#include "MIMS.h"
#include "afxdialogex.h"


// LoginDlg 对话框

IMPLEMENT_DYNAMIC(LoginDlg, CDialog)

LoginDlg::LoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_LOGIN, pParent)
	, m_username(_T(""))
	, m_passworld(_T(""))
{

}

LoginDlg::~LoginDlg()
{
}

void LoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_username);
	DDX_Text(pDX, IDC_EDIT2, m_passworld);
}


BEGIN_MESSAGE_MAP(LoginDlg, CDialog)
	ON_BN_CLICKED(IDOK, &LoginDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &LoginDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// LoginDlg 消息处理程序


void LoginDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_username == "" || m_passworld == "")
		MessageBox("用户名或密码不能为空");
	else if(m_username=="123"&&m_passworld=="123")
		CDialog::OnOK();
	else
		MessageBox("用户名或密码错误");

}


void LoginDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}
