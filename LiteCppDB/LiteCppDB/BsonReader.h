#pragma once

#include "BsonArray.h"
#include "BsonDocument.h"
#include "ByteReader.h"
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
	// Internal class to deserialize a byte[] into a BsonDocument using BSON data format
	class BsonReader
	{
	public:
		// Main method - deserialize using ByteReader helper
		LITECPPDB_API BsonDocument Deserialize(std::vector<uint8_t> bson);

		// Read a BsonDocument from reader
		LITECPPDB_API BsonDocument ReadDocument(ByteReader reader);

		// Read an BsonArray from reader
		LITECPPDB_API BsonArray ReadArray(ByteReader reader);

	private:
		// Reads an element (key-value) from an reader
		LITECPPDB_API BsonValue ReadElement(ByteReader& reader, /*out*/ std::string* name);

		std::string ReadString(ByteReader& reader);

		std::string ReadDateTime(ByteReader& reader);

		std::string ReadCString(ByteReader& reader);

		double ReadDouble(ByteReader& reader);

		// use byte array buffer for CString (key-only)
		std::vector<uint8_t> _strBuffer;
	};
}