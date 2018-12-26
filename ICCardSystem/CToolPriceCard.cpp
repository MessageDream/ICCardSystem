// CToolPriceCard.cpp: 实现文件
//

#include "stdafx.h"
#include "ICCardSystem.h"
#include "CToolPriceCard.h"
#include "afxdialogex.h"


// CToolPriceCard 对话框

IMPLEMENT_DYNAMIC(CToolPriceCard, CDialogEx)

CToolPriceCard::CToolPriceCard(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TOOLPRICECARD, pParent)
{

}

CToolPriceCard::~CToolPriceCard()
{
}

void CToolPriceCard::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CToolPriceCard, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_PRICECARD, &CToolPriceCard::OnBnClickedButtonPricecard)
END_MESSAGE_MAP()


// CToolPriceCard 消息处理程序


BOOL CToolPriceCard::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CToolPriceCard::OnBnClickedButtonPricecard()
{
	// TODO: 在此添加控件通知处理程序代码
	int nUnitID, nPrice;
	nUnitID = GetDlgItemInt(IDC_EDIT_UNITID);
	nPrice = GetDlgItemInt(IDC_EDIT_PRICE);
	CString strCard, strError;
	strCard = CCardOperator::EncodePriceCard(0x00000000, nUnitID, CCardOperator::TYPE_PRICE,nPrice);
	if (CCardOperator::WriteCard(strCard, strError,true))
		AfxMessageBox(_T("写卡成功!"));
	else
		AfxMessageBox(_T("写卡失败!\r\n") + strError);
}
