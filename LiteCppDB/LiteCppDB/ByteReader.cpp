#include "stdafx.h"

#include "ByteReader.h"

namespace LiteCppDB
{
	int32_t ByteReader::getPosition()
	{
		return this->mPos;
	}

	ByteReader::ByteReader(std::vector<uint8_t> buffer)
	{
		this->mBuffer = buffer;
		this->mPos = 0;
	}

	void ByteReader::Skip(int32_t length)
	{
		this->mPos += length;
	}

#pragma region Native data types

	uint8_t ByteReader::ReadByte()
	{
		auto value = this->mBuffer.at(this->mPos);
		this->mPos++;

		return value;
	}

	bool ByteReader::ReadBoolean()
	{
		auto value = this->mBuffer[this->mPos];

		this->mPos++;

		if (value == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	uint16_t ByteReader::ReadUInt16()
	{
		this->mPos += 2;

		return (uint16_t)(mBuffer.at(mPos - 1) << 8 | (mBuffer.at(mPos - 2)));
	}

	uint32_t ByteReader::ReadUInt32()
	{
		this->mPos += 4;

		return (uint32_t)(mBuffer.at(mPos - 1) << 24 | (mBuffer.at(mPos - 2) << 16) | (mBuffer.at(mPos - 3) << 8) | (mBuffer.at(mPos - 4)));
	}

	uint64_t ByteReader::ReadUInt64()
	{
		this->mPos += 8;

		return (uint64_t)(((uint64_t)mBuffer.at(mPos - 1) << 56) | ((uint64_t)mBuffer.at(mPos - 2) << 48) | ((uint64_t)mBuffer.at(mPos - 3) << 40) | ((uint64_t)mBuffer.at(mPos - 4) << 32) | ((uint64_t)mBuffer.at(mPos - 5) << 24) | ((uint64_t)mBuffer.at(mPos - 6) << 16) | ((uint64_t)mBuffer.at(mPos - 7) << 8) | ((uint64_t)mBuffer.at(mPos - 8)));
	}

	int16_t ByteReader::ReadInt16()
	{
		this->mPos += 2;

		return (int16_t)(mBuffer.at(mPos - 1) << 8 | (mBuffer.at(mPos - 2)));
	}

	int32_t ByteReader::ReadInt32()
	{
		this->mPos += 4;

		return (int32_t)(mBuffer.at(mPos - 1) << 24 | (mBuffer.at(mPos - 2) << 16) | (mBuffer.at(mPos - 3) << 8) | (mBuffer.at(mPos - 4)));
	}

	int64_t ByteReader::ReadInt64()
	{
		this->mPos += 8;

		return (int64_t)(((int64_t)mBuffer.at(mPos - 1) << 56) | ((int64_t)mBuffer.at(mPos - 2) << 48) | ((int64_t)mBuffer.at(mPos - 3) << 40) | ((int64_t)mBuffer.at(mPos - 4) << 32) | ((int64_t)mBuffer.at(mPos - 5) << 24) | ((int64_t)mBuffer.at(mPos - 6) << 16) | ((int64_t)mBuffer.at(mPos - 7) << 8) | ((int64_t)mBuffer.at(mPos - 8)));
	}

	std::vector<uint8_t> ByteReader::ReadBytes(int32_t count)
	{
		std::vector<uint8_t> buffer;

		for (int32_t i = 0; i < count; i++)
		{
			buffer.push_back(this->mBuffer.at(this->mPos + i));
		}

		this->mPos += count;

		return buffer;
	}

#pragma endregion Native data types

#pragma region Extended types

	std::string ByteReader::ReadString()
	{
		auto length = this->ReadInt32();
		auto bytes = this->ReadBytes(length);
		return std::string();
	}

	std::string ByteReader::ReadString(int32_t length)
	{
		auto bytes = this->ReadBytes(length);
		return std::string();
	}

	ObjectId ByteReader::ReadObjectId()
	{
		return new ObjectId(this->ReadBytes(12));
	}

	PageAddress ByteReader::ReadPageAddress()
	{
		return PageAddress(this->ReadUInt32(), this->ReadUInt16());
	}

	LiteCppDB::BsonValue ByteReader::ReadBsonValue(uint16_t length)
	{
		auto type = (BsonType)this->ReadByte();

		switch (type)
		{
			case BsonType::Int8: return this->ReadByte();
			case BsonType::Int16: return this->ReadInt16();
			case BsonType::Int32: return this->ReadInt32();
			case BsonType::Int64: return this->ReadInt64();

			case BsonType::UInt8: return this->ReadByte();
			case BsonType::UInt16: return this->ReadUInt16();
			case BsonType::UInt32: return this->ReadUInt32();
			case BsonType::UInt64: return this->ReadUInt64();

			case BsonType::String: return this->ReadString(length);

			case BsonType::Boolean: return this->ReadBoolean();
		}

		throw std::exception("NotImplementedException()");
	}

#pragma endregion Extended types
}