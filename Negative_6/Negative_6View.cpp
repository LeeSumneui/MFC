
// Negative_6View.cpp : CNegative_6View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CNegative_6View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CNegative_6View ����/�Ҹ�

CNegative_6View::CNegative_6View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CNegative_6View::~CNegative_6View()
{
}

BOOL CNegative_6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CNegative_6View �׸���

void CNegative_6View::OnDraw(CDC* /*pDC*/)
{
	CNegative_6Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	LoadBmp();
}


// CNegative_6View �μ�


void CNegative_6View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CNegative_6View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CNegative_6View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CNegative_6View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
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


// CNegative_6View ����

#ifdef _DEBUG
void CNegative_6View::AssertValid() const
{
	CView::AssertValid();
}

void CNegative_6View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNegative_6Doc* CNegative_6View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNegative_6Doc)));
	return (CNegative_6Doc*)m_pDocument;
}
#endif //_DEBUG


// CNegative_6View �޽��� ó����


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
         AfxMessageBox(_T("��Ʈ�� ���� ��� �б� ����..."));
 
   if(temp_BmpFileHeader.bfType != 0x4d42)
         AfxMessageBox(_T("��Ʈ�� ������ �ƴ�..."));
 
   if(!file.Read(&temp_BmpInfo, sizeof(BITMAPINFOHEADER)))
          AfxMessageBox(_T("��Ʈ�� ���� ���� ��� �б� ����..."));

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
