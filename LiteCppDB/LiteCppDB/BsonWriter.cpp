#include "stdafx.h"

#include "BsonWriter.h"

//#include <algorithm>

namespace LiteCppDB
{
	// Main method - serialize document. Uses ByteWriter
	std::vector<uint8_t> BsonWriter::Serialize(BsonDocument doc)
	{
		auto count = doc.GetBytesCount(true);
		auto& writer = ByteWriter(count);

		this->WriteDocument(writer, doc);

		return writer.getBuffer();
	}

	// Write a bson document
	void BsonWriter::WriteDocument(ByteWriter& writer, BsonDocument doc)
	{
		writer.Write(doc.GetBytesCount(false));

		std::vector<std::string> keys = doc.getKeys();

		for (std::string k : keys)
		{
			auto value = doc.TryGetValue(k);
			if (!value.hasValue())
			{
				this->WriteElement(writer, k, BsonValue::getNull());
			}
			else
			{
				this->WriteElement(writer, k, doc.TryGetValue(k));
			}
		}

		writer.Write(static_cast<uint8_t>(0x00));
	}

	void BsonWriter::WriteArray(ByteWriter& writer, BsonArray array)
	{
		writer.Write(array.getCount());

		for (auto i = 0; i < array.getCount(); i++)
		{
			this->WriteElement(writer, std::to_string(i), array.getValueAt(i));
		}

		writer.Write(static_cast<uint8_t>(0x00));
	}

	void BsonWriter::WriteElement(ByteWriter& writer, std::string key, BsonValue value)
	{
		// cast RawValue to avoid one if on As<Type>
		switch (value.getType())
		{
			case BsonType::Null:
				writer.Write(static_cast<uint8_t>(0x0A));
				this->WriteCString(writer, key);
				break;
			case BsonType::Int32:
				writer.Write(static_cast<uint8_t>(0x10));
				this->WriteCString(writer, key);
				writer.Write(value.AsInt32());
				break;
			case BsonType::Double:
				writer.Write(static_cast<uint8_t>(0x13));
				this->WriteCString(writer, key);
				writer.Write(value.AsDouble());
				break;
			case BsonType::String:
				writer.Write(static_cast<uint8_t>(0x02));
				this->WriteCString(writer, key);
				this->WriteString(writer, value.AsString());
				break;
			case BsonType::MinValue:
				writer.Write(static_cast<uint8_t>(0xFF));
				this->WriteCString(writer, key);
				break;
			case BsonType::MaxValue:
				writer.Write(static_cast<uint8_t>(0x7F));
				this->WriteCString(writer, key);
				break;
			case BsonType::DateTime:
				writer.Write(static_cast<uint8_t>(0x09)); 
				this->WriteCString(writer, key);
				this->WriteString(writer, value.AsDateTime());
				break;
			default:
				throw std::exception("NotSupportedException(\"WriteElement type not supported\")");
				break;
		}
	}

	void BsonWriter::WriteString(ByteWriter& writer, std::string s)
	{
		std::vector<uint8_t> myVector(s.begin(), s.end());
		writer.Write(static_cast<int32_t>(myVector.size()) + 1);
		//writer.Write(static_cast<int32_t>(myVector.size()));
		writer.Write(myVector);
		writer.Write(static_cast<uint8_t>(0x00));
	}

	void BsonWriter::WriteCString(ByteWriter& writer, std::string s)
	{
		std::vector<uint8_t> myVector(s.begin(), s.end());
		writer.Write(myVector);
		writer.Write(static_cast<uint8_t>(0x00));
	}
}