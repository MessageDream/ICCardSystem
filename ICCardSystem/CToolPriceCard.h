#pragma once


// CToolPriceCard 对话框

class CToolPriceCard : public CDialogEx
{
	DECLARE_DYNAMIC(CToolPriceCard)

public:
	CToolPriceCard(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CToolPriceCard();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TOOLPRICECARD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonPricecard();
};
