#pragma once
#include "Ingredient.h"
class Carb : public Ingredient
{
public:
	DECLARE_SERIAL(Carb)
	Carb();
	Carb(CString name, int calories);
	Carb(Carb const& other);
	CString GetCategory() const;
	virtual CString GetName() const;
	virtual CString GetImagePath() const;
	virtual int GetHealthScore() const;
	virtual bool IsProcessed() const { return isProcessed; };
	virtual void SetProcessed(bool _isProcessed) { isProcessed = _isProcessed; };
	virtual Carb* clone() const { return new Carb(*this); };
	void Serialize(CArchive& archive);
	virtual CString GetInfo();
	virtual ~Carb() {};

protected:
	bool isProcessed = false;

};