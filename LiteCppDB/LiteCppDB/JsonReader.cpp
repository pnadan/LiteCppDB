#include "stdafx.h"

#include "JsonReader.h"
#include "BsonDocument.h"

#include <bitset>

namespace LiteCppDB
{
	JsonReader::JsonReader(std::istringstream& reader)
	{
		if (&reader == nullptr) throw std::exception("ArgumentNullException(\"reader\")");

		_tokenizer = JsonTokenizer(&reader);
	}

	BsonValue JsonReader::Deserialize()
	{
		auto token = _tokenizer.ReadToken();

		if (token.getTokenType() == JsonTokenType::EOFjtt) return BsonValue::getNull();

		auto value = this->ReadValue(token);

		return value;
	}

	BsonValue JsonReader::ReadValue(JsonToken token)
	{
		switch (token.getTokenType())
		{
			case JsonTokenType::BeginDoc: return this->ReadObject();
			case JsonTokenType::BeginArray: return this->ReadArray();
			case JsonTokenType::Word:
				std::string tok = token.getToken();
				if (tok == "null")
					return BsonValue::getNull();
				else
					throw std::exception("LiteException.UnexpectedToken(token.Token)");
		}

		throw std::exception("LiteException.UnexpectedToken(token.Token)");
	}

	BsonValue JsonReader::ReadObject()
	{
		auto obj = BsonDocument();

		auto token = _tokenizer.ReadToken(); // read "<key>"

		while (token.getTokenType() != JsonTokenType::EndDoc)
		{
			token.Expect(JsonTokenType::String, JsonTokenType::Word);

			auto key = token.getToken();

			token = _tokenizer.ReadToken(); // read ":"

			token.Expect(JsonTokenType::Colon);

			token = _tokenizer.ReadToken(); // read "<value>"

			// check if not a special data type - only if is first attribute
			if (key[0] == '$' && obj.getCount() == 0)
			{
				auto val = this->ReadExtendedDataType(key, token.getToken());

				// if val is null then it's not a extended data type - it's just a object with $ attribute
				if (!val.IsNull) return val;
			}

			obj.Set(key, this->ReadValue(token));

			token = _tokenizer.ReadToken();

			if (token.getTokenType() == JsonTokenType::Comma)
			{
				token = _tokenizer.ReadToken();
			}
		}

		return obj;
	}

	BsonArray JsonReader::ReadArray()
	{
		auto arr = BsonArray();

		auto token = _tokenizer.ReadToken();

		while (token.getTokenType() != JsonTokenType::EndArray)
		{
			auto value = this->ReadValue(token);

			arr.Add(value);

			token = _tokenizer.ReadToken();

			if (token.getTokenType() == JsonTokenType::Comma)
			{
				token = _tokenizer.ReadToken();
			}
		}

		return arr;
	}

	BsonValue JsonReader::ReadExtendedDataType(std::string key, std::string value)
	{
		BsonValue val;

		if (key == "$minValue")
			val = BsonValue::getMinValue();
		else if (key == "$maxValue")
			val = BsonValue::getMaxValue();
		else
			return BsonValue::getNull();

		_tokenizer.ReadToken().Expect(JsonTokenType::EndDoc);

		return val;
	}
}