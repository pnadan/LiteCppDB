#include "stdafx.h"

#include "LiteDatabase.h"

namespace LiteCppDB
{
	// The LiteDB database. Used for create a LiteDB instance and use all storage resources. It's the database connection
#pragma region Properties

	// Get current instance of BsonMapper used in this database instance (can be BsonMapper.Global)
	BsonMapper LiteDatabase::getMapper()
	{
		return this->_mapper;
	}

	// Get current database engine instance. Engine is lower data layer that works with BsonDocuments only (no mapper, no LINQ)
	LiteEngine LiteDatabase::getEngine()
	{
		return _engine;
	}

#pragma endregion

#pragma region Ctor

	LiteDatabase::LiteDatabase()
	{
	}

	LiteDatabase::~LiteDatabase()
	{
	}

	/// Starts LiteDB database using a connection string for file system database
	LiteDatabase::LiteDatabase(std::string connectionString, BsonMapper mapper)
	{
	}

	// Starts LiteDB database using a connection string for file system database
	LiteDatabase::LiteDatabase(ConnectionString connectionString, BsonMapper mapper)
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
	long LiteDatabase::Shrink()
	{
		//return this.Shrink(_connectionString == NULL ? NULL : _connectionString.Password);
		return 0;
	}

	// Reduce disk size re-arranging unused space. Can change password. If a temporary disk was not provided, use MemoryStream temp disk
	long LiteDatabase::Shrink(std::string password)
	{
		return 0;
	}

#pragma endregion
}