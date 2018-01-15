#pragma once

#include "Command.h"
#include "Ingredient.h"
#include <vector>

using namespace std;

class UpdateCommand : public Command {
public:
	UpdateCommand(CListBox* ingredientsListBox, vector<Ingredient*> &ingredients, Ingredient *ingredient, int quantityToUpdate)
		: ingredientsListBox(ingredientsListBox), ingredients(ingredients), ingredient(ingredient), quantityToUpdate(quantityToUpdate)
	{
		vector<Ingredient*>::iterator it;
		for (it = ingredients.begin(); it != ingredients.end(); ++it, ++location)
			if (*it == ingredient)
				break;

	}


	void perform()
	{
		oldQuantity = ingredient->GetQuantityInGrams();
		ingredient->SetQuantityInGrams(quantityToUpdate);
		ingredientsListBox->DeleteString(location);
		ingredientsListBox->InsertString(location, ingredient->GetName());
		ingredientsListBox->SetItemDataPtr(location, ingredient);
		ingredientsListBox->Invalidate();
	}


	void rollback() {
		ingredient->SetQuantityInGrams(oldQuantity);
		ingredientsListBox->DeleteString(location);
		ingredientsListBox->InsertString(location, ingredient->GetName());
		ingredientsListBox->SetItemDataPtr(location, ingredient);
		ingredientsListBox->Invalidate();
	}


	Ingredient* getIngredient()
	{
		return ingredient;
	}
private:
	CListBox * ingredientsListBox = NULL;
	vector<Ingredient*> &ingredients;
	Ingredient *ingredient = NULL;
	int quantityToUpdate = 0;
	int oldQuantity = 0;
	int location = 0;
};