#include "stdafx.h"
#include "Vegetable.h"

IMPLEMENT_SERIAL(Vegetable, Ingredient, 1)




Vegetable::Vegetable()
{
}

Vegetable::Vegetable(CString _name, CString _color)
{
	name = _name;
	color = _color;
}

Vegetable::Vegetable(Vegetable const & other) : Ingredient(other)
{
	color = other.color;
}

CString Vegetable::GetCategory() const
{
	return CString(L"Vegetable");
}

CString Vegetable::GetColor() const
{
	return color;
}


CString Vegetable::GetName() const
{
	CString formmated = L"";
	formmated.Format(L"%s %s", color, Ingredient::GetName());
	return formmated;
}

CString Vegetable::GetImagePath() const
{
	return CString(L"Dairy.png");
}

int Vegetable::GetHealthScore() const
{
	return Ingredient::GetHealthScore() - 2;
}

void Vegetable::Serialize(CArchive & archive)
{
	Ingredient::Serialize(archive);
	if (archive.IsStoring())
	{
		archive << color;
	}
	else
	{
		archive >> color;
	}
}

CString Vegetable::GetInfo()
{
	CString formmated = L"";
	formmated.Format(L"%s_%s_%s", GetCategory(), color, Ingredient::GetInfo());
	return formmated;
}
