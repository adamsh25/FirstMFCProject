
// RecipeGeneratorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RecipeGenerator.h"
#include "AddCommand.h"
#include "UpdateCommand.h"
#include "DeleteCommand.h"
#include "RecipeGeneratorDlg.h"
#include "Ingredient.h"
#include "Dairy.h"
#include "Milk.h"
#include "Carb.h"
#include "Vegetable.h"
#include "Cereal.h"
#include "Recipe.h"
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
	ON_BN_CLICKED(IDC_BUTTON_UNDO, &CRecipeGeneratorDlg::OnBnClickedButtonUndo)
	ON_BN_CLICKED(IDC_BUTTON_REDO, &CRecipeGeneratorDlg::OnBnClickedButtonRedo)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CRecipeGeneratorDlg::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_LOAD, &CRecipeGeneratorDlg::OnBnClickedButtonLoad)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CRecipeGeneratorDlg::OnBnClickedButtonClear)
	ON_LBN_SELCHANGE(IDC_LIST_MY_INGREDIENTS, &CRecipeGeneratorDlg::OnLbnSelchangeListMyIngredients)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CRecipeGeneratorDlg::OnBnClickedButtonDelete)
	ON_LBN_SELCANCEL(IDC_LIST_MY_INGREDIENTS, &CRecipeGeneratorDlg::OnLbnSelcancelListMyIngredients)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE_QUANTITY, &CRecipeGeneratorDlg::OnBnClickedButtonUpdateQuantity)
	ON_BN_CLICKED(IDC_BUTTON_GENERATE, &CRecipeGeneratorDlg::OnBnClickedButtonGenerate)
	ON_LBN_SELCHANGE(IDC_LIST_RECIPES, &CRecipeGeneratorDlg::OnLbnSelchangeListRecipes)
	ON_BN_CLICKED(IDC_BUTTON_USE_RECIPE, &CRecipeGeneratorDlg::OnBnClickedButtonUseRecipe)
//	ON_WM_NCMOUSELEAVE()
//ON_WM_MOUSELEAVE()
ON_WM_MOUSEMOVE()
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
ON_LBN_DBLCLK(IDC_LIST_INGREDIENTS, &CRecipeGeneratorDlg::OnLbnDblclkListIngredients)
ON_LBN_DBLCLK(IDC_LIST_MY_INGREDIENTS, &CRecipeGeneratorDlg::OnLbnDblclkListMyIngredients)
END_MESSAGE_MAP()


void CRecipeGeneratorDlg::InitData()
{
	////////////////////////// Add Ingredients /////////////////////////////////////
	Milk* milk3p = new Milk(3);
	Milk* milk5p = new Milk(5);
	Milk* milk9p = new Milk(9);

	Milk* milkGoat = new Milk(3, L"Goat");
	Milk* milkSheap = new Milk(15, L"Sheep");
	Milk* milkSoy = new Milk(9, L"Soy");


	Cereal* cheerios = new Cereal(L"Cheerios");

	m_allIngredients.push_back(milk3p);
	m_allIngredients.push_back(milk5p);
	m_allIngredients.push_back(milk9p);

	m_allIngredients.push_back(milkGoat);
	m_allIngredients.push_back(milkSheap);
	m_allIngredients.push_back(milkSoy);

	m_allIngredients.push_back(cheerios);



	////////////////////////// Add Recipes /////////////////////////////////////



	Recipe* milkAndCereals = new Recipe(L"Milk And Cereals");
	milkAndCereals->AddIngredient(milk3p, 400);
	milkAndCereals->AddIngredient(cheerios, 200);
	milkAndCereals->SetRecipeInstructionText(L"-\tPut The Cerales Inside A Bowl\r\n-\tPut Milk Inside The Bowl\r\n-\tJust Mix!");
	m_allRecipes.push_back(milkAndCereals);


	Carb* rice = new Carb(L"Rice", 600);
	m_allIngredients.push_back(rice);

	Vegetable* carrot = new Vegetable(L"Carrot", L"Orange");
	m_allIngredients.push_back(carrot);

	Recipe* padThai = new Recipe(L"Pad Thai");
	padThai->AddIngredient(rice, 300);
	padThai->AddIngredient(carrot, 150);
	padThai->SetRecipeInstructionText(L"-\tMix!!!");
	m_allRecipes.push_back(padThai);

}


