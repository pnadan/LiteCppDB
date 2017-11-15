#include "stdafx.h"
#include "BsonValue.h"
#include <ctime> 
#include <iomanip>

#include <sstream>
#include <chrono>
#include <memory>

using namespace std;

namespace LiteCppDB
{
	// Indicate BsonType of this BsonValue
	BsonType BsonValue::getType()
	{
		return this->mType;
	}
	void BsonValue::setType(BsonType type)
	{
		this->mType = type;
	}

	// Get internal .NET value object
	std::any BsonValue::getRawValueSuper()
	{
		return this->mRawValue;
	}
	void BsonValue::setRawValueSuper(std::any rawValue)
	{
		this->mRawValue = rawValue;
	}

	// Get internal .NET value object
	std::map<std::string, BsonValue> BsonValue::getRawValueSuperMap()
	{
		return this->mRawValueMap;
	}
	void BsonValue::setRawValueSuperMap(std::map<std::string, BsonValue> rawValue)
	{
		this->mRawValueMap = rawValue;
	}

	LITECPPDB_API const BsonValue BsonValue::getNull()
	{
		return BsonValue();
	}

	LITECPPDB_API const BsonValue BsonValue::getMinValue()
	{
		return BsonValue();
	}

	LITECPPDB_API const BsonValue BsonValue::getMaxValue()
	{
		return BsonValue();
	}

#pragma region Constructor

	BsonValue::BsonValue()
	{
		this->mRawValue = nullptr;
	}

	BsonValue::BsonValue(std::any &value)
	{
		this->mRawValue = value;
	}

	BsonValue::BsonValue(BsonType type, std::any mRawValue)
	{
		this->setType(type);
		this->mRawValue = mRawValue;
	}

	BsonValue::BsonValue(std::map<std::string, BsonValue> value)
	{
		if (&value == nullptr)
			this->setType(BsonType::Null);
		else
			this->setType(BsonType::Document);
		this->mRawValue = value;
	}

	BsonValue::BsonValue(uint8_t value)
	{
		if (&value == nullptr)
			this->setType(BsonType::Null);
		else
			this->setType(BsonType::UInt8);
		this->mRawValue = value;

	}

	BsonValue::BsonValue(uint16_t value)
	{
		if (&value == nullptr)
			this->setType(BsonType::Null);
		else
			this->setType(BsonType::UInt16);
		this->mRawValue = value;

	}

	BsonValue::BsonValue(uint32_t value)
	{
		if (&value == nullptr)
			this->setType(BsonType::Null);
		else
			this->setType(BsonType::UInt32);
		this->mRawValue = value;

	}

	BsonValue::BsonValue(uint64_t value)
	{
		if (&value == nullptr)
			this->setType(BsonType::Null);
		else
			this->setType(BsonType::UInt64);
		this->mRawValue = value;

	}

	BsonValue::BsonValue(int8_t value)
	{
		if (&value == nullptr)
			this->setType(BsonType::Null);
		else
			this->setType(BsonType::Int8);
		this->mRawValue = value;

	}

	BsonValue::BsonValue(int16_t value)
	{
		if (&value == nullptr)
			this->setType(BsonType::Null);
		else
			this->setType(BsonType::Int16);
		this->mRawValue = value;

	}

	BsonValue::BsonValue(int32_t value)
	{
		if (&value == nullptr)
			this->setType(BsonType::Null);
		else
			this->setType(BsonType::Int32);
		this->mRawValue = value;

	}

	BsonValue::BsonValue(int64_t value)
	{
		if (&value == nullptr)
			this->setType(BsonType::Null);
		else
			this->setType(BsonType::Int64);
		this->mRawValue = value;

	}

	BsonValue::BsonValue(double value)
	{
		if (&value == nullptr)
			this->setType(BsonType::Null);
		else
			this->setType(BsonType::Double);
		this->mRawValue = value;
	}

	BsonValue::BsonValue(std::string value)
	{
		if (&value == nullptr)
			this->setType(BsonType::Null);
		else
			this->setType(BsonType::String);
		this->mRawValue = value;

		if (!this->IsString())
			throw std::exception("IsString is not correct");
	}

	BsonValue::BsonValue(std::chrono::time_point<std::chrono::system_clock> value)
	{
		if (&value == nullptr)
			this->setType(BsonType::Null);
		else
			this->setType(BsonType::DateTime);
		this->mRawValue = value;

		if (!this->IsDateTime())
			throw std::exception("IsDateTime is not correct");
	}

	BsonValue::BsonValue(ObjectId value)
	{
		if (&value == nullptr)
			this->setType(BsonType::Null);
		else
			this->setType(BsonType::ObjectId);
		this->mRawValue = value;
	}

	std::any& BsonValue::getValue()
	{
		return this->mRawValue;
	}

	bool BsonValue::hasValue()
	{
		return this->mRawValue.has_value();
	}

#pragma endregion Constructor

	#pragma region Convert types

	bool BsonValue::AsBoolean()
	{
		return false;
	}

