#include "stdafx.h"
#include "Quit.h"

namespace LiteCppDB_Console_Commands
{
	DataAccess Quit::getAccess()
	{
		return DataAccess::None;
	}

	bool Quit::IsCommand(LiteCppDB::StringScanner& s)
	{
		return s.Scan("quit[[:s:]]*|exit[[:s:]]*").length() > 0;
	}

	void Quit::Execute(LiteCppDB::LiteEngine engine, LiteCppDB::StringScanner& s, LiteCppDB_Console::Display d, LiteCppDB_Console::InputCommand input, LiteCppDB_Console::Env env)
	{
		input.setRunning(false);
	}
}