#pragma once
#include "Carb.h"
class Cereal : public Carb
{
public:
	DECLARE_SERIAL(Cereal)
	Cereal();
	Cereal(CString brandName);
	Cereal(Cereal const& other);
	CString GetCategory() const;
	virtual CString GetName() const;
	CString GetImagePath() const;
	double GetCaloriesFor100Gram() const;
	int GetHealthScore() const;
	Cereal* clone() const { return new Cereal(*this); };
	void Serialize(CArchive& archive);
	CString GetInfo();
	~Cereal() {};
};