#include "stdafx.h"

#include "JsonTokenizer.h"

#include <cctype>
#include <any>
#include <string>

namespace LiteCppDB
{
	JsonToken::JsonToken(JsonTokenType tokenType, std::string token)
	{
		this->mToken = token;
		this->mTokenType = mTokenType;
	}


	std::string JsonToken::getToken()
	{
		return this->mToken;
	}
	void JsonToken::setToken(std::string token)
	{
		this->mToken = token;
	}

	JsonTokenType JsonToken::getTokenType()
	{
		return this->mTokenType;
	}
	void JsonToken::setTokenType(JsonTokenType tokenType)
	{
		this->mTokenType = tokenType;
	}

	void JsonToken::Expect(JsonTokenType type)
	{
		if (this->getTokenType() != type)
		{
			throw std::exception("LiteException.UnexpectedToken(this.Token)");
		}
	}

	void JsonToken::Expect(JsonTokenType type1, JsonTokenType type2)
	{
		if (this->getTokenType() != type1 && this->getTokenType() != type2)
		{
			throw std::exception("LiteException.UnexpectedToken(this.Token)");
		}
	}


	bool JsonTokenizer::getEOF()
	{
		return this->mEOF;
	}
	void JsonTokenizer::setEOF(bool eOF)
	{
		this->mEOF = eOF;
	}

	int64_t JsonTokenizer::getPosition()
	{
		return this->mPosition;
	}
	void JsonTokenizer::setPosition(int64_t position)
	{
		this->mPosition = position;
	}

	JsonTokenizer::JsonTokenizer(std::istringstream* reader)
	{
		this->mPosition = 0;
		this->mEOF = false;
		_reader = reader;
		this->setPosition(0);
		this->Read();
	}

	// Read next char in stream and set in _current
	char JsonTokenizer::Read()
	{
		if (this->getEOF()) return '\0';

		char c;
		(*_reader) >> c;

		int64_t actualPosition = this->getPosition();
		this->setPosition(actualPosition++);

		if (c == -1)
		{
			(*_current) = '\0';
			this->setEOF(true);
		}

		(*_current) = static_cast<char>(c);

		return (*_current);
	}

	// Read next json token
	JsonToken JsonTokenizer::ReadToken()
	{
		this->EatWhitespace();

		if (this->getEOF())
		{
			return JsonToken(JsonTokenType::EOFjtt, "");
		}

		auto token = JsonToken(JsonTokenType::EOFjtt, "");

		switch (*_current)
		{
		case '[':
			token = JsonToken(JsonTokenType::BeginArray, "[");
			this->Read();
			break;

		case ']':
			token = JsonToken(JsonTokenType::EndArray, "]");
			this->Read();
			break;

		case '{':
			token = JsonToken(JsonTokenType::BeginDoc, "{");
			this->Read();
			break;

		case '}':
			token = JsonToken(JsonTokenType::EndDoc, "}");
			this->Read();
			break;

		case ':':
			token = JsonToken(JsonTokenType::Colon, ":");
			this->Read();
			break;

		case ',':
			token = JsonToken(JsonTokenType::Comma, ",");
			this->Read();
			break;

		case '\"':
			token = JsonToken(JsonTokenType::String, this->ReadString());
			break;

		case '-':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			token = JsonToken(JsonTokenType::Number, this->ReadNumber());
			break;

		default:
			token = JsonToken(JsonTokenType::Word, this->ReadWord());
			break;
		}

		return token;
	}

	// Eat all whitespace - used before a valid token
	void JsonTokenizer::EatWhitespace()
	{
		while (iswspace(*_current) && !this->getEOF())
		{
			this->Read();
		}
	}

	// Read a word without "
	std::string JsonTokenizer::ReadWord()
	{
		std::string sb;
		sb.append(_current);

		this->Read();

		while (!this->getEOF() && std::isdigit(static_cast<unsigned char>(*_current)) || std::isalpha(*_current) || (*_current) == '_' || (*_current) == '$')
		{
			sb.append(_current);
			this->Read();
		}

		return sb;
	}

	// Read a number - it's accepts all number char, but not validate. When run Convert, .NET will check if number is correct
	std::string JsonTokenizer::ReadNumber()
	{
		std::string sb;
		sb.append(_current);

		this->Read();

		while (!this->getEOF() &&
			(std::isdigit(static_cast<unsigned char>(*_current)) || (*_current) == '+' || (*_current) == '-' || (*_current) == '.' || (*_current) == 'e' || (*_current) == 'E'))
		{
			sb.append(_current);
			this->Read();
		}

		return sb;
	}

	// Read a string removing open and close "
	std::string JsonTokenizer::ReadString()
	{
		std::string sb;
		this->Read(); // remove first "

		while ((*_current) != '\"' && !this->getEOF())
		{
			if ((*_current) == '\\')
			{
				this->Read();

				switch ((*_current))
				{
				case '"': sb.append(_current); break;
				//case '"': sb.append(reinterpret_cast<char*>('"')); break;
				case '\\': sb.append(_current); break;
				//case '\\': sb.append(reinterpret_cast<char*>('\\')); break;
				case '/': sb.append(_current); break;
				//case '/': sb.append(reinterpret_cast<char*>('/')); break;

				case 'b': sb.append(_current); break;
				//case 'b': sb.append(reinterpret_cast<char*>('\b')); break;
				case 'f': sb.append(_current); break;
				//case 'f': sb.append(reinterpret_cast<char*>('\f')); break;
				case 'n': sb.append(_current); break;
				//case 'n': sb.append(reinterpret_cast<char*>('\n')); break;
				case 'r': sb.append(_current); break;
				//case 'r': sb.append(reinterpret_cast<char*>('\r')); break;
				case 't': sb.append(_current); break;
				//case 't': sb.append(reinterpret_cast<char*>('\t')); break;
				case 'u':
					auto codePoint = this->ParseUnicode(this->Read(), this->Read(), this->Read(), this->Read());
					std::string s = std::any_cast<std::string>(codePoint);
					sb.append(s);
					break;
				}
			}
			else
			{
				sb.append(_current);
			}

			this->Read();
		}

		this->Read(); // read last "

		return sb;
	}

	uint32_t JsonTokenizer::ParseUnicode(char c1, char c2, char c3, char c4)
	{
		uint32_t p1 = this->ParseSingleChar(c1, 0x1000);
		uint32_t p2 = this->ParseSingleChar(c2, 0x100);
		uint32_t p3 = this->ParseSingleChar(c3, 0x10);
		uint32_t p4 = this->ParseSingleChar(c4, 1);

		return p1 + p2 + p3 + p4;
	}

	uint32_t JsonTokenizer::ParseSingleChar(char c1, uint32_t multiplier)
	{
		uint32_t p1 = 0;
		if (c1 >= '0' && c1 <= '9')
			p1 = static_cast<uint32_t>(c1 - '0') * multiplier;
		else if (c1 >= 'A' && c1 <= 'F')
			p1 = static_cast<uint32_t>((c1 - 'A') + 10) * multiplier;
		else if (c1 >= 'a' && c1 <= 'f')
			p1 = static_cast<uint32_t>((c1 - 'a') + 10) * multiplier;
		return p1;
	}
}