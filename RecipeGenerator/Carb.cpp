#include "stdafx.h"
#include "Carb.h"




IMPLEMENT_SERIAL(Carb, Ingredient, 1)

Carb::Carb()
{
}

Carb::Carb(CString _name, int _calories=800)
{
	name = _name;
	calories = _calories;
}

Carb::Carb(Carb const & other) : Ingredient(other)
{
	isProcessed = other.isProcessed;
}

CString Carb::GetCategory() const
{
	return CString(L"Carbs");
}


CString Carb::GetImagePath() const
{
	return CString(L"CarbImage.png");
}

CString Carb::GetName() const
{
	CString formmated = L"";
	CString proccessString = isProcessed ? L"Processesd" : L"Healthy Carb";
	formmated.Format(L"(%s) %s", proccessString, Ingredient::GetName());
	return formmated;
}

int Carb::GetHealthScore() const
{
	return Ingredient::GetHealthScore() - 30;
}


void Carb::Serialize(CArchive & archive)
{
	Ingredient::Serialize(archive);
	if (archive.IsStoring())
	{
		archive << isProcessed;
	}
	else
	{
		archive >> isProcessed;
	}
}

CString Carb::GetInfo()
{
	CString formmated = L"";
	formmated.Format(L"%s_%d_%s", GetCategory(), isProcessed, Ingredient::GetInfo());
	return formmated;
}
