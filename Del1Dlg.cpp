// Del1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MIMS.h"
#include "afxdialogex.h"
#include "Del1Dlg.h"


// Del1Dlg 对话框

IMPLEMENT_DYNAMIC(Del1Dlg, CDialogEx)

Del1Dlg::Del1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DEL1, pParent)
	, m_del1name(_T(""))
	, m_del1type(_T(""))
{

}

Del1Dlg::~Del1Dlg()
{
}

void Del1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBOdel1id, m_del1id);
	DDX_Text(pDX, IDC_EDITdel1name, m_del1name);
	DDX_Text(pDX, IDC_EDITdel1type, m_del1type);
}


BEGIN_MESSAGE_MAP(Del1Dlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &Del1Dlg::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBOdel1id, &Del1Dlg::OnCbnSelchangeCombodel1id)
END_MESSAGE_MAP()


// Del1Dlg 消息处理程序


BOOL Del1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//设置下拉列表选项
	for (LinkList tp = L->next; tp; tp = tp->next)
	{
		m_del1id.AddString(tp->data.id.c_str());
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void Del1Dlg::OnCbnSelchangeCombodel1id()
{
	// TODO: 在此添加控件通知处理程序代码

	//显示对应的货物信息
	int i = 0;
	LinkList tp = L->next;
	for (; tp; tp = tp->next, i++)
	{
		if (i == m_del1id.GetCurSel())
		{
			m_del1name = tp->data.name.c_str();
			m_del1type = tp->data.type.c_str();
			UpdateData(FALSE);
		}
	}
}

void Del1Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	CString dataid;
	if (m_del1id.GetCurSel() == -1)
	{
		((CComboBox*)GetDlgItem(IDC_COMBOdel1id))->GetWindowText(dataid);
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
				m_del1name = tp->data.name.c_str();
				m_del1type = tp->data.type.c_str();
				UpdateData(FALSE);
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
		m_del1id.GetLBText(m_del1id.GetCurSel(), dataid);
	}
	
	goods data;
	data.id = dataid.GetString();
	data.name = m_del1name;
	data.type = m_del1type;

	string str1, str2;
	str1 = "是否确认删除?";
	str2 += "货物编号:" + data.id + '\n';
	str2 += "货物名称:" + data.name + '\n';
	str2 += "货物类型:" + data.type;
	if (MessageBox(str2.c_str(), str1.c_str(), MB_OKCANCEL | MB_ICONQUESTION) == IDCANCEL)
	{
		return;
	}

	if (!DelGoods(L, data) || !WriteGoods(L))
	{
		MessageBox("删除失败!");
		return;
	}

	string folderPath = ".\\data\\log\\" + data.id + ".txt";
	DeleteFile(folderPath.c_str());
	updateflag2 = 1;
	updateflag3 = 1;

	MessageBox("删除成功!");
	Del1Dlg::OnOK();
}

void Del1Dlg::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类

	CDialogEx::OnCancel();
}
