
// MIMSDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MIMS.h"
#include "MIMSDlg.h"
#include "afxdialogex.h"
#include "Tab1.h"
#include "Tab2.h"
#include "Tab3.h"
#include "Tab4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMIMSDlg 对话框



CMIMSDlg::CMIMSDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MIMS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMIMSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB, m_tab);
}

BEGIN_MESSAGE_MAP(CMIMSDlg, CDialog)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CMIMSDlg::OnTcnSelchangeTab)
END_MESSAGE_MAP()


// CMIMSDlg 消息处理程序

BOOL CMIMSDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	if (!InitList(L) || !InitLogList(LogL))
	{
		MessageBox("程序初始化失败!");
		exit(-1);
	}

	if (!ReadGoods(L))
	{
		string folderPath = ".\\data";
		// 是否有重名文件夹
		if (!PathIsDirectory(folderPath.c_str()))
		{
			::CreateDirectory(folderPath.c_str(), 0);
		}
		ofstream addfile(".\\data\\goods.txt");
		addfile.close();
	}

	//为Tab Control增加页面
	m_tab.InsertItem(0, "货物信息管理");
	m_tab.InsertItem(1, "货物数量管理");
	m_tab.InsertItem(2, "货物及操作日志查询");
	m_tab.InsertItem(3, "设置");

	//创建对话框
	m_tab1.Create(IDD_TAB1, &m_tab);
	m_tab2.Create(IDD_TAB2, &m_tab);
	m_tab3.Create(IDD_TAB3, &m_tab);
	m_tab4.Create(IDD_TAB4, &m_tab);

	//设定在Tab内显示的范围  
	CRect tabRect;
	m_tab.GetClientRect(tabRect);
	tabRect.left += 1;
	tabRect.right -= 1;
	tabRect.top += 40;
	tabRect.bottom -= 1;
	m_tab1.MoveWindow(&tabRect);
	m_tab2.MoveWindow(&tabRect);
	m_tab3.MoveWindow(&tabRect);
	m_tab4.MoveWindow(&tabRect);

	//显示初始页面  
	m_tab1.ShowWindow(SW_SHOW);


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMIMSDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMIMSDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMIMSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMIMSDlg::OnTcnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此添加控件通知处理程序代码

	//控制不同的页面切换
	switch (m_tab.GetCurSel())
	{
	case 0:
	{
		m_tab1.ShowWindow(SW_SHOW);
		m_tab2.ShowWindow(SW_HIDE);
		m_tab3.ShowWindow(SW_HIDE);
		m_tab4.ShowWindow(SW_HIDE);
		break;
	}
	case 1:
	{
		m_tab1.ShowWindow(SW_HIDE);
		m_tab2.ShowWindow(SW_SHOW);
		m_tab3.ShowWindow(SW_HIDE);
		m_tab4.ShowWindow(SW_HIDE);

		//切换界面自动更新表格内容
		if (updateflag2)
		{
			m_tab2.m_list2.DeleteAllItems();
			LinkList tp = L->next;
			int i = 0;
			for (; tp; tp = tp->next, i++)
			{
				m_tab2.m_list2.InsertItem(i, to_string(i + 1).c_str());
				m_tab2.m_list2.SetItemText(i, 1, tp->data.id.c_str());
				m_tab2.m_list2.SetItemText(i, 2, tp->data.name.c_str());
				m_tab2.m_list2.SetItemText(i, 3, tp->data.type.c_str());
				m_tab2.m_list2.SetItemText(i, 4, to_string(tp->data.num).c_str());
			}
			updateflag2 = 0;
		}

		break;
	}
	case 2:
	{
		m_tab1.ShowWindow(SW_HIDE);
		m_tab2.ShowWindow(SW_HIDE);
		m_tab3.ShowWindow(SW_SHOW);
		m_tab4.ShowWindow(SW_HIDE);

		//切换界面自动更新按钮内容
		if (updateflag3)
		{
			m_tab3.m_tab3id.ResetContent();
			for (LinkList tp = L->next; tp; tp = tp->next)
			{
				m_tab3.m_tab3id.AddString(tp->data.id.c_str());
			}
			updateflag3 = 0;
		}

		break;
	}
	case 3:
	{
		m_tab1.ShowWindow(SW_HIDE);
		m_tab2.ShowWindow(SW_HIDE);
		m_tab3.ShowWindow(SW_HIDE);
		m_tab4.ShowWindow(SW_SHOW);
		break;
	}
	}
	*pResult = 0;
}


void CMIMSDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类

	//CDialog::OnOK();
}


void CMIMSDlg::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类
	if (MessageBox("是否确认退出?", "提示", MB_YESNO | MB_ICONQUESTION) == IDYES)
	{
		CDialog::OnCancel();
	}
}