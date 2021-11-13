
// Ex2To4Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Ex2To4.h"
#include "Ex2To4Dlg.h"
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


// CEx2To4Dlg 대화 상자



CEx2To4Dlg::CEx2To4Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EX2TO4_DIALOG, pParent)
	, isFirstQtrChecked(FALSE)
	, isSecondQtrChecked(FALSE)
	, isThirdQtrChecked(FALSE)
	, isFourthQtrChecked(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEx2To4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO, m_ctlCombo);
	DDX_Check(pDX, IDC_CHECK_FIRST_QTR, isFirstQtrChecked);
	DDX_Check(pDX, IDC_CHECK_SECOND_QTR, isSecondQtrChecked);
	DDX_Check(pDX, IDC_CHECK_THIRD_QTR, isThirdQtrChecked);
	DDX_Check(pDX, IDC_CHECK_FOURTH_QTR, isFourthQtrChecked);
}

BEGIN_MESSAGE_MAP(CEx2To4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_RESULT, &CEx2To4Dlg::OnBnClickedButtResult)
END_MESSAGE_MAP()


// CEx2To4Dlg 메시지 처리기

BOOL CEx2To4Dlg::OnInitDialog()
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
	// 월별 수익
	m_comboBoxValue[0] = "120";	// 1월
	m_comboBoxValue[1] = "110";	// 2월
	m_comboBoxValue[2] = "100";	// 3월
	m_comboBoxValue[3] = "90";	// 4월
	m_comboBoxValue[4] = "80";	// 5월
	m_comboBoxValue[5] = "70";	// 6월
	m_comboBoxValue[6] = "60";	// 7월
	m_comboBoxValue[7] = "50";	// 8월
	m_comboBoxValue[8] = "40";	// 9월
	m_comboBoxValue[9] = "30";	// 10월
	m_comboBoxValue[10] = "20";	// 11월
	m_comboBoxValue[11] = "10";	// 12월
	for (int i = 0; i < 12; i++)
	{
		m_ctlCombo.AddString(m_comboBoxValue[i]);
	}
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CEx2To4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEx2To4Dlg::OnPaint()
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
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CEx2To4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CEx2To4Dlg::OnBnClickedButtResult()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CString str;
	int result = 0;
	int countChecked = 0;

	if (isFirstQtrChecked)
	{
		for (int i = 0; i < 3; i++)
		{
			result += _ttoi(m_comboBoxValue[i]);
			countChecked++;
		}
	}
	if (isSecondQtrChecked)
	{
		for (int i = 3; i < 6; i++)
		{
			result += _ttoi(m_comboBoxValue[i]);
			countChecked++;
		}
	}
	if (isThirdQtrChecked)
	{
		for (int i = 6; i < 9; i++)
		{
			result += _ttoi(m_comboBoxValue[i]);
			countChecked++;
		}
	}
	if (isFourthQtrChecked)
	{
		for (int i = 9; i < 12; i++)
		{
			result += _ttoi(m_comboBoxValue[i]);
			countChecked++;
		}
	}

	if (countChecked != 0)
	{
		result /= countChecked;
	}

	str.Format(_T("평균값은 %d입니다."), result);
	MessageBox(str);
}
