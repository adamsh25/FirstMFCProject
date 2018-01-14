#pragma once

#include "Command.h"
#include "Ingredient.h"
#include <vector>

using namespace std;

class AddCommand : public Command {
public:
	AddCommand(CListBox* ingredientsListBox, vector<Ingredient*> &ingredients, Ingredient *ingredient)
		: ingredientsListBox(ingredientsListBox), ingredients(ingredients), ingredient(ingredient) {}

	int getExistingIndex()
	{
		vector<Ingredient*>::iterator it;
		int i = 0;
		for (it = ingredients.begin(); it != ingredients.end(); ++it, ++i)
			if ((*it)->GetInfo().Compare(ingredient->GetInfo()) == 0)
				break;
		if (it != ingredients.end())
		{
			return i;
		}
		return LB_ERR;
	}

	void perform() 
	{ 
		int exists = getExistingIndex();
		if (exists == LB_ERR)
		{
			ingredients.push_back(ingredient);
			int i = ingredients.size() - 1;
			ingredientsListBox->InsertString(i, ingredient->GetName());
			ingredientsListBox->SetItemDataPtr(i, ingredient);
		}
		else 
		{
			Ingredient* existingIngredient = ingredients.at(exists);
			existingIngredient->SetQuantityInGrams(existingIngredient->GetQuantityInGrams() + ingredient->GetQuantityInGrams());
			ingredient = existingIngredient;
			ingredientsListBox->DeleteString(exists);
			ingredientsListBox->InsertString(exists, ingredient->GetName());
			ingredientsListBox->SetItemDataPtr(exists, ingredient);
		}
		ingredientsListBox->Invalidate();
	}


	void rollback() {
		vector<Ingredient*>::iterator it;
		int i = 0;
		for (it = ingredients.begin(); it != ingredients.end(); ++it, ++i)
			if (*it == ingredient)
				break;
		if (it != ingredients.end())
		{
			ingredients.erase(it);
			ingredientsListBox->DeleteString(i);
			ingredientsListBox->Invalidate();
		}
	}


	Ingredient* getIngredient()
	{
		return ingredient;
	}
private:
	CListBox * ingredientsListBox;
	vector<Ingredient*> &ingredients;
	Ingredient *ingredient;
};