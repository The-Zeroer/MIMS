// Add2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MIMS.h"
#include "afxdialogex.h"
#include "Add2Dlg.h"


// Add2Dlg 对话框

IMPLEMENT_DYNAMIC(Add2Dlg, CDialogEx)

Add2Dlg::Add2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD2, pParent)
	, m_add2username(_T(""))
	, m_add2password1(_T(""))
	, m_add2password2(_T(""))
{

}

Add2Dlg::~Add2Dlg()
{
}

void Add2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITadd2username, m_add2username);
	DDX_Text(pDX, IDC_EDITadd2password1, m_add2password1);
	DDX_Text(pDX, IDC_EDITadd2password2, m_add2password2);
	DDX_Control(pDX, IDC_CHECKadd1, m_checkadd1);
	DDX_Control(pDX, IDC_CHECKadd2, m_checkadd2);
	DDX_Control(pDX, IDC_CHECKadd3, m_checkadd3);
	DDX_Control(pDX, IDC_CHECKadd4, m_checkadd4);
	DDX_Control(pDX, IDC_CHECKadd5, m_checkadd5);
	DDX_Control(pDX, IDC_CHECKadd6, m_checkadd6);
	DDX_Control(pDX, IDC_CHECKadd7, m_checkadd7);
	DDX_Control(pDX, IDC_CHECKadd8, m_checkadd8);
	DDX_Control(pDX, IDC_CHECKadd9, m_checkadd9);
	DDX_Control(pDX, IDC_CHECKadd10, m_checkadd10);
}


BEGIN_MESSAGE_MAP(Add2Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &Add2Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Add2Dlg 消息处理程序

BOOL Add2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//设置货物信息查询为默认权限
	m_checkadd6.SetCheck(1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void Add2Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	//判断用户信息是否完整
	if (m_add2username == "" || m_add2password1 == "" || m_add2password2 == "")
	{
		MessageBox("用户信息不完整!");
		return;
	}

	//判断两次输入的密码是否相同
	if (m_add2password1 != m_add2password2)
	{
		MessageBox("两次输入的密码不同!");
		return;
	}

	//获取添加的用户信息和权限
	user udata;
	udata.username = m_add2username.GetString();
	udata.password = m_add2password1.GetString();
	udata.privilege = to_string(m_checkadd1.GetCheck()) + to_string(m_checkadd2.GetCheck()) + to_string(m_checkadd3.GetCheck()) + to_string(m_checkadd4.GetCheck()) + to_string(m_checkadd5.GetCheck()) + to_string(m_checkadd6.GetCheck()) + to_string(m_checkadd7.GetCheck()) + to_string(m_checkadd8.GetCheck()) + to_string(m_checkadd9.GetCheck()) + to_string(m_checkadd10.GetCheck());
	udata.reguser = UserName;
	udata.time = time(NULL);

	//判断用户信息是否已存在
	if (!AddUser(UserL, udata))
	{
		MessageBox("用户已存在!");
		return;
	}

	if(!WriteUser(UserL))
	{
		MessageBox("添加失败!");
		return;
	}

	MessageBox("添加成功!");
	Add2Dlg::OnOK();
}