// Del2Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MIMS.h"
#include "afxdialogex.h"
#include "Del2Dlg.h"


// Del2Dlg 对话框

IMPLEMENT_DYNAMIC(Del2Dlg, CDialogEx)

Del2Dlg::Del2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DEL2, pParent)
{

}

Del2Dlg::~Del2Dlg()
{
}

void Del2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBOdel2username, m_del2username);
}


BEGIN_MESSAGE_MAP(Del2Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &Del2Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Del2Dlg 消息处理程序


BOOL Del2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//设置选择项的内容
	for (UserLinkList tp = UserL->next; tp; tp = tp->next)
	{
		m_del2username.AddString(tp->data.username.c_str());
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void Del2Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	CString dataid;
	if (m_del2username.GetCurSel() == -1)
	{
		((CComboBox*)GetDlgItem(IDC_COMBOdel2username))->GetWindowText(dataid);
		if (dataid == "")
		{
			MessageBox("用户名不能为空!");
			return;
		}

		int i = 0, flag = 1;
		UserLinkList tp = UserL->next;
		for (; tp; tp = tp->next, i++)
		{
			if (tp->data.username == dataid.GetString())
			{
				flag = 0;
				break;
			}
		}

		if (flag)
		{
			MessageBox("用户不存在!");
			return;
		}
	}
	else
	{
		m_del2username.GetLBText(m_del2username.GetCurSel(), dataid);
	}

	user data;
	data.username = dataid.GetString();

	string temp;
	temp = "是否确认删除?";
	if (MessageBox(dataid, temp.c_str(), MB_OKCANCEL | MB_ICONQUESTION) == IDCANCEL)
	{
		return;
	}

	if (!DelUser(UserL, data) || !WriteUser(UserL))
	{
		MessageBox("删除失败!");
		return;
	}

	MessageBox("删除成功!");
	Del2Dlg::OnOK();
}