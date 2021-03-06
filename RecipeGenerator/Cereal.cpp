#include "stdafx.h"
#include "Cereal.h"

IMPLEMENT_SERIAL(Cereal, Carb, 1)

Cereal::Cereal()
{

}

Cereal::Cereal(CString _name)
{
	name = _name;
}

Cereal::Cereal(Cereal const & other) : Carb(other)
{
	calories = 666;
}


CString Cereal::GetCategory() const
{
	return L"Cereal";
}


CString Cereal::GetImagePath() const
{
	return CString(L"CerealImage.png");
}


CString Cereal::GetName() const
{
	CString formmated = L"";
	formmated.Format(L"%s %s",GetCategory(), Carb::GetName());
	return formmated;
}

int Cereal::GetHealthScore() const
{
	return Carb::GetHealthScore() + 10;
}


void Cereal::Serialize(CArchive & archive)
{
	Carb::Serialize(archive);
}

CString Cereal::GetInfo()
{
	CString formmated = L"";
	formmated.Format(L"%s_%s", GetCategory(), Carb::GetInfo());
	return formmated;
}