void CRecipeGeneratorDlg::InitDlgIngredientsList()
{

	m_ingredientsList = (CListBox*)GetDlgItem(IDC_LIST_INGREDIENTS);
	m_recipesList = (CListBox*)GetDlgItem(IDC_LIST_RECIPES);
	m_myIngredientsList = (CListBox*)GetDlgItem(IDC_LIST_MY_INGREDIENTS);
	m_generateButton = (CButton*)GetDlgItem(IDC_BUTTON_GENERATE);
	m_undoButton = (CButton*)GetDlgItem(IDC_BUTTON_UNDO);
	m_redoButton = (CButton*)GetDlgItem(IDC_BUTTON_REDO);
	m_addButton = (CButton*)GetDlgItem(IDC_BUTTON_ADD);
	m_updateButton = (CButton*)GetDlgItem(IDC_BUTTON_UPDATE_QUANTITY);
	m_editAdd = (CEdit*)GetDlgItem(IDC_EDIT_ADD);
	m_editUpdate = (CEdit*)GetDlgItem(IDC_EDIT_UPDATE_QUANTITY);
	m_deleteButton = (CButton*)GetDlgItem(IDC_BUTTON_DELETE);
	m_richEdit = (CEdit*)GetDlgItem(IDC_RICHEDIT_RECIPE);
	m_useRecipeButton = (CButton*)GetDlgItem(IDC_BUTTON_USE_RECIPE);


	int i = 0;
	for (std::vector<Ingredient*>::iterator it = m_allIngredients.begin(); it != m_allIngredients.end(); ++it, ++i)
	{
		m_ingredientsList->InsertString(i, (*it)->GetName());
		m_ingredientsList->SetItemDataPtr(i, (*it));
	}

	Load();

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
	
	CString totalGrams;
	m_editAdd->GetWindowTextW(totalGrams);
	WCHAR* p;
	int totalGramsNumber = wcstol(totalGrams, &p, 10);
	if (*p == 0)
	{
		Ingredient* selectedItem = m_allIngredients[selectedIndex];
		Ingredient* added = selectedItem->clone();
		added->SetQuantityInGrams(totalGramsNumber);
		AddCommand* addCommand = new AddCommand(m_myIngredientsList, m_myIngredients, added);
		addCommand->perform();
		m_generateButton->EnableWindow();
		m_commandListToUndo.push_back(addCommand);
		m_undoButton->EnableWindow();
		m_commandListToRedo.clear();
		m_redoButton->EnableWindow(false);
		m_myIngredientsList->SetCurSel(addCommand->getExistingIndex());
		CRecipeGeneratorDlg::OnLbnSelchangeListMyIngredients();
	}
	CRecipeGeneratorDlg::OnBnClickedButtonGenerate();
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


void CRecipeGeneratorDlg::OnBnClickedButtonUndo()
{
	if (m_commandListToUndo.size() == 0)
		return;
	Command* commandToUndo = m_commandListToUndo.back();
	m_commandListToRedo.push_back(commandToUndo);
	commandToUndo->rollback();
	m_commandListToUndo.pop_back();
	if (m_commandListToUndo.size() == 0)
		m_undoButton->EnableWindow(false);
	m_redoButton->EnableWindow();
	CRecipeGeneratorDlg::OnBnClickedButtonGenerate();
}


void CRecipeGeneratorDlg::OnBnClickedButtonRedo()
{
	if (m_commandListToRedo.size() == 0)
		return;
	Command* commandToRedo = m_commandListToRedo.back();
	m_commandListToUndo.push_back(commandToRedo);
	commandToRedo->perform();
	m_commandListToRedo.pop_back();
	if (m_commandListToRedo.size() == 0)
		m_redoButton->EnableWindow(false);
	m_undoButton->EnableWindow();
	CRecipeGeneratorDlg::OnBnClickedButtonGenerate();
}


void CRecipeGeneratorDlg::OnBnClickedButtonSave()
{
	CFile file(L"ingredients.bin", CFile::modeCreate | CFile::modeWrite);
	CArchive archive(&file, CArchive::store);
	archive << m_myIngredients.size();
	for (int i = 0; i < m_myIngredients.size(); ++i)
		archive << m_myIngredients[i];
}

void CRecipeGeneratorDlg::OnBnClickedButtonLoad()
{
	Load();
}

void CRecipeGeneratorDlg::ClearAll()
{
	m_generatedRecipes.clear();
	m_recipesList->ResetContent();
	m_myIngredients.clear();
	m_myIngredientsList->ResetContent();
	m_myIngredientsList->Invalidate();
	m_commandListToUndo.clear();
	m_commandListToRedo.clear();
	m_undoButton->EnableWindow(false);
	m_redoButton->EnableWindow(false);
	m_richEdit->SetWindowTextW(L"");
	m_richEdit->Invalidate();
}

void CRecipeGeneratorDlg::Load()
{
	ClearAll();
	WCHAR* fileName = L"ingredients.bin";
	CFileStatus status;
	if (!CFile::GetStatus(fileName, status))
		return;
	CFile file(fileName, CFile::modeRead);
	CArchive archive(&file, CArchive::load);
	size_t count;
	archive >> count;

	for (int i = 0; i < count; i++)
	{
		Ingredient* ingredient;
		archive >> ingredient;
		m_myIngredients.push_back(ingredient);
		m_myIngredientsList->InsertString(i, ingredient->GetName());
		m_myIngredientsList->SetItemDataPtr(i, ingredient);
	}
	if (count > 0)
	{
		m_generateButton->EnableWindow();
	}
	m_myIngredientsList->Invalidate();
	m_myIngredientsList->SetCurSel(0);
	CRecipeGeneratorDlg::OnLbnSelchangeListMyIngredients();
	m_ingredientsList->SetCurSel(0);
	CRecipeGeneratorDlg::OnLbnSelchangeListIngredients();
	m_recipesList->SetCurSel(0);
	CRecipeGeneratorDlg::OnLbnSelchangeListRecipes();
	CRecipeGeneratorDlg::OnBnClickedButtonGenerate();
}

void CRecipeGeneratorDlg::OnBnClickedButtonClear()
{
	ClearAll();
}

void CRecipeGeneratorDlg::OnLbnSelchangeListMyIngredients()
{
	int selectedIndex = m_myIngredientsList->GetCurSel();
	if (selectedIndex == -1)
	{
		m_deleteButton->EnableWindow(false);
		m_updateButton->EnableWindow(false);
		m_editUpdate->EnableWindow(false);
		return;
	}
	m_editUpdate->EnableWindow();
	m_updateButton->EnableWindow();
	m_deleteButton->EnableWindow();
	m_deleteButton->Invalidate();
}

void CRecipeGeneratorDlg::OnBnClickedButtonDelete()
{
	int selectedIndex = m_myIngredientsList->GetCurSel();
	if (selectedIndex == -1)
		return;
	
	Ingredient* selectedItem = m_myIngredients[selectedIndex];

	DeleteCommand* deleteCommand = new DeleteCommand(m_myIngredientsList, m_myIngredients, selectedItem);
	deleteCommand->perform();
	m_generateButton->EnableWindow();
	m_commandListToUndo.push_back(deleteCommand);
	m_undoButton->EnableWindow();
	m_deleteButton->EnableWindow(false);
	m_updateButton->EnableWindow(false);
	m_editUpdate->EnableWindow(false);
	m_commandListToRedo.clear();
	m_redoButton->EnableWindow(false);
	m_myIngredientsList->SetCurSel(selectedIndex-1);
	CRecipeGeneratorDlg::OnLbnSelchangeListMyIngredients();
	CRecipeGeneratorDlg::OnBnClickedButtonGenerate();
}

void CRecipeGeneratorDlg::OnLbnSelcancelListMyIngredients()
{

}

void CRecipeGeneratorDlg::OnBnClickedButtonUpdateQuantity()
{
	int selectedIndex = m_myIngredientsList->GetCurSel();
	if (selectedIndex == -1)
		return;

	CString totalGrams;
	m_editUpdate->GetWindowTextW(totalGrams);
	WCHAR* p;
	int totalGramsNumber = wcstol(totalGrams, &p, 10);
	if (*p == 0)
	{
		Ingredient* selectedItem = m_myIngredients[selectedIndex];
		UpdateCommand* updateCommand = new UpdateCommand(m_myIngredientsList, m_myIngredients, selectedItem, totalGramsNumber, selectedIndex);
		updateCommand->perform();
		m_generateButton->EnableWindow();
		m_commandListToUndo.push_back(updateCommand);
		m_undoButton->EnableWindow();
		m_deleteButton->EnableWindow(false);
		m_updateButton->EnableWindow(false);
		m_editUpdate->EnableWindow(false);
		m_commandListToRedo.clear();
		m_redoButton->EnableWindow(false);

		m_myIngredientsList->SetCurSel(selectedIndex);
		CRecipeGeneratorDlg::OnLbnSelchangeListMyIngredients();
		CRecipeGeneratorDlg::OnBnClickedButtonGenerate();
	}

}

void CRecipeGeneratorDlg::OnBnClickedButtonGenerate()
{
	m_generatedRecipes.clear();
	m_recipesList->ResetContent();
	m_richEdit->SetWindowTextW(L"");
	m_richEdit->Invalidate();
	for (std::vector<Recipe*>::iterator it = m_allRecipes.begin(); it != m_allRecipes.end(); ++it)
	{
		if((*it)->MatchRecipe(m_myIngredients))
			m_generatedRecipes.push_back(*it);
	}

	int i = 0;
	for (std::vector<Recipe*>::iterator it = m_generatedRecipes.begin(); it != m_generatedRecipes.end(); ++it, ++i)
	{

		m_recipesList->InsertString(i, (*it)->GetName());
		if (i == 0)
		{
			m_recipesList->SetCurSel(i);
			CRecipeGeneratorDlg::OnLbnSelchangeListRecipes();
		}
		m_recipesList->SetItemDataPtr(i, (*it));
	}
	m_recipesList->Invalidate();
}


void CRecipeGeneratorDlg::OnLbnSelchangeListRecipes()
{
	int selectedIndex = m_recipesList->GetCurSel();
	if (selectedIndex == -1)
		return;

	Recipe* selectedItem = m_generatedRecipes[selectedIndex];
	m_richEdit->SetWindowTextW(selectedItem->GetRecipeText());
	m_useRecipeButton->EnableWindow();

	m_richEdit->Invalidate();
}


void CRecipeGeneratorDlg::OnBnClickedButtonUseRecipe()
{
	int selectedIndex = m_recipesList->GetCurSel();
	if (selectedIndex == -1)
		return;

	Recipe* selectedItem = m_generatedRecipes[selectedIndex];
	vector<Ingredient*> recipeIngredients = selectedItem->GetIngredients();
	for (std::vector<Ingredient*>::const_iterator recipeIngredient = recipeIngredients.begin(); recipeIngredient != recipeIngredients.end(); ++recipeIngredient)
	{
		int location = 0;
		vector<Ingredient*>::iterator it;
		for (it = m_myIngredients.begin(); it != m_myIngredients.end(); ++it, location++)
			if ((*recipeIngredient)->GetInfo().Compare((*it)->GetInfo()) == 0)
				break;

		int newQunatity = (*it)->GetQuantityInGrams() - (*recipeIngredient)->GetQuantityInGrams();
		Command* usedCommand = NULL;
		if (newQunatity == 0)
			usedCommand = new DeleteCommand(m_myIngredientsList, m_myIngredients, (*it));
		else
			usedCommand = new UpdateCommand(m_myIngredientsList, m_myIngredients, (*it), newQunatity, location);

		usedCommand->perform();
		m_commandListToUndo.push_back(usedCommand);
		m_undoButton->EnableWindow();
		m_deleteButton->EnableWindow(false);
		m_updateButton->EnableWindow(false);
		m_editUpdate->EnableWindow(false);
		m_useRecipeButton->EnableWindow(false);
		m_commandListToRedo.clear();
		m_redoButton->EnableWindow(false);
	}

	CRecipeGeneratorDlg::OnBnClickedButtonGenerate();
	m_richEdit->Invalidate();
}



void CRecipeGeneratorDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CDialog::OnMouseMove(nFlags, point);
}


void CRecipeGeneratorDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CDialog::OnLButtonDown(nFlags, point);
}


void CRecipeGeneratorDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CDialog::OnLButtonUp(nFlags, point);
}


void CRecipeGeneratorDlg::OnLbnDblclkListIngredients()
{
	CRecipeGeneratorDlg::OnBnClickedButtonAdd();
}


void CRecipeGeneratorDlg::OnLbnDblclkListMyIngredients()
{
	int selectedIndex = m_myIngredientsList->GetCurSel();
	if (selectedIndex == -1)
		return;

	CString totalGrams;
	m_editAdd->GetWindowTextW(totalGrams);
	WCHAR* p;
	int totalGramsNumber = wcstol(totalGrams, &p, 10);
	if (*p == 0)
	{
		Ingredient* selectedItem = m_myIngredients[selectedIndex];
		Ingredient* added = selectedItem->clone();
		added->SetQuantityInGrams(totalGramsNumber);
		AddCommand* addCommand = new AddCommand(m_myIngredientsList, m_myIngredients, added);
		addCommand->perform();
		m_generateButton->EnableWindow();
		m_commandListToUndo.push_back(addCommand);
		m_undoButton->EnableWindow();
		m_commandListToRedo.clear();
		m_redoButton->EnableWindow(false);
		m_myIngredientsList->SetCurSel(addCommand->getExistingIndex());
		CRecipeGeneratorDlg::OnLbnSelchangeListMyIngredients();
	}
	CRecipeGeneratorDlg::OnBnClickedButtonGenerate();
}
