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

		void setType(BsonType type) noexcept;
		void setRawValueSuper(std::any rawValue);

	public:
		LITECPPDB_API static const std::any UnixEpoch;//= std::chrono::system_clock::now() DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc);

		// Represent a Null bson type
		LITECPPDB_API const static BsonValue BsonValue::getNull() noexcept;

		// Represent a MinValue bson type
		LITECPPDB_API static const BsonValue BsonValue::getMinValue() noexcept;

		// Represent a MaxValue bson type
		LITECPPDB_API static const BsonValue BsonValue::getMaxValue() noexcept;

		// Indicate BsonType of this BsonValue
		LITECPPDB_API BsonType getType() noexcept;

		// Get internal .NET value object
		LITECPPDB_API std::any getRawValueSuper();
		LITECPPDB_API std::map<std::string, BsonValue> getRawValueSuperMap();
		LITECPPDB_API void setRawValueSuperMap(std::map<std::string, BsonValue> rawValue);

#pragma region Constructor

		LITECPPDB_API BsonValue() noexcept;
		LITECPPDB_API virtual ~BsonValue() noexcept {};

		LITECPPDB_API BsonValue(const BsonValue& src) noexcept;
		LITECPPDB_API virtual BsonValue& operator=(const BsonValue& rhs) noexcept;

		LITECPPDB_API BsonValue(const BsonValue&& src) noexcept;
		LITECPPDB_API virtual BsonValue& operator=(BsonValue&& rhs) noexcept;

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

		LITECPPDB_API BsonValue(double value);

		LITECPPDB_API BsonValue(std::string value);

		LITECPPDB_API BsonValue(std::chrono::time_point<std::chrono::system_clock> value);

		LITECPPDB_API BsonValue(ObjectId value);

		LITECPPDB_API virtual std::any& getValue() noexcept;

		LITECPPDB_API bool hasValue() noexcept;

#pragma endregion Constructor

#pragma region Convert types

		bool AsBoolean() noexcept;

		LITECPPDB_API std::string AsString();

		LITECPPDB_API int32_t AsInt32();

		LITECPPDB_API int64_t AsInt64();

		LITECPPDB_API uint64_t AsUInt64();

		LITECPPDB_API double AsDouble();

		LITECPPDB_API std::any AsRawValue();

		//LITECPPDB_API std::chrono::time_point<std::chrono::system_clock> AsDateTime();
		LITECPPDB_API std::string AsDateTime();

#pragma endregion Convert types

#pragma region IsTypes

		LITECPPDB_API bool IsNull() noexcept { return (this->mType == LiteCppDB::BsonType::Null); };

		bool IsArray{ false };

		LITECPPDB_API bool IsDocument() noexcept { return (this->mType == LiteCppDB::BsonType::Document); }

		LITECPPDB_API bool IsInt8() noexcept { return (this->mType == LiteCppDB::BsonType::Int8); };

		LITECPPDB_API bool IsInt16() noexcept { return (this->mType == LiteCppDB::BsonType::Int16); };

		LITECPPDB_API bool IsInt32() noexcept { return (this->mType == LiteCppDB::BsonType::Int32); };

		LITECPPDB_API bool IsInt64() noexcept { return (this->mType == LiteCppDB::BsonType::Int64); };

		LITECPPDB_API bool IsUInt8() noexcept { return (this->mType == LiteCppDB::BsonType::UInt8); };

		LITECPPDB_API bool IsUInt16() noexcept { return (this->mType == LiteCppDB::BsonType::UInt16); };

		LITECPPDB_API bool IsUInt32() noexcept { return (this->mType == LiteCppDB::BsonType::UInt32); };

		LITECPPDB_API bool IsUInt64() noexcept { return (this->mType == LiteCppDB::BsonType::UInt64); };

		LITECPPDB_API bool IsDouble() noexcept { return (this->mType == LiteCppDB::BsonType::Double); };

		bool IsDecimal{ false };

		bool IsNumber{ false };

		bool IsBinary{ false };

		LITECPPDB_API bool IsBoolean() noexcept { return (this->mType == LiteCppDB::BsonType::Boolean); };

		LITECPPDB_API bool IsString() noexcept { return (this->mType == LiteCppDB::BsonType::String); };

		LITECPPDB_API bool IsObjectId() noexcept { return (this->mType == LiteCppDB::BsonType::ObjectId); };

		LITECPPDB_API bool IsGuid() noexcept { return (this->mType == LiteCppDB::BsonType::Guid); };

		LITECPPDB_API bool IsDateTime() noexcept { return (this->mType == LiteCppDB::BsonType::DateTime); };

		LITECPPDB_API bool IsMinValue() noexcept { return (this->mType == LiteCppDB::BsonType::MinValue); };

		LITECPPDB_API bool IsMaxValue() noexcept { return (this->mType == LiteCppDB::BsonType::MaxValue); };

#pragma endregion IsTypes

#pragma region  Implicit Ctor

		LITECPPDB_API void operator==(const std::string value);



#pragma endregion Implicit Ctor

#pragma region IComparable<BsonValue>, IEquatable<BsonValue>

		LITECPPDB_API virtual int CompareTo(BsonValue other) noexcept;

		bool Equals(BsonValue other) noexcept;

#pragma endregion IComparable<BsonValue>, IEquatable<BsonValue>

#pragma region Operators

		//static bool operator ==(BsonValue lhs, BsonValue rhs);
		friend bool operator ==(const BsonValue& lhs, const BsonValue& rhs) noexcept;

		//bool operator ==(const std::any& lhs, const std::any& rhs) const {return lhs == rhs};
		//bool operator ==(const std::any& rhs) const { return this->mRawValue == rhs };

#pragma endregion Operators

#pragma region  GetBytesCount

		// Returns how many bytes this BsonValue will use to persist in index writes
		LITECPPDB_API int32_t GetBytesCount(bool recalc);

		int32_t GetBytesCountElement(std::string key, BsonValue value, bool recalc);

		int32_t GetBytesInString(std::string stringVal);

#pragma endregion GetBytesCount
	};
}