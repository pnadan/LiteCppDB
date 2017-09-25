#pragma once

#include "ICommand.h"

namespace LiteCppDB_Console_Commands
{
	class Open final : public LiteCppDB_Console::ICommand
	{
	public:
		DataAccess getAccess();

		bool IsCommand(LiteCppDB::StringScanner& s);

		void Execute(LiteCppDB::LiteEngine engine, LiteCppDB::StringScanner& s, LiteCppDB_Console::Display display, LiteCppDB_Console::InputCommand input, LiteCppDB_Console::Env env);
	};
}