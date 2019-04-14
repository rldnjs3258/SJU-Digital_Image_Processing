
// mYUVView.h : CmYUVView Ŭ������ �������̽�
//

#pragma once


class CmYUVView : public CView
{
protected: // serialization������ ��������ϴ�.
	CmYUVView();
	DECLARE_DYNCREATE(CmYUVView)

// Ư���Դϴ�.
public:
	CmYUVDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CmYUVView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // mYUVView.cpp�� ����� ����
inline CmYUVDoc* CmYUVView::GetDocument() const
   { return reinterpret_cast<CmYUVDoc*>(m_pDocument); }
#endif

