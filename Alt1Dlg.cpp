// Alt1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MIMS.h"
#include "afxdialogex.h"
#include "Alt1Dlg.h"


// Alt1Dlg 对话框

IMPLEMENT_DYNAMIC(Alt1Dlg, CDialogEx)

Alt1Dlg::Alt1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ALT1, pParent)
	, m_alt1name(_T(""))
	, m_alt1type(_T(""))
	, m_alt1price(_T(""))
	, m_alt1descr(_T(""))
{

}

Alt1Dlg::~Alt1Dlg()
{
}

void Alt1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBOalt1id, m_alt1id);
	DDX_Text(pDX, IDC_EDITalt1name, m_alt1name);
	DDX_Text(pDX, IDC_EDITalt1type, m_alt1type);
	DDX_Text(pDX, IDC_EDITalt1price, m_alt1price);
	DDX_Text(pDX, IDC_EDITalt1descr, m_alt1descr);
}


BEGIN_MESSAGE_MAP(Alt1Dlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBOalt1id, &Alt1Dlg::OnCbnSelchangeComboalt1id)
	ON_BN_CLICKED(IDOK, &Alt1Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Alt1Dlg 消息处理程序


BOOL Alt1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//设置下拉列表选项
	for (LinkList tp = L->next; tp; tp = tp->next)
	{
		m_alt1id.AddString(tp->data.id.c_str());
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void Alt1Dlg::OnCbnSelchangeComboalt1id()
{
	// TODO: 在此添加控件通知处理程序代码

	//显示对应的货物信息
	int i = 0;
	for (LinkList tp = L->next; tp; tp = tp->next, i++)
	{
		if (i == m_alt1id.GetCurSel())
		{
			m_alt1name = tp->data.name.c_str();
			m_alt1type = tp->data.type.c_str();
			m_alt1price.Format("%.2f", tp->data.price);
			m_alt1descr = tp->data.descr.c_str();
			UpdateData(FALSE);
		}
	}
}

void Alt1Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	//判断修改后的货物信息是否完整
	if (m_alt1name == "" || m_alt1type == "" || m_alt1price == "")
	{
		MessageBox("货物信息不完整!");
		return;
	}

	//判断修改后的货物价格是否大于零
	if (atof(m_alt1price) <= 0)
	{
		MessageBox("价格应当大于零!");
		return;
	}

	//获取修改后的货物信息
	CString dataid;
	m_alt1id.GetLBText(m_alt1id.GetCurSel(), dataid);
	goods gdata;
	gdata.id = dataid.GetString();
	gdata.name = m_alt1name.GetString();
	gdata.type = m_alt1type.GetString();
	gdata.price = atof(m_alt1price);
	gdata.descr = m_alt1descr.GetString();
	if (gdata.descr == "")
	{
		gdata.descr = "无";
	}

	if (!AltGoods(L, gdata, 1))
	{
		MessageBox("货物信息重复!");
		return;
	}

	//添加操作日志
	opelog ldata;
	ldata.operate = "货物信息修改";
	ldata.username = UserName;
	ldata.time = time(NULL);

	if (!WriteGoods(L) || !WriteLog(gdata.id, ldata, 1))
	{
		MessageBox("修改失败!");
		return;
	}

	//切换界面后更新信息的标志
	updateflag2 = 1;
	updateflag3 = 1;

	MessageBox("修改成功!");
	Alt1Dlg::OnOK();
}


void Alt1Dlg::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类

	CDialogEx::OnCancel();
}