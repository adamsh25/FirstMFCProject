#include "stdafx.h"
#include "Recipe.h"

Recipe::Recipe()
{
}

Recipe::Recipe(Recipe const & other)
{
	name = other.name;
	imagePath = other.imagePath;
	recipeText = other.recipeText;
}

Recipe * Recipe::clone() const
{
	return new Recipe(*this);
}

CString Recipe::GetName() const
{
	return name;
}

void Recipe::SetName(CString _name)
{
	name = _name;
}

CString Recipe::GetImagePath() const
{
	return imagePath;
}

void Recipe::SetImagePath(CString _imagePath)
{
	imagePath = _imagePath;
}


double Recipe::GetTotalCalories() const
{
	return 0.0;
}

int Recipe::GetHealthScore() const
{
	return 0;
}

void Recipe::SetRecipeInstructionText(CString _recipeText)
{
	recipeText = _recipeText;
}

bool Recipe::MatchRecipe(vector<Ingredient*> _ingredients)
{
	return true;
}

CString Recipe::GetRecipeText()
{
	return CString(L"Empty");
}

Recipe::~Recipe()
{

}

