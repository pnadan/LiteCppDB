#include "stdafx.h"

#include "StringExtensions.h"

#include <algorithm> 

namespace LiteCppDB
{
	bool StringExtensions::isNullOrWhiteSpace(std::string const& str) noexcept
	{
		return std::find_if(
			str.begin(),
			str.end(),
			[](unsigned char ch) noexcept { return !isspace(ch);})
			== str.end();
	}

	std::string StringExtensions::ThrowIfEmpty(const std::string& str, std::string message)
	{
		if (this->isNullOrWhiteSpace(str))
		{
			throw message;
		}

		return str;
	}

	std::string StringExtensions::TrimToNull(const std::string& str)
	{
		return str;
	}
}