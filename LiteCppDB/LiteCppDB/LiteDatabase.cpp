#include "stdafx.h"

#include "LiteDatabase.h"

namespace LiteCppDB
{
	// The LiteDB database. Used for create a LiteDB instance and use all storage resources. It's the database connection
#pragma region Properties

	// Get current instance of BsonMapper used in this database instance (can be BsonMapper.Global)
	BsonMapper LiteDatabase::getMapper() noexcept
	{
		return this->mMapper;
	}

	// Get current database engine instance. Engine is lower data layer that works with BsonDocuments only (no mapper, no LINQ)
	LiteEngine LiteDatabase::getEngine() noexcept
	{
		return mEngine;
	}

#pragma endregion

#pragma region Ctor

	LiteDatabase::LiteDatabase() noexcept
	{
	}

	LiteDatabase::~LiteDatabase()
	{
	}

	LiteDatabase::LiteDatabase(const LiteDatabase& src) noexcept
	{
		this->mConnectionString = src.mConnectionString;
		this->mEngine = src.mEngine;
		this->mMapper = src.mMapper;
	}

	LiteDatabase& LiteDatabase::operator=(const LiteDatabase& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		this->mConnectionString = rhs.mConnectionString;
		this->mEngine = rhs.mEngine;
		this->mMapper = rhs.mMapper;
		return *this;
	}

	LiteDatabase::LiteDatabase(const LiteDatabase&& src) noexcept
	{
		this->mConnectionString = src.mConnectionString;
		this->mEngine = src.mEngine;
		this->mMapper = src.mMapper;
	}

	LiteDatabase& LiteDatabase::operator=(LiteDatabase&& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		this->mConnectionString = rhs.mConnectionString;
		this->mEngine = rhs.mEngine;
		this->mMapper = rhs.mMapper;
		return *this;
	}

	/// Starts LiteDB database using a connection string for file system database
	LiteDatabase::LiteDatabase(std::string connectionString, BsonMapper mapper) noexcept
	{
	}

	// Starts LiteDB database using a connection string for file system database
	LiteDatabase::LiteDatabase(ConnectionString connectionString, BsonMapper mapper) noexcept
	{
	}

#pragma endregion

#pragma region Transaction

#pragma endregion

#pragma region Collections

#pragma endregion

#pragma region FileStorage

#pragma endregion

#pragma region Shortcut

	// Checks if a collection exists on database. Collection name is case insensitive
	bool LiteDatabase::CollectionExists(std::string name)
	{
		if (name.empty()) throw std::exception::exception("ArgumentNullException(name)");

		//return _engine.Value.GetCollectionNames().Contains(name, StringComparer.OrdinalIgnoreCase);
		return false;
	}

	// Drop a collection and all data + indexes
	bool LiteDatabase::DropCollection(std::string name)
	{
		if (name.empty()) throw std::exception::exception("ArgumentNullException(name)");

		//return _engine.Value.DropCollection(name);
		return false;
	}

	// Rename a collection. Returns false if oldName does not exists or newName already exists
	bool LiteDatabase::RenameCollection(std::string oldName, std::string newName)
	{
		if (oldName.empty()) throw std::exception::exception("ArgumentNullException(oldName)");
		if (newName.empty()) throw std::exception::exception("ArgumentNullException(newName)");

		//return _engine.Value.RenameCollection(oldName, newName);
		return false;
	}

#pragma endregion

#pragma region Shrink

	// Reduce disk size re-arranging unused spaces.
	long LiteDatabase::Shrink() noexcept
	{
		//return this.Shrink(_connectionString == NULL ? NULL : _connectionString.Password);
		return 0;
	}

	// Reduce disk size re-arranging unused space. Can change password. If a temporary disk was not provided, use MemoryStream temp disk
	long LiteDatabase::Shrink(std::string password) noexcept
	{
		return 0;
	}

#pragma endregion
}