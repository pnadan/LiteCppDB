#include "stdafx.h"
#include "InputCommand.h"

#include <iostream>
#include <string>

namespace LiteCppDB_Console
{
	InputCommand::InputCommand()
	{
		this->mRunning = true;
	}

	InputCommand::~InputCommand()
	{

	}

	bool InputCommand::getRunning()
	{
		return this->mRunning;
	}
	void InputCommand::setRunning(bool running)
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