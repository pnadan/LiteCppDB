#include "stdafx.h"
#include "ConsoleProgram.h"
#include "ConsoleException.h"

#include "Cls.h"
#include "Help.h"

#include <typeinfo>
#include <exception>
#include <iostream>
#include <memory>

using namespace std;

namespace LiteCppDB_Console
{
	ConsoleProgram::ConsoleProgram() noexcept
	{
	}

	ConsoleProgram::ConsoleProgram(const ConsoleProgram& src) noexcept
	{
	}

	ConsoleProgram& ConsoleProgram::operator=(const ConsoleProgram& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		return *this;
	}

	ConsoleProgram::ConsoleProgram(const ConsoleProgram&& src) noexcept
	{
	}

	ConsoleProgram& ConsoleProgram::operator=(ConsoleProgram&& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		return *this;
	}

	void myfunction(int i) 
	{
		std::cout << ' ' << i;
	}

	void ConsoleProgram::Start(InputCommand input, Display display)
	{
		vector<unique_ptr<ICommand>> commands;

		Env env;

		const LiteCppDB::LiteEngine engine;

		// register commands
		this->RegisterCommands(commands);

		// show welcome message
		display.WriteWelcome();

		while (input.getRunning())
		{
			// read next command from user or queue
			auto cmd = input.ReadCommand();

			if (cmd.empty()) continue;

			try
			{
				auto s = LiteCppDB::StringScanner::StringScanner(cmd);
				auto found = false;

				for (int32_t i = 0; i < commands.size(); ++i)
				{
					if (!commands.at(i)->IsCommand(s))
						continue;

					if (commands.at(i)->getAccess() != DataAccess::None)
					{
					}

					commands.at(i)->Execute(engine, s, display, input, env);

					found = true;
					break;
				}

				if (!found) throw(ConsoleException("Command not found"));
			}
			catch (const exception& ex)
			{
				display.WriteError(ex.what());
			}
		}
	}

#pragma region Register all commands

	void ConsoleProgram::RegisterCommands(vector<unique_ptr<ICommand>>& commands)
	{
		commands.push_back(make_unique<LiteCppDB_Console_Commands::Cls>());
		commands.push_back(make_unique<LiteCppDB_Console_Commands::Help>());
	}

#pragma endregion
}