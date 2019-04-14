
// mYUVDoc.cpp : CmYUVDoc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "mYUV.h"
#endif

#include "mYUVDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CmYUVDoc

IMPLEMENT_DYNCREATE(CmYUVDoc, CDocument)

BEGIN_MESSAGE_MAP(CmYUVDoc, CDocument)
	ON_COMMAND(ID_FILE_OPEN, &CmYUVDoc::OnFileOpen)
END_MESSAGE_MAP()


// CmYUVDoc 생성/소멸

CmYUVDoc::CmYUVDoc()
	: m_fdInputImage(NULL)
	, m_paBitmapData(NULL)
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CmYUVDoc::~CmYUVDoc()
{
}

BOOL CmYUVDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CmYUVDoc serialization

void CmYUVDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CmYUVDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CmYUVDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CmYUVDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CmYUVDoc 진단

#ifdef _DEBUG
void CmYUVDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CmYUVDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CmYUVDoc 명령

#include "YuvConfDlg.h"
void CmYUVDoc::OnFileOpen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	INT_PTR iDialogResult;
	CFileDialog fileDialog(true);

	iDialogResult = fileDialog.DoModal();

	if (iDialogResult != IDOK)
		return;

	CYuvConfDlg yuvConfDialog;
	iDialogResult = yuvConfDialog.DoModal();

	if (iDialogResult != IDOK)
		return;

	enum ImageFormat
	{
		NONE = 0,
		RGB444 = 1,
		YUV420 = 2,
		YUV400 = 3,
	};

	int iWidth = yuvConfDialog.m_iWidth;
	int iHeight = yuvConfDialog.m_iHeight;
	ImageFormat fmt = NONE;

	if (yuvConfDialog.m_iRGB444) fmt = RGB444;
	else if (yuvConfDialog.m_iYUV420) fmt = YUV420;
	else if (yuvConfDialog.m_iYUV400) fmt = YUV400;

	m_fdInputImage = _wfopen((LPCTSTR)fileDialog.GetPathName(), _T("rb"));

	if(m_paBitmapData)
		delete[] m_paBitmapData;

	const int iBufferSize = iWidth * iHeight * 3;
	m_paBitmapData = new BYTE[iBufferSize];

	if (fmt == RGB444){
		BYTE b[3];
		BYTE* pDst = m_paBitmapData + iBufferSize - (iWidth*3);

		for (int i=0; i<iHeight; i++){
			for (int j=0; j<iWidth; j++){
				fread(b, sizeof(BYTE), 3, m_fdInputImage);
				pDst[j*3+0] = b[2];
				pDst[j*3+1] = b[1];
				pDst[j*3+2] = b[0];
			}
			pDst -= (iWidth*3);
		}
	}
	else if (fmt == YUV420){
		BYTE* paYUV = new BYTE[iWidth*iHeight*3/2];
		int cbOffset = iWidth*iHeight;
		int crOffset = cbOffset + (iWidth*iHeight/4);
		int iWidth2 = iWidth/2;

		fread(paYUV, sizeof(BYTE), iWidth * iHeight *3 /2, m_fdInputImage);

		int y, cb, cr, r, g, b;
		BYTE* pDst = m_paBitmapData + iBufferSize - (iWidth *3);

		for (int iY=0; iY<iHeight; iY++){
			for(int iX=0; iX<iHeight; iX++){
				int hx=iX/2;
				int hy=iY/2;

				y = paYUV[iY*iWidth+iX];
				cb = paYUV[hy*iWidth2+hx+cbOffset];
				cr = paYUV[hy*iWidth2+hx+crOffset];

				r = (int)(y+(1.4065f*(cr-128.f)));
				g = (int)(y-(0.3455f*(cb-128.f)) - (0.7169f * (cr-128.f)));
				b = (int)(y+(1.7790f*(cb-128.f)));

				r = r < 0 ? 0 : (r>255 ? 255 : r);
				g = g < 0 ? 0 : (g>255 ? 255 : g);
				b = b < 0 ? 0 : (b>255 ? 255 : b);

				pDst[iX*3+0] = b;
				pDst[iX*3+1] = g;
				pDst[iX*3+2] = r;
			}
			pDst -= (iWidth*3);
		}

		delete[] paYUV;
	}
	else if (fmt==YUV400){
		BYTE b;
		BYTE* pDst = m_paBitmapData + iBufferSize - (iWidth*3);
		for (int i =0; i<iHeight; i++){
			for (int j=0; j<iWidth; j++){
				fread(&b, sizeof(BYTE), 1, m_fdInputImage);

				pDst[j*3+0] = b;
				pDst[j*3+1] = b;
				pDst[j*3+2] = b;
			}
			pDst -= (iWidth*3);
		}
	}

	m_bitmapHeader.biSize = sizeof(BITMAPINFOHEADER);
	m_bitmapHeader.biPlanes = 1;
	m_bitmapHeader.biBitCount = 24;
	m_bitmapHeader.biCompression = BI_RGB;
	m_bitmapHeader.biSizeImage = 0;
	m_bitmapHeader.biXPelsPerMeter = 0;
	m_bitmapHeader.biYPelsPerMeter = 0;
	m_bitmapHeader.biClrUsed = 0;
	m_bitmapHeader.biClrImportant = 0;
	m_bitmapHeader.biWidth = iWidth;
	m_bitmapHeader.biHeight = iHeight;

	fclose(m_fdInputImage);

	UpdateAllViews(0);

}