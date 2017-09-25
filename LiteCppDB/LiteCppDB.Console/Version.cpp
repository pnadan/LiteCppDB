#include "stdafx.h"
#include "Version.h"

namespace LiteCppDB_Console_Commands
{
	Version::Version()
	{

	}

	DataAccess Version::getAccess()
	{
		return DataAccess::None;
	}

	bool Version::IsCommand(LiteCppDB::StringScanner& s)
	{
		std::string stringToScan("ver(sion) ? $");
		return s.Scan(stringToScan).length() > 0;
	}

	void Version::Execute(LiteCppDB::LiteEngine engine, LiteCppDB::StringScanner& s, LiteCppDB_Console::Display d, LiteCppDB_Console::InputCommand input, LiteCppDB_Console::Env env)
	{
		d.WriteLine("Version: UNKNOWN");
	}
}