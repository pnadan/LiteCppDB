#pragma once

#include "BsonDocument.h"

#include <vector>

#ifdef LITECPPDB_EXPORTS
#define LITECPPDB_API __declspec(dllexport)
#else
#define LITECPPDB_API __declspec(dllimport)
#endif

namespace LiteCppDB
{
	// Class to call method for convert BsonDocument to/from byte[] - based on http://bsonspec.org/spec.html
	class BsonSerializer
	{
	public:
		LITECPPDB_API static std::vector<uint8_t> Serialize(const BsonDocument& doc);

		LITECPPDB_API static BsonDocument Deserialize(const std::vector<uint8_t>& bson);
	};
}