#pragma once

#include "Command.h"
#include "Ingredient.h"
#include <vector>

using namespace std;

class DeleteCommand : public Command {
public:
	DeleteCommand(CListBox* ingredientsListBox, vector<Ingredient*> &ingredients, Ingredient *ingredient)
		: ingredientsListBox(ingredientsListBox), ingredients(ingredients), ingredient(ingredient) {}

	void perform()
	{
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

	void rollback() {
		ingredients.push_back(ingredient);
		int i = ingredients.size() - 1;
		ingredientsListBox->InsertString(i, ingredient->GetName());
		ingredientsListBox->SetItemDataPtr(i, ingredient);
		ingredientsListBox->Invalidate();
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