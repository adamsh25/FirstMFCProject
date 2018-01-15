#pragma once
#include <afx.h>
#include <iostream>
#include <vector>
#include "Ingredient.h"

using namespace std;
class Recipe : public CObject
{
public:
	Recipe();
	Recipe(Recipe const& other);
	virtual Recipe* clone() const;
	CString GetName() const;
	void SetName(CString _name);
	CString GetImagePath() const;
	void SetImagePath(CString _imagePath);
	double GetTotalCalories() const;
	int GetHealthScore() const;
	void SetRecipeInstructionText(CString _recipeText);
	bool MatchRecipe(vector<Ingredient*> _ingredients);
	CString GetRecipeText();
	virtual ~Recipe();

protected:
	CString name;
	CString imagePath;
	CString recipeText;
	vector<Ingredient*> ingredients;
};