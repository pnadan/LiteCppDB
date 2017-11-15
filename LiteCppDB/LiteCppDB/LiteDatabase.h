#pragma once

#ifdef LITECPPDB_EXPORTS
#define LITECPPDB_API __declspec(dllexport)
#else
#define LITECPPDB_API __declspec(dllimport)
#endif

#include "LiteEngine.h"
#include "BsonMapper.h"
#include "ConnectionString.h"

#include <string>

namespace LiteCppDB
{
	// The LiteDB database. Used for create a LiteDB instance and use all storage resources. It's the database connection
	class LiteDatabase
	{
#pragma region Properties

	private:
		LiteCppDB::LiteEngine _engine;// = NULL;
		LiteCppDB::BsonMapper _mapper;// (BsonMapper::Global());
									  //LiteCppDB::Logger _log;
		//LiteCppDB::ConnectionString _connectionString = NULL;
		LiteCppDB::ConnectionString _connectionString;// = nullptr;

	public:
		// Get current instance of BsonMapper used in this database instance (can be BsonMapper.Global)
		LITECPPDB_API BsonMapper getMapper();

		// Get current database engine instance. Engine is lower data layer that works with BsonDocuments only (no mapper, no LINQ)
		LITECPPDB_API LiteEngine getEngine();

#pragma endregion

#pragma region Ctor

		LITECPPDB_API LiteDatabase();
		virtual ~LiteDatabase();

		// Starts LiteDB database using a connection string for file system database
		LITECPPDB_API LiteDatabase(std::string connectionString, BsonMapper mapper = BsonMapper());

		// Starts LiteDB database using a connection string for file system database
		LITECPPDB_API LiteDatabase(ConnectionString connectionString, BsonMapper mapper = BsonMapper());

#pragma endregion

#pragma region Transaction

#pragma endregion

#pragma region Collections

#pragma endregion

#pragma region FileStorage

#pragma endregion

#pragma region Shortcut

		//// Get all collections name inside this database.
		//IEnumerable<std::string> GetCollectionNames();

		// Checks if a collection exists on database. Collection name is case insensitive
		LITECPPDB_API bool CollectionExists(std::string name);

		// Drop a collection and all data + indexes
		LITECPPDB_API bool DropCollection(std::string name);

		// Rename a collection. Returns false if oldName does not exists or newName already exists
		LITECPPDB_API bool RenameCollection(std::string oldName, std::string newName);

#pragma endregion

#pragma region Shrink

		// Reduce disk size re-arranging unused spaces.
		LITECPPDB_API long Shrink();

		// Reduce disk size re-arranging unused space. Can change password. If a temporary disk was not provided, use MemoryStream temp disk
		LITECPPDB_API long Shrink(std::string password);

#pragma endregion
	};
}