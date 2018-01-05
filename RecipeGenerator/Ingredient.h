#pragma once
#include <afx.h>
#include <iostream>
using namespace std;
class Ingredient : public CObject
{
public:
	Ingredient();
	virtual wstring GetName() = 0;
	virtual wstring GetImagePath() = 0;
	virtual int GetQuantityInGrams() = 0;
	virtual void SetQuantityInGrams(const int quantityInGrams) = 0;
	virtual int GetTotalCalories() = 0;
	virtual void SetCaloriesFor100Gram(const double calories) = 0;

protected:
	const wstring name;
	const wstring imagePath;
	int quantityInGrams;
	int calories;
};