	std::string BsonValue::AsString()
	{
		if (this->mType != BsonType::String)
		{
			if (this->mType == BsonType::DateTime)
			{
				const std::chrono::time_point<std::chrono::system_clock> valueClock = std::any_cast<std::chrono::time_point<std::chrono::system_clock>>(this->mRawValue);

				const auto in_time_t = std::chrono::system_clock::to_time_t(valueClock);

				struct tm timeinfo;
				::localtime_s(&timeinfo, &in_time_t);
				std::stringstream ss;
				ss << std::put_time(&timeinfo, "%d-%m-%Y %H:%M:%S");

				return ss.str();
			}
			else
				return std::string();
		}
		else
		{
			return std::any_cast<std::string>(this->mRawValue);
		}
	}

	int32_t BsonValue::AsInt32()
	{
		if (this->mType != BsonType::Int32)
		{
			return int32_t(0);
		}
		else
		{
			return std::any_cast<int32_t>(this->mRawValue);
		}
	}

	int64_t BsonValue::AsInt64()
	{
		if (this->mType != BsonType::Int64)
		{
			return int64_t(0);
		}
		else
		{
			return std::any_cast<int64_t>(this->mRawValue);
		}
	}

	uint64_t BsonValue::AsUInt64()
	{
		if (this->mType != BsonType::UInt64)
		{
			return uint64_t(0);
		}
		else
		{
			return std::any_cast<uint64_t>(this->mRawValue);
		}
	}

	double BsonValue::AsDouble()
	{
		if (this->mType != BsonType::Double)
		{
			return double(0);
		}
		else
		{
			return std::any_cast<double>(this->mRawValue);
		}
	}

	std::any BsonValue::AsRawValue()
	{
		if (this->mType == BsonType::Null)
		{
			return std::any();
		}
		else
		{
			return this->mRawValue;
		}
	}

	std::string BsonValue::AsDateTime()
	{
		if (this->mType != BsonType::DateTime)
		{
			return std::string();
		}
		else
		{
			const auto actualtime = std::any_cast<std::chrono::time_point<std::chrono::system_clock>>(this->mRawValue);
			const auto in_time_t = std::chrono::system_clock::to_time_t(actualtime);
			std::stringstream ss;
			struct tm timeinfo;
			::localtime_s(&timeinfo, &in_time_t);
			ss << std::put_time(&timeinfo, "%d-%m-%Y %H:%M:%S");
			return ss.str();
		}
	}

#pragma endregion Convert types
	
	int BsonValue::CompareTo(BsonValue other)
	{
		return 0;
	}

	bool BsonValue::Equals(BsonValue other)
	{
		return false;
	}

	void BsonValue::operator==(const std::string value)
	{
		//TODO
	}

	bool operator ==(const BsonValue& lhs, const BsonValue& rhs)
	{
		//TODO
		return false;
	}

#pragma region GetBytesCount

	// Returns how many bytes this BsonValue will use to persist in index writes
	LITECPPDB_API int32_t BsonValue::GetBytesCount(bool recalc)
	{
		switch (this->getType())
		{
			case BsonType::Null:
			case BsonType::MinValue:
			case BsonType::MaxValue:
				this->mLength = 0; break;
			case BsonType::Int16: this->mLength = 2; break;
			case BsonType::Int32: this->mLength = 4; break;
			case BsonType::Int64: this->mLength = 8; break;
			case BsonType::Double: this->mLength = 8 + static_cast<int32_t>(std::to_string((this->AsDouble())).length()); break;
			case BsonType::String:
				this->mLength = GetBytesInString(std::any_cast<std::string>(this->getValue()));
				break;
			case BsonType::Document:
				{
					auto doc = this->getRawValueSuperMap();
					this->mLength = 5; // header + footer
					for_each(cbegin(doc), cend(doc), [this, &recalc](const auto& p)
					{
						if (&(p.second) == nullptr)
							this->mLength += this->GetBytesCountElement(p.first, BsonValue::getNull(), recalc);
						else
							this->mLength += this->GetBytesCountElement(p.first, p.second, recalc);
					});
				}
				break;
			case BsonType::DateTime: this->mLength = 24; break;
			default:
				throw std::exception("LiteException.InvalidType : Specifyed getType not found!");
				break;
		}

		return this->mLength;
	}

	int32_t BsonValue::GetBytesCountElement(std::string key, BsonValue value, bool recalc)
	{
		int32_t bytesCount = 0;

		bytesCount++; // element type
		bytesCount = bytesCount + GetBytesInString(key); // CString
		bytesCount++; // CString 0x00
		bytesCount = bytesCount + value.GetBytesCount(recalc);
		if (value.getType() == BsonType::String)
			bytesCount = bytesCount + 5;

		return bytesCount;
	}

	int32_t BsonValue::GetBytesInString(std::string stringVal)
	{
		std::string df = std::any_cast<std::string>(stringVal);
		std::vector<uint8_t> myVector(df.begin(), df.end());

		return static_cast<int32_t>(myVector.size());
	}

#pragma endregion
}