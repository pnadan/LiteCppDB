#include "stdafx.h"

#include "BsonValue.h"
#include "BsonWriter.h"
#include "ByteWriter.h"

namespace LiteCppDB
{
	std::vector<uint8_t> ByteWriter::getBuffer()
	{
		return this->mBuffer;
	}

	int32_t ByteWriter::getPosition()
	{
		return this->mPosition;
	}

	ByteWriter::ByteWriter(int32_t length)
	{
		std::vector<uint8_t> byte(length);
		this->mBuffer = byte;
		this->mPosition = 0;
	}

	ByteWriter::ByteWriter(std::vector<uint8_t> buffer)
	{
		this->mBuffer = buffer;
		this->mPosition = 0;
	}

	void ByteWriter::Skip(int32_t length)
	{
		this->mPosition += length;
	}

#pragma region Native data types

	void ByteWriter::Write(uint8_t value)
	{
		this->mBuffer[this->mPosition] = value;

		this->mPosition++;
	}

	void ByteWriter::Write(bool value)
	{
		if (value)
			this->mBuffer[this->mPosition] = static_cast<uint8_t>(1);
		else
			this->mBuffer[this->mPosition] = static_cast<uint8_t>(0);

		this->mPosition++;
	}

	void ByteWriter::Write(uint16_t value)
	{
		for (int i = 0; i < 2; i++)
		{
			this->mBuffer[this->mPosition + i] = static_cast<uint8_t>((value >> (2 * i)) & 0xFF);
		}

		this->mPosition += 2;
	}

	void ByteWriter::Write(uint32_t value)
	{
		for (int i = 0; i < 4; i++)
		{
			this->mBuffer[this->mPosition + i] = static_cast<uint8_t>((value >> (4 * i)) & 0xFF);
		}

		this->mPosition += 4;
	}

	void ByteWriter::Write(uint64_t value)
	{
		for (int i = 0; i < 8; i++)
		{
			this->mBuffer[this->mPosition + i] = static_cast<uint8_t>((value >> (8 * i)) & 0xFF);
		}

		this->mPosition += 8;
	}

	void ByteWriter::Write(int16_t value)
	{
		for (int i = 0; i < 2; i++)
		{
			this->mBuffer[this->mPosition + i] = static_cast<uint8_t>((value >> (2 * i)) & 0xFF);
		}

		this->mPosition += 2;
	}

	void ByteWriter::Write(int32_t value)
	{
		for (int i = 0; i < 4; i++)
		{
			this->mBuffer[this->mPosition + i] = static_cast<uint8_t>((value >> (8 * i)) & 0xFF);
		}

		this->mPosition += 4;
	}

	void ByteWriter::Write(int64_t value)
	{
		for (int i = 0; i < 8; i++)
		{
			this->mBuffer[this->mPosition + i] = static_cast<uint8_t>((value >> (8 * i)) & 0xFF);
		}

		this->mPosition += 8;
	}

	void ByteWriter::Write(double value)
	{
		std::string stringDouble = std::to_string(value);
		
		std::vector<uint8_t> myVector(stringDouble.begin(), stringDouble.end());

		this->Write(myVector);
	}


	void ByteWriter::Write(std::vector<uint8_t> value)
	{
		for (int i = 0; i < static_cast<int32_t>(value.size()); i++)
		{
			this->mBuffer[this->mPosition + i] = value.at(i) & 0xFF;
		}

		this->mPosition += static_cast<int32_t>(value.size());
	}

#pragma endregion Native data types

#pragma region Extended types

	void ByteWriter::Write(std::string value)
	{
		std::vector<uint8_t> myVector(value.begin(), value.end());

		this->Write(myVector);
	}

	void ByteWriter::Write(std::string value, int32_t length)
	{
		std::vector<uint8_t> myVector(value.begin(), value.end());

		if (length != myVector.size())
			throw std::exception("Invalid string length");

		this->Write(myVector);
	}

	void ByteWriter::Write(std::chrono::time_point<std::chrono::system_clock> value)
	{
		const uint8_t* my_bytes = static_cast<uint8_t*>(static_cast<void*>(&value));
	}

	void ByteWriter::Write(PageAddress value)
	{
		this->Write(value.getPageID());
		this->Write(value.getIndex());
	}

	void ByteWriter::WriteBsonValue(BsonValue value, uint16_t length)
	{
		this->Write(static_cast<int8_t>(value.getType()));

		switch (value.getType())
		{
			case BsonType::Null:
			case BsonType::MinValue:
			case BsonType::MaxValue:
				break;

			case BsonType::Int32: this->Write(value.AsInt32()); break;
			case BsonType::Int64: this->Write(value.AsInt64()); break;
			case BsonType::Double: this->Write(value.AsDouble()); break;

			case BsonType::String: this->Write(value.AsString(), length); break;

			case BsonType::Boolean: this->Write(value.AsBoolean()); break;
			case BsonType::DateTime: this->Write(value.AsDateTime()); break;

			default:
				throw std::exception("NotSupportedException(\"WriteBsonValue type not supported\")");
				break;
		}

	}

#pragma endregion Extended types
}