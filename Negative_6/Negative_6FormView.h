#pragma once



// CNegative_6FormView 폼 뷰입니다.

class CNegative_6FormView : public CFormView
{
	DECLARE_DYNCREATE(CNegative_6FormView)

protected:
	CNegative_6FormView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CNegative_6FormView();

public:
	enum { IDD = IDD_NEGATIVE_6FORMVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLoadImage();
	afx_msg void OnBnClickedNegaImage();
};


