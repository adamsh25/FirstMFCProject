#pragma once

#include "Command.h"
#include "Ingredient.h"
#include <vector>

using namespace std;

class AddCommand : public Command {
public:
	AddCommand(CListBox* ingredientsListBox, vector<Ingredient*> &ingredients, Ingredient *ingredient)
		: ingredientsListBox(ingredientsListBox), ingredients(ingredients), ingredient(ingredient) {}

	void perform() 
	{ 
		ingredients.push_back(ingredient);
		int i = ingredients.size() - 1;
		ingredientsListBox->InsertString(i, ingredient->GetName());
		ingredientsListBox->SetItemDataPtr(i, ingredient);
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