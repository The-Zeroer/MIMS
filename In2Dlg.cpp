// In2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MIMS.h"
#include "afxdialogex.h"
#include "In2Dlg.h"


// In2Dlg 对话框

IMPLEMENT_DYNAMIC(In2Dlg, CDialogEx)

In2Dlg::In2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_IN2, pParent)
	, m_in2name(_T(""))
	, m_in2type(_T(""))
	, m_in2num(_T(""))
{

}

In2Dlg::~In2Dlg()
{
}

void In2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBOin2id, m_in2id);
	DDX_Text(pDX, IDC_EDITin2name, m_in2name);
	DDX_Text(pDX, IDC_EDITin2type, m_in2type);
	DDX_Text(pDX, IDC_EDITin2num, m_in2num);
}


BEGIN_MESSAGE_MAP(In2Dlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBOin2id, &In2Dlg::OnCbnSelchangeComboin2id)
	ON_BN_CLICKED(IDOK, &In2Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// In2Dlg 消息处理程序

int tempin = 0;

BOOL In2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	for (LinkList tp = L->next; tp; tp = tp->next)
	{
		m_in2id.AddString(tp->data.id.c_str());
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void In2Dlg::OnCbnSelchangeComboin2id()
{
	// TODO: 在此添加控件通知处理程序代码

	int i = 0;
	LinkList tp = L->next;
	for (; tp; tp = tp->next, i++)
	{
		if (i == m_in2id.GetCurSel())
		{
			m_in2name = tp->data.name.c_str();
			m_in2type = tp->data.type.c_str();
			UpdateData(FALSE);
			tempin = tp->data.num;
		}
	}
}

void In2Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	CString dataid;
	if (m_in2id.GetCurSel() == -1)
	{
		((CComboBox*)GetDlgItem(IDC_COMBOin2id))->GetWindowText(dataid);
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
				m_in2name = tp->data.name.c_str();
				m_in2type = tp->data.type.c_str();
				UpdateData(FALSE);
				tempin = tp->data.num;
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
		m_in2id.GetLBText(m_in2id.GetCurSel(), dataid);
	}


	if (atoi(m_in2num) <= 0)
	{
		MessageBox("变化数量错误!");
		return;
	}

	goods data;
	data.id = dataid.GetString();
	data.num = tempin + atoi(m_in2num);

	opelog logdata;
	logdata.operate = "货物入库登记:+";
	logdata.operate += m_in2num.GetString();
	logdata.username = UserName;
	logdata.time = time(NULL);

	if (!AltGoods(L, data, 2) || !WriteGoods(L) || !WriteLog(data.id, logdata, 1))
	{
		MessageBox("入库登记失败!");
		return;
	}

	MessageBox("入库登记成功!");
	In2Dlg::OnOK();
}


void In2Dlg::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类

	CDialogEx::OnCancel();
}
