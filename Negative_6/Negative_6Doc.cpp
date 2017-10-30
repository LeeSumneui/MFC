
// Negative_6Doc.cpp : CNegative_6Doc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Negative_6.h"
#endif

#include "Negative_6Doc.h"
#include "MainFrm.h"
#include "Negative_6View.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#define WIDTHBYTES(bits) (((bits)+31)/32*4)
#endif

// CNegative_6Doc

IMPLEMENT_DYNCREATE(CNegative_6Doc, CDocument)

BEGIN_MESSAGE_MAP(CNegative_6Doc, CDocument)
	ON_COMMAND(ID_FILE_OPEN, &CNegative_6Doc::OnFileOpen)
END_MESSAGE_MAP()


// CNegative_6Doc 생성/소멸

CNegative_6Doc::CNegative_6Doc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.
	m_BmpHeight , m_BmpWidth = 0;
	InitRect = false;
	pDib = NULL;
	pDib2 = NULL;
}

CNegative_6Doc::~CNegative_6Doc()
{
}

BOOL CNegative_6Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CNegative_6Doc serialization

void CNegative_6Doc::Serialize(CArchive& ar)
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
void CNegative_6Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CNegative_6Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CNegative_6Doc::SetSearchContent(const CString& value)
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

// CNegative_6Doc 진단

#ifdef _DEBUG
void CNegative_6Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CNegative_6Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CNegative_6Doc 명령


void CNegative_6Doc::OnFileOpen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	
	CFileDialog tempDlg(TRUE);

    if(tempDlg.DoModal() == IDOK)
	{
          Bmpstr = tempDlg.GetPathName();
          Bmpstr1 = tempDlg.GetFileName();
    }
    
     UpdateAllViews(NULL);
 
     InitRect = FALSE;
}


void CNegative_6Doc::NegativeImage(void)
{

	//BITMAPFILEHEADER temp_BmpFileHeader;
	//BITMAPINFOHEADER temp_BmpInfo;

	//CFile file(Bmpstr, CFile::modeRead);
	////CFile file2;
	////file2.Open(_T("Negative.bmp"),CFile::modeCreate | CFile::modeWrite);

	//file.Read(&temp_BmpFileHeader, sizeof(BITMAPFILEHEADER));
	//file.Read(&temp_BmpInfo, sizeof(BITMAPINFOHEADER));
	////int size = temp_BmpInfo.biWidth * temp_BmpInfo.biHeight * temp_BmpInfo.biBitCount;

	//pDib = new BYTE[temp_BmpInfo.biSizeImage];
	//pDib2 = new BYTE[temp_BmpInfo.biSizeImage];

	////RGBQUAD gRGB[256];

	//file.Read(&pDib,sizeof(temp_BmpInfo.biSizeImage));
	////file.Read(&gRGB,sizeof(256));

	//int rwSize = WIDTHBYTES(temp_BmpInfo.biBitCount * temp_BmpInfo.biWidth);

	////역상화데이터 생성
	//for(int i = 0; i < temp_BmpInfo.biHeight; i++)
	//	for(int j = 0; j < temp_BmpInfo.biWidth; j++)
	//		pDib2[i*rwSize+j] = 255 - pDib[i*rwSize+j];
	////(temp_BmpInfo.biHeight-i-1)

	//////파일복사
	////FH.bfType = temp_BmpFileHeader.bfType;
	////FH.bfSize = temp_BmpFileHeader.bfSize;
	////FH.bfReserved1 = temp_BmpFileHeader.bfReserved1;
	////FH.bfReserved2 = temp_BmpFileHeader.bfReserved2;
	////FH.bfOffBits = temp_BmpFileHeader.bfOffBits;

	////IH.biSize = temp_BmpInfo.biSize;
	////IH.biWidth = temp_BmpInfo.biWidth;
	////IH.biHeight = temp_BmpInfo.biHeight;
	////IH.biPlanes = temp_BmpInfo.biPlanes;
	////IH.biBitCount = temp_BmpInfo.biBitCount;
	////IH.biCompression = temp_BmpInfo.biCompression;
	////IH.biSizeImage = temp_BmpInfo.biSizeImage;
	////IH.biXPelsPerMeter = temp_BmpInfo.biXPelsPerMeter;
	////IH.biYPelsPerMeter = temp_BmpInfo.biYPelsPerMeter;
	////IH.biClrUsed = temp_BmpInfo.biClrUsed;
	////IH.biClrImportant = temp_BmpInfo.biClrImportant;

	////// file2.SetFilePath(pstrName);  C:\Users\이지민\Desktop\Negative_6
	////file2.Write(&FH, sizeof(BITMAPFILEHEADER));
	////file2.Write(&IH, sizeof(BITMAPINFOHEADER));
	////file2.Write(gRGB, sizeof(256));
	////file2.Write(&pDib2, sizeof(size));

	////file2.Close();

	//UpdateAllViews(NULL);
}


