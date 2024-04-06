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
	, m_passworld1(_T(""))
	, m_passworld2(_T(""))
	, m_passworld3(_T(""))
{

}

Alt3Dlg::~Alt3Dlg()
{
}

void Alt3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITalt3passworld1, m_passworld1);
	DDX_Text(pDX, IDC_EDITalt3passworld2, m_passworld2);
	DDX_Text(pDX, IDC_EDITalt3passworld3, m_passworld3);
}


BEGIN_MESSAGE_MAP(Alt3Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &Alt3Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ALT3Dlg 消息处理程序


void Alt3Dlg::OnBnClickedOk()	//修改用户密码
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	for (UserLinkList tp = UserL->next; tp; tp = tp->next)
	{
		if (tp->data.username == UserName)
		{
			if (tp->data.passworld == m_passworld1.GetString())
			{
				if (m_passworld2 == m_passworld3)
				{
					user data;
					data.username = UserName;
					data.passworld = m_passworld2.GetString();
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
