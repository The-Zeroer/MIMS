// ALT3Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MIMS.h"
#include "afxdialogex.h"
#include "Alt3Dlg.h"


// ALT3Dlg 对话框

IMPLEMENT_DYNAMIC(Alt3Dlg, CDialogEx)

Alt3Dlg::Alt3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ALT3, pParent)
	, m_password1(_T(""))
	, m_password2(_T(""))
	, m_password3(_T(""))
{

}

Alt3Dlg::~Alt3Dlg()
{
}

void Alt3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITalt3password1, m_password1);
	DDX_Text(pDX, IDC_EDITalt3password2, m_password2);
	DDX_Text(pDX, IDC_EDITalt3password3, m_password3);
}


BEGIN_MESSAGE_MAP(Alt3Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &Alt3Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ALT3Dlg 消息处理程序


void Alt3Dlg::OnBnClickedOk()	//修改用户密码
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	if (m_password1 == "")
	{
		MessageBox("请输入旧密码!");
		return;
	}

	if (m_password2 == "" || m_password3 == "")
	{
		MessageBox("请输入新密码!");
		return;
	}

	for (UserLinkList tp = UserL->next; tp; tp = tp->next)
	{
		if (tp->data.username == UserName)
		{
			if (tp->data.password == m_password1.GetString())
			{
				if (m_password2 == m_password3)
				{
					user data;
					data.username = UserName;
					data.password = m_password2.GetString();
					if (!AltUser(UserL, data, 1) || !WriteUser(UserL))
					{
						MessageBox("修改失败!");
						return;
					}

					fstream file;
					file.open(".\\data\\flag.txt", ios::out);
					file.close();

					MessageBox("修改成功!");
					Alt3Dlg::OnOK();
				}
				MessageBox("两次输入的新密码不同!");
				return;
			}
			MessageBox("旧密码错误!");
			return;
		}
	}
	return;
}
