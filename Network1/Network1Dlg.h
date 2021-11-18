
// Network1Dlg.h: 헤더 파일
//
#include "CMySocket.h"
#pragma once


// CNetwork1Dlg 대화 상자
class CNetwork1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CNetwork1Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NETWORK1_DIALOG };
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
	int m_iType;
	int m_iPaintType;
	CString m_strNmae;
	afx_msg void OnRType();
	CMySocket m_Csocket, m_Ssocket;
	void OnAccept();
	void OnConnect();
	void OnReceive();
	void OnClose();
	void OnSend();
	afx_msg void OnBnClickedBlisten();
	afx_msg void OnBnClickedBconnect();
	afx_msg void OnBnClickedBcircle();
	afx_msg void OnBnClickedBrect();
	afx_msg void OnBnClickedBline();
	afx_msg void OnBnClickedBdiscon();
};
