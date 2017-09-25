#pragma once

#include "BsonType.h"

#include "ObjectId.h"

#include <any>
#include <map>
#include <chrono>
#include <string>
#include <list>

#ifdef LITECPPDB_EXPORTS
#define LITECPPDB_API __declspec(dllexport)
#else
#define LITECPPDB_API __declspec(dllimport)
#endif

namespace LiteCppDB
{
	// Represent a Bson Value used in BsonDocument
	class BsonValue
	{
	private:
		int32_t mLength = NULL;

		BsonType mType = BsonType::Null;
		std::any mRawValue;
		std::map<std::string, BsonValue> mRawValueMap;

		void setType(BsonType type);
		void setRawValueSuper(std::any rawValue);

	public:
		LITECPPDB_API static const std::any UnixEpoch;//= std::chrono::system_clock::now() DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc);

		// Represent a Null bson type
		LITECPPDB_API const static BsonValue BsonValue::getNull();

		// Represent a MinValue bson type
		LITECPPDB_API static const BsonValue BsonValue::getMinValue();

		// Represent a MaxValue bson type
		LITECPPDB_API static const BsonValue BsonValue::getMaxValue();

		// Indicate BsonType of this BsonValue
		LITECPPDB_API BsonType getType();

		// Get internal .NET value object
		LITECPPDB_API std::any getRawValueSuper();
		LITECPPDB_API std::map<std::string, BsonValue> getRawValueSuperMap();
		LITECPPDB_API void setRawValueSuperMap(std::map<std::string, BsonValue> rawValue);

#pragma region Constructor

		LITECPPDB_API BsonValue();

		LITECPPDB_API BsonValue(std::any &value);

		LITECPPDB_API BsonValue(BsonType type, std::any mRawValue);

		LITECPPDB_API BsonValue(std::map<std::string, BsonValue> value);

		LITECPPDB_API BsonValue(uint8_t value);
		LITECPPDB_API BsonValue(uint16_t value);
		LITECPPDB_API BsonValue(uint32_t value);
		LITECPPDB_API BsonValue(uint64_t value);

		LITECPPDB_API BsonValue(int8_t value);
		LITECPPDB_API BsonValue(int16_t value);
		LITECPPDB_API BsonValue(int32_t value);
		LITECPPDB_API BsonValue(int64_t value);

		LITECPPDB_API BsonValue(std::string value);

		LITECPPDB_API BsonValue(ObjectId value);

		LITECPPDB_API std::any& getValue();

		LITECPPDB_API bool hasValue();

#pragma endregion Constructor

#pragma region Convert types

		bool AsBoolean();

		LITECPPDB_API std::string AsString();

		LITECPPDB_API int32_t AsInt32();

		int64_t AsInt64();

		double AsDouble();

#pragma endregion Convert types

#pragma region IsTypes

		bool IsNull{ this->mType == LiteCppDB::BsonType::Null };

		bool IsArray{ false };

		bool IsDocument() { return (this->mType == LiteCppDB::BsonType::Document); }

		bool IsInt8{ this->mType == LiteCppDB::BsonType::Int8 };

		bool IsInt16{ this->mType == LiteCppDB::BsonType::Int16 };

		LITECPPDB_API bool IsInt32() { return (this->mType == LiteCppDB::BsonType::Int32); }

		bool IsInt64{ this->mType == LiteCppDB::BsonType::Int64 };

		bool IsUInt8{ this->mType == LiteCppDB::BsonType::UInt8 };

		bool IsUInt16{ this->mType == LiteCppDB::BsonType::UInt16 };

		bool IsUInt32{ this->mType == LiteCppDB::BsonType::UInt32 };

		bool IsUInt64{ this->mType == LiteCppDB::BsonType::UInt64 };

		bool IsDouble{ this->mType == LiteCppDB::BsonType::Double };

		bool IsDecimal{ false };

		bool IsNumber{ false };

		bool IsBinary{ false };

		bool IsBoolean{ this->mType == LiteCppDB::BsonType::Boolean };

		LITECPPDB_API bool IsString() { return (this->mType == LiteCppDB::BsonType::String); }

		bool IsObjectId{ this->mType == LiteCppDB::BsonType::ObjectId };

		bool IsGuid{ this->mType == LiteCppDB::BsonType::Guid };

		bool IsDateTime{ this->mType == LiteCppDB::BsonType::DateTime };

		bool IsMinValue{ this->mType == LiteCppDB::BsonType::MinValue };

		bool IsMaxValue{ this->mType == LiteCppDB::BsonType::MaxValue };

#pragma endregion IsTypes

#pragma region  Implicit Ctor

		LITECPPDB_API void operator==(const std::string value);



#pragma endregion Implicit Ctor

#pragma region IComparable<BsonValue>, IEquatable<BsonValue>

		LITECPPDB_API virtual int CompareTo(BsonValue other);

		bool Equals(BsonValue other);

#pragma endregion IComparable<BsonValue>, IEquatable<BsonValue>

#pragma region Operators

		//static bool operator ==(BsonValue lhs, BsonValue rhs);
		friend bool operator ==(const BsonValue& lhs, const BsonValue& rhs);

#pragma endregion Operators

#pragma region  GetBytesCount

		// Returns how many bytes this BsonValue will use to persist in index writes
		LITECPPDB_API int32_t GetBytesCount(bool recalc);

		int32_t GetBytesCountElement(std::string key, BsonValue value, bool recalc);

		int32_t GetBytesInString(std::string stringVal);

#pragma endregion GetBytesCount
	};
}