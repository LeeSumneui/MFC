
// Negative_6View.cpp : CNegative_6View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Negative_6.h"
#endif

#include "Negative_6Doc.h"
#include "Negative_6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNegative_6View

IMPLEMENT_DYNCREATE(CNegative_6View, CView)

BEGIN_MESSAGE_MAP(CNegative_6View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CNegative_6View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CNegative_6View 생성/소멸

CNegative_6View::CNegative_6View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CNegative_6View::~CNegative_6View()
{
}

BOOL CNegative_6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CNegative_6View 그리기

void CNegative_6View::OnDraw(CDC* /*pDC*/)
{
	CNegative_6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	LoadBmp();
}


// CNegative_6View 인쇄


void CNegative_6View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CNegative_6View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CNegative_6View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CNegative_6View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CNegative_6View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CNegative_6View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CNegative_6View 진단

#ifdef _DEBUG
void CNegative_6View::AssertValid() const
{
	CView::AssertValid();
}

void CNegative_6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNegative_6Doc* CNegative_6View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNegative_6Doc)));
	return (CNegative_6Doc*)m_pDocument;
}
#endif //_DEBUG


// CNegative_6View 메시지 처리기


void CNegative_6View::LoadBmp(void)
{
	CNegative_6Doc *pDoc = GetDocument();
	CClientDC dc(this);
      
   CDC MemDC;
   CDC BufferDC;
     
   CBitmap Backbmp, *pBackbmp;
   HBITMAP hBitmap, OldBitmap;
 
   BITMAPFILEHEADER temp_BmpFileHeader;
   BITMAPINFOHEADER temp_BmpInfo;
 
   hBitmap =(HBITMAP)::LoadImage(NULL, pDoc->Bmpstr, IMAGE_BITMAP, NULL, NULL, 
         LR_DEFAULTSIZE| LR_LOADFROMFILE);

     CFile file(pDoc->Bmpstr, CFile::modeRead);
 
   if(!file.Read(&temp_BmpFileHeader, sizeof(BITMAPFILEHEADER)))
         AfxMessageBox(_T("비트맵 파일 헤더 읽기 에러..."));
 
   if(temp_BmpFileHeader.bfType != 0x4d42)
         AfxMessageBox(_T("비트맵 형식이 아님..."));
 
   if(!file.Read(&temp_BmpInfo, sizeof(BITMAPINFOHEADER)))
          AfxMessageBox(_T("비트맵 정보 파일 헤더 읽기 에러..."));

   pDoc->m_BmpHeight = (UINT)temp_BmpInfo.biHeight;
   pDoc->m_BmpWidth = (UINT)temp_BmpInfo.biWidth;
  
   if(pDoc->m_BmpHeight < 200 || pDoc->m_BmpWidth <200)
   {
           pDoc->m_BmpHeight = 500;
           pDoc->m_BmpWidth = 500;
   }
 
   if(!pDoc->InitRect)
   {
           int cx = ::GetSystemMetrics(SM_CXSCREEN)/ 4;
           int cy = ::GetSystemMetrics(SM_CXSCREEN)/ 4;
  
          AfxGetMainWnd()->SetWindowPos(NULL, 0, 0, pDoc->m_BmpWidth + 8,
                pDoc->m_BmpHeight + 54,  SWP_DRAWFRAME | SWP_SHOWWINDOW);
  
          pDoc->InitRect = TRUE;
   }

   MemDC.CreateCompatibleDC(&dc);
   BufferDC.CreateCompatibleDC(&dc);
 
   Backbmp.CreateCompatibleBitmap(&dc, pDoc->m_BmpWidth, pDoc->m_BmpHeight);
 
   OldBitmap = (HBITMAP)SelectObject(MemDC, hBitmap);
   pBackbmp = BufferDC.SelectObject(&Backbmp);
 
   BufferDC.BitBlt(0,0, pDoc->m_BmpWidth, pDoc->m_BmpHeight, &MemDC, 0, 0, SRCCOPY);
   dc.BitBlt(0, 0, pDoc->m_BmpWidth, pDoc->m_BmpHeight, &BufferDC, 0, 0, SRCCOPY);
 
   MemDC.SelectObject(OldBitmap);
   BufferDC.SelectObject(pBackbmp);
}
