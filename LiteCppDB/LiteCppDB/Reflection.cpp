#include "stdafx.h"
#include "Reflection.h"


namespace LiteCppDB
{
#pragma region CreateInstance

	// Create a new instance from a Type
	std::any Reflection::CreateInstance(std::any type) noexcept
	{
		return std::any::any();
	}

#pragma endregion

#pragma region Utils

	bool Reflection::IsNullable(std::any type) noexcept
	{
		return false;
	}

	// Get underlying get - using to get inner Type from Nullable type
	std::any Reflection::UnderlyingTypeOf(std::any type) noexcept
	{
		return std::any::any();
	}

	//std::any Reflection::GetGenericListOfType(std::any type) noexcept
	//{
	//	return std::any::any();
	//}

	//std::any Reflection::GetGenericDictionaryOfType(std::any k, std::any v) noexcept
	//{
	//	return std::any::any();
	//}

	// Get item type from a generic List or Array
	std::any Reflection::GetListItemType(std::any listType) noexcept
	{
		return std::any::any();
	}

	// Returns true if Type is any kind of Array/IList/ICollection/....
	bool Reflection::IsList(std::any type) noexcept
	{
		return false;
	}

#pragma endregion
}