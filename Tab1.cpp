// Tab1.cpp: 实现文件
//

#include "pch.h"
#include "MIMS.h"
#include "afxdialogex.h"
#include "Tab1.h"

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
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &Tab1::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTONadd1, &Tab1::OnBnClickedButtonadd1)
	ON_BN_CLICKED(IDC_BUTTONdel1, &Tab1::OnBnClickedButtondel1)
	ON_BN_CLICKED(IDC_BUTTONalt1, &Tab1::OnBnClickedButtonalt1)
END_MESSAGE_MAP()


// Tab1 消息处理程序


BOOL Tab1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	if (!InitList(L))
	{
		MessageBox("程序初始化失败!");
		exit(-1);
	}
	if (!ReadGoods(L))
	{
		MessageBox("文件不存在且创建失败!");
	}

	m_list1.CListCtrl::InsertColumn(0, "序号", LVCFMT_LEFT, 100);
	m_list1.CListCtrl::InsertColumn(1, "编号", LVCFMT_LEFT, 200);
	m_list1.CListCtrl::InsertColumn(2, "名称", LVCFMT_LEFT, 200);
	m_list1.CListCtrl::InsertColumn(3, "类型", LVCFMT_LEFT, 200);
	m_list1.CListCtrl::InsertColumn(4, "单价", LVCFMT_LEFT, 200);
	m_list1.SetExtendedStyle(LVS_EX_GRIDLINES);
	LinkList tp = nullptr;
	int i = 0;
	for (tp = L->next, i = 0; tp; tp = tp->next, i++)
	{
		string temp = to_string(i + 1);
		m_list1.InsertItem(i, temp.c_str());
		m_list1.SetItemText(i, 1, tp->data.id.c_str());
		m_list1.SetItemText(i, 2, tp->data.name.c_str());
		m_list1.SetItemText(i, 3, tp->data.type.c_str());
		temp = to_string(tp->data.price);
		m_list1.SetItemText(i, 4, temp.c_str());
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void Tab1::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void Tab1::OnBnClickedButtonadd1()
{
	// TODO: 在此添加控件通知处理程序代码
	Add1Dlg A1dlg;
	INT_PTR choose = A1dlg.DoModal();
	if (choose == IDOK)
	{
		m_list1.DeleteAllItems();
		LinkList tp = nullptr;
		int i = 0;
		for (tp = L->next, i = 0; tp; tp = tp->next, i++)
		{
			string temp = to_string(i + 1);
			m_list1.InsertItem(i, temp.c_str());
			m_list1.SetItemText(i, 1, tp->data.id.c_str());
			m_list1.SetItemText(i, 2, tp->data.name.c_str());
			m_list1.SetItemText(i, 3, tp->data.type.c_str());
			temp = to_string(tp->data.price);
			m_list1.SetItemText(i, 4, temp.c_str());
		}
	}
}


void Tab1::OnBnClickedButtondel1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Tab1::OnBnClickedButtonalt1()
{
	// TODO: 在此添加控件通知处理程序代码
}
