
// GomokuDlg.h: 헤더 파일
//

#pragma once


// CGomokuDlg 대화 상자
class CGomokuDlg : public CDialogEx
{
// 생성입니다.
public:
	CGomokuDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GOMOKU_DIALOG };
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
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedButtStart();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButtStop();
	CString m_strTime;
	CFont m_font;
	BOOL isWhiteTurn;
	BOOL isGameStart;
	int isExist[13][13];
	int m_timer;
	int m_setTime;

	// 오목 알고리즘 관련
	typedef void(__thiscall CGomokuDlg::* Shift_fp)(char, char);
	void CheckResult(char y, char x, Shift_fp fp);
	void Shift1(char y, char x);
	void Shift2(char y, char x);
	void Shift3(char y, char x);
	void Shift4(char y, char x);
	void Shift5(char y, char x);
	void Shift6(char y, char x);
	void Shift7(char y, char x);
	void Shift8(char y, char x);
	int m_state = 0;
	int m_result = 0;
	int m_countNum[4];
	afx_msg void OnSetTimer();
};
