#include "stdafx.h"
#include "Milk.h"

IMPLEMENT_SERIAL(Milk, Dairy, 1)

Milk::Milk()
{
	calories = 80;
}

Milk::Milk(Milk const& other) : Dairy(other)
{
	kind = other.kind;
}

Milk::Milk(int _fatPercentage, CString _kind)
{
	name = "Milk";
	kind = _kind;
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


int Milk::GetHealthScore() const
{
	return ((Dairy::GetHealthScore() + 15) * quantityInGrams)/100;
}

void Milk::Serialize(CArchive & archive)
{
	Dairy::Serialize(archive);
	if (archive.IsStoring())
	{
		archive << kind;
	}
	else
	{
		archive >> kind;
	}
}

CString Milk::GetInfo()
{
	CString formmated = L"";
	formmated.Format(L"Milk_%s_%s", kind, Dairy::GetInfo());
	return formmated;
}

