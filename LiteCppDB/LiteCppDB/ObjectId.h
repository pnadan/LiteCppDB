#pragma once

#include <any>
#include <array>
#include <string>
#include <vector>

namespace LiteCppDB
{
	// Represent a 12-bytes BSON type used in document Id
	class ObjectId
	{
	private:
		int32_t mTimestamp;
		int32_t mMachine;
		int16_t mPid;
		int32_t mIncrement;

		// Convert hex value string in byte array
		std::array<uint8_t, 12> FromHex(std::string value);

	public:
		// A zero 12-bytes ObjectId
		static const ObjectId Empty;

#pragma region Properties

		// Get timestamp
		int32_t getTimestamp() noexcept;
		void setTimestamp(int32_t timestamp) noexcept;

		// Get machine number
		int32_t getMachine() noexcept;
		void setMachine(int32_t machine) noexcept;

		// Get pid number
		int16_t getPid() noexcept;
		void setPid(int16_t mPid) noexcept;

		// Get increment
		int32_t getIncrement() noexcept;
		void setIncrement(int32_t increment) noexcept;

		// Get creation time
		std::any getCreationTime() noexcept;

#pragma endregion Properties

#pragma region Ctor

		// Initializes a new empty instance of the ObjectId class.
		ObjectId() noexcept;

		// Initializes a new instance of the ObjectId class from ObjectId vars.
		ObjectId(int32_t timestamp, int32_t machine, int16_t pid, int32_t increment) noexcept;

		// Initializes a new instance of ObjectId class from another ObjectId.
		ObjectId(LiteCppDB::ObjectId* from) noexcept;

		// Initializes a new instance of the ObjectId class from hex string.
		ObjectId(std::string value) noexcept;// : this(FromHex(value));

		// Initializes a new instance of the ObjectId class from byte array.
		ObjectId(std::vector<uint8_t> bytes);

#pragma endregion Ctor

#pragma region Equals / CompareTo / ToString

	public:
		// Checks if this ObjectId is equal to the given object. Returns true
		// if the given object is equal to the value of this instance. 
		// Returns false otherwise.
		bool Equals(ObjectId other) noexcept;

		// Determines whether the specified object is equal to this instance.
		bool Equals(std::any other);

		// Returns a hash code for this instance.
		int32_t GetHashCode();

		// Compares two instances of ObjectId
		int32_t CompareTo(ObjectId other) noexcept;

		// Represent ObjectId as 12 bytes array
		std::array<uint8_t, 12> ToByteArray() noexcept;

		std::string ToString() noexcept;

#pragma endregion Equals / CompareTo / ToString

#pragma region Operators

		friend bool operator ==(ObjectId lhs, ObjectId rhs) noexcept;

		friend bool operator !=(ObjectId lhs, ObjectId rhs) noexcept;

		friend bool operator >=(ObjectId lhs, ObjectId rhs) noexcept;

		friend bool operator >(ObjectId lhs, ObjectId rhs) noexcept;

		friend bool operator <(ObjectId lhs, ObjectId rhs) noexcept;

		friend bool operator <=(ObjectId lhs, ObjectId rhs) noexcept;

#pragma endregion Operators

#pragma region Static methods

#pragma endregion Static methods
	};
}