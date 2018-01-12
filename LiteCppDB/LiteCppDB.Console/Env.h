#pragma once

#include "..\LiteCppDB\ConnectionString.h"
#include "..\LiteCppDB\LiteEngine.h"
#include "..\LiteCppDB\LiteDatabase.h"

enum class DataAccess { None, Read, Write };

namespace LiteCppDB_Console
{
	class Env
	{
	public:
		LiteCppDB::ConnectionString getConnectionString() noexcept;
		void setConnectionString(LiteCppDB::ConnectionString connectionString) noexcept;

		Env() noexcept;

		LiteCppDB::LiteEngine CreateEngine(DataAccess access);
	private:
		LiteCppDB::ConnectionString mConnectionString;
	};
}