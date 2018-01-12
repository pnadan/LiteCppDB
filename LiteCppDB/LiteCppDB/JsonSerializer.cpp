#include "stdafx.h"

#include "JsonSerializer.h"
#include "JsonWriter.h"
#include "JsonReader.h"
#include "StringScanner.h"
#include <gsl\gsl>

namespace LiteCppDB
{
#pragma region Serialize

	// Json serialize a BsonValue into a String
	LITECPPDB_API std::string JsonSerializer::Serialize(BsonValue value, bool pretty, bool writeBinary)
	{
		std::ostringstream sw;

		//if (value.IsNull)
		if (!value.AsRawValue().has_value())
			Serialize(BsonValue::getNull(), sw, pretty, writeBinary);
		else
			Serialize(value, sw, pretty, writeBinary);

		return sw.str();
	}

	// Json serialize a BsonValue into a TextWriter
	LITECPPDB_API void JsonSerializer::Serialize(BsonValue value, std::ostringstream& writer, bool pretty, bool writeBinary)
	{
		auto w = JsonWriter(writer);
		w.setPretty(pretty);
		w.setWriteBinary(writeBinary);
		//if (value.IsNull)
		if (!value.AsRawValue().has_value())
			w.Serialize(BsonValue::getNull());
		else
			w.Serialize(value);
	}

#pragma endregion Serialize

#pragma region Deserialize

	// Deserialize a Json string into a BsonValue
	LITECPPDB_API BsonValue JsonSerializer::Deserialize(std::string json)
	{
		if (json == nullptr) throw std::exception("ArgumentNullException(\"json\")");

		std::istringstream sr;
		auto reader = JsonReader(sr);

		return reader.Deserialize();
	}

	/// Deserialize a Json TextReader into a BsonValue
	LITECPPDB_API BsonValue JsonSerializer::Deserialize(std::istringstream& reader)
	{
		if (&reader == nullptr) throw std::exception("ArgumentNullException(\"reader\")");

		auto jr = JsonReader(reader);

		return jr.Deserialize();
	}

	// Deserialize a json using a StringScanner and returns BsonValue
	LITECPPDB_API BsonValue JsonSerializer::Deserialize(StringScanner& s)
	{
		if (&s == nullptr) throw std::exception("ArgumentNullException( \"s\")");

		if (s.HasTerminated()) return BsonValue::getNull();

		std::istringstream sr;
		auto reader = JsonReader(sr);
		auto value = reader.Deserialize();
		s.Seek(gsl::narrow_cast<int32_t>(reader.getPosition() - 1));
		return value;

	}

#pragma endregion Deserialize
}