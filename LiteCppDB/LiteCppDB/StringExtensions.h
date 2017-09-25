#pragma once

#include <cctype>
#include <locale>

#include <string>

#ifdef LITECPPDB_EXPORTS
#define LITECPPDB_API __declspec(dllexport)
#else
#define LITECPPDB_API __declspec(dllimport)
#endif

namespace LiteCppDB
{
	class StringExtensions
	{
	private:
		bool isNullOrWhiteSpace(std::string const& str);

	public:
		LITECPPDB_API std::string ThrowIfEmpty(std::string& str, std::string message);

		LITECPPDB_API static std::string TrimToNull(std::string& str);
	};
}