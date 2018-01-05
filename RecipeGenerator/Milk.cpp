#include "stdafx.h"
#include "Milk.h"


CString Milk::GetCategory() const
{
	return CString(L"Milk");
}

CString Milk::GetName() const
{
	CString formmated = L"";
	formmated.Format(L"%s %d\%", name, fatPercentage);
	return formmated;
}
