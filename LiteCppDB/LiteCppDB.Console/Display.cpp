#include "stdafx.h"
#include "Display.h"

#include <iostream>
#include <string>

namespace LiteCppDB_Console
{
	bool Display::getPretty()
	{
		return mPretty;
	}
	void Display::setPretty(bool bPretty)
	{
		mPretty = bPretty;
	}

	Display::Display()
	{
		mPretty = false;
	}

	void Display::WriteWelcome()
	{
		system("CLS");
		this->WriteInfo("Welcome to LiteCppDB Console");
		this->WriteInfo("");
		this->WriteInfo("Getting started with `help`");
		this->WriteInfo("");
	}

	void Display::WriteInfo(std::string text)
	{
		std::cout << text << std::endl;
	}

	void Display::WriteError(std::string err)
	{
		this->WriteLine(12, err);
	}

	void Display::WriteHelp(std::string line1, std::string line2)
	{
		if (line1.empty())
		{
			this->WriteLine("");
		}
		else
		{
			this->WriteLine((FOREGROUND_BLUE | FOREGROUND_GREEN), line1);

			if (!line2.empty())
			{
				this->WriteLine((FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY), "    " + line2);
				this->WriteLine("");
			}
		}
	}

	void Display::WriteLine(std::string text)
	{
		this->WriteLine(2, text);
	}

	void Display::WriteLine(int32_t color, std::string text)
	{
		this->Write(color, text);
	}

	void Display::Write(int32_t color, std::string text)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_SCREEN_BUFFER_INFO csbi = CONSOLE_SCREEN_BUFFER_INFO();
		WORD mCurrentConsoleAttr = 0;

		if (GetConsoleScreenBufferInfo(hConsole, &csbi))
		{
			mCurrentConsoleAttr = csbi.wAttributes;
		}

		if (SetConsoleTextAttribute(hConsole, color))
		{
			std::cout << text << std::endl;
			SetConsoleTextAttribute(hConsole, mCurrentConsoleAttr);
		}
	}
}