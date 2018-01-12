#pragma once

#include "ObjectId.h"
#include "PageAddress.h"
#include "BsonType.h"
#include "BsonValue.h"

#include <string>
#include <vector>

#ifdef LITECPPDB_EXPORTS
#define LITECPPDB_API __declspec(dllexport)
#else
#define LITECPPDB_API __declspec(dllimport)
#endif

namespace LiteCppDB
{
	class ByteReader
	{
	private:
		std::vector<uint8_t> mBuffer;
		uint32_t mPos;

	public:
		int32_t getPosition() noexcept;

		ByteReader(std::vector<uint8_t> buffer);

		void Skip(int32_t length) noexcept;

#pragma region Native data types

		uint8_t ReadByte();

		bool ReadBoolean();

		uint16_t ReadUInt16();

		uint32_t ReadUInt32();

		uint64_t ReadUInt64();

		int16_t ReadInt16();

		LITECPPDB_API int32_t ReadInt32();

		int64_t ReadInt64();

		double ReadDouble(int32_t length);

		LITECPPDB_API std::vector<uint8_t> ReadBytes(int32_t count);

#pragma endregion Native data types

#pragma region Extended types

		std::string ReadString();

		std::string ReadString(int32_t length);

		ObjectId ReadObjectId();

		PageAddress ReadPageAddress();

		LITECPPDB_API LiteCppDB::BsonValue ReadBsonValue(uint16_t length);

#pragma endregion Extended types
	};
}