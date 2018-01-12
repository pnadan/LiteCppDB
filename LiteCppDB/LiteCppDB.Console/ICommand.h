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
		ICommand() noexcept {};
		virtual ~ICommand() {};

		ICommand(const ICommand& src) noexcept;
		virtual ICommand& operator=(const ICommand& rhs) noexcept;

		ICommand(const ICommand&& src) noexcept;
		virtual ICommand& operator=(ICommand&& rhs) noexcept;

		virtual DataAccess getAccess() noexcept { return DataAccess::None; };

		virtual bool IsCommand(LiteCppDB::StringScanner& s) noexcept { return false; };

		virtual void Execute(LiteCppDB::LiteEngine engine, LiteCppDB::StringScanner& s, Display display, InputCommand input, LiteCppDB_Console::Env env) noexcept {};
	};
}