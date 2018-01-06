
// RecipeGeneratorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RecipeGenerator.h"
#include "RecipeGeneratorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRecipeGeneratorDlg dialog



CRecipeGeneratorDlg::CRecipeGeneratorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_RECIPEGENERATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRecipeGeneratorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRecipeGeneratorDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CRecipeGeneratorDlg::OnBnClickedButtonAdd)
	ON_LBN_SELCHANGE(IDC_LIST_INGREDIENTS, &CRecipeGeneratorDlg::OnLbnSelchangeListIngredients)
END_MESSAGE_MAP()


void CRecipeGeneratorDlg::InitData()
{

	Milk* milk3p = new Milk(3);
	Milk* milk5p = new Milk(5);
	
	m_allIngredients.push_back(milk3p);
	m_allIngredients.push_back(milk5p);

}


void CRecipeGeneratorDlg::InitDlgIngredientsList()
{

	m_ingredientsList = (CListBox*)GetDlgItem(IDC_LIST_INGREDIENTS);
	m_myIngredientsList = (CListBox*)GetDlgItem(IDC_LIST_MY_INGREDIENTS);
	m_generateButton = (CButton*)GetDlgItem(IDC_BUTTON_GENERATE);
	m_addButton = (CButton*)GetDlgItem(IDC_BUTTON_ADD);
	m_editAdd = (CEdit*)GetDlgItem(IDC_EDIT_ADD);




	int i = 0;
	for (std::vector<Ingredient*>::iterator it = m_allIngredients.begin(); it != m_allIngredients.end(); ++it, i++)
	{
		m_ingredientsList->InsertString(i, (*it)->GetName());
		m_ingredientsList->SetItemDataPtr(i, (*it));
	}

	i = 0;
	for (std::vector<Ingredient*>::iterator it = m_myIngredients.begin(); it != m_myIngredients.end(); ++it, i++)
	{
		m_myIngredientsList->InsertString(i, (*it)->GetName());
		m_myIngredientsList->SetItemDataPtr(i, (*it));
	}
	if (i > 0)
	{
		m_generateButton->EnableWindow();
	}

}


// CRecipeGeneratorDlg message handlers

BOOL CRecipeGeneratorDlg::OnInitDialog()
{

	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	InitData();
	InitDlgIngredientsList();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRecipeGeneratorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRecipeGeneratorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
		
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRecipeGeneratorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRecipeGeneratorDlg::OnBnClickedButtonAdd()
{
	int selectedIndex = m_ingredientsList->GetCurSel();
	if (selectedIndex == -1)
		return;
	

	Ingredient* selectedItem = m_allIngredients[selectedIndex];
	m_myIngredients.push_back(selectedItem);

	Ingredient* added = selectedItem->clone();
	CString totalGrams;
	m_editAdd->GetWindowTextW(totalGrams);
	WCHAR* p;
	int totalGramsNumber = wcstol(totalGrams, &p, 10);
	if (*p == 0)
	{
		int i = m_myIngredients.size() - 1;
		added->SetQuantityInGrams(totalGramsNumber);
		m_myIngredientsList->InsertString(i, added->GetName());
		m_myIngredientsList->SetItemDataPtr(i, added);
		m_generateButton->EnableWindow();
		m_myIngredientsList->Invalidate();
	}
}


void CRecipeGeneratorDlg::OnLbnSelchangeListIngredients()
{
	int selectedIndex = m_ingredientsList->GetCurSel();
	if (selectedIndex == -1)
		return;
	m_addButton->EnableWindow();
	m_editAdd->EnableWindow();
	m_editAdd->SetWindowTextW(L"100");
}
