#include "stdafx.h"
#include "Carb.h"

int Carb::GetHealthScore()
{
	return Ingredient::GetHealthScore() - 5;
}

CString Carb::GetCategory() const
{
	return CString(L"Carbs");
}


CString Carb::GetImagePath() const
{
	return CString(L"CarbImage.png");
}
