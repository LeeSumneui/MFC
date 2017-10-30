
// Negative_6Doc.h : CNegative_6Doc 클래스의 인터페이스
//


#pragma once


class CNegative_6Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CNegative_6Doc();
	DECLARE_DYNCREATE(CNegative_6Doc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CNegative_6Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnFileOpen();
	CString Bmpstr, Bmpstr1;                  // 파일의 이름과 경로를 받아오기 위한 변수
	int m_BmpHeight;  
	int m_BmpWidth;    // 파일의 가로, 세로길이를 받아오기 위한 변수
	BOOL InitRect ;                               // 나중에 맵툴 사각형 체크 변수
	void NegativeImage(void);
	void LoadBmp(void);
	BITMAPFILEHEADER FH;
	BITMAPINFOHEADER IH;
	BYTE * pDib;
	BYTE * pDib2;
	RGBQUAD rgb[256];
};
