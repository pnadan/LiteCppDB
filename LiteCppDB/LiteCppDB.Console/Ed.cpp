#include "stdafx.h"
#include "Ed.h"

namespace LiteCppDB_Console_Commands
{
	DataAccess Ed::getAccess()
	{
		return DataAccess::None;
	}

	bool Ed::IsCommand(LiteCppDB::StringScanner& s)
	{
		return false;
	}

	void Ed::Execute(LiteCppDB::LiteEngine engine, LiteCppDB::StringScanner& s, LiteCppDB_Console::Display d, LiteCppDB_Console::InputCommand input, LiteCppDB_Console::Env env)
	{

	}
}