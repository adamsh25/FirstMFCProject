#include "stdafx.h"
#include "Ingredient.h"

IMPLEMENT_SERIAL(Ingredient, CObject, 1)

Ingredient::Ingredient()
{
}

Ingredient::Ingredient(Ingredient const & other)
{
	name = other.name;
	imagePath = other.imagePath;
	quantityInGrams = other.quantityInGrams;
}

void Ingredient::Serialize(CArchive& archive) {
	if (archive.IsStoring())
	{
		archive << name << imagePath << quantityInGrams;
	}
	else
	{
		archive >> name >> imagePath >> quantityInGrams;
	}
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
