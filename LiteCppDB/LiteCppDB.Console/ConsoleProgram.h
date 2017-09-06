#pragma once

#include "Display.h"
#include "InputCommand.h"
#include "ICommand.h"

#include <memory>
#include <vector>

namespace LiteCppDB_Console
{
	class ConsoleProgram
	{
	public:
		ConsoleProgram();
		~ConsoleProgram() {};

		void Start(InputCommand input, Display display);

#pragma region Register all commands

		void RegisterCommands(std::vector<std::unique_ptr<ICommand>>& commands);

#pragma endregion
	};
}