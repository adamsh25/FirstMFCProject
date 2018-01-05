#include "stdafx.h"
#include "Milk.h"

CString Milk::GetCategory() const
{
	return CString(L"Milk");
}

CString Milk::GetName() const
{
	return name + L" ";
}
