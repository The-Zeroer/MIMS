// Tab1.cpp: 实现文件
//

#include "pch.h"
#include "MIMS.h"
#include "afxdialogex.h"
#include "Tab1.h"
#include "Add1Dlg.h"
#include "Del1Dlg.h"
#include "Alt1Dlg.h"

// Tab1 对话框

IMPLEMENT_DYNAMIC(Tab1, CDialogEx)

Tab1::Tab1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB1, pParent)
{

}

Tab1::~Tab1()
{
}

void Tab1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list1);
}


BEGIN_MESSAGE_MAP(Tab1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTONadd1, &Tab1::OnBnClickedButtonadd1)
	ON_BN_CLICKED(IDC_BUTTONdel1, &Tab1::OnBnClickedButtondel1)
	ON_BN_CLICKED(IDC_BUTTONalt1, &Tab1::OnBnClickedButtonalt1)
END_MESSAGE_MAP()


// Tab1 消息处理程序


BOOL Tab1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_list1.MoveWindow(20, 20, 1310, 1050);

	m_list1.CListCtrl::InsertColumn(0, "序号", LVCFMT_LEFT, 100);
	m_list1.CListCtrl::InsertColumn(1, "编号", LVCFMT_LEFT, 200);
	m_list1.CListCtrl::InsertColumn(2, "名称", LVCFMT_LEFT, 200);
	m_list1.CListCtrl::InsertColumn(3, "类型", LVCFMT_LEFT, 200);
	m_list1.CListCtrl::InsertColumn(4, "单价", LVCFMT_LEFT, 200);
	m_list1.CListCtrl::InsertColumn(5, "备注", LVCFMT_LEFT, 400);
	m_list1.SetExtendedStyle(LVS_EX_GRIDLINES);

	LinkList tp = L->next;
	int i = 0;
	for (; tp; tp = tp->next, i++)
	{
		m_list1.InsertItem(i, to_string(i + 1).c_str());
		m_list1.SetItemText(i, 1, tp->data.id.c_str());
		m_list1.SetItemText(i, 2, tp->data.name.c_str());
		m_list1.SetItemText(i, 3, tp->data.type.c_str());
		CString tempprice;
		tempprice.Format("%.2f", tp->data.price);
		m_list1.SetItemText(i, 4, tempprice);
		m_list1.SetItemText(i, 5, tp->data.descr.c_str());
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void Tab1::OnBnClickedButtonadd1()
{
	// TODO: 在此添加控件通知处理程序代码

	if (!ViewUserPrivilege(Privilege, 1))
	{
		MessageBox("没有权限!");
		return;
	}

	Add1Dlg Add1dlg;
	INT_PTR choose = Add1dlg.DoModal();
	if (choose == IDOK)
	{
		LinkList tp = L->next;
		int i = 0;
		while(tp->next)
		{
			tp = tp->next;
			i++;
		}
		m_list1.InsertItem(i, to_string(i + 1).c_str());
		m_list1.SetItemText(i, 1, tp->data.id.c_str());
		m_list1.SetItemText(i, 2, tp->data.name.c_str());
		m_list1.SetItemText(i, 3, tp->data.type.c_str());
		CString tempprice;
		tempprice.Format("%.2f", tp->data.price);
		m_list1.SetItemText(i, 4, tempprice);
		m_list1.SetItemText(i, 5, tp->data.descr.c_str());
		i++;
	}
}


void Tab1::OnBnClickedButtondel1()
{
	// TODO: 在此添加控件通知处理程序代码

	if (!ViewUserPrivilege(Privilege, 2))
	{
		MessageBox("没有权限!");
		return;
	}

	Del1Dlg Del1dlg;
	INT_PTR choose = Del1dlg.DoModal();
	if (choose == IDOK)
	{
		m_list1.DeleteAllItems();
		LinkList tp = L->next;
		int i = 0;
		for (; tp; tp = tp->next, i++)
		{
			m_list1.InsertItem(i, to_string(i + 1).c_str());
			m_list1.SetItemText(i, 1, tp->data.id.c_str());
			m_list1.SetItemText(i, 2, tp->data.name.c_str());
			m_list1.SetItemText(i, 3, tp->data.type.c_str());
			CString tempprice;
			tempprice.Format("%.2f", tp->data.price);
			m_list1.SetItemText(i, 4, tempprice);
			m_list1.SetItemText(i, 5, tp->data.descr.c_str());
		}
	}
}


void Tab1::OnBnClickedButtonalt1()
{
	// TODO: 在此添加控件通知处理程序代码

	if (!ViewUserPrivilege(Privilege, 3))
	{
		MessageBox("没有权限!");
		return;
	}

	Alt1Dlg Alt1dlg;
	INT_PTR choose = Alt1dlg.DoModal();
	if (choose == IDOK)
	{
		m_list1.DeleteAllItems();
		LinkList tp = L->next;
		int i = 0;
		for (; tp; tp = tp->next, i++)
		{
			m_list1.InsertItem(i, to_string(i + 1).c_str());
			m_list1.SetItemText(i, 1, tp->data.id.c_str());
			m_list1.SetItemText(i, 2, tp->data.name.c_str());
			m_list1.SetItemText(i, 3, tp->data.type.c_str());
			CString tempprice;
			tempprice.Format("%.2f", tp->data.price);
			m_list1.SetItemText(i, 4, tempprice);
			m_list1.SetItemText(i, 5, tp->data.descr.c_str());
		}
	}
}

void Tab1::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void Tab1::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类
	if (MessageBox("是否确认退出?", "提示", MB_YESNO | MB_ICONQUESTION) == IDYES)
	{
		CDialog::OnCancel();
	}
}
