#pragma once
#include "Ingredient.h"
class Vegetable : public Ingredient
{
public:
	DECLARE_SERIAL(Vegetable)
	Vegetable();
	Vegetable(CString _name, CString color);
	Vegetable(Vegetable const& other);
	CString GetCategory() const;
	virtual CString GetName() const;
	virtual CString GetImagePath() const;
	virtual int GetHealthScore() const;
	virtual Vegetable* clone() const { return new Vegetable(*this); };
	void Serialize(CArchive& archive);
	virtual CString GetInfo();
	virtual ~Vegetable() {};
	virtual CString GetColor() const;
protected:
	CString color;
};