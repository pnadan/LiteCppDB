#pragma once

#include "ICommand.h"

namespace LiteCppDB_Console_Commands
{
	class Debug final : public LiteCppDB_Console::ICommand
	{
	public:
		Debug();

		DataAccess getAccess() override;

		bool IsCommand(LiteCppDB::StringScanner& s) override;

		void Execute(LiteCppDB::LiteEngine engine, LiteCppDB::StringScanner& s, LiteCppDB_Console::Display d, LiteCppDB_Console::InputCommand input, LiteCppDB_Console::Env env) override;
	};
}