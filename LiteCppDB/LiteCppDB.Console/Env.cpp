#include "stdafx.h"

#include "Env.h"
#include "ConsoleException.h"

namespace LiteCppDB_Console
{
	LiteCppDB::ConnectionString Env::getConnectionString() noexcept
	{
		return this->mConnectionString;
	}
	void Env::setConnectionString(LiteCppDB::ConnectionString connectionString) noexcept
	{
		this->mConnectionString = connectionString;
	}

	Env::Env() noexcept
	{
	}

	LiteCppDB::LiteEngine Env::CreateEngine(DataAccess access)
	{
		if (this->getConnectionString().getFilename().empty())
			throw(ConsoleException("No database"));

		return LiteCppDB::LiteEngine();
	}
}