#pragma once
#include "Dairy.h"
#include <afx.h>
class Milk : public Dairy
{
public:
	DECLARE_SERIAL(Milk)
	Milk();
	Milk(Milk const& other);
	Milk(int fatPercentage, CString _kind = L"Cow");
	virtual ~Milk() {};
	Milk* clone() const;
	CString GetCategory() const;
	CString GetName() const;
	CString GetImagePath() const;

	double GetCaloriesFor100Gram() const;
	int GetHealthScore() const;
	void Serialize(CArchive& archive);
	virtual CString GetInfo();

protected:
	CString kind = L"Cow";
};