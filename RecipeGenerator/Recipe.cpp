#include "stdafx.h"
#include "Recipe.h"

Recipe::Recipe()
{
}

Recipe::Recipe(CString _name)
{
	name = _name;
}

Recipe::Recipe(Recipe const & other)
{
	name = other.name;
	imagePath = other.imagePath;
	recipeText = other.recipeText;

	vector<Ingredient*>::const_iterator it;
	for (it = other.ingredients.begin(); it != other.ingredients.end(); ++it)
	{
		Ingredient* current = (*it)->clone();
		ingredients.push_back(current);
	}
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
	return calories;
}

int Recipe::GetHealthScore() const
{
	return healthScore;
}

void Recipe::SetRecipeInstructionText(CString _recipeText)
{
	recipeText = _recipeText;
}

bool Recipe::MatchRecipe(vector<Ingredient*> _ingredients)
{
	vector<Ingredient*>::iterator it;
	for (it = ingredients.begin(); it != ingredients.end(); ++it)
	{
		vector<Ingredient*>::iterator it2;
		for (it2 = _ingredients.begin(); it != _ingredients.end(); ++it2)
		{
			if ((*it)->GetInfo().Compare((*it2)->GetInfo()) == 0 && (*it2)->GetQuantityInGrams() >= (*it)->GetQuantityInGrams())
				break;
			return false;
		}
	}
	return true;
}

CString Recipe::GetRecipeText()
{
	CString formmated = L"";

	vector<Ingredient*>::iterator it;
	for (it = ingredients.begin(); it != ingredients.end(); ++it)
	{
		Ingredient* current = *it;
		formmated.Format(L"\n%d Grams of %s\n", current->GetQuantityInGrams(), current->GetName());
	}

	formmated.Format(L"\n\n%s\n\n", this->recipeText);
	return formmated;
}

void Recipe::AddIngredient(Ingredient* ingredient, int quantityInGrams)
{
	Ingredient* toAdd = ingredient->clone();
	toAdd->SetQuantityInGrams(quantityInGrams);
	ingredients.push_back(toAdd);
	calories += toAdd->GetTotalCalories();
	calories += toAdd->GetHealthScore();
}

Recipe::~Recipe()
{
	vector<Ingredient*>::iterator it;
	ingredients.clear();
}

