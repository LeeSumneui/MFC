// Negative_6FormView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Negative_6.h"
#include "Negative_6FormView.h"
#include "MainFrm.h"
#include "Negative_6Doc.h"
#include "Negative_6VIew_2.h"


// CNegative_6FormView

IMPLEMENT_DYNCREATE(CNegative_6FormView, CFormView)

CNegative_6FormView::CNegative_6FormView()
	: CFormView(CNegative_6FormView::IDD)
{
}

CNegative_6FormView::~CNegative_6FormView()
{
}

void CNegative_6FormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNegative_6FormView, CFormView)
	ON_BN_CLICKED(IDC_LOAD_IMAGE, &CNegative_6FormView::OnBnClickedLoadImage)
	ON_BN_CLICKED(IDC_NEGA_IMAGE, &CNegative_6FormView::OnBnClickedNegaImage)
END_MESSAGE_MAP()


// CNegative_6FormView 진단입니다.

#ifdef _DEBUG
void CNegative_6FormView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CNegative_6FormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CNegative_6FormView 메시지 처리기입니다.


void CNegative_6FormView::OnBnClickedLoadImage()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CNegative_6Doc *pDoc = (CNegative_6Doc *)pFrame->GetActiveDocument();

	pDoc->OnFileOpen();
}


void CNegative_6FormView::OnBnClickedNegaImage()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	CNegative_6VIew_2 *pView = (CNegative_6VIew_2 *)pFrame->GetActiveView();
	////CNegative_6Doc *pDoc = (CNegative_6Doc *)pFrame->GetActiveDocument();
	//
	pView->Negative_Image();
	//AfxMessageBox(_T("Wks"));
	//pDoc->NegativeImage();
}
