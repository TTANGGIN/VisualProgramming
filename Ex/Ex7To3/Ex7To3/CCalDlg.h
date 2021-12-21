#pragma once
#include "resource.h"

// CCalDlg 대화 상자

class AFX_EXT_CLASS CCalDlg : public CDialog
{
	DECLARE_DYNAMIC(CCalDlg)

public:
	CCalDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CCalDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	// enum { IDD = IDD_CCalDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_num1;
	int m_num2;
	afx_msg void OnBnClickedButton1();
};
