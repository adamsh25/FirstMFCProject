#include "stdafx.h"
#include "Recipe.h"

Recipe::Recipe()
{

}

Recipe::Recipe(CString _name):Recipe()
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
		healthScore += current->GetHealthScore();
		calories += current->GetTotalCalories();
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

bool Recipe::MatchRecipe(const vector<Ingredient*>& _ingredients) const
{
	vector<Ingredient*>::const_iterator it;
	if (ingredients.size() > _ingredients.size())
		return false;
	int matchCounter = 0;
	for (it = ingredients.begin(); it != ingredients.end(); ++it)
	{
		vector<Ingredient*>::const_iterator it2;
		for (it2 = _ingredients.begin(); it2 != _ingredients.end(); ++it2)
		{
			if ((*it)->GetInfo().Compare((*it2)->GetInfo()) == 0 && (*it2)->GetQuantityInGrams() >= (*it)->GetQuantityInGrams())
			{
				matchCounter++;
				break;
			}
		}
	}
	return matchCounter == ingredients.size();
}

CString Recipe::GetRecipeText()
{
	CString formmated = L"Ingredients:\r\n\r\n";

	vector<Ingredient*>::iterator it;
	for (it = ingredients.begin(); it != ingredients.end(); ++it)
	{
		Ingredient* current = *it;
		CString toFind = L"";
		toFind.Format(L"[%d]", current->GetQuantityInGrams());
		int foundIndex = current->GetName().Find(toFind);
		
		CString pretty = L"%s";
		pretty.Format(pretty, current->GetName());
		if (foundIndex != -1)
			pretty.Delete(foundIndex, toFind.GetLength());
		formmated.Format(L"%s -\t%d Grams of %s\r\n", formmated, current->GetQuantityInGrams(), pretty);
	}

	formmated.Format(L"%s\r\n\r\nInstructions:\r\n\r\n%s\r\n\r\n", formmated, this->recipeText);
	formmated.Format(L"%s\r\n\r\nHealth:\r\n\tCalories:\t %0.0f\r\n\tHealth Score:\t%d\r\n\r\n\r\n\r\n", formmated, this->GetTotalCalories(), this->GetHealthScore());
	return formmated;
}

void Recipe::AddIngredient(Ingredient* ingredient, int quantityInGrams)
{
	Ingredient* toAdd = ingredient->clone();
	toAdd->SetQuantityInGrams(quantityInGrams);
	ingredients.push_back(toAdd);
	calories += toAdd->GetTotalCalories();
	healthScore += toAdd->GetHealthScore();
}

const vector<Ingredient*>& Recipe::GetIngredients() const
{
	return ingredients;
}

Recipe::~Recipe()
{
	vector<Ingredient*>::iterator it;
	ingredients.clear();
}

