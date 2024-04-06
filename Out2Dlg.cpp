// Out2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MIMS.h"
#include "afxdialogex.h"
#include "Out2Dlg.h"


// Out2Dlg 对话框

IMPLEMENT_DYNAMIC(Out2Dlg, CDialogEx)

Out2Dlg::Out2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OUT2, pParent)
	, m_out2name(_T(""))
	, m_out2type(_T(""))
	, m_out2num(_T(""))
{

}

Out2Dlg::~Out2Dlg()
{
}

void Out2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBOout2id, m_out2id);
	DDX_Text(pDX, IDC_out2name, m_out2name);
	DDX_Text(pDX, IDC_EDITout2type, m_out2type);
	DDX_Text(pDX, IDC_EDITout2num, m_out2num);
}


BEGIN_MESSAGE_MAP(Out2Dlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBOout2id, &Out2Dlg::OnCbnSelchangeComboout2id)
	ON_BN_CLICKED(IDOK, &Out2Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Out2Dlg 消息处理程序

int tempout = 0;

BOOL Out2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	for (LinkList tp = L->next; tp; tp = tp->next)
	{
		m_out2id.AddString(tp->data.id.c_str());
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void Out2Dlg::OnCbnSelchangeComboout2id()
{
	// TODO: 在此添加控件通知处理程序代码

	int i = 0;
	for (LinkList tp = L->next; tp; tp = tp->next, i++)
	{
		if (i == m_out2id.GetCurSel())
		{
			m_out2name = tp->data.name.c_str();
			m_out2type = tp->data.type.c_str();
			UpdateData(FALSE);
			tempout = tp->data.num;
		}
	}


}


void Out2Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码UpdateData(TRUE);

	UpdateData(TRUE);

	CString dataid;
	if (m_out2id.GetCurSel() == -1)
	{
		((CComboBox*)GetDlgItem(IDC_COMBOout2id))->GetWindowText(dataid);
		if (dataid == "")
		{
			MessageBox("货物编号不能为空!");
		}
		int i = 0, flag = 1;
		LinkList tp = L->next;
		for (; tp; tp = tp->next, i++)
		{
			if (tp->data.id == dataid.GetString())
			{
				m_out2name = tp->data.name.c_str();
				m_out2type = tp->data.type.c_str();
				UpdateData(FALSE);
				tempout = tp->data.num;
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
		m_out2id.GetLBText(m_out2id.GetCurSel(), dataid);
	}

	if (atoi(m_out2num) <= 0)
	{
		MessageBox("变化数量错误!");
		return;
	}

	goods data;
	data.id = dataid.GetString();
	data.num = tempout - atoi(m_out2num);

	if (data.num < 0)
	{
		MessageBox("货物剩余数量小于零!");
		return;
	}

	opelog logdata;
	logdata.operate = "货物出库登记:-";
	logdata.operate += m_out2num.GetString();
	logdata.username = UserName;
	logdata.time = time(NULL);

	if (!AltGoods(L, data, 2) || !WriteGoods(L) || !WriteLog(data.id, logdata, 1))
	{
		MessageBox("出库登记失败!");
		return;
	}

	MessageBox("出库登记成功!");
	Out2Dlg::OnOK();
}



void Out2Dlg::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类

	CDialogEx::OnCancel();
}
