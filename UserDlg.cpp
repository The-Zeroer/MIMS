// UserDlg.cpp: 实现文件
//

#include "pch.h"
#include "MIMS.h"
#include "afxdialogex.h"
#include "UserDlg.h"
#include "Add2Dlg.h"
#include "Del2Dlg.h"
#include "Alt2Dlg.h"


// UserDlg 对话框

IMPLEMENT_DYNAMIC(UserDlg, CDialogEx)

UserDlg::UserDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_USER, pParent)
{

}

UserDlg::~UserDlg()
{
}

void UserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST4, m_list4);
}


BEGIN_MESSAGE_MAP(UserDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTONuseradd, &UserDlg::OnBnClickedButtonuseradd)
	ON_BN_CLICKED(IDC_BUTTONuserdel, &UserDlg::OnBnClickedButtonuserdel)
	ON_BN_CLICKED(IDC_BUTTONalt2, &UserDlg::OnBnClickedButtonalt2)
END_MESSAGE_MAP()


// UserDlg 消息处理程序

BOOL UserDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_list4.CListCtrl::InsertColumn(0, "序号", LVCFMT_LEFT, 100);
	m_list4.CListCtrl::InsertColumn(1, "用户名", LVCFMT_LEFT, 200);
	m_list4.CListCtrl::InsertColumn(2, "添加人员", LVCFMT_LEFT, 200);
	m_list4.CListCtrl::InsertColumn(3, "添加时间", LVCFMT_LEFT, 300);
	m_list4.SetExtendedStyle(LVS_EX_GRIDLINES);

	UserLinkList tp = UserL->next;
	int i = 0;
	for (; tp; tp = tp->next, i++)
	{
		m_list4.InsertItem(i, to_string(i + 1).c_str());
		m_list4.SetItemText(i, 1, tp->data.username.c_str());
		m_list4.SetItemText(i, 2, tp->data.reguser.c_str());
		m_list4.SetItemText(i, 3, TimeToString(tp->data.time).c_str());
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void UserDlg::OnBnClickedButtonuseradd()
{
	// TODO: 在此添加控件通知处理程序代码

	if (!ViewUserPrivilege(Privilege, 8))
	{
		MessageBox("没有权限!");
		return;
	}
	Add2Dlg Add2dlg;
	INT_PTR choose = Add2dlg.DoModal();
	if (choose == IDOK)
	{
		UserLinkList tp = UserL->next;
		int i = 0;
		while (tp->next)
		{
			tp = tp->next;
			i++;
		}
		m_list4.InsertItem(i, to_string(i + 1).c_str());
		m_list4.SetItemText(i, 1, tp->data.username.c_str());
		m_list4.SetItemText(i, 2, tp->data.reguser.c_str());
		m_list4.SetItemText(i, 3, TimeToString(tp->data.time).c_str());
	}
}


void UserDlg::OnBnClickedButtonuserdel()
{
	// TODO: 在此添加控件通知处理程序代码

	if (!ViewUserPrivilege(Privilege, 9))
	{
		MessageBox("没有权限!");
		return;
	}
	Del2Dlg Del2dlg;
	INT_PTR choose = Del2dlg.DoModal();
	if (choose == IDOK)
	{
		m_list4.DeleteAllItems();
		UserLinkList tp = UserL->next;
		int i = 0;
		for (; tp; tp = tp->next, i++)
		{
			m_list4.InsertItem(i, to_string(i + 1).c_str());
			m_list4.SetItemText(i, 1, tp->data.username.c_str());
			m_list4.SetItemText(i, 2, tp->data.reguser.c_str());
			m_list4.SetItemText(i, 3, TimeToString(tp->data.time).c_str());
		}
	}
}


void UserDlg::OnBnClickedButtonalt2()
{
	// TODO: 在此添加控件通知处理程序代码

	if (!ViewUserPrivilege(Privilege, 10))
	{
		MessageBox("没有权限!");
		return;
	}
	Alt2Dlg Alt2dlg;
	Alt2dlg.DoModal();
}