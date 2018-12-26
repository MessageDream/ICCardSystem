// CToolQueryCard.cpp: 实现文件
//

#include "stdafx.h"
#include "ICCardSystem.h"
#include "CToolQueryCard.h"
#include "afxdialogex.h"


// CToolQueryCard 对话框

IMPLEMENT_DYNAMIC(CToolQueryCard, CDialogEx)

CToolQueryCard::CToolQueryCard(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TOOLQUERYCARD, pParent)
{

}

CToolQueryCard::~CToolQueryCard()
{
}

void CToolQueryCard::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CToolQueryCard, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_QUERYCARD, &CToolQueryCard::OnBnClickedButtonQuerycard)
END_MESSAGE_MAP()


// CToolQueryCard 消息处理程序


BOOL CToolQueryCard::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CToolQueryCard::OnBnClickedButtonQuerycard()
{
	// TODO: 在此添加控件通知处理程序代码
	int nUnitID;
	nUnitID = GetDlgItemInt(IDC_EDIT_UNITID);
	CString strCard, strError;
	strCard = CCardOperator::EncodeQueryCard(0x00000000, nUnitID, CCardOperator::TYPE_QUERY);
	if (CCardOperator::WriteCard(strCard, strError,true))
		AfxMessageBox(_T("写卡成功!"));
	else
		AfxMessageBox(_T("写卡失败!\r\n") + strError);
}
