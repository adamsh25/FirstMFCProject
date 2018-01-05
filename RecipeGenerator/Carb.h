#pragma once
#include "Ingredient.h"
class Carb : public Ingredient
{
public:
	CString GetCategory() const;
	virtual bool IsProcessed() const = 0;
	virtual void SetProcessed(bool isProcessed) const = 0;
	virtual CString GetName() const = 0;
	virtual CString GetImagePath() const;
	virtual int GetQuantityInGrams() const = 0;
	virtual void SetQuantityInGrams(const int quantityInGrams) = 0;
	virtual double GetCaloriesFor100Gram() = 0;
	virtual int GetHealthScore();
protected:
	bool isProcessed = false;

};