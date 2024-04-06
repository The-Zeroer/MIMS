// Tab3.cpp: 实现文件
//

#include "pch.h"
#include "MIMS.h"
#include "afxdialogex.h"
#include "Tab3.h"


// Tab3 对话框

IMPLEMENT_DYNAMIC(Tab3, CDialogEx)

Tab3::Tab3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TAB3, pParent)
	, m_tab3name(_T(""))
	, m_tab3type(_T(""))
	, m_tab3price(_T(""))
	, m_tab3num(_T(""))
	, m_tab3descr(_T(""))
	, m_tab3sumprice(_T(""))
{

}

Tab3::~Tab3()
{
}

void Tab3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST3, m_list3);
	DDX_Control(pDX, IDC_COMBOtab3id, m_tab3id);
	DDX_Text(pDX, IDC_EDITtab3name, m_tab3name);
	DDX_Text(pDX, IDC_EDITtab3type, m_tab3type);
	DDX_Text(pDX, IDC_EDITtab3price, m_tab3price);
	DDX_Text(pDX, IDC_EDITtab3num, m_tab3num);
	DDX_Text(pDX, IDC_EDITtab3descr, m_tab3descr);
	DDX_Text(pDX, IDC_EDITtab3sumprice, m_tab3sumprice);
}


BEGIN_MESSAGE_MAP(Tab3, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBOtab3id, &Tab3::OnCbnSelchangeCombotab3id)
	ON_BN_CLICKED(IDC_BUTTONtab3inq, &Tab3::OnBnClickedButtontab3inq)
END_MESSAGE_MAP()


// Tab3 消息处理程序


BOOL Tab3::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_list3.MoveWindow(20, 20, 1310, 1050);

	string folderPath = ".\\data\\log";
	// 是否有重名文件夹
	if (!PathIsDirectory(folderPath.c_str()))
	{
		::CreateDirectory(folderPath.c_str(), 0);
	}

	m_list3.CListCtrl::InsertColumn(0, "序号", LVCFMT_LEFT, 100);
	m_list3.CListCtrl::InsertColumn(1, "操作", LVCFMT_LEFT, 300);
	m_list3.CListCtrl::InsertColumn(2, "操作账户", LVCFMT_LEFT, 300);
	m_list3.CListCtrl::InsertColumn(3, "操作时间", LVCFMT_LEFT, 400);
	m_list3.SetExtendedStyle(LVS_EX_GRIDLINES);

	for (LinkList tp = L->next; tp; tp = tp->next)
	{
		m_tab3id.AddString(tp->data.id.c_str());
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void Tab3::OnCbnSelchangeCombotab3id()
{
	// TODO: 在此添加控件通知处理程序代码

	int i = 0;
	LinkList tp = L->next;
	for (; tp; tp = tp->next, i++)
	{
		if (i == m_tab3id.GetCurSel())
		{
			m_tab3name = tp->data.name.c_str();
			m_tab3type = tp->data.type.c_str();
			m_tab3price.Format("%.2f", tp->data.price);
			m_tab3num = to_string(tp->data.num).c_str();
			m_tab3sumprice.Format("%.2f", (tp->data.price * tp->data.num));
			m_tab3descr = tp->data.descr.c_str();
			UpdateData(FALSE);

			if (ViewUserPrivilege(Privilege, 7))
			{
				CString dataid;
				m_tab3id.GetLBText(m_tab3id.GetCurSel(), dataid);
				if (ReadLog(LogL, dataid.GetString()))
				{
					m_list3.DeleteAllItems();
					LogLinkList tp = LogL->next;
					int i = 0;
					for (; tp; tp = tp->next, i++)
					{
						m_list3.InsertItem(i, to_string(i + 1).c_str());
						m_list3.SetItemText(i, 1, tp->data.operate.c_str());
						m_list3.SetItemText(i, 2, tp->data.username.c_str());
						m_list3.SetItemText(i, 3, TimeToString(tp->data.time).c_str());
					}
				}
			}
		}
	}
}


void Tab3::OnBnClickedButtontab3inq()
{
	// TODO: 在此添加控件通知处理程序代码

	if (!ViewUserPrivilege(Privilege, 7))
	{
		MessageBox("没有权限!");
		return;
	}

	UpdateData(TRUE);

	CString dataid;
	if (m_tab3id.GetCurSel() == -1)
	{
		((CComboBox*)GetDlgItem(IDC_COMBOtab3id))->GetWindowText(dataid);
		if (dataid == "")
		{
			MessageBox("货物编号不能为空!");
			return;
		}

		int i = 0, flag = 1;
		LinkList tp = L->next;
		for (; tp; tp = tp->next, i++)
		{
			if (tp->data.id == dataid.GetString())
			{
				m_tab3name = tp->data.name.c_str();
				m_tab3type = tp->data.type.c_str();
				m_tab3price.Format("%.2f", tp->data.price);
				m_tab3num = to_string(tp->data.num).c_str();
				m_tab3sumprice.Format("%.2f", (tp->data.price * tp->data.num));
				m_tab3descr = tp->data.descr.c_str();
				UpdateData(FALSE);
				flag = 0;
				break;
			}
		}

		if (flag)
		{
			MessageBox("货物不存在!");
			return;
		}
	}
	else
	{
		m_tab3id.GetLBText(m_tab3id.GetCurSel(), dataid);
	}

	if (!ReadLog(LogL, dataid.GetString()))
	{
		MessageBox("文件不存在!");
		return;
	}

	m_list3.DeleteAllItems();
	LogLinkList tp = LogL->next;
	int i = 0;
	for (; tp; tp = tp->next, i++)
	{
		m_list3.InsertItem(i, to_string(i + 1).c_str());
		m_list3.SetItemText(i, 1, tp->data.operate.c_str());
		m_list3.SetItemText(i, 2, tp->data.username.c_str());
		m_list3.SetItemText(i, 3, TimeToString(tp->data.time).c_str());
	}
}


void Tab3::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialogEx::OnOK();
}


void Tab3::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类
	if (MessageBox("是否确认退出?", "提示", MB_YESNO | MB_ICONQUESTION) == IDYES)
	{
		CDialog::OnCancel();
	}
}
