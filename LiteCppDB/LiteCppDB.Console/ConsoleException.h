#pragma once

#include <string>

namespace LiteCppDB_Console
{
	class ConsoleException : public std::exception
	{
	public:
		ConsoleException(const std::string& message) : mMsg(message) {};

		virtual const char* what() const noexcept override { return mMsg.c_str(); };

	private:
		std::string mMsg;
	};
}