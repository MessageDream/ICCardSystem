// CLogin.cpp: 实现文件
//

#include "stdafx.h"
#include "ICCardSystem.h"
#include "CLogin.h"
#include "afxdialogex.h"


// CLogin 对话框

IMPLEMENT_DYNAMIC(CLogin, CDialogEx)

CLogin::CLogin(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOGIN, pParent)
{

}

CLogin::~CLogin()
{
}

void CLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_LOGO, m_btnLogo);
}


BEGIN_MESSAGE_MAP(CLogin, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLogin::OnBnClickedOk)
END_MESSAGE_MAP()


// CLogin 消息处理程序


BOOL CLogin::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	HICON hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	SetIcon(hIcon, FALSE);
	std::vector<CEmployee> vec_employee;
	m_edb.Select(_T("SELECT * FROM Employee WHERE ID=99"), vec_employee);
	if (vec_employee.size() != 1)
	{
		CEmployee employee0(99, _T("fyzn"), _T("58831946"), 0, 1);
		CEmployee employee1(100, _T("fy"), _T("123123"), 1, 1);
		m_edb.Insert(employee0);
		m_edb.Insert(employee1);
	}
	m_btnLogo.SetBitmap(IDB_BITMAP_LOGO, IDB_BITMAP_LOGO);
	m_btnLogo.DrawBorder(FALSE);
	m_btnLogo.SetFlat(TRUE);
	m_btnLogo.EnableWindow(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CLogin::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strID, strPassword,strSql;
	GetDlgItemText(IDC_EDIT_ID, strID);
	GetDlgItemText(IDC_EDIT_PASSWORD, strPassword);
	std::vector<CEmployee> vec_employee;
	strSql.Format(_T("SELECT * FROM Employee WHERE ID=%d"),_ttoi(strID));
	m_edb.Select(strSql, vec_employee);
	if (vec_employee.size() == 1)
	{
		if(!vec_employee[0].IsUsing())
		{
			AfxMessageBox(_T("该工号已停用!"));
			GetDlgItem(IDC_EDIT_ID)->SetFocus();
			((CEdit *)GetDlgItem(IDC_EDIT_ID))->SetSel(0, -1);
			return;
		}
		if (vec_employee[0].GetPassword() != strPassword)
		{
			AfxMessageBox(_T("密码错误!"));
			GetDlgItem(IDC_EDIT_PASSWORD)->SetFocus();
			((CEdit *)GetDlgItem(IDC_EDIT_PASSWORD))->SetSel(0, -1);
			return;
		}
		g_employee = vec_employee[0];
	}
	else
	{
		AfxMessageBox(_T("工号不存在!"));
		GetDlgItem(IDC_EDIT_ID)->SetFocus();
		((CEdit *)GetDlgItem(IDC_EDIT_ID))->SetSel(0, -1);
		return;
	}
	CDialogEx::OnOK();
}


BOOL CLogin::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN || pMsg->message == WM_SYSKEYDOWN)
	{
		UINT nKey = pMsg->wParam;
		if (nKey == VK_RETURN)
		{
			CEdit * p_edits[2] = { NULL };
			p_edits[0]= (CEdit *)GetDlgItem(IDC_EDIT_ID);
			p_edits[1] = (CEdit *)GetDlgItem(IDC_EDIT_PASSWORD);
			CWnd * p_wnd = GetFocus();
			int nSize = sizeof(p_edits) / sizeof(CEdit *);
			for (int i = 0; i < nSize; ++i)
			{
				if (p_edits[i]->GetSafeHwnd() == p_wnd->GetSafeHwnd())
				{
					if (i+1 < nSize)
					{
						p_edits[i+1]->SetFocus();
						p_edits[i+1]->SetSel(0,-1);
					}
					else
					{
						OnBnClickedOk();
					}
					return TRUE;
				}
			}
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
