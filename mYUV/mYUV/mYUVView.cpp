
// mYUVView.cpp : CmYUVView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CmYUVView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CmYUVView 생성/소멸

CmYUVView::CmYUVView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CmYUVView::~CmYUVView()
{
}

BOOL CmYUVView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CmYUVView 그리기

void CmYUVView::OnDraw(CDC* pDC)
{
	CmYUVDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	if (pDoc->m_paBitmapData){
		int iWidth = pDoc->m_bitmapHeader.biWidth;
		int iHeight = pDoc->m_bitmapHeader.biHeight;

		::StretchDIBits(pDC->GetSafeHdc(), 0, 0, iWidth, iHeight, 0, 0,
			iWidth, iHeight, pDoc->m_paBitmapData,
			(LPBITMAPINFO)&pDoc->m_bitmapHeader, DIB_RGB_COLORS, SRCCOPY);
	}
}


// CmYUVView 인쇄


void CmYUVView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CmYUVView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CmYUVView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CmYUVView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
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


// CmYUVView 진단

#ifdef _DEBUG
void CmYUVView::AssertValid() const
{
	CView::AssertValid();
}

void CmYUVView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CmYUVDoc* CmYUVView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmYUVDoc)));
	return (CmYUVDoc*)m_pDocument;
}
#endif //_DEBUG


// CmYUVView 메시지 처리기
