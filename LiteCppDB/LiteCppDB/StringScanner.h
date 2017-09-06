#pragma once

#include <string>
#include <regex>

#ifdef LITECPPDB_EXPORTS
#define LITECPPDB_API __declspec(dllexport)
#else
#define LITECPPDB_API __declspec(dllimport)
#endif

namespace LiteCppDB
{
	// A StringScanner is state machine used in text parsers based on regular expressions
	class StringScanner
	{
	private:
		std::string mSource;
		size_t mIndex;

	public:
		LITECPPDB_API std::string getSource();
		LITECPPDB_API void setSource(std::string source);

		LITECPPDB_API size_t getIndex();
		LITECPPDB_API void setIndex(size_t index);

		// Initialize scanner with a string to be parsed
		LITECPPDB_API StringScanner(std::string source);

		LITECPPDB_API std::string ToString();

		// Reset cursor position
		LITECPPDB_API void Reset();

		// Skip cursor position in string source
		LITECPPDB_API void Seek(int length);

		// Indicate that cursor is EOF
		LITECPPDB_API bool HasTerminated();

		// Scan in current cursor position for this patterns. If found, returns string and run with cursor
		LITECPPDB_API std::string Scan(std::string pattern);

		// Scan in current cursor position for this patterns. If found, returns string and run with cursor
		LITECPPDB_API std::string Scan(std::regex regex);

		// Scan pattern and returns group string index 1 based
		LITECPPDB_API std::string Scan(std::string pattern, size_t group);

		LITECPPDB_API std::string Scan(std::regex regex, size_t group);

		// Match if pattern is true in current cursor position. Do not change cursor position
		LITECPPDB_API bool Match(std::string pattern);

		// Match if pattern is true in current cursor position. Do not change cursor position
		LITECPPDB_API bool Match(std::regex regex);
	};
}