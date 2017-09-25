#pragma once

#include "BsonValue.h"
#include "StringScanner.h"

#include <string>
#include <sstream>

#ifdef LITECPPDB_EXPORTS
#define LITECPPDB_API __declspec(dllexport)
#else
#define LITECPPDB_API __declspec(dllimport)
#endif

namespace LiteCppDB
{
	// Static class for serialize/deserialize BsonDocuments into json extended format
	class JsonSerializer
	{
	public:
#pragma region Serialize

		// Json serialize a BsonValue into a String
		LITECPPDB_API static std::string Serialize(BsonValue value, bool pretty = false, bool writeBinary = true);

		// Json serialize a BsonValue into a TextWriter
		LITECPPDB_API static void Serialize(BsonValue value, std::ostringstream& writer, bool pretty = false, bool writeBinary = true);

#pragma endregion Serialize

#pragma region Deserialize

		/// Deserialize a Json string into a BsonValue
		LITECPPDB_API static BsonValue Deserialize(std::string json);

		// Deserialize a Json TextReader into a BsonValue
		LITECPPDB_API static BsonValue Deserialize(std::istringstream& reader);

		// Deserialize a json using a StringScanner and returns BsonValue
		LITECPPDB_API static BsonValue Deserialize(StringScanner& s);

#pragma endregion Deserialize
	};
}