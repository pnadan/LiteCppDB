#include "stdafx.h"

#include "BsonValue.h"
#include <functional>
#include <random>
#include <sstream>

#include "ObjectId.h"
#include <gsl\gsl>

namespace LiteCppDB
{
#pragma region Properties

	// Get timestamp
	int32_t ObjectId::getTimestamp() noexcept
	{
		return this->mTimestamp;
	}
	void ObjectId::setTimestamp(int32_t timestamp) noexcept
	{
		this->mTimestamp = timestamp;
	}

	// Get machine number
	int32_t ObjectId::getMachine() noexcept
	{
		return this->mMachine;
	}
	void ObjectId::setMachine(int32_t machine) noexcept
	{
		this->mMachine = machine;
	}

	// Get pid number
	int16_t ObjectId::getPid() noexcept
	{
		return this->mPid;
	}
	void ObjectId::setPid(int16_t pid) noexcept
	{
		this->mPid = pid;
	}

	// Get increment
	int32_t ObjectId::getIncrement() noexcept
	{
		return this->mIncrement;
	}
	void ObjectId::setIncrement(int32_t increment) noexcept
	{
		this->mIncrement = increment;
	}

	// Get creation time
	std::any ObjectId::getCreationTime() noexcept
	{
		return std::any();
	}

#pragma endregion Properties

#pragma region Ctor

	// Initializes a new empty instance of the ObjectId class.
	ObjectId::ObjectId() noexcept
	{
		this->mTimestamp = 0;
		this->mMachine = 0;
		this->mPid = 0;
		this->mIncrement = 0;
	}

	// Initializes a new instance of the ObjectId class from ObjectId vars.
	ObjectId::ObjectId(int32_t timestamp, int32_t machine, int16_t pid, int32_t increment) noexcept
	{
		this->mTimestamp = timestamp;
		this->mMachine = machine;
		this->mPid = pid;
		this->mIncrement = increment;
	}

	// Initializes a new instance of ObjectId class from another ObjectId.
	ObjectId::ObjectId(LiteCppDB::ObjectId* from) noexcept
	{
		this->mTimestamp = 0;
		this->mIncrement = from->mTimestamp;
		this->mMachine = from->mMachine;
		this->mPid = from->mPid;
		this->mIncrement = from->mIncrement;
	}

	// Initializes a new instance of the ObjectId class from hex string.
	ObjectId::ObjectId(std::string value) noexcept//TODO : FromHex(value)
	{
		this->mIncrement = 0;
		this->mMachine = 0;
		this->mPid = 0;
		this->mTimestamp = 0;
	}

	// Initializes a new instance of the ObjectId class from byte array.
	ObjectId::ObjectId(std::vector<uint8_t> bytes)
	{
		this->mTimestamp = (bytes.at(0) << 24) + (bytes.at(1) << 16) + (bytes.at(2) << 8) + bytes.at(3);
		this->mMachine = (bytes[4] << 16) + (bytes[5] << 8) + bytes[6];
		this->mPid = gsl::narrow_cast<int16_t>((bytes[7] << 8) + bytes[8]);
		this->mIncrement = (bytes[9] << 16) + (bytes[10] << 8) + bytes[11];
	}

	/// Convert hex value string in byte array
	std::array<uint8_t, 12> ObjectId::FromHex(std::string value)
	{
		if (value.empty()) throw std::exception("ArgumentNullException(\"val\")");

		std::array<uint8_t, 12> bytes{0,0,0,0,0,0,0,0,0,0,0,0};

		std::vector<uint8_t> myVector(value.begin(), value.end());

		if (12 == myVector.size())
		{
			int32_t i = 0;
			for (auto& byte : bytes)
			{
				byte = myVector.at(i);
				i++;
			}

		}

		return bytes;
	}

#pragma endregion Ctor

#pragma region Equals / CompareTo / ToString

	// Checks if this ObjectId is equal to the given object. Returns true
	// if the given object is equal to the value of this instance. 
	// Returns false otherwise.
	bool ObjectId::Equals(ObjectId other) noexcept
	{
		return
			this->mTimestamp == other.mTimestamp &&
			this->mMachine == other.mMachine &&
			this->mPid == other.mPid &&
			this->mIncrement == other.mIncrement;
	}

	// Determines whether the specified object is equal to this instance.
	bool ObjectId::Equals(std::any other)
	{
		if (std::any_cast<ObjectId>(other) == ObjectId::ObjectId())
		{
			return this->Equals(std::any_cast<ObjectId>(other));
		}

		return false;
	}

	// Returns a hash code for this instance.
	int32_t ObjectId::GetHashCode()
	{
		int32_t hash = 17;
		hash = 37 * hash + std::any_cast<int32_t>(std::hash<int32_t>{}(this->mTimestamp));
		hash = 37 * hash + std::any_cast<int32_t>(std::hash<int32_t>{}(this->mMachine));
		hash = 37 * hash + std::any_cast<int32_t>(std::hash<int32_t>{}(this->mPid));
		hash = 37 * hash + std::any_cast<int32_t>(std::hash<int32_t>{}(this->mIncrement));
		return hash;
	}

	/// Compares two instances of ObjectId
	int32_t ObjectId::CompareTo(ObjectId other) noexcept
	{
		//return this->mIncrement.CompareTo(other.mIncrement);
		return 0;
	}

	/// Represent ObjectId as 12 bytes array
	std::array<uint8_t, 12> ObjectId::ToByteArray() noexcept
	{
		std::array<uint8_t, 12> bytes =
		{
			gsl::narrow_cast<uint8_t>(this->mTimestamp >> 24),
			gsl::narrow_cast<uint8_t>(this->mTimestamp >> 16),
			gsl::narrow_cast<uint8_t>(this->mTimestamp >> 8),
			gsl::narrow_cast<uint8_t>(this->mTimestamp),
			gsl::narrow_cast<uint8_t>(this->mMachine >> 16),
			gsl::narrow_cast<uint8_t>(this->mMachine >> 8),
			gsl::narrow_cast<uint8_t>(this->mMachine),
			gsl::narrow_cast<uint8_t>(this->mPid >> 8),
			gsl::narrow_cast<uint8_t>(this->mPid),
			gsl::narrow_cast<uint8_t>(this->mIncrement >> 16),
			gsl::narrow_cast<uint8_t>(this->mIncrement >> 8),
			gsl::narrow_cast<uint8_t>(this->mIncrement)
		};

		return bytes;
	}

	std::string ObjectId::ToString() noexcept
	{
		return std::string();
	}

#pragma endregion Equals / CompareTo / ToString

#pragma region Operators

	bool operator ==(ObjectId lhs, ObjectId rhs) noexcept
	{
		return lhs.Equals(rhs);
	}

	bool operator !=(ObjectId lhs, ObjectId rhs) noexcept
	{
		return !(lhs == rhs);
	}

	bool operator >=(ObjectId lhs, ObjectId rhs) noexcept
	{
		return lhs.CompareTo(rhs) >= 0;
	}

	bool operator >(ObjectId lhs, ObjectId rhs) noexcept
	{
		return lhs.CompareTo(rhs) > 0;
	}

	bool operator <(ObjectId lhs, ObjectId rhs) noexcept
	{
		return lhs.CompareTo(rhs) < 0;
	}

	bool operator <=(ObjectId lhs, ObjectId rhs) noexcept
	{
		return lhs.CompareTo(rhs) <= 0;
	}

#pragma endregion Operators

#pragma region Static methods

	int32_t GetMachineHash()
	{
		auto hostname = "unknown"; //boost::asio::ip::host_name();

		return 0x00ffffff & (int32_t)std::hash<std::string>{}(hostname);
	}

#pragma endregion Static methods
}