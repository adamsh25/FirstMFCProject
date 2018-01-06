#include "stdafx.h"
#include "Milk.h"


Milk::Milk()
{
}



Milk::Milk(int fatPercentage):fatPercentage(fatPercentage)
{
	name = "Milk";
}

CString Milk::GetCategory() const
{
	return Dairy::GetCategory();
}

CString Milk::GetName() const
{
	CString formmated = L"";
	formmated.Format(L"%s %dP", name, fatPercentage);
	return formmated;
}

CString Milk::GetImagePath() const
{
	return CString(L"Milk.png");
}

int Milk::GetQuantityInGrams() const
{
	return quantityInGrams;
}

void Milk::SetQuantityInGrams(int quantityInGrams)
{
	Ingredient::quantityInGrams = quantityInGrams;
}

double Milk::GetCaloriesFor100Gram() const
{
	return 80.7;
}

int Milk::GetHealthScore() const
{
	return Dairy::GetHealthScore() + 15;
}

int Milk::GetFatPercentage() const
{
	return fatPercentage;
}

void Milk::SetFatPercentage(int _fatPercentage)
{
	fatPercentage = _fatPercentage;
}
