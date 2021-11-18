
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
	int m_timer;
	CString m_strTime;
	afx_msg void OnBnClickedButtStart();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	BOOL isWhiteTurn;
	BOOL isGameStart;
	CFont m_font;
};
