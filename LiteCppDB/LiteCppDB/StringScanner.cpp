#include "stdafx.h"
#include "StringScanner.h"

// A StringScanner is state machine used in text parsers based on regular expressions
namespace LiteCppDB
{
	std::string StringScanner::getSource()
	{
		return this->mSource;
	}
	void StringScanner::setSource(std::string source)
	{
		this->mSource = source;
	}

	size_t StringScanner::getIndex() noexcept
	{
		return this->mIndex;
	}
	void StringScanner::setIndex(size_t index) noexcept
	{
		this->mIndex = index;
	}

	// Initialize scanner with a string to be parsed
	StringScanner::StringScanner(std::string source)
	{
		this->mSource = source;
		this->mIndex = 0;
	}

	std::string StringScanner::ToString()
	{
		return HasTerminated() ? "<EOF>" : this->mSource.substr(this->mIndex);
	}

	// Reset cursor position
	void StringScanner::Reset() noexcept
	{
		this->mIndex = 0;
	}

	// Skip cursor position in string source
	void StringScanner::Seek(int length) noexcept
	{
		this->mIndex += length;
	}

	// Indicate that cursor is EOF
	bool StringScanner::HasTerminated() noexcept
	{
		if (this->mIndex >= this->mSource.length())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// Scan in current cursor position for this patterns. If found, returns string and run with cursor
	std::string StringScanner::StringScanner::Scan(std::string pattern)
	{
		std::string t("^");

		if (pattern.compare(0, t.size(), t) == 0)
		{
			std::regex txt_regex(pattern, std::regex_constants::ECMAScript);
			return this->Scan(txt_regex);
		}
		else
		{
			std::regex txt_regex("^" + pattern, std::regex_constants::ECMAScript);
			return this->Scan(txt_regex);
		}
	}

	// Scan in current cursor position for this patterns. If found, returns string and run with cursor
	std::string StringScanner::Scan(std::regex regex)
	{
		std::smatch m;
		std::string s = this->mSource.substr(this->mIndex, this->mSource.length() - this->mIndex);

		if (std::regex_search(s, m, regex))
		{
			if (this->mSource.length() > (this->mIndex + m.length()))
				this->mIndex += m.length();
			return m.str();
		}
		else
		{
			return std::string();
		}
	}

	// Scan pattern and returns group string index 1 based
	std::string StringScanner::Scan(std::string pattern, size_t group)
	{
		std::string t("^");
		if (pattern.compare(0, t.length(), t) == 0)
		{
			std::regex txt_regex(pattern);
			return this->Scan(txt_regex, group);
		}
		else
		{
			std::regex txt_regex("^" + pattern);
			return this->Scan(txt_regex, group);
		}
	}

	std::string StringScanner::Scan(std::regex regex, size_t group)
	{
		std::smatch m;
		const auto &s = this->mSource.substr(this->mIndex, this->mSource.length() - this->mIndex);

		if (std::regex_match(s, m, regex))
		{
			this->mIndex += m.length();
			if (group >= m.size())
			{
				return "";
			}
			else
			{
				return m[group].str();
			}
		}
		else
		{
			return std::string();
		}
	}

	// Match if pattern is true in current cursor position. Do not change cursor position
	bool StringScanner::Match(std::string pattern)
	{
		std::string t("^");

		if (pattern.compare(0, t.size(), t) == 0)
		{
			std::regex txt_regex(pattern);
			return this->Match(txt_regex);
		}
		else
		{
			std::regex txt_regex("^" + pattern);
			return this->Match(txt_regex);
		}
	}

	// Match if pattern is true in current cursor position. Do not change cursor position
	bool StringScanner::Match(std::regex regex)
	{
		std::smatch m;
		const auto &s = this->mSource.substr(this->mIndex, this->mSource.length() - this->mIndex);

		return std::regex_search(s, m, regex);
	}
}