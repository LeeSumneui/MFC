
// Negative_6Doc.h : CNegative_6Doc Ŭ������ �������̽�
//


#pragma once


class CNegative_6Doc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CNegative_6Doc();
	DECLARE_DYNCREATE(CNegative_6Doc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CNegative_6Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnFileOpen();
	CString Bmpstr, Bmpstr1;                  // ������ �̸��� ��θ� �޾ƿ��� ���� ����
	int m_BmpHeight;  
	int m_BmpWidth;    // ������ ����, ���α��̸� �޾ƿ��� ���� ����
	BOOL InitRect ;                               // ���߿� ���� �簢�� üũ ����
	void NegativeImage(void);
	void LoadBmp(void);
	BITMAPFILEHEADER FH;
	BITMAPINFOHEADER IH;
	BYTE * pDib;
	BYTE * pDib2;
	RGBQUAD rgb[256];
};
