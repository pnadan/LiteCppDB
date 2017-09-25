#pragma once

#include <string>
#include <sstream>

namespace LiteCppDB
{
#pragma region JsonToken

	enum JsonTokenType { BeginDoc, EndDoc, BeginArray, EndArray, Comma, Colon, String, Number, Word, EOFjtt };

	class JsonToken
	{
	private:
		JsonTokenType mTokenType;
		std::string mToken;

	public:
		JsonToken(JsonTokenType tokenType, std::string token);

		std::string getToken();
		void setToken(std::string token);

		JsonTokenType getTokenType();
		void setTokenType(JsonTokenType tokenType);

		void Expect(JsonTokenType type);

		void Expect(JsonTokenType type1, JsonTokenType type2);
	};

#pragma endregion JsonToken

	// Class that parse a json string and returns in json token
	class JsonTokenizer
	{
	public:
		bool getEOF();

		int64_t getPosition();

		JsonTokenizer(std::istringstream* reader);

		// Read next json token
		JsonToken ReadToken();
	private:
		bool mEOF;
		int64_t mPosition;

		char *_current = '\0';
		std::istringstream* _reader;

		void setEOF(bool eOF);
		void setPosition(int64_t position);

		// Read next char in stream and set in _current
		char Read();

		/// Eat all whitespace - used before a valid token
		void EatWhitespace();

		// Read a word without "
		std::string ReadWord();

		// Read a number - it's accepts all number char, but not validate. When run Convert, .NET will check if number is correct
		std::string ReadNumber();

		// Read a string removing open and close "
		std::string ReadString();

		uint32_t ParseUnicode(char c1, char c2, char c3, char c4);

		uint32_t ParseSingleChar(char c1, uint32_t multiplier);
	};
}