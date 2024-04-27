// Add1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MIMS.h"
#include "afxdialogex.h"
#include "Add1Dlg.h"
#include "Tab2.h"


// Add1Dlg 对话框

IMPLEMENT_DYNAMIC(Add1Dlg, CDialogEx)

Add1Dlg::Add1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD1, pParent)
	, m_add1id(_T(""))
	, m_add1name(_T(""))
	, m_add1type(_T(""))
	, m_add1price(_T(""))
	, m_add1descr(_T(""))
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
	DDX_Text(pDX, IDC_EDITadd1descr, m_add1descr);
}


BEGIN_MESSAGE_MAP(Add1Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &Add1Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Add1Dlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// Add1Dlg 消息处理程序

void Add1Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	//判断货物信息是否完整
	if (m_add1id == "" || m_add1name == "" || m_add1type == "" || m_add1price == "")
	{
		MessageBox("货物信息不完整!");
		return;
	}

	//判断货物信息是否大于零
	if (atof(m_add1price) <= 0)
	{
		MessageBox("价格应当大于零!");
		return;
	}


	//获取新添加的货物信息
	goods gdata;
	gdata.id = m_add1id.GetString();
	gdata.name = m_add1name.GetString();
	gdata.type = m_add1type.GetString();
	gdata.price = atof(m_add1price);
	gdata.num = 0;
	gdata.descr = m_add1descr.GetString();
	if (gdata.descr == "")
	{
		gdata.descr = "无";
	}

	if (!AddGoods(L, gdata))
	{
		MessageBox("货物已存在!");
		return;
	}

	//添加操作日志
	opelog ldata;
	ldata.operate = "货物信息登记";
	ldata.username = UserName;
	ldata.time = time(NULL);

	if (!WriteGoods(L) || !WriteLog(gdata.id, ldata, 0))
	{
		MessageBeep(1);
		MessageBox("添加失败!");
		return;
	}

	//切换界面后更新信息的标志
	updateflag2 = 1;
	updateflag3 = 1;

	MessageBox("添加成功!");
	Add1Dlg::OnOK();
}


void Add1Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	Add1Dlg::OnCancel();
}


void Add1Dlg::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类

	CDialogEx::OnCancel();
}