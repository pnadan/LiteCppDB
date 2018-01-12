#pragma once

#include <any>
#include <map>
#include <functional>

namespace LiteCppDB
{
#pragma region Delegates

#pragma endregion

	// Helper class to get entity properties and map as BsonValue
	class Reflection
	{
	private:

#pragma region CreateInstance

	public:
		// Create a new instance from a Type
		static std::any CreateInstance(std::any type) noexcept;

#pragma endregion

#pragma region Utils

		bool IsNullable(std::any type) noexcept;

		// Get underlying get - using to get inner Type from Nullable type
		static std::any UnderlyingTypeOf(std::any type) noexcept;

		// Get item type from a generic List or Array
		static std::any GetListItemType(std::any listType) noexcept;

		// Returns true if Type is any kind of Array/IList/ICollection/....
		static bool IsList(std::any type) noexcept;

#pragma endregion
	};
}