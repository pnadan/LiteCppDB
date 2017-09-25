#pragma once

#include "BsonArray.h"
#include "BsonValue.h"
#include "JsonTokenizer.h"

#include <string>
#include <sstream>

namespace LiteCppDB
{
	// A class that read a json string using a tokenizer (without regex)
	class JsonReader
	{
	public:
		int64_t getPosition() { return _tokenizer.getPosition(); };

		JsonReader(std::istringstream& reader);

		BsonValue Deserialize();

	private:
		JsonTokenizer _tokenizer = nullptr;

		BsonValue ReadValue(JsonToken token);

		BsonValue ReadObject();

		BsonArray ReadArray();

		BsonValue ReadExtendedDataType(std::string key, std::string value);
	};
}