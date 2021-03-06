
// RecipeGeneratorDlg.h : header file
//

#pragma once


// CRecipeGeneratorDlg dialog
class CRecipeGeneratorDlg : public CDialog
{
// Construction
public:
	CRecipeGeneratorDlg(CWnd* pParent = NULL);	// standard constructor
	void InitData();
	void InitDlgIngredientsList();
	void Load();
	void ClearAll();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RECIPEGENERATOR_DIALOG };
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

	afx_msg void OnBnClickedButtonAdd();


private:
	vector<Ingredient*> m_allIngredients;
	vector<Recipe*> m_allRecipes;
	vector<Recipe*> m_generatedRecipes;
	vector<Ingredient*> m_myIngredients;
	vector<Command*> m_commandListToUndo;
	vector<Command*> m_commandListToRedo;
	CListBox* m_ingredientsList;
	CListBox* m_recipesList;
	CListBox* m_myIngredientsList;
	CButton* m_addButton;
	CButton* m_updateButton;
	CButton* m_deleteButton;
	CButton* m_useRecipeButton;
	CButton* m_generateButton;
	CButton* m_undoButton;
	CButton* m_redoButton;
	CEdit* m_editAdd;
	CEdit* m_editUpdate;
	CEdit* m_richEdit;
public:
	afx_msg void OnLbnSelchangeListIngredients();
	afx_msg void OnBnClickedButtonUndo();
	afx_msg void OnBnClickedButtonRedo();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonLoad();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnLbnSelchangeListMyIngredients();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnLbnSelcancelListMyIngredients();
	afx_msg void OnBnClickedButtonUpdateQuantity();
	afx_msg void OnBnClickedButtonGenerate();
	afx_msg void OnLbnSelchangeListRecipes();
	afx_msg void OnBnClickedButtonUseRecipe();
//	afx_msg void OnNcMouseLeave();
//	afx_msg void OnMouseLeave();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLbnDblclkListIngredients();
	afx_msg void OnLbnDblclkListMyIngredients();
};
