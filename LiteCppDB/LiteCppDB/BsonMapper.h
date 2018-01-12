#pragma once

#ifdef LITECPPDB_EXPORTS
#define LITECPPDB_API __declspec(dllexport)
#else
#define LITECPPDB_API __declspec(dllimport)
#endif

#include "BsonValue.h"
#include "MemberMapper.h"
#include "LiteEngine.h"

#include <regex>
#include <map>
#include <string>
#include <functional>

namespace LiteCppDB
{
	// Class that converts your entity class to/from BsonDocument
	// If you prefer use a new instance of BsonMapper (not Global), be sure cache this instance for better performance
	// Serialization rules:
	//     - Classes must be "public" with a public constructor (without parameters)
	//     - Properties must have public getter (can be read-only)
	//     - Entity class must have Id property, [ClassName]Id property or [BsonId] attribute
	//     - No circular references
	//     - Fields are not valid
	//     - IList, Array supports
	//     - IDictionary supports (Key must be a simple datatype - converted by ChangeType)
	class LITECPPDB_API BsonMapper
	{
	private:
		bool mSerializeNullValues;
		bool mTrimWhitespace;
		bool mEmptyStringToNull;
		bool mIncludeFields;
		bool mIncludeNonPublic;

#pragma region Properties

	public:
		BsonMapper() noexcept;

		// Indicate that mapper do not serialize null values (default false)
		bool getSerializeNullValues() noexcept;
		void setSerializeNullValues(bool serializeNullValues) noexcept;

		// Apply .Trim() in strings when serialize (default true)
		bool getTrimWhitespace() noexcept;
		void setTrimWhitespace(bool trimWhitespace) noexcept;

		// Convert EmptyString to Null (default true)
		bool getEmptyStringToNull() noexcept;
		void setEmptyStringToNull(bool emptyStringToNull) noexcept;

		// Get/Set that mapper must include fields (default: false)
		bool getIncludeFields() noexcept;
		void setIncludeFields(bool includeFields) noexcept;

		// Get/Set that mapper must include non public (private, protected and internal) (default: false)
		bool getIncludeNonPublic() noexcept;
		void setIncludeNonPublic(bool includeNonPublic) noexcept;

#pragma endregion

#pragma region Register CustomType

#pragma endregion

#pragma region AutoId

		// Set new Id in entity class if entity needs one
		void SetAutoId(std::any entity, LiteEngine engine, std::string collection) noexcept;

#pragma endregion

		//// Map your entity class to BsonDocument using fluent API
		//EntityBuilder<T> Entity<T>();

#pragma region Predefinded Property Resolvers

		// Use lower camel case resolution for convert property names to field names
		BsonMapper UseCamelCase() noexcept;

		// Uses lower camel case with delimiter to convert property names to field names
		BsonMapper UseLowerCaseDelimiter(char delimiter = '_') noexcept;

#pragma endregion

#pragma region GetEntityMapper

	protected:

#pragma endregion

#pragma region Register DbRef

		// Register a property mapper as DbRef to serialize/deserialize only document reference _id
		static void RegisterDbRef(BsonMapper mapper, MemberMapper member, std::string collection) noexcept;

		// Register a property as a DbRef - implement a custom Serialize/Deserialize actions to convert entity to $id, $ref only
		static void RegisterDbRefItem(BsonMapper mapper, MemberMapper member, std::string collection) noexcept;

		// Register a property as a DbRefList - implement a custom Serialize/Deserialize actions to convert entity to $id, $ref only
		static void RegisterDbRefList(BsonMapper mapper, MemberMapper member, std::string collection) noexcept;

#pragma endregion
	};
}