#include "stdafx.h"
#include "Comment.h"

namespace LiteCppDB_Console_Commands
{
	Comment::Comment() noexcept
	{

	}

	DataAccess Comment::getAccess() noexcept
	{
		return DataAccess::None;
	}

	bool Comment::IsCommand(LiteCppDB::StringScanner& s) noexcept
	{
		return false;// s.Match("--");
	}

	void Comment::Execute(LiteCppDB::LiteEngine engine, LiteCppDB::StringScanner& s, LiteCppDB_Console::Display d, LiteCppDB_Console::InputCommand input, LiteCppDB_Console::Env env) noexcept
	{
	}
}