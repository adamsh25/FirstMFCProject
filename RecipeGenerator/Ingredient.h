#pragma once
#include <afx.h>
#include <iostream>
using namespace std;
class Ingredient : public CObject
{
public:
	Ingredient();
	virtual CString GetName() const = 0;
	virtual CString GetCategory() const = 0;
	virtual CString GetImagePath() const = 0;
	virtual int GetQuantityInGrams() const = 0;
	virtual void SetQuantityInGrams(int quantityInGrams) = 0;
	virtual double GetTotalCalories() const;
	virtual double GetCaloriesFor100Gram() const = 0;
	virtual int GetHealthScore() const;

protected:
	const CString name;
	const CString imagePath;
	int quantityInGrams;
};