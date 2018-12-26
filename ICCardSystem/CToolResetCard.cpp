// CToolResetCard.cpp: 实现文件
//

#include "stdafx.h"
#include "ICCardSystem.h"
#include "CToolResetCard.h"
#include "afxdialogex.h"


// CToolResetCard 对话框

IMPLEMENT_DYNAMIC(CToolResetCard, CDialogEx)

CToolResetCard::CToolResetCard(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TOOLRESETCARD, pParent)
{

}

CToolResetCard::~CToolResetCard()
{
}

void CToolResetCard::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CToolResetCard, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_RESETCARD, &CToolResetCard::OnBnClickedButtonResetcard)
END_MESSAGE_MAP()


// CToolResetCard 消息处理程序


BOOL CToolResetCard::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CToolResetCard::OnBnClickedButtonResetcard()
{
	// TODO: 在此添加控件通知处理程序代码
	int nUnitID, nWriteDeviceID;
	nUnitID=GetDlgItemInt(IDC_EDIT_UNITID);
	nWriteDeviceID = GetDlgItemInt(IDC_EDIT_DEVICEID);
	CString strCard,strError;
	strCard = CCardOperator::EncodeResetCard(0x00000000,nUnitID, CCardOperator::TYPE_RESET,nWriteDeviceID);
	if (CCardOperator::WriteCard(strCard, strError,true))
		AfxMessageBox(_T("写卡成功!"));
	else
		AfxMessageBox(_T("写卡失败!\r\n") + strError);
}
