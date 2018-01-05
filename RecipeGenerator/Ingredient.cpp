#include "stdafx.h"
#include "Ingredient.h"

double Ingredient::GetTotalCalories() const
{
	return GetCaloriesFor100Gram()/100 * GetQuantityInGrams();
}

int Ingredient::GetHealthScore() const
{
	return 10;
}
