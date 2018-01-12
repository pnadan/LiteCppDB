#include "stdafx.h"

#include "BsonSerializer.h"
#include "BsonReader.h"
#include "BsonWriter.h"

namespace LiteCppDB
{
	LITECPPDB_API std::vector<uint8_t> BsonSerializer::Serialize(const BsonDocument& doc)
	{
		if (&doc == nullptr) throw std::exception("ArgumentNullException(\"doc\")");

		auto writer = BsonWriter();

		return writer.Serialize(doc);
	}

	LITECPPDB_API BsonDocument BsonSerializer::Deserialize(const std::vector<uint8_t>& bson)
	{
		if (&bson == nullptr || bson.size() == 0) throw std::exception("ArgumentNullException(\"bson\")");

		auto reader = BsonReader();

		return reader.Deserialize(bson);
	}
}