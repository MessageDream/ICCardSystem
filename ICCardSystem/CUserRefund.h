#pragma once


// CUserRefund 对话框

class CUserRefund : public CDialogEx
{
	DECLARE_DYNAMIC(CUserRefund)

public:
	CUserRefund(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CUserRefund();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USERREFUND };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CEdit m_editID;
	CEdit m_editName;
	CEdit m_editIDNo;
	CEdit m_editPhoneNo;
	CEdit m_editAddr;
	CEdit m_editUnitID;
	CEdit m_editUnitName;
	CEdit m_editBalance;
	CEdit m_editDeviceID;
	CEdit m_editAmount;
	CEdit m_editBalanceNew;
	CEdit m_editLastAmount;
	CEdit m_editTotalAmount;
	CEdit m_editPrestoreTimes;
	CEdit m_editNoteInfo;
	CUser m_SelectUser;
	int m_nDeposit;
	CUserDB m_udb;
	CPrestoreRecordDB m_prdb;
	CRefundRecordDB m_rrdb;
	CReturnDepositRecordDB m_rdrdb;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonReadcard();
	afx_msg void OnBnClickedButtonRefund();
	afx_msg void OnEnChangeEditAmount();
	void GetDeposit(const CUser & user);
	void InsertEdit(const CUser & user);
};
