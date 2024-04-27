// Tab4.cpp: 实现文件
//

#include "pch.h"
#include "MIMS.h"
#include "afxdialogex.h"
#include "Tab4.h"
#include "Alt3Dlg.h"
#include "UserDlg.h"


// Tab4 对话框

IMPLEMENT_DYNAMIC(Tab4, CDialogEx)

Tab4::Tab4(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB4, pParent)
{

}

Tab4::~Tab4()
{
}

void Tab4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Tab4, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTONtab4user, &Tab4::OnBnClickedButtontab4user)
	ON_BN_CLICKED(IDC_BUTTONtab4altpassword, &Tab4::OnBnClickedButtontab4altposswarld)
END_MESSAGE_MAP()


// Tab4 消息处理程序


void Tab4::OnBnClickedButtontab4altposswarld()
{
	// TODO: 在此添加控件通知处理程序代码
	Alt3Dlg Adlg;
	Adlg.DoModal();
}

void Tab4::OnBnClickedButtontab4user()
{
	// TODO: 在此添加控件通知处理程序代码

	if (!ViewUserPrivilege(Privilege, 8) && !ViewUserPrivilege(Privilege, 9) && !ViewUserPrivilege(Privilege, 10))
	{
		MessageBox("没有权限!");
		return;
	}

	UserDlg Udlg;
	Udlg.DoModal();
}


void Tab4::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void Tab4::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类
	if (MessageBox("是否确认退出?", "提示", MB_YESNO | MB_ICONQUESTION) == IDYES)
	{
		CDialog::OnCancel();
	}
}