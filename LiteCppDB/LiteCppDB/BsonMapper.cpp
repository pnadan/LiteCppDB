#include "stdafx.h"

#include "BsonMapper.h"

namespace LiteCppDB
{
#pragma region Properties

	BsonMapper::BsonMapper() noexcept
	{
		this->mIncludeFields = false;
		this->mIncludeNonPublic = false;
		this->mEmptyStringToNull = false;
		this->mSerializeNullValues = false;
		this->mTrimWhitespace = false;
	}

	// Indicate that mapper do not serialize null values (default false)
	bool BsonMapper::getSerializeNullValues() noexcept
	{
		return this->mSerializeNullValues;
	}
	void BsonMapper::setSerializeNullValues(bool serializeNullValues) noexcept
	{
		this->mSerializeNullValues = serializeNullValues;
	}

	// Apply .Trim() in strings when serialize (default true)
	bool BsonMapper::getTrimWhitespace() noexcept
	{
		return	this->mTrimWhitespace;
	}
	void BsonMapper::setTrimWhitespace(bool trimWhitespace) noexcept
	{
		this->mTrimWhitespace = trimWhitespace;
	}

	// Convert EmptyString to Null (default true)
	bool BsonMapper::getEmptyStringToNull() noexcept
	{
		return this->mEmptyStringToNull;
	}
	void BsonMapper::setEmptyStringToNull(bool emptyStringToNull) noexcept
	{
		this->mEmptyStringToNull = emptyStringToNull;
	}

	// Get/Set that mapper must include fields (default: false)
	bool BsonMapper::getIncludeFields() noexcept
	{
		return this->mIncludeFields;
	}
	void BsonMapper::setIncludeFields(bool includeFields) noexcept
	{
		this->mIncludeFields = includeFields;
	}

	// Get/Set that mapper must include non public (private, protected and internal) (default: false)
	bool BsonMapper::getIncludeNonPublic() noexcept
	{
		return this->mIncludeNonPublic;
	}
	void BsonMapper::setIncludeNonPublic(bool includeNonPublic) noexcept
	{
		this->mIncludeNonPublic = includeNonPublic;
	}

#pragma endregion

#pragma region Register CustomType

#pragma endregion

#pragma region AutoId

	// Set new Id in entity class if entity needs one
	void SetAutoId(std::any entity, LiteEngine engine, std::string collection) noexcept
	{

	}

#pragma endregion

#pragma region Predefinded Property Resolvers

	// Use lower camel case resolution for convert property names to field names
	BsonMapper UseCamelCase() noexcept
	{
		return BsonMapper();
	}

	// Uses lower camel case with delimiter to convert property names to field names
	BsonMapper UseLowerCaseDelimiter(char delimiter = '_') noexcept
	{
		return BsonMapper();
	}

#pragma endregion

#pragma region GetEntityMapper

#pragma endregion

#pragma region Register DbRef

	/// Register a property mapper as DbRef to serialize/deserialize only document reference _id
	static void RegisterDbRef(BsonMapper mapper, MemberMapper member, std::string collection) noexcept
	{

	}

	// Register a property as a DbRef - implement a custom Serialize/Deserialize actions to convert entity to $id, $ref only
	static void RegisterDbRefItem(BsonMapper mapper, MemberMapper member, std::string collection) noexcept
	{

	}

	// Register a property as a DbRefList - implement a custom Serialize/Deserialize actions to convert entity to $id, $ref only
	static void RegisterDbRefList(BsonMapper mapper, MemberMapper member, std::string collection) noexcept
	{

	}

#pragma endregion
}