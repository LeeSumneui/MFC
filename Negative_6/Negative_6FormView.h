#pragma once



// CNegative_6FormView �� ���Դϴ�.

class CNegative_6FormView : public CFormView
{
	DECLARE_DYNCREATE(CNegative_6FormView)

protected:
	CNegative_6FormView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLoadImage();
	afx_msg void OnBnClickedNegaImage();
};


