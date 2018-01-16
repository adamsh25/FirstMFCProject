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
	Recipe::Recipe(CString _name);
	Recipe(Recipe const& other);
	virtual Recipe* clone() const;
	CString GetName() const;
	void SetName(CString _name);
	CString GetImagePath() const;
	void SetImagePath(CString _imagePath);
	double GetTotalCalories() const;
	int GetHealthScore() const;
	void SetRecipeInstructionText(CString _recipeText);
	bool MatchRecipe(const vector<Ingredient*>& _ingredients) const;
	CString GetRecipeText();
	void AddIngredient(Ingredient* ingredient, int quantityInGrams);
	virtual ~Recipe();

protected:
	CString name = L"";
	CString imagePath = L"";
	CString recipeText = L"";
	int healthScore = 0;
	int calories = 0;
	vector<Ingredient*> ingredients;
};