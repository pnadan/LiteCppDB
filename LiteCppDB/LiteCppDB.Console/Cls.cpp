#include "stdafx.h"
#include "Cls.h"

namespace LiteCppDB_Console_Commands
{
	DataAccess Cls::getAccess() noexcept
	{
		return DataAccess::None;
	}

	bool Cls::IsCommand(LiteCppDB::StringScanner& s) noexcept
	{
		return s.Scan("cls[[:s:]]*").length() > 0;
	}

	void Cls::Execute(LiteCppDB::LiteEngine engine, LiteCppDB::StringScanner& s, LiteCppDB_Console::Display d, LiteCppDB_Console::InputCommand input, LiteCppDB_Console::Env env) noexcept
	{
		d.WriteWelcome();
	}
}