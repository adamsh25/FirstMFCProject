#pragma once
#include "Ingredient.h"
class Fruit : public Ingredient
{
public:
	CString GetCategory() const;
	virtual bool IsDry() const = 0;
private:
	const bool dry;
};