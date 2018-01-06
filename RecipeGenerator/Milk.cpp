#include "stdafx.h"
#include "Milk.h"


Milk::Milk()
{

}

Milk::Milk(Milk const& other) : Dairy(other)
{
	kind = other.kind;
}


Milk::Milk(int _fatPercentage)
{
	name = "Milk";
	fatPercentage = _fatPercentage;
}

Milk* Milk::clone() const
{
	return new Milk(*this);
}

CString Milk::GetCategory() const
{
	return Dairy::GetCategory();
}

CString Milk::GetName() const
{
	CString formmated = L"";
	formmated.Format(L"%s %s", kind, Dairy::GetName());
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

