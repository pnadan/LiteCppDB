#include "stdafx.h"

#include "BsonReader.h"

namespace LiteCppDB
{
	// Main method - deserialize using ByteReader helper
	BsonDocument BsonReader::Deserialize(std::vector<uint8_t> bson)
	{
		return this->ReadDocument(ByteReader(bson));
	}

	// Read a BsonDocument from reader
	BsonDocument BsonReader::ReadDocument(ByteReader reader)
	{
		auto length = reader.ReadInt32();
		auto end = reader.getPosition() + length - 5;
		auto obj = BsonDocument();

		while (reader.getPosition() < end)
		{
			std::string name;
			auto value = this->ReadElement(reader, &name);
			//obj.Set(name, value);
			obj.setFieldForDoc(name, LiteCppDB::BsonDocument::BsonValue(value));
		}

		reader.ReadByte(); // zero

		return obj;
	}

	// Read an BsonArray from reader
	BsonArray BsonReader::ReadArray(ByteReader reader)
	{
		auto length = reader.ReadInt32();
		auto end = reader.getPosition() + length - 5;
		auto arr = new BsonArray();

		while (reader.getPosition() < end)
		{
			std::string name;
			auto value = this->ReadElement(reader, &name);
			arr->Add(value);
		}

		reader.ReadByte(); // zero

		return *arr;
	}

	/// Reads an element (key-value) from an reader
	BsonValue BsonReader::ReadElement(ByteReader& reader, /*out*/ std::string* name)
	{
		auto type = reader.ReadByte();
		*name = ReadCString(reader);

		if (type == 0x02) // String
		{
			return ReadString(reader);
		}
		else if (type == 0x03) // Document
		{
			return ReadDocument(reader);
		}
		else if (type == 0x04) // Array
		{
			return this->ReadArray(reader);
		}
		else if (type == 0x05) // Binary
		{
			auto length = reader.ReadInt32();
			auto subType = reader.ReadByte();
			auto bytes = reader.ReadBytes(length);

			switch (subType)
			{
			case 0x00: return bytes;
				/*case 0x04: return Guid(uint8_t);*/
			}
		}
		else if (type == 0x07) // ObjectId
		{
			return ObjectId(reader.ReadBytes(12));
		}
		else if (type == 0x08) // Boolean
		{
			return reader.ReadBoolean();
		}
		else if (type == 0x10) // Int32
		{
			return reader.ReadInt32();
		}
		else if (type == 0x12) // Int64
		{
			return reader.ReadInt64();
		}

		throw std::exception("NotSupportedException(\"BSON type not supported\")");
	}

	std::string BsonReader::ReadString(ByteReader& reader)
	{
		auto length = reader.ReadInt32();
		auto bytes = reader.ReadBytes(length - 1);
		reader.ReadByte(); // discard \x00
		std::string str(bytes.cbegin(), bytes.cend());
		return str;
	}

	std::string BsonReader::ReadCString(ByteReader& reader)
	{
		auto pos = 0;

		while (true)
		{
			uint8_t buf = reader.ReadByte();
			if (buf == 0x00) 
				break;
			_strBuffer.insert(_strBuffer.begin() + pos++, buf);
		}

		std::string str(_strBuffer.cbegin(), _strBuffer.cbegin()+pos);
		return str;
	}

	// use byte array buffer for CString (key-only)
	std::vector<uint8_t> _strBuffer;
}