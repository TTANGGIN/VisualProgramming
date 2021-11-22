
// GomokuDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Gomoku.h"
#include "GomokuDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGomokuDlg 대화 상자



CGomokuDlg::CGomokuDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GOMOKU_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGomokuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGomokuDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTT_START, &CGomokuDlg::OnBnClickedButtStart)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTT_STOP, &CGomokuDlg::OnBnClickedButtStop)
END_MESSAGE_MAP()


// CGomokuDlg 메시지 처리기

BOOL CGomokuDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_timer = 20;
	isWhiteTurn = FALSE;
	isGameStart = FALSE;
	m_font.CreateFontW(30, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("맑은고딕"));
	GetDlgItem(IDC_STATIC_TIMER)->SetFont(&m_font);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CGomokuDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CGomokuDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();

		// 바둑판 그리기
		CClientDC dc(this);
		CRect rect(200, 100, 900, 800);
		CBrush brush;
		brush.CreateSolidBrush(RGB(227, 178, 74));
		CBrush* oldBrush = dc.SelectObject(&brush);
		dc.FillRect(&rect, &brush);
		dc.SelectObject(oldBrush);
		brush.DeleteObject();

		CPen pEn, * oldPen;
		pEn.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
		oldPen = (CPen*)dc.SelectObject(&pEn);

		for (int i = 0; i < 13; i++)
		{
			dc.MoveTo(250 + (i * 50), 150);
			dc.LineTo(250 + (i * 50), 750);
			dc.MoveTo(250, 150 + (i * 50));
			dc.LineTo(850, 150 + (i * 50));
		}
		dc.SelectObject(oldPen);

		// Invalid시 바둑알 복원
		if (isGameStart)
		{
			CBrush black_brush(RGB(0, 0, 0));
			CBrush* p_oldBrush;
			for (int y = 1; y <= 13; y++)
			{
				for (int x = 1; x <= 13; x++)
				{
					if (isExist[y - 1][x - 1] > 0)
					{
						if (isExist[y - 1][x - 1] == 1)
						{
							p_oldBrush = dc.SelectObject(&black_brush);
							dc.Ellipse(x * 50 - 20 + 200, y * 50 - 20 + 100, x * 50 + 20 + 200, y * 50 + 20 + 100);
							dc.SelectObject(p_oldBrush);
						}
						else
							dc.Ellipse(x * 50 - 20 + 200, y * 50 - 20 + 100, x * 50 + 20 + 200, y * 50 + 20 + 100);
					}
				}
			}
		}
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CGomokuDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGomokuDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_timer -= 1;
	if (m_timer < 0)
	{
		m_timer = 20;
		if (isWhiteTurn)
			isWhiteTurn = FALSE;
		else
			isWhiteTurn = TRUE;
	}
	m_strTime.Format(_T("%d"), m_timer);
	SetDlgItemText(IDC_STATIC_TIMER, m_strTime);
	UpdateData(FALSE);
	CDialogEx::OnTimer(nIDEvent);
}


HBRUSH CGomokuDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  여기서 DC의 특성을 변경합니다.
	if (pWnd->GetDlgCtrlID() == IDC_STATIC_TIMER)
	{
		if(m_timer<=5)
			pDC->SetTextColor(RGB(255, 0, 0));
		else
			pDC->SetTextColor(RGB(0, 0, 0));
	}
	// TODO:  기본값이 적당하지 않으면 다른 브러시를 반환합니다.
	return hbr;
}


void CGomokuDlg::OnBnClickedButtStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetTimer(0, 1000, NULL);
	isGameStart = TRUE;
	GetDlgItem(IDC_BUTT_START)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTT_STOP)->EnableWindow(TRUE);

}

void CGomokuDlg::OnBnClickedButtStop()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	GetDlgItem(IDC_BUTT_START)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTT_STOP)->EnableWindow(FALSE);
	KillTimer(0);
	isGameStart = FALSE;
	memset(isExist, 0, sizeof(isExist));
	memset(m_countNum, 0, sizeof(m_countNum));
	m_timer = 20;
	m_result = 0;
	m_state = 0;
	m_result = 0;
	Invalidate(TRUE);
}

void CGomokuDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (isGameStart)
	{
		CClientDC dc(this);
		CBrush brush;
		brush.CreateSolidBrush(RGB(0, 0, 0));
		CBrush* oldBrush;
		int x = (point.x+25) / 50;
		int y = (point.y+25) / 50;
		int Ex = x - 5;
		int Ey = y - 3;
		x *= 50;
		y *= 50;
		if (x > 225 && y > 125 && x <= 875 && y <= 775 && isExist[Ey][Ex] == 0)
		{
			if (!isWhiteTurn)
			{
				isExist[Ey][Ex] = 1;
				m_state = 1;
				oldBrush = dc.SelectObject(&brush);
				dc.Ellipse(x - 20, y - 20, x + 20, y + 20);
				dc.SelectObject(oldBrush);
				m_timer = 20;
				isWhiteTurn = TRUE;
			}
			else
			{
				isExist[Ey][Ex] = 2;
				m_state = 2;
				dc.Ellipse(x - 20, y - 20, x + 20, y + 20);
				m_timer = 20;
				isWhiteTurn = FALSE;
			}

			Shift_fp fp[8] = { &CGomokuDlg::Shift1, &CGomokuDlg::Shift2, &CGomokuDlg::Shift3, &CGomokuDlg::Shift4,
				&CGomokuDlg::Shift5, &CGomokuDlg::Shift6, &CGomokuDlg::Shift7, &CGomokuDlg::Shift8 };

			if (m_result == 0)
			{
				for (int i = 0; i < 8; i++)
				{
					CheckResult(Ey, Ex, fp[i]);
				}
				for (int i = 0; i < 4; i++)
				{
					m_countNum[i] = 0;
				}
			}
			if (m_result == 1)
			{
				if (m_state == 1)
				{
					MessageBox(_T("흑돌 승!"));
					CGomokuDlg::OnBnClickedButtStop();
				}
				else
				{
					MessageBox(_T("백돌 승!"));
					CGomokuDlg::OnBnClickedButtStop();
				}
			}
			
		}
	}
	
	CDialogEx::OnLButtonDown(nFlags, point);
}

typedef void(__thiscall CGomokuDlg::* Shift_fp)(char, char);

void CGomokuDlg::CheckResult(char y, char x, Shift_fp fp)
{
	(this->*fp)(y, x);
}

void CGomokuDlg::Shift1(char y, char x)
{
	if (y > 0 && x > 0)
	{
		if (isExist[y - 1][x - 1] == m_state)
			m_countNum[0]++;
		else
			return;

		if (m_countNum[0] == 4)
			m_result = 1;
		else
			Shift1(y - 1, x - 1);
	}
}

void CGomokuDlg::Shift2(char y, char x)
{
	if (y > 0)
	{
		if (isExist[y - 1][x] == m_state)
			m_countNum[1]++;
		else
			return;

		if (m_countNum[1] == 4)
			m_result = 1;
		else
			Shift2(y - 1, x);
	}
}

void CGomokuDlg::Shift3(char y, char x)
{
	if (y > 0 && x < 12)
	{
		if (isExist[y - 1][x + 1] == m_state)
			m_countNum[2]++;
		else
			return;

		if (m_countNum[2] == 4)
			m_result = 1;
		else
			Shift3(y - 1, x + 1);
	}
}

void CGomokuDlg::Shift4(char y, char x)
{
	if (x < 12)
	{
		if (isExist[y][x + 1] == m_state)
			m_countNum[3]++;
		else
			return;

		if (m_countNum[3] == 4)
			m_result = 1;
		else
			Shift4(y, x + 1);
	}
}

void CGomokuDlg::Shift5(char y, char x)
{
	if (y < 12 && x < 12)
	{
		if (isExist[y + 1][x + 1] == m_state)
			m_countNum[0]++;
		else
			return;

		if (m_countNum[0] == 4)
			m_result = 1;
		else
			Shift5(y + 1, x + 1);
	}
}

void CGomokuDlg::Shift6(char y, char x)
{
	if (y < 12)
	{
		if (isExist[y + 1][x] == m_state)
			m_countNum[1]++;
		else
			return;

		if (m_countNum[1] == 4)
			m_result = 1;
		else
			Shift6(y + 1, x);
	}
}

void CGomokuDlg::Shift7(char y, char x)
{
	if (y < 12 && x > 0)
	{
		if (isExist[y + 1][x - 1] == m_state)
			m_countNum[2]++;
		else
			return;

		if (m_countNum[2] == 4)
			m_result = 1;
		else
			Shift7(y + 1, x - 1);
	}
}

void CGomokuDlg::Shift8(char y, char x)
{
	if (x > 0)
	{
		if (isExist[y][x - 1] == m_state)
			m_countNum[3]++;
		else
			return;

		if (m_countNum[3] == 4)
			m_result = 1;
		else
			Shift8(y, x - 1);
	}
}
