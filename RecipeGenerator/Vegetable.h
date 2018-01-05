#pragma once
#include "Ingredient.h"
class Vegetable : public Ingredient
{
public:
	CString GetCategory() const;
	virtual CString GetColor() const = 0;
protected:
	const CString color;
};