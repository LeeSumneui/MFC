
// Negative_6View.h : CNegative_6View Ŭ������ �������̽�
//

#pragma once
class CNegative_6Doc ;

class CNegative_6View : public CView
{
protected: // serialization������ ��������ϴ�.
	CNegative_6View();
	DECLARE_DYNCREATE(CNegative_6View)

// Ư���Դϴ�.
public:
	CNegative_6Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CNegative_6View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	void LoadBmp(void);
};

#ifndef _DEBUG  // Negative_6View.cpp�� ����� ����
inline CNegative_6Doc* CNegative_6View::GetDocument() const
   { return reinterpret_cast<CNegative_6Doc*>(m_pDocument); }
#endif

