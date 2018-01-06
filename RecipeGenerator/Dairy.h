#pragma once
#include "Ingredient.h"
class Dairy : public Ingredient
{
public:
	Dairy();
	Dairy(Dairy const& other);
	CString GetCategory() const;
	virtual CString GetName() const;
	virtual CString GetImagePath() const;
	virtual int GetQuantityInGrams() const = 0;
	virtual void SetQuantityInGrams(const int quantityInGrams) = 0;
	virtual double GetCaloriesFor100Gram() const = 0;
	virtual int GetHealthScore() const;
	virtual int GetFatPercentage() const = 0;
	virtual void SetFatPercentage(int _fatPercentage) = 0;
	virtual Dairy* clone() const = 0;
	virtual ~Dairy() {};
protected:
	int fatPercentage = 3;
};