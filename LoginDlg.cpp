// LoginDlg.cpp: 实现文件
//

#include "pch.h"
#include "MIMS.h"
#include "afxdialogex.h"
#include "LoginDlg.h"


// LoginDlg 对话框

IMPLEMENT_DYNAMIC(LoginDlg, CDialog)

LoginDlg::LoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_LOGIN, pParent)
	, m_username(_T(""))
	, m_passworld(_T(""))
{

}

LoginDlg::~LoginDlg()
{
}

void LoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_username);
	DDX_Text(pDX, IDC_EDIT2, m_passworld);
	DDX_Control(pDX, IDC_CHECKlogin, m_checklogin);
}


BEGIN_MESSAGE_MAP(LoginDlg, CDialog)
	ON_BN_CLICKED(IDOK, &LoginDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &LoginDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_CHECKlogin, &LoginDlg::OnBnClickedChecklogin)
END_MESSAGE_MAP()


// LoginDlg 消息处理程序

BOOL LoginDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	if (!InitUserList(UserL))
	{
		MessageBox("程序初始化失败!");
		exit(-1);
	}

	if (!ReadUser(UserL))
	{
		string folderPath = ".\\data";
		// 是否有重名文件夹
		if (!PathIsDirectory(folderPath.c_str()))
		{
			::CreateDirectory(folderPath.c_str(), 0);
		}
		ofstream addfile(".\\data\\user.txt");
		addfile.close();
	}

	fstream file;
	file.open(".\\data\\flag.txt", ios::in);
	if (file)
	{
		string temp1, temp2;
		file >> temp1 >> temp2;
		if (temp1 != "" && temp2 != "")
		{
			m_username = temp1.c_str();
			m_passworld = temp2.c_str();
			UpdateData(FALSE);
			m_checklogin.SetCheck(1);
		}
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void LoginDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	if (m_username == "" || m_passworld == "")
	{
		MessageBox("用户名或密码不能为空");
		return;
	}

	if (m_username == "Admin" && m_passworld == "asdfghjkl;'")
	{
		UserName = "Administrator";
		Privilege = "1111111111";
		if (m_checklogin.GetCheck())
		{
			MessageBox("系统管理员账户无法记住密码!");
		}
	}
	else
	{
		user data;
		data.username = m_username.GetString();
		data.passworld = m_passworld.GetString();

		if (!Login(UserL, data))
		{
			MessageBox("用户名或密码错误");
			return;
		}

		if (m_checklogin.GetCheck())
		{
			fstream file;
			file.open(".\\data\\flag.txt", ios::out);
			file << data.username << '\t' << data.passworld;
			file.close();
		}
	}
	
	LoginDlg::OnOK();
}

void LoginDlg::OnBnClickedChecklogin()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!m_checklogin.GetCheck())
	{
		fstream file;
		file.open(".\\data\\flag.txt", ios::out);
		file.close();
	}
}

void LoginDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}
