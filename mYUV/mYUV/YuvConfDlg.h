#pragma once


// CYuvConfDlg ��ȭ �����Դϴ�.

class CYuvConfDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CYuvConfDlg)

public:
	CYuvConfDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CYuvConfDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int m_iWidth;
	int m_iHeight;
	int m_iRGB444;
	int m_iYUV420;
	int m_iYUV400;
};
