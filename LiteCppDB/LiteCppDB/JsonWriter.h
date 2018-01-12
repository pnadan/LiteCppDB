#pragma once

#include "BsonArray.h"
#include "BsonValue.h"
#include "BsonDocument.h"

#include <string>
#include <sstream>

namespace LiteCppDB
{
	class JsonWriter
	{
	public:
		bool getPretty() noexcept;
		void setPretty(bool pretty) noexcept;

		bool getWriteBinary() noexcept;
		void setWriteBinary(bool writeBinary) noexcept;

		JsonWriter(std::ostringstream& writer);

		void Serialize(BsonValue value);

	private:
		const int INDENT_SIZE = 4;

		bool mPretty;
		bool mWriteBinary;

		std::ostringstream* _writer;
		int32_t _indent;
		std::string _spacer = "";

		void WriteValue(BsonValue value);

		void WriteObject(BsonDocument obj);

		void WriteArray(BsonArray arr);

		void WriteString(std::string s);

		void WriteExtendDataType(std::string type, std::string value);

		void WriteKeyValue(std::string key, BsonValue value, bool comma);

		void WriteStartBlock(std::string str, bool hasData);

		void WriteEndBlock(std::string str, bool hasData);

		void WriteNewLine();

		void WriteIndent();

		void padTo(std::string &str, const size_t num, const char paddingChar = ' ');
	};
}