#include "stdafx.h"

#include "JsonWriter.h"
#include <gsl\gsl>

namespace LiteCppDB
{
	bool JsonWriter::getPretty() noexcept
	{
		return this->mPretty;
	}
	void JsonWriter::setPretty(bool pretty) noexcept
	{
		this->mPretty = pretty;
	}

	bool JsonWriter::getWriteBinary() noexcept
	{
		return this->mWriteBinary;
	}
	void JsonWriter::setWriteBinary(bool writeBinary) noexcept
	{
		this->mWriteBinary = writeBinary;
	}

	JsonWriter::JsonWriter(std::ostringstream& writer)
	{
		this->_indent = 0;
		this->mWriteBinary = false;
		this->mPretty = false;
		this->_writer = &writer;
	}

	void JsonWriter::Serialize(BsonValue value)
	{
		_indent = 0;
		_spacer = this->mPretty ? " " : "";

		//if (value.IsNull)
		if (!value.AsRawValue().has_value())
			this->WriteValue(BsonValue::getNull());
		else
			this->WriteValue(value);
	}

	void JsonWriter::WriteValue(BsonValue value)
	{
		// use direct cast to better performance
		switch (value.getType())
		{
		case BsonType::Null:
			*(_writer) << "NULL";
			break;

		case BsonType::Document:
			this->WriteObject(BsonDocument(std::any_cast<std::map<std::string, BsonValue>>(value.getRawValueSuper())));
			break;

		case BsonType::Boolean:
			*(_writer) << std::any_cast<std::string>(value.getRawValueSuper());
			break;

		case BsonType::String:
			this->WriteString(std::any_cast<std::string>(value.getRawValueSuper()));
			break;

		case BsonType::Int32:
			*(_writer) << std::any_cast<int32_t>(value.getRawValueSuper());
			break;

		case BsonType::Int64:
			this->WriteExtendDataType("$numberLong", std::to_string(std::any_cast<int64_t>(value.getRawValueSuper())));
			break;

		case BsonType::Double:
			this->WriteExtendDataType("0.0########", std::to_string(std::any_cast<double>(value.getRawValueSuper())));
			break;

		case BsonType::DateTime:
			this->WriteExtendDataType("$date", (value.AsDateTime()));
			break;

		case BsonType::MinValue:
			this->WriteExtendDataType("$minValue", "1");
			break;

		case BsonType::MaxValue:
			this->WriteExtendDataType("$maxValue", "1");
			break;
		}
	}

	void JsonWriter::WriteObject(BsonDocument obj)
	{
		auto length = obj.getKeys().size();
		const auto hasData = length > 0;

		this->WriteStartBlock("{", hasData);

		auto index = 0;

		for (auto _begin = obj.getKeys().cbegin(), _end = obj.getKeys().cend(); _begin != _end; ++_begin)
		{
			std::string objBsonDocument = *_begin;

			this->WriteKeyValue(objBsonDocument, obj.TryGetValue(objBsonDocument), index++ < gsl::narrow_cast<int32_t>(length) - 1);
		}

		this->WriteEndBlock("}", hasData);
	}

	void JsonWriter::WriteArray(BsonArray arr)
	{
		const auto hasData = arr.getCount() > 0;

		this->WriteStartBlock("[", hasData);

		for (auto i = 0; i < arr.getCount(); i++)
		{
			auto item = arr.getValueAt(i);

			// do not do this tests if is not pretty format - to better performance
			if (this->mPretty)
			{
			}

			if (item.IsNull())
				this->WriteValue(BsonValue::getNull());
			else
				this->WriteValue(item);

			if (i < arr.getCount() - 1)
			{
				*(_writer) << ',';
			}
			this->WriteNewLine();
		}

		this->WriteEndBlock("]", hasData);
	}

	void JsonWriter::WriteString(std::string s)
	{
		*(_writer) << '\"';
		int32_t l = std::any_cast<int32_t>(s.length());
		for (auto index = 0; index < l; index++)
		{
			auto c = s[index];
			switch (c)
			{
			case '\"':
				*(_writer) << "\\\"";
				break;

			case '\\':
				*(_writer) << "\\\\";
				break;

			case '\b':
				*(_writer) << "\\b";
				break;

			case '\f':
				*(_writer) << "\\f";
				break;

			case '\n':
				*(_writer) << "\\n";
				break;

			case '\r':
				*(_writer) << "\\r";
				break;

			case '\t':
				*(_writer) << "\\t";
				break;

			default:
				const int i = gsl::narrow_cast<int32_t>(c);
				if (i < 32 || i > 127)
				{
					*(_writer) << "\\u";
					*(_writer) << std::hex << i;
				}
				else
				{
					*(_writer) << c;
				}
				break;
			}
		}
		*(_writer) << '\"';
	}

	void JsonWriter::WriteExtendDataType(std::string type, std::string value)
	{
		// format: { "$type": "string-value" }
		// no string.Format to better performance
		*(_writer) << "{\"";
		*(_writer) << type;
		*(_writer) << "\":";
		*(_writer) << _spacer;
		*(_writer) << "\"";
		*(_writer) << value;
		*(_writer) << "\"}";
	}

	void JsonWriter::WriteKeyValue(std::string key, BsonValue value, bool comma)
	{
		this->WriteIndent();

		*(_writer) << "\"";
		*(_writer) << key;
		*(_writer) << "\":";

		// do not do this tests if is not pretty format - to better performance
		if (this->mPretty)
		{
			*(_writer) << ' ';
		}

		//if (value.IsNull)
		if (!value.AsRawValue().has_value())
			this->WriteValue(BsonValue::getNull());
		else
			this->WriteValue(value);

		if (comma)
		{
			*(_writer) << ',';
		}

		this->WriteNewLine();
	}

	void JsonWriter::WriteStartBlock(std::string str, bool hasData)
	{
		if (hasData)
		{
			this->WriteIndent();
			*(_writer) << str;
			this->WriteNewLine();
			_indent++;
		}
		else
		{
			*(_writer) << str;
		}
	}

	void JsonWriter::WriteEndBlock(std::string str, bool hasData)
	{
		if (hasData)
		{
			_indent--;
			this->WriteIndent();
			*(_writer) << str;
		}
		else
		{
			*(_writer) << str;
		}
	}

	void JsonWriter::WriteNewLine()
	{
		if (this->mPretty)
		{
			*(_writer) << "" << std::endl;
		}
	}

	void JsonWriter::WriteIndent()
	{
		if (this->mPretty)
		{
			std::string s = std::string();
			this->padTo(s, (_indent * INDENT_SIZE, ' '));
			*(_writer) << s;
		}
	}

	void JsonWriter::padTo(std::string &str, const size_t num, const char paddingChar)
	{
		if (num > str.size())
			str.insert(0, num - str.size(), paddingChar);
	}
}