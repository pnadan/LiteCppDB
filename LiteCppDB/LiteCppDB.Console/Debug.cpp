#include "stdafx.h"
#include "Debug.h"

namespace LiteCppDB_Console_Commands
{
	Debug::Debug() noexcept
	{

	}

	DataAccess Debug::getAccess() noexcept
	{
		return DataAccess::None;
	}

	bool Debug::IsCommand(LiteCppDB::StringScanner& s) noexcept
	{
		return false;
	}

	void Debug::Execute(LiteCppDB::LiteEngine engine, LiteCppDB::StringScanner& s, LiteCppDB_Console::Display d, LiteCppDB_Console::InputCommand input, LiteCppDB_Console::Env env) noexcept
	{

	}
}