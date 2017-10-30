// Negative_6VIew_2.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Negative_6.h"
#include "Negative_6VIew_2.h"
#include "Negative_6Doc.h"
#include "MainFrm.h"

#define WIDTHBYTES(bits) (((bits)+31)/32*4)
// CNegative_6VIew_2

IMPLEMENT_DYNCREATE(CNegative_6VIew_2, CView)

CNegative_6VIew_2::CNegative_6VIew_2()
{
	pDib = NULL;
	pDib2 = NULL;
}

CNegative_6VIew_2::~CNegative_6VIew_2()
{
}

BEGIN_MESSAGE_MAP(CNegative_6VIew_2, CView)
END_MESSAGE_MAP()


// CNegative_6VIew_2 그리기입니다.

void CNegative_6VIew_2::OnDraw(CDC* pDC)
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CNegative_6Doc *pDoc = (CNegative_6Doc *)pFrame->GetActiveDocument();
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	//BmInfo;
//	int height;
//	int width;
//	int rwsize;
//
//	ASSERT_VALID(pDoc);
//	if (!pDoc)
//		return;
////24비트 비트맵 파일의 영상출력
//	
//		int index;
//		rwsize=WIDTHBYTES(8*256);
//		
//
//   //팔레트를 읽어들이며 반복출력
//		for(int i=0; i<256;i++)
//			for(int j=0; j<256;j++){
//				index=pDoc->pDib[i*rwsize+j];
//				BYTE R=pDoc->rgb[index].rgbRed;
//				BYTE G=pDoc->rgb[index].rgbGreen;
//				BYTE B=pDoc->rgb[index].rgbBlue;
//
//				//pDC->SetPixel(j,i,RGB(R,G,B));
// //영상 반전출력
//				pDC->SetPixel(j,256-i-1,RGB(R,G,B));
//
//			}
	//CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	//CNegative_6Doc *pDoc = (CNegative_6Doc *)pFrame->GetActiveDocument();
	// TODO: 여기에 그리기 코드를 추가합니다.
	//int k = pDoc->temp_BmpInfo.biBitCount;
	//int h = pDoc->temp_BmpInfo.biWidth;
  int rwSize = WIDTHBYTES(8 * 256);
  DWORD dwPos;
//  pDC->TextOutW(0,0,(LPTSTR)(LPCTSTR)pDib[0]);
	RGBQUAD rgb[256];
    //   HDC   hdc = GetDC(g_hWnd);

	for(int i = 0; i<pDoc->m_BmpHeight; i++)
   {
	   for(int j = 0; j<pDoc->m_BmpWidth; j++)
	   {

		 // pDC->SetPixel(j,i,pDib2[i*rwSize+j]);
			//pDC->TextOutW(i,j,(LPTSTR)(LPCTSTR)pDib2[i*rwSize+j]);
		  //Image.BitBlt(pDC->GetSafeHdc(), 0, 0);
		/*  dwPos = (256 - i - 1) * 256 + j;
		   pDC->SetPixel(i,j,RGB(rgb[pDib2[dwPos]].
			  rgbRed,rgb[pDib2[dwPos]].rgbBlue,rgb[pDib2[dwPos]].rgbGreen));*/
	   }
   }
	// AfxMessageBox(_T("Wks"));
}


// CNegative_6VIew_2 진단입니다.

#ifdef _DEBUG
void CNegative_6VIew_2::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CNegative_6VIew_2::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CNegative_6VIew_2 메시지 처리기입니다.


void CNegative_6VIew_2::Negative_Image(void)
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CNegative_6Doc *pDoc = (CNegative_6Doc *)pFrame->GetActiveDocument();
	
	//CClientDC dc(this);
 //     
 //  CDC MemDC;
 //  CDC BufferDC;
 //    
   //CBitmap Backbmp, *pBackbmp;
   //HBITMAP hBitmap, OldBitmap;
 
   BITMAPFILEHEADER temp_BmpFileHeader;
   BITMAPINFOHEADER temp_BmpInfo;
 
  ///* hBitmap =(HBITMAP)::LoadImage(NULL, pDoc->Bmpstr, IMAGE_BITMAP, NULL, NULL, 
  //       LR_DEFAULTSIZE| LR_LOADFROMFILE);*/

   CFile file(pDoc->Bmpstr, CFile::modeRead);
 
   if(!file.Read(&temp_BmpFileHeader, sizeof(BITMAPFILEHEADER)))
         AfxMessageBox(_T("비트맵 파일 헤더 읽기 에러..."));
 
   if(temp_BmpFileHeader.bfType != 0x4d42)
         AfxMessageBox(_T("비트맵 형식이 아님..."));
 
   if(!file.Read(&temp_BmpInfo, sizeof(BITMAPINFOHEADER)))
          AfxMessageBox(_T("비트맵 정보 파일 헤더 읽기 에러..."));

   RGBQUAD rgb[256];
   pDoc->m_BmpHeight = (UINT)temp_BmpInfo.biHeight;
   pDoc->m_BmpWidth = (UINT)temp_BmpInfo.biWidth;

   file.Read(&pDib,sizeof(pDoc->m_BmpHeight*pDoc->m_BmpWidth));
   file.Read(rgb,sizeof(RGBQUAD)*256);

   int rwSize = WIDTHBYTES(temp_BmpInfo.biBitCount * temp_BmpInfo.biWidth);
   pDib = new BYTE[temp_BmpInfo.biSizeImage];
   pDib2 = new BYTE[temp_BmpInfo.biSizeImage];

 //  COLORREF rgb;
 //  CWnd* pWndDesktop = GetDesktopWindow();  // 바탕 화면 윈도우 DC
	//CWindowDC ScrDC(pWndDesktop);                // 뷰 윈도우 DC

	//Image.Create(256, 256, ScrDC.GetDeviceCaps(BITSPIXEL));


   for(int i = 0; i<pDoc->m_BmpHeight; i++)
   {
	   for(int j = 0; j<pDoc->m_BmpWidth; j++)
	   {
		   //DWORD dwPos = (256 - i - 1) * 256 + j;
		   //rgb = Image.GetPixel(i, j);
		   //Image.SetPixel(i, j, 255-rgb);
		   pDib2[i*rwSize+j] = 255 - pDib[i*rwSize+j];
			/*rgb[pDib2[i*rwSize+j]].rgbRed = 255 - rgb[pDib[i*rwSize+j]].rgbRed;
		   rgb[pDib2[i*rwSize+j]].rgbGreen = 255 - rgb[pDib[i*rwSize+j]].rgbGreen;
		   rgb[pDib2[i*rwSize+j]].rgbBlue = 255 - rgb[pDib[i*rwSize+j]].rgbBlue;
		   *///pDC->SetPixel(i,j,RGB(rgb[pDib2[dwPos]].
			  // rgbRed,rgb[pDib2[dwPos]].rgbBlue,rgb[pDib2[dwPos]].rgbGreen));
	   }
   }
  
 
 /*  if(pDoc->m_BmpHeight < 200 || pDoc->m_BmpWidth < 200)
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
   BufferDC.SelectObject(pBackbmp);*/
}
