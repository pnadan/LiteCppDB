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
		bool isNullOrWhiteSpace(std::string const& str) noexcept;

	public:
		LITECPPDB_API std::string ThrowIfEmpty(const std::string& str, std::string message);

		LITECPPDB_API static std::string TrimToNull(const std::string& str);
	};
}