#include "stdafx.h"

#include <string>
#include <regex>
#include <iostream>
#include <fstream>

#include "Open.h"
#include "StringExtensions.h"

namespace LiteCppDB_Console_Commands
{
	DataAccess Open::getAccess() noexcept
	{
		return DataAccess::None;
	}

	bool Open::IsCommand(LiteCppDB::StringScanner& s) noexcept
	{
		return s.Scan("open[[:s:]]+").length() > 0;
	}

	void Open::Execute(LiteCppDB::LiteEngine engine, LiteCppDB::StringScanner& s, LiteCppDB_Console::Display d, LiteCppDB_Console::InputCommand input, LiteCppDB_Console::Env env) noexcept
	{
		//// if needs upgrade, do it now
		if (env.getConnectionString().getUpgrade())
		{

		}
		else
		{
			std::ofstream file(env.getConnectionString().getFilename());

			// open datafile just to test if it's ok (or to create new)
			if (!file)
			{
				const auto e = env.CreateEngine(DataAccess::Read);
			}
			else
			{
				const auto e = env.CreateEngine(DataAccess::Write);
			}
		}
	}
}