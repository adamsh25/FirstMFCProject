#pragma once
#include "Ingredient.h"
class Dairy : public Ingredient
{
public:
	DECLARE_SERIAL(Dairy)
	Dairy();
	Dairy(Dairy const& other);
	CString GetCategory() const;
	virtual CString GetName() const;
	virtual CString GetImagePath() const;
	virtual int GetQuantityInGrams() const { return 0; };
	virtual void SetQuantityInGrams(const int quantityInGrams) {};
	virtual double GetCaloriesFor100Gram() const { return 0; };
	virtual int GetHealthScore() const;
	int GetFatPercentage() const;
	void SetFatPercentage(int _fatPercentage);
	virtual Dairy* clone() const { return new Dairy(*this); };
	void Serialize(CArchive& archive);
	virtual ~Dairy() {};
protected:
	int fatPercentage = 3;
};