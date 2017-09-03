#pragma once
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the LITECPPDB_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// LITECPPDB_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef LITECPPDB_EXPORTS
#define LITECPPDB_API __declspec(dllexport)
#else
#define LITECPPDB_API __declspec(dllimport)
#endif

//// This class is exported from the LiteCppDB.dll
//class LITECPPDB_API CLiteCppDB {
//public:
//	CLiteCppDB(void);
//	// TODO: add your methods here.
//};
//
//extern LITECPPDB_API int nLiteCppDB;
//
//LITECPPDB_API int fnLiteCppDB(void);

namespace MathLibrary
{
	// This class is exported from the MathLibrary.dll  
	class Functions
	{
	public:
		// Returns a + b  
		LITECPPDB_API double Add(double a, double b);

		// Returns a * b  
		LITECPPDB_API double Multiply(double a, double b);

		// Returns a + (a * b)  
		/*static MATHLIBRARY_API*/ 
		LITECPPDB_API double AddMultiply(double a, double b);
	};
}