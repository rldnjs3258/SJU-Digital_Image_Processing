
// mYUVView.cpp : CmYUVView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "mYUV.h"
#endif

#include "mYUVDoc.h"
#include "mYUVView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CmYUVView

IMPLEMENT_DYNCREATE(CmYUVView, CView)

BEGIN_MESSAGE_MAP(CmYUVView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CmYUVView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CmYUVView ����/�Ҹ�

CmYUVView::CmYUVView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CmYUVView::~CmYUVView()
{
}

BOOL CmYUVView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CmYUVView �׸���

void CmYUVView::OnDraw(CDC* pDC)
{
	CmYUVDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	if (pDoc->m_paBitmapData){
		int iWidth = pDoc->m_bitmapHeader.biWidth;
		int iHeight = pDoc->m_bitmapHeader.biHeight;

		::StretchDIBits(pDC->GetSafeHdc(), 0, 0, iWidth, iHeight, 0, 0,
			iWidth, iHeight, pDoc->m_paBitmapData,
			(LPBITMAPINFO)&pDoc->m_bitmapHeader, DIB_RGB_COLORS, SRCCOPY);
	}
}


// CmYUVView �μ�


void CmYUVView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CmYUVView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CmYUVView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CmYUVView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CmYUVView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CmYUVView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CmYUVView ����

#ifdef _DEBUG
void CmYUVView::AssertValid() const
{
	CView::AssertValid();
}

void CmYUVView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmYUVDoc* CmYUVView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmYUVDoc)));
	return (CmYUVDoc*)m_pDocument;
}
#endif //_DEBUG


// CmYUVView �޽��� ó����
