#pragma once

#include<windows.h>
#include<iosfwd>

#include <queue>
#include <vector>

namespace LiteCppDB_Console
{

	class Display
	{
	public:
		bool getPretty();
		void setPretty(bool bPretty);

		Display();

		void WriteWelcome();

		void WriteInfo(std::string text);

		void WriteError(std::string err);

		void WriteHelp(std::string line1 = std::string(), std::string line2 = std::string());

		void WriteLine(std::string text);

		void WriteLine(int32_t color, std::string text);

		void Write(int32_t color, std::string text);
	private:
		bool mPretty;
	};
}