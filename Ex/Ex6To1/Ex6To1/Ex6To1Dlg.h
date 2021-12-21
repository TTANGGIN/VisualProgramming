
// Ex6To1Dlg.h: 헤더 파일
//

#pragma once
#include "CMySocket.h"

// CEx6To1Dlg 대화 상자
class CEx6To1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CEx6To1Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EX6TO1_DIALOG };
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
	afx_msg void OnRType();
	int m_iType;
	int m_iPaintType;
	CString m_strName;
	CString m_strMessage;
	CMySocket m_Ssocket, m_Csocket;
	void OnAccept();
	void OnConnect();
	void OnClose();
	void OnReceive();
	void OnSend();
	afx_msg void OnBnClickedButtListen();
	afx_msg void OnBnClickedButtConnect();
	afx_msg void OnBnClickedButtSend();
	afx_msg void OnBnClickedButtRect();
	afx_msg void OnBnClickedButtLine();
	afx_msg void OnBnClickedButtDiscon();
};
