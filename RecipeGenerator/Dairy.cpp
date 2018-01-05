#include "stdafx.h"
#include "Dairy.h"

CString Dairy::GetCategory() const
{
	return CString(L"Dairy");
}

CString Dairy::GetImagePath() const
{
	return CString(L"Dairy.png");
}

int Dairy::GetHealthScore() const
{
	return Ingredient::GetHealthScore() - 2;
}
