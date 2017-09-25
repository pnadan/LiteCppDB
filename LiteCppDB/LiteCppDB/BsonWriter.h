#pragma once

#include "BsonArray.h"
#include "BsonDocument.h"
#include "BsonWriter.h"
#include "ByteWriter.h"

#include <string>
#include <vector>

namespace LiteCppDB
{
	// Internal class to serialize a BsonDocument to BSON data format (byte[])
	//internal class BsonWriter
	class BsonWriter
	{
	public:
		// Main method - serialize document. Uses ByteWriter
		std::vector<uint8_t> Serialize(BsonDocument doc);

		// Write a bson document
		void WriteDocument(ByteWriter& writer, BsonDocument doc);

		void WriteArray(ByteWriter& writer, BsonArray array);

	private:

		void WriteElement(ByteWriter& writer, std::string key, BsonValue value);

		void WriteString(ByteWriter& writer, std::string s);

		void WriteCString(ByteWriter& writer, std::string s);
	};
}
