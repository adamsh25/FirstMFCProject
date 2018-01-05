#include "stdafx.h"
#include "Fish.h"

CString Fish::GetCategory() const
{
	return CString(L"Fishes");
}

bool Fish::IsSweetWater()
{
	return !isSaltyWater;
}
