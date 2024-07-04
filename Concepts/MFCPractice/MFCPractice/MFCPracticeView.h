
// MFCPracticeView.h : interface of the CMFCPracticeView class
//

#pragma once


class CMFCPracticeView : public CView
{
protected: // create from serialization only
	CMFCPracticeView();
	DECLARE_DYNCREATE(CMFCPracticeView)

// Attributes
public:
	CMFCPracticeDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMFCPracticeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCPracticeView.cpp
inline CMFCPracticeDoc* CMFCPracticeView::GetDocument() const
   { return reinterpret_cast<CMFCPracticeDoc*>(m_pDocument); }
#endif

