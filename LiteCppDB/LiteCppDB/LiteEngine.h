#pragma once

#include "Logger.h"
#include "LockService.h"
#include "IDiskService.h"
#include "CacheService.h"
#include "PageService.h"
#include "TransactionService.h"
#include "IndexService.h"
#include "DataService.h"
#include "CollectionService.h"
#include "AesEncryption.h"

#include "Query.h"
#include <vector>
#include "BsonValue.h"
#include <stdint.h>
#include "IndexInfo.h"
#include "CollectionIndex.h"
#include "BsonDocument.h"
#include "IDiskService.h"
#include "CollectionPage.h"
#include <cstdint>

//#include "AggregateEngine.h"
//#include "InsertEngine.h"

#ifdef LITECPPDB_EXPORTS
#define LITECPPDB_API __declspec(dllexport)
#else
#define LITECPPDB_API __declspec(dllimport)
#endif

namespace LiteCppDB
{
	class LiteEngine
	{
	private:
		Logger _log;
		LockService _locker;
		IDiskService _disk;
		CacheService _cache;
		PageService _pager;
		TransactionService _trans;
		IndexService _indexer;
		DataService _data;
		CollectionService _collection;
		AesEncryption _crypto;

		uint16_t _UserVersion;

	public:
		LITECPPDB_API LiteEngine() noexcept;

		LITECPPDB_API LiteEngine(std::string filename, bool journal = true) noexcept;

		LITECPPDB_API virtual ~LiteEngine() noexcept {};

		LITECPPDB_API LiteEngine(const LiteEngine& src) noexcept;
		LITECPPDB_API virtual LiteEngine& operator=(const LiteEngine& rhs) noexcept;

		LITECPPDB_API LiteEngine(const LiteEngine&& src) noexcept;
		LITECPPDB_API virtual LiteEngine& operator=(LiteEngine&& rhs) noexcept;

#pragma region Services instances
	private:
		LITECPPDB_API Logger getLog() noexcept { return this->_log; };
#pragma endregion Services instances

#pragma region AggregateEngine
	public:
		// Returns first value from an index (first is min value)
		BsonValue Min(std::string collection, std::string field) noexcept;

		// Returns last value from an index (last is max value)
		BsonValue Max(std::string collection, std::string field) noexcept;

		// Count all nodes from a query execution - do not deserialize documents to count. If query is null, use Collection counter variable
		int64_t Count(std::string collection, Query query = Query()) noexcept;

		// Check if has at least one node in a query execution - do not deserialize documents to check
		bool Exists(std::string collection, Query query) noexcept;
#pragma endregion AggregateEngine

#pragma region CollectionEngine
	public:
		// Returns all collection inside datafile
		std::vector<std::string> GetCollectionNames() noexcept;

		// Drop collection including all documents, indexes and extended pages
		bool DropCollection(std::string collection) noexcept;

		// Rename a collection
		bool RenameCollection(std::string collection, std::string newName) noexcept;
#pragma endregion CollectionEngine

#pragma region DeleteEngine
	public:
		// Implement delete command based on _id value. Returns true if deleted
		bool Delete(std::string collection, BsonValue id);

		// Implements delete based on a query result
		int32_t Delete(std::string collection, Query query) noexcept;
#pragma endregion DeleteEngine

#pragma region FindEngine
	public:

		// Find for documents in a collection using Query definition
		LITECPPDB_API std::vector<BsonDocument> Find(std::string collection, Query query, int32_t skip = 0, int32_t limit = INT32_MAX) noexcept;

		// Find index keys from collection. Do not retorn document, only key value
		std::vector<BsonValue> FindIndex(std::string collection, Query query, int32_t skip = 0, int32_t limit = INT32_MAX);

#pragma region FindOne / FindById

		// Find first or default document based in collection based on Query filter
		BsonDocument FindOne(std::string collection, Query query) noexcept;

		// Find first or default document based in _id field
		BsonDocument FindById(std::string collection, BsonValue id) noexcept;

