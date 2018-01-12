#pragma once

#include <queue>
#include <vector>

namespace LiteCppDB_Console
{
	class InputCommand
	{
	public:
		InputCommand() noexcept;
		virtual ~InputCommand();

		// Copy constructor.
		InputCommand(const InputCommand& src) noexcept;
		// Move assigment.
		virtual InputCommand& operator=(const InputCommand& rhs) noexcept;

		// Move constructor.
		InputCommand(const InputCommand&& src) noexcept;
		// Move assigment.
		virtual InputCommand& operator=(InputCommand&& rhs) noexcept;

		std::queue<std::string> queueInput;

		std::vector<std::string> historyInput;

		bool getRunning() noexcept;
		void setRunning(bool running) noexcept;

		std::string ReadCommand();

	private:
		// Read a line from queue or user
		std::string ReadLine();
		bool mRunning;
	};
}