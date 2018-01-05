#pragma once
#include "Ingredient.h"
class Fish : public Ingredient
{
public:
	CString GetCategory() const;
	virtual bool IsSaltyWater() const = 0;
	virtual bool IsSweetWater();
protected:
	const bool isSaltyWater;
};