#include "stdafx.h"

#include "BsonMapper.h"

namespace LiteCppDB
{
#pragma region Properties

	BsonMapper::BsonMapper()
	{
		this->mIncludeFields = false;
		this->mIncludeNonPublic = false;
		this->mEmptyStringToNull = false;
		this->mSerializeNullValues = false;
		this->mTrimWhitespace = false;
	}

	// Indicate that mapper do not serialize null values (default false)
	bool BsonMapper::getSerializeNullValues()
	{
		return this->mSerializeNullValues;
	}
	void BsonMapper::setSerializeNullValues(bool serializeNullValues)
	{
		this->mSerializeNullValues = serializeNullValues;
	}

	// Apply .Trim() in strings when serialize (default true)
	bool BsonMapper::getTrimWhitespace()
	{
		return	this->mTrimWhitespace;
	}
	void BsonMapper::setTrimWhitespace(bool trimWhitespace)
	{
		this->mTrimWhitespace = trimWhitespace;
	}

	// Convert EmptyString to Null (default true)
	bool BsonMapper::getEmptyStringToNull()
	{
		return this->mEmptyStringToNull;
	}
	void BsonMapper::setEmptyStringToNull(bool emptyStringToNull)
	{
		this->mEmptyStringToNull = emptyStringToNull;
	}

	// Get/Set that mapper must include fields (default: false)
	bool BsonMapper::getIncludeFields()
	{
		return this->mIncludeFields;
	}
	void BsonMapper::setIncludeFields(bool includeFields)
	{
		this->mIncludeFields = includeFields;
	}

	// Get/Set that mapper must include non public (private, protected and internal) (default: false)
	bool BsonMapper::getIncludeNonPublic()
	{
		return this->mIncludeNonPublic;
	}
	void BsonMapper::setIncludeNonPublic(bool includeNonPublic)
	{
		this->mIncludeNonPublic = includeNonPublic;
	}

#pragma endregion

#pragma region Register CustomType

#pragma endregion

#pragma region AutoId

	// Set new Id in entity class if entity needs one
	void SetAutoId(std::any entity, LiteEngine engine, std::string collection)
	{

	}

#pragma endregion

#pragma region Predefinded Property Resolvers

	// Use lower camel case resolution for convert property names to field names
	BsonMapper UseCamelCase()
	{
		return BsonMapper();
	}

	// Uses lower camel case with delimiter to convert property names to field names
	BsonMapper UseLowerCaseDelimiter(char delimiter = '_')
	{
		return BsonMapper();
	}

#pragma endregion

#pragma region GetEntityMapper

#pragma endregion

#pragma region Register DbRef

	/// Register a property mapper as DbRef to serialize/deserialize only document reference _id
	static void RegisterDbRef(BsonMapper mapper, MemberMapper member, std::string collection)
	{

	}

	// Register a property as a DbRef - implement a custom Serialize/Deserialize actions to convert entity to $id, $ref only
	static void RegisterDbRefItem(BsonMapper mapper, MemberMapper member, std::string collection)
	{

	}

	// Register a property as a DbRefList - implement a custom Serialize/Deserialize actions to convert entity to $id, $ref only
	static void RegisterDbRefList(BsonMapper mapper, MemberMapper member, std::string collection)
	{

	}

#pragma endregion
}