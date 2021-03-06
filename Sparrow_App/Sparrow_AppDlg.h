
// Sparrow_AppDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "Dothinkey.h"
#include "Utils.h"
#include "threads.h"
#include "Utils.h"
#include <strsafe.h>
#include "Sfr_entry.h"
#include "Sfr.h"
#include <thread>
#include <future>
#include <opencv2\opencv.hpp>
#include "afxbutton.h"
#include "afxcmn.h"
#include "PositionLearningDlg.h"
#include "MotionDlg.h"
#include "json.hpp"

// CSparrowAppDlg dialog
class CSparrowAppDlg : public CDialog
{
// Construction
public:
	CSparrowAppDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Sparrow_APP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public: 
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	Log* pLog;
	Dothinkey * dk;
	virtual BOOL DestroyWindow();
	afx_msg void OnBnClickedOpencamera();

	CStatic m_wndVideoA;
	//CStatic m_wndVideoB;
	CStatic m_wndGraph;
	CStatic m_wndTaitText;
	CStatic m_wndCentreText;
	CStatic m_zText;
	afx_msg void OnBnClickedOpenCloseCamera();
	afx_msg void OnBnClickedCloseCamera();
	afx_msg void OnBnClickedSaveImage();
	afx_msg void OnBnClickedTakeAAZPoint();
	afx_msg void OnBnClickedClearAAZPoint();
	afx_msg void OnBnClickedMTFPlot();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedMTFLive();

	BOOL liveViewThreadFlag;
	bool mtfLiveViewThread = false;
	vector<Sfr_entry> calculateSfrAtCurrZ(bool isDisplayResult, double currZ);
	vector<vector<Sfr_entry>> sfr_sampling;

//UI 
	CFont SFont;
	CMFCButton m_testButton;
	CListCtrl m_logList;
	afx_msg void OnBnClickedButton6();
    void logToListBox(CString str);
	afx_msg void OnBnClickedMotionDlg();

//Machine Definition
	MachineDefinition machineDefinition;
	CPositionLearningDlg *positionLearningDlg;
//Motion 
	MotionDlg *motionDlg;
	afx_msg void OnBnClickedCommand2();

	bool directionY;
};
