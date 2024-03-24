// Add1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MIMS.h"
#include "afxdialogex.h"
#include "Add1Dlg.h"


// Add1Dlg 对话框

IMPLEMENT_DYNAMIC(Add1Dlg, CDialogEx)

Add1Dlg::Add1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD1, pParent)
	, m_add1id(_T(""))
	, m_add1name(_T(""))
	, m_add1type(_T(""))
	, m_add1price(_T(""))
{

}

Add1Dlg::~Add1Dlg()
{
}

void Add1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITadd1id, m_add1id);
	DDX_Text(pDX, IDC_EDITaad1name, m_add1name);
	DDX_Text(pDX, IDC_EDITadd1type, m_add1type);
	DDX_Text(pDX, IDC_EDITadd1price, m_add1price);
}


BEGIN_MESSAGE_MAP(Add1Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTONadd1ok, &Add1Dlg::OnBnClickedButtonadd1ok)
	ON_BN_CLICKED(IDC_BUTTONadd1cancel, &Add1Dlg::OnBnClickedButtonadd1cancel)
END_MESSAGE_MAP()


// Add1Dlg 消息处理程序

void Add1Dlg::OnBnClickedButtonadd1ok()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_add1id == "" || m_add1name == "" || m_add1type == "" || m_add1price == "")
	{
		MessageBox("货物信息不完整!");
		return;
	}

	LinkList tp = L;
	if (tp->next)
	{
		for (; tp->next; tp = tp->next)
		{
			if (m_add1id == tp->next->data.id.c_str() || (m_add1name == tp->next->data.name.c_str() && m_add1type == tp->next->data.type.c_str()))
			{
				MessageBox("此货物已存在!");
				return;
			}
		}
	}

	tp->next = new LNode;
	tp = tp->next;
	tp->data.id = m_add1id.GetString();
	tp->data.name = m_add1name.GetString();
	tp->data.type = m_add1type.GetString();
	tp->data.price = atoi(m_add1price);
	tp->data.num = 0;
	tp->data.descr = "无";
	tp->next = nullptr;

	fstream outfile;
	outfile.open("goods.txt", ios_base::app);
	if (outfile)
	{
		if (L->next->next)
		{
			outfile << '\n';
		}
		outfile << tp->data.id << '\t' << tp->data.name << '\t' << tp->data.type << '\t' << tp->data.price << '\t' << tp->data.num << '\t' << tp->data.descr;
		MessageBox("添加成功!");
		Add1Dlg::OnOK();
	}
	else
	{
		MessageBox("添加失败!");
		Add1Dlg::OnCancel();
	}

}


void Add1Dlg::OnBnClickedButtonadd1cancel()
{
	// TODO: 在此添加控件通知处理程序代码
	Add1Dlg::OnCancel();
}
