
// Ex2To2Dlg.h: 헤더 파일
//

#pragma once


// CEx2To2Dlg 대화 상자
class CEx2To2Dlg : public CDialogEx
{
// 생성입니다.
public:
	CEx2To2Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EX2TO2_DIALOG };
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
	float m_edit;
	int m_operator;
	afx_msg void OnBnClickedButtPlus();
	afx_msg void OnBnClickedButtMinus();
	afx_msg void OnBnClickedButtTime();
	afx_msg void OnBnClickedButtDivide();
	afx_msg void OnBnClickedButtEqual();
	afx_msg void OnBnClickedButtClear();
	float m_num1;
	float m_num2;
};
