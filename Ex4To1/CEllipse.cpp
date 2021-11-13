// CEllipse.cpp: 구현 파일
//

#include "pch.h"
#include "Ex4To1.h"
#include "CEllipse.h"
#include "afxdialogex.h"


// CEllipse 대화 상자

IMPLEMENT_DYNAMIC(CEllipse, CDialog)

CEllipse::CEllipse(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_ELLIPSE, pParent)
	, m_dlgTimer(0)
{

}

CEllipse::~CEllipse()
{
}

void CEllipse::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TIMER, m_dlgTimer);
}


BEGIN_MESSAGE_MAP(CEllipse, CDialog)
END_MESSAGE_MAP()


// CEllipse 메시지 처리기
