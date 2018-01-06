
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
	vector<Ingredient*> m_myIngredients;
	CListBox* m_ingredientsList;
	CListBox* m_myIngredientsList;
	CButton* m_addButton;
	CButton* m_generateButton;
	CEdit* m_editAdd;
public:
	afx_msg void OnLbnSelchangeListIngredients();
};