		// Returns all documents inside collection order by _id index.
		std::vector<BsonDocument> FindAll(std::string collection) noexcept;

#pragma endregion FindOne / FindById

#pragma endregion FindEngine

#pragma region IndexEngine
	public:
		// Create a new index (or do nothing if already exists) to a collection/field
		LITECPPDB_API bool EnsureIndex(std::string collection, std::string field, bool unique = false);

		// Drop an index from a collection
		bool DropIndex(std::string collection, std::string field);

		// List all indexes inside a collection
		LITECPPDB_API std::vector<IndexInfo> GetIndexes(std::string collection);
#pragma endregion IndexEngine

#pragma region InsertEngine
	public:
		// Implements insert documents in a collection - returns _id value
		LITECPPDB_API BsonValue Insert(std::string collection, BsonDocument doc) noexcept;

		// Implements insert documents in a collection - use a buffer to commit transaction in each buffer count
		LITECPPDB_API int32_t Insert(std::string collection, std::vector<BsonDocument> docs) noexcept;

		// Bulk documents to a collection - use data chunks for most efficient insert
		LITECPPDB_API int32_t InsertBulk(std::string collection, std::vector<BsonDocument> docs, int32_t batchSize = 5000) noexcept;

	private:
		// Internal implementation of insert a document
		void InsertDocument(CollectionPage col, BsonDocument doc) noexcept;
#pragma endregion InsertEngine

#pragma region ShrinkEngine
	public:
		// Reduce disk size re-arranging unused spaces. Can change password. If temporary disk was not provided, use MemoryStream temp disk
		int64_t Shrink(std::string password = nullptr, IDiskService temp = IDiskService());
#pragma endregion ShrinkEngine

#pragma region TransactionEngine
	private:
		//Stack<LockControl> _transactions = new Stack<LockControl>();
		
		//// Get transaction stack count. If returns 0, there is no transaction.
		//int32_t TransactionCount{ get{ return _transactions.Count; } };

	public:
		// Starts a new transaction keeping all changed from now in memory only until Commit() be executed.
		// Lock thread in write mode to not accept other transaction
		void BeginTrans() noexcept;

		// Persist in disk all changed from last BeginTrans()
		// Returns true if real commit was done (false to nested commit only)
		bool Commit() noexcept;

		// Discard all changes from last BeginTrans()
		void Rollback() noexcept;

	private:
		//// Encapsulate all write transaction operation
		//private T Transaction<T>(std::string collection, bool addIfNotExists, Func<CollectionPage, T> action);
#pragma endregion TransactionEngine

#pragma region UpdateEngine
		public:
			// Implement update command to a document inside a collection. Returns true if document was updated
			bool Update(std::string collection, BsonDocument doc) noexcept;

			// Implement update command to a document inside a collection. Return number of documents updated
			int32_t Update(std::string collection, std::vector<BsonDocument> docs) noexcept;

		private:
			// Implement internal update document
			bool UpdateDocument(CollectionPage col, BsonDocument doc) noexcept;
#pragma endregion UpdateEngine

#pragma region UpsertEngine
	public:
		// Implement upsert command to documents in a collection. Calls update on all documents,
		// then any documents not updated are then attempted to insert.
		// This will have the side effect of throwing if duplicate items are attempted to be inserted. Returns true if document is inserted
		bool Upsert(std::string collection, BsonDocument doc) noexcept;

		// Implement upsert command to documents in a collection. Calls update on all documents,
		// then any documents not updated are then attempted to insert.
		// This will have the side effect of throwing if duplicate items are attempted to be inserted.
		int32_t Upsert(std::string collection, std::vector<BsonDocument> docs) noexcept;
#pragma endregion UpsertEngine

#pragma region UserVersionEngine
	public:
		// Get/Set User version internal database
		uint16_t getUserVersion() noexcept;
		void setUserVersion(uint16_t userVersion) noexcept;
#pragma endregion UserVersionEngine
	};
}