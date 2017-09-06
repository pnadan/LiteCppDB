#pragma once

#include "Display.h"
#include "Env.h"
#include "InputCommand.h"
#include "..\LiteCppDB\LiteEngine.h"
#include "..\LiteCppDB\StringScanner.h"

#pragma comment(lib, "LiteCppDB.lib")

namespace LiteCppDB_Console
{
	class ICommand
	{
	public:
		virtual DataAccess getAccess() { return DataAccess::None; };

		virtual bool IsCommand(LiteCppDB::StringScanner& s) { return false; };

		virtual void Execute(LiteCppDB::LiteEngine engine, LiteCppDB::StringScanner& s, Display display, InputCommand input, LiteCppDB_Console::Env env) {};
	};
}