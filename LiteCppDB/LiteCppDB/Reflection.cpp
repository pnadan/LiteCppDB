#include "stdafx.h"
#include "Reflection.h"


namespace LiteCppDB
{
#pragma region CreateInstance

	// Create a new instance from a Type
	std::any CreateInstance(std::any type)
	{
		return std::any::any();
	}

#pragma endregion

#pragma region Utils

	bool IsNullable(std::any type)
	{
		return false;
	}

	// Get underlying get - using to get inner Type from Nullable type
	std::any UnderlyingTypeOf(std::any type)
	{
		return std::any::any();
	}

	std::any GetGenericListOfType(std::any type)
	{
		return std::any::any();
	}

	std::any GetGenericDictionaryOfType(std::any k, std::any v)
	{
		return std::any::any();
	}

	// Get item type from a generic List or Array
	std::any GetListItemType(std::any listType)
	{
		return std::any::any();
	}

	// Returns true if Type is any kind of Array/IList/ICollection/....
	bool IsList(std::any type)
	{
		return false;
	}

#pragma endregion
}