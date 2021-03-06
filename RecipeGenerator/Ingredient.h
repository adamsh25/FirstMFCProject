#pragma once
#include <afx.h>
#include <iostream>
using namespace std;
class Ingredient : public CObject
{
public:
	DECLARE_SERIAL(Ingredient)
	Ingredient();
	Ingredient(Ingredient const& other);
	virtual Ingredient* clone() const { return new Ingredient(*this); };
	virtual CString GetName() const;
	virtual CString GetCategory() const { return CString(L""); };
	virtual CString GetImagePath() const { return CString(L""); };
	virtual int GetQuantityInGrams() const { return quantityInGrams; };
	virtual void SetQuantityInGrams(int _quantityInGrams) { quantityInGrams = _quantityInGrams; };
	virtual double GetTotalCalories() const;
	virtual double GetCaloriesFor100Gram() const { return calories; };
	virtual int GetHealthScore() const;
	virtual CString GetInfo();
	void Serialize(CArchive& archive);
	virtual ~Ingredient() {}

protected:
	CString name;
	CString imagePath;
	int quantityInGrams = 0;
	int calories = 0;
};