#pragma once
#include "Dairy.h"
class Milk : public Dairy
{
public:
	CString GetCategory() const;
	CString GetName() const;
	CString GetImagePath() const;
	int GetQuantityInGrams() const;
	void SetQuantityInGrams(const int quantityInGrams);
	double GetCaloriesFor100Gram();
	int GetHealthScore() const;
	int GetFatPercentage() const;
	int SetFatPercentage();
protected:
	int fatPercentage = 3;
};