#include "stdafx.h"
#include "InputCommand.h"

#include <iostream>
#include <string>

namespace LiteCppDB_Console
{
	InputCommand::InputCommand() noexcept
	{
		this->mRunning = true;
	}

	InputCommand::~InputCommand()
	{

	}

	InputCommand::InputCommand(const InputCommand& src) noexcept
	{
		this->mRunning = src.mRunning;
	}

	InputCommand& InputCommand::operator=(const InputCommand& rhs) noexcept
	{
		// TODO: insert return statement here
		if (this == &rhs)
		{
			return *this;
		}

		this->mRunning = rhs.mRunning;
		return *this;
	}

	InputCommand::InputCommand(const InputCommand&& src) noexcept
	{
		this->mRunning = src.mRunning;
	}

	InputCommand& InputCommand::operator=(InputCommand&& rhs) noexcept
	{
		// TODO: insert return statement here
		if (this == &rhs)
		{
			return *this;
		}

		this->mRunning = rhs.mRunning;
		return *this;
	}

	bool InputCommand::getRunning() noexcept
	{
		return this->mRunning;
	}
	void InputCommand::setRunning(bool running) noexcept
	{
		this->mRunning = running;
	}

	std::string InputCommand::ReadCommand()
	{
		auto cmd = this->ReadLine();
		return cmd;
	}

	// Read a line from queue or user
	std::string InputCommand::ReadLine()
	{
		std::string userCommand("");

		std::cout << "> ";

		getline(std::cin, userCommand);

		return userCommand;
	}
}