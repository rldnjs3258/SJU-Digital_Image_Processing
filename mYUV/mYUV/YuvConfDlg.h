#pragma once


// CYuvConfDlg 대화 상자입니다.

class CYuvConfDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CYuvConfDlg)

public:
	CYuvConfDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CYuvConfDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_iWidth;
	int m_iHeight;
	int m_iRGB444;
	int m_iYUV420;
	int m_iYUV400;
};
