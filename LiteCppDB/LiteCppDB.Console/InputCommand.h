#pragma once

#include <queue>
#include <vector>

namespace LiteCppDB_Console
{
	class InputCommand
	{
	public:
		InputCommand();
		~InputCommand();

		std::queue<std::string> queueInput;

		std::vector<std::string> historyInput;

		bool getRunning();
		void setRunning(bool running);

		std::string ReadCommand();

	private:
		// Read a line from queue or user
		std::string ReadLine();
		bool mRunning;
	};
}