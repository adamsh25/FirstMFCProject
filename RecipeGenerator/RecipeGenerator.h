
// RecipeGenerator.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <vector>
#include "Command.h"
#include "AddCommand.h"
#include "Ingredient.h"
#include "Carb.h"
#include "Cereal.h"
#include "Recipe.h"
#include "Dairy.h"
#include "Milk.h"


// CRecipeGeneratorApp:
// See RecipeGenerator.cpp for the implementation of this class
//

class CRecipeGeneratorApp : public CWinApp
{
public:
	CRecipeGeneratorApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CRecipeGeneratorApp theApp;
