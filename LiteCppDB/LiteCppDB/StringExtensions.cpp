#include "stdafx.h"

#include "StringExtensions.h"

#include <algorithm> 

namespace LiteCppDB
{
	bool StringExtensions::isNullOrWhiteSpace(std::string const& str)
	{
		return std::find_if(
			str.begin(),
			str.end(),
			[](unsigned char ch) { return !isspace(ch); })
			== str.end();
	}

	std::string StringExtensions::ThrowIfEmpty(std::string& str, std::string message)
	{
		if (this->isNullOrWhiteSpace(str))
		{
			throw message;
		}

		return str;
	}

	std::string StringExtensions::TrimToNull(std::string& str)
	{
		return str;
	}
}