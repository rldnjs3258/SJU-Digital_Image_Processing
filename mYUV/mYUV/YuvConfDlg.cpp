// YuvConfDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "mYUV.h"
#include "YuvConfDlg.h"
#include "afxdialogex.h"


// CYuvConfDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CYuvConfDlg, CDialogEx)

CYuvConfDlg::CYuvConfDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CYuvConfDlg::IDD, pParent)
	, m_iWidth(0)
	, m_iHeight(0)
	, m_iRGB444(0)
	, m_iYUV420(0)
	, m_iYUV400(0)
{

}

CYuvConfDlg::~CYuvConfDlg()
{
}

void CYuvConfDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_iWidth);
	DDX_Text(pDX, IDC_EDIT2, m_iHeight);
	DDX_Check(pDX, IDC_RADIO1, m_iRGB444);
	DDX_Check(pDX, IDC_RADIO2, m_iYUV420);
	DDX_Check(pDX, IDC_RADIO3, m_iYUV400);
}


BEGIN_MESSAGE_MAP(CYuvConfDlg, CDialogEx)
END_MESSAGE_MAP()


// CYuvConfDlg 메시지 처리기입니다.
