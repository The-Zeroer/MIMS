// MainWindow.cpp: 实现文件
//

#include "pch.h"
#include "MIMS.h"
#include "MainWindow.h"


// MainWindow

IMPLEMENT_DYNCREATE(MainWindow, CFormView)

MainWindow::MainWindow()
	: CFormView(IDD_FORMVIEW)
{

}

MainWindow::~MainWindow()
{
}

void MainWindow::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(MainWindow, CFormView)
END_MESSAGE_MAP()


// MainWindow 诊断

#ifdef _DEBUG
void MainWindow::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void MainWindow::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// MainWindow 消息处理程序
