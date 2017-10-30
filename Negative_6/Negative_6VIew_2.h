#pragma once


// CNegative_6VIew_2 뷰입니다.

class CNegative_6VIew_2 : public CView
{
	DECLARE_DYNCREATE(CNegative_6VIew_2)

protected:
	CNegative_6VIew_2();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CNegative_6VIew_2();

public:
	virtual void OnDraw(CDC* pDC);      // 이 뷰를 그리기 위해 재정의되었습니다.
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	void Negative_Image(void);
	BYTE * pDib;
	BYTE * pDib2;
	CImage Image;
};


