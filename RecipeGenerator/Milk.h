#pragma once
#include "Dairy.h"
#include <afx.h>
class Milk : public Dairy
{
public:
	Milk();
	Milk(Milk const& other);
	Milk(int fatPercentage);
	virtual ~Milk() {};
	Milk* clone() const;
	CString GetCategory() const;
	CString GetName() const;
	CString GetImagePath() const;
	int GetQuantityInGrams() const;
	void SetQuantityInGrams(const int quantityInGrams);
	double GetCaloriesFor100Gram() const;
	int GetHealthScore() const;
	int GetFatPercentage() const;
	void SetFatPercentage(int _fatPercentage);

protected:
	CString kind = L"Cow";
};