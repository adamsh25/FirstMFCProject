#include "stdafx.h"
#include "Dairy.h"

Dairy::Dairy()
{
}

Dairy::Dairy(Dairy const & other) : Ingredient(other)
{
	fatPercentage = other.fatPercentage;
}

CString Dairy::GetCategory() const
{
	return CString(L"Dairy");
}

CString Dairy::GetName() const
{
	CString formmated = L"";
	formmated.Format(L"%d%% %s", fatPercentage, Ingredient::GetName());
	return formmated;
}

CString Dairy::GetImagePath() const
{
	return CString(L"Dairy.png");
}

int Dairy::GetHealthScore() const
{
	return Ingredient::GetHealthScore() - 2;
}
