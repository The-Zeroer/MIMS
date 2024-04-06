// Alt2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MIMS.h"
#include "afxdialogex.h"
#include "Alt2Dlg.h"


// Alt2Dlg 对话框

IMPLEMENT_DYNAMIC(Alt2Dlg, CDialogEx)

Alt2Dlg::Alt2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ALT2, pParent)
{

}

Alt2Dlg::~Alt2Dlg()
{
}

void Alt2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBOalt2username, m_alt2username);
	DDX_Control(pDX, IDC_CHECKalt1, m_checkalt1);
	DDX_Control(pDX, IDC_CHECKalt2, m_checkalt2);
	DDX_Control(pDX, IDC_CHECKalt3, m_checkalt3);
	DDX_Control(pDX, IDC_CHECKalt4, m_checkalt4);
	DDX_Control(pDX, IDC_CHECKalt5, m_checkalt5);
	DDX_Control(pDX, IDC_CHECKalt6, m_checkalt6);
	DDX_Control(pDX, IDC_CHECKalt7, m_checkalt7);
	DDX_Control(pDX, IDC_CHECKalt8, m_checkalt8);
	DDX_Control(pDX, IDC_CHECKalt9, m_checkalt9);
	DDX_Control(pDX, IDC_CHECKalt10, m_checkalt10);
}


BEGIN_MESSAGE_MAP(Alt2Dlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBOalt2username, &Alt2Dlg::OnCbnSelchangeComboalt2username)
	ON_BN_CLICKED(IDOK, &Alt2Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Alt2Dlg 消息处理程序



BOOL Alt2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//设置下拉列表选项
	for (UserLinkList tp = UserL->next; tp; tp = tp->next)
	{
		m_alt2username.AddString(tp->data.username.c_str());
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void Alt2Dlg::OnCbnSelchangeComboalt2username()
{
	// TODO: 在此添加控件通知处理程序代码

	//显示对应的用户权限信息
	int i = 0;
	UserLinkList tp = UserL->next;
	for (; tp; tp = tp->next, i++)
	{
		if (i == m_alt2username.GetCurSel())
		{
			CString temp;
			temp = tp->data.privilege[0];
			m_checkalt1.SetCheck(atoi(temp));
			temp = tp->data.privilege[1];
			m_checkalt2.SetCheck(atoi(temp));
			temp = tp->data.privilege[2];
			m_checkalt3.SetCheck(atoi(temp));
			temp = tp->data.privilege[3];
			m_checkalt4.SetCheck(atoi(temp));
			temp = tp->data.privilege[4];
			m_checkalt5.SetCheck(atoi(temp));
			temp = tp->data.privilege[5];
			m_checkalt6.SetCheck(atoi(temp));
			temp = tp->data.privilege[6];
			m_checkalt7.SetCheck(atoi(temp));
			temp = tp->data.privilege[7];
			m_checkalt8.SetCheck(atoi(temp));
			temp = tp->data.privilege[8];
			m_checkalt9.SetCheck(atoi(temp));
			temp = tp->data.privilege[9];
			m_checkalt10.SetCheck(atoi(temp));
		}
	}

}

void Alt2Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	//获取修改后的用户权限信息
	CString datausername;
	m_alt2username.GetLBText(m_alt2username.GetCurSel(), datausername);
	user data;
	data.username = datausername.GetString();
	data.privilege = to_string(m_checkalt1.GetCheck()) + to_string(m_checkalt2.GetCheck()) + to_string(m_checkalt3.GetCheck()) + to_string(m_checkalt4.GetCheck()) + to_string(m_checkalt5.GetCheck()) + to_string(m_checkalt6.GetCheck()) + to_string(m_checkalt7.GetCheck()) + to_string(m_checkalt8.GetCheck()) + to_string(m_checkalt9.GetCheck()) + to_string(m_checkalt10.GetCheck());

	if (!AltUser(UserL, data, 0) || !WriteUser(UserL))
	{
		MessageBox("修改失败!");
		return;
	}

	MessageBox("修改成功!");
	Alt2Dlg::OnOK();
}