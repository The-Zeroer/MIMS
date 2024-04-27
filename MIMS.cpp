
// MIMS.cpp: 定义应用程序的类行为。
//

#include "pch.h"
#include "framework.h"
#include "MIMS.h"
#include "MIMSDlg.h"
#include "LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMIMSApp

BEGIN_MESSAGE_MAP(CMIMSApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMIMSApp 构造

CMIMSApp::CMIMSApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的 CMIMSApp 对象

CMIMSApp theApp;


// CMIMSApp 初始化

BOOL CMIMSApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。  否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);

	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 激活“Windows Native”视觉管理器，以便在 MFC 控件中启用主题
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	//显示登录界面
	LoginDlg Ldlg;
	Ldlg.DoModal();

	//显示主界面
	CMIMSDlg Mdlg;
	Mdlg.DoModal();
	

	// 删除上面创建的 shell 管理器。
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。

	return FALSE;
}



BOOL CMIMSApp::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类

	if (pMsg->message == WM_KEYDOWN)			//判断是否是按键消息
	{
		CWnd* pCtrl = CWnd::GetFocus();			//获取焦点
		if (pCtrl)
		{
			//获取焦点所在控件的ID
			int iCtrlID = pCtrl->GetDlgCtrlID();
			//焦点在编辑框控件时处理按键消息，不在编辑框控件时不处理按键消息
			if (iCtrlID == IDC_EDITusername || iCtrlID == IDC_EDITpassword || iCtrlID == IDC_EDITadd1id || iCtrlID == IDC_EDITaad1name || iCtrlID == IDC_EDITadd1type || iCtrlID == IDC_EDITadd1price || iCtrlID == IDC_EDITadd1descr || iCtrlID == IDC_COMBOdel1id || iCtrlID == IDC_EDITalt1name || iCtrlID == IDC_EDITalt1type || iCtrlID == IDC_EDITalt1price || iCtrlID == IDC_EDITalt1descr || iCtrlID == IDC_COMBOin2id || iCtrlID == IDC_EDITin2num || iCtrlID == IDC_COMBOout2id || iCtrlID == IDC_EDITout2num || iCtrlID == IDC_COMBOtab3id || iCtrlID == IDC_EDITalt3password1 || iCtrlID == IDC_EDITalt3password2 || iCtrlID == IDC_EDITalt3password3 || iCtrlID == IDC_EDITadd2username || iCtrlID == IDC_EDITadd2password1 || iCtrlID == IDC_EDITadd2password2 || iCtrlID == IDC_COMBOdel2username)
			{
				if (pMsg->wParam == ' ')
				{
					MessageBox(NULL, "请勿输入空格!", 0, 0);
					return 1;
				}

				if (iCtrlID == IDC_EDITadd1price || iCtrlID == IDC_EDITalt1price)
				{

				}
			}

		}
	}

	return CWinApp::PreTranslateMessage(pMsg);
}