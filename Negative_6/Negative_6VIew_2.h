#pragma once


// CNegative_6VIew_2 ���Դϴ�.

class CNegative_6VIew_2 : public CView
{
	DECLARE_DYNCREATE(CNegative_6VIew_2)

protected:
	CNegative_6VIew_2();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CNegative_6VIew_2();

public:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
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


