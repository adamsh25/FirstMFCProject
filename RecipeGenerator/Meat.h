#pragma once
#include "Ingredient.h"
class Meat : public Ingredient
{
public:
	CString GetCategory() const;
	virtual bool IsKosher() const = 0;
protected:
	const bool kosher;
};