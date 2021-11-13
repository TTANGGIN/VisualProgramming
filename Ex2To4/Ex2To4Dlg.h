
// Ex2To4Dlg.h: 헤더 파일
//

#pragma once


// CEx2To4Dlg 대화 상자
class CEx2To4Dlg : public CDialogEx
{
// 생성입니다.
public:
	CEx2To4Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EX2TO4_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_ctlCombo;
	afx_msg void OnBnClickedButtResult();
	BOOL isFirstQtrChecked;
	BOOL isSecondQtrChecked;
	BOOL isThirdQtrChecked;
	BOOL isFourthQtrChecked;
	CString m_comboBoxValue[12];
};
