#include "stdafx.h"
#include "Ingredient.h"

Ingredient::Ingredient()
{
}

Ingredient::Ingredient(Ingredient const & other)
{
	name = other.name;
	imagePath = other.imagePath;
	quantityInGrams = other.quantityInGrams;
}

CString Ingredient::GetName() const
{
	CString formmated = L"";
	formmated.Format(L"%s", name);
	if(quantityInGrams > 0)
		formmated.Format(L"%s [%d]", formmated, quantityInGrams);
	return formmated;
}

double Ingredient::GetTotalCalories() const
{
	return GetCaloriesFor100Gram()/100 * GetQuantityInGrams();
}

int Ingredient::GetHealthScore() const
{
	return 10;
}
