// LiteCppDB.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "LiteCppDB.h"  

namespace MathLibrary
{
	LITECPPDB_API double Functions::Add(double a, double b)
	{
		return a + b;
	}

	LITECPPDB_API double Functions::Multiply(double a, double b)
	{
		return a * b;
	}

	LITECPPDB_API double Functions::AddMultiply(double a, double b)
	{
		return a + (a * b);
	}
}