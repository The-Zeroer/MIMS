// Tab2.cpp: 实现文件
//

#include "pch.h"
#include "MIMS.h"
#include "afxdialogex.h"
#include "Tab2.h"
#include "In2Dlg.h"
#include "Out2Dlg.h"



// Tab2 对话框

IMPLEMENT_DYNAMIC(Tab2, CDialogEx)

Tab2::Tab2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB2, pParent)
{

}

Tab2::~Tab2()
{
}

void Tab2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list2);
}


BEGIN_MESSAGE_MAP(Tab2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTONin2, &Tab2::OnBnClickedButtonin2)
	ON_BN_CLICKED(IDC_BUTTONout2, &Tab2::OnBnClickedButtonout2)
END_MESSAGE_MAP()


// Tab2 消息处理程序


BOOL Tab2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_list2.MoveWindow(20, 20, 1310, 1050);

	m_list2.CListCtrl::InsertColumn(0, "序号", LVCFMT_LEFT, 100);
	m_list2.CListCtrl::InsertColumn(1, "编号", LVCFMT_LEFT, 200);
	m_list2.CListCtrl::InsertColumn(2, "名称", LVCFMT_LEFT, 200);
	m_list2.CListCtrl::InsertColumn(3, "类型", LVCFMT_LEFT, 200);
	m_list2.CListCtrl::InsertColumn(4, "数量", LVCFMT_LEFT, 200);
	m_list2.SetExtendedStyle(LVS_EX_GRIDLINES);

	LinkList tp = L->next;
	int i = 0;
	for (; tp; tp = tp->next, i++)
	{
		m_list2.InsertItem(i, to_string(i + 1).c_str());
		m_list2.SetItemText(i, 1, tp->data.id.c_str());
		m_list2.SetItemText(i, 2, tp->data.name.c_str());
		m_list2.SetItemText(i, 3, tp->data.type.c_str());
		m_list2.SetItemText(i, 4, to_string(tp->data.num).c_str());
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void Tab2::OnBnClickedButtonin2()
{
	// TODO: 在此添加控件通知处理程序代码

	if (!ViewUserPrivilege(Privilege, 4))
	{
		MessageBox("没有权限!");
		return;
	}

	In2Dlg I2dlg;
	INT_PTR choose = I2dlg.DoModal();
	if (choose == IDOK)
	{
		m_list2.DeleteAllItems();
		LinkList tp = L->next;
		int i = 0;
		for (; tp; tp = tp->next, i++)
		{
			m_list2.InsertItem(i, to_string(i + 1).c_str());
			m_list2.SetItemText(i, 1, tp->data.id.c_str());
			m_list2.SetItemText(i, 2, tp->data.name.c_str());
			m_list2.SetItemText(i, 3, tp->data.type.c_str());
			m_list2.SetItemText(i, 4, to_string(tp->data.num).c_str());
		}
	}
}


void Tab2::OnBnClickedButtonout2()
{
	// TODO: 在此添加控件通知处理程序代码

	if (!ViewUserPrivilege(Privilege, 5))
	{
		MessageBox("没有权限!");
		return;
	}

	Out2Dlg O2dlg;
	INT_PTR choose = O2dlg.DoModal();
	if (choose == IDOK)
	{
		m_list2.DeleteAllItems();
		LinkList tp = L->next;
		int i = 0;
		for (; tp; tp = tp->next, i++)
		{
			m_list2.InsertItem(i, to_string(i + 1).c_str());
			m_list2.SetItemText(i, 1, tp->data.id.c_str());
			m_list2.SetItemText(i, 2, tp->data.name.c_str());
			m_list2.SetItemText(i, 3, tp->data.type.c_str());
			m_list2.SetItemText(i, 4, to_string(tp->data.num).c_str());
		}
	}
}

void Tab2::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}

void Tab2::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类
	if (MessageBox("是否确认退出?", "提示", MB_YESNO | MB_ICONQUESTION) == IDYES)
	{
		CDialog::OnCancel();
	}
}


