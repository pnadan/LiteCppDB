#pragma once

#include "BsonArray.h"

#include "IndexNode.h"
#include "IndexService.h"
#include "CollectionPage.h"

#ifdef LITECPPDB_EXPORTS
#define LITECPPDB_API __declspec(dllexport)
#else
#define LITECPPDB_API __declspec(dllimport)
#endif

namespace LiteCppDB
{
	// Class helper to create query using indexes in database. All methods are statics.
	// Queries can be executed in 2 ways: Index Seek (fast), Index Scan (good)
	class Query
	{
	private:
		std::string m_Field;

		//Action<std::string, string> _indexFactory = null;

		//// Set, only if not defined yet, a new factory to create index if nedded
		//internal virtual void IndexFactory(Action<string, string> indexFactory);

		void setField(std::string field) noexcept;

	public:

		std::string getField() noexcept;

		LITECPPDB_API Query() noexcept {};
		LITECPPDB_API Query(std::string field) { this->m_Field = field; };
		LITECPPDB_API virtual ~Query() noexcept {};

		LITECPPDB_API Query(const Query& src) noexcept;
		LITECPPDB_API virtual Query& operator=(const Query& rhs) noexcept;

		LITECPPDB_API Query(const Query&& src) noexcept;
		LITECPPDB_API virtual Query& operator=(Query&& rhs) noexcept;

#pragma region Static Methods

		// Indicate when a query must execute in ascending order
		LITECPPDB_API static const int32_t Ascending = 1;

		// Indicate when a query must execute in descending order
		LITECPPDB_API static const int32_t Descending = -1;

		// Returns all documents using _id index order
		LITECPPDB_API static Query All(int32_t order = Ascending) noexcept;

		// Returns all documents using field index order
		LITECPPDB_API static Query All(std::string field, int32_t order = Ascending) noexcept;

		// Returns all documents that value are equals to value (=)
		LITECPPDB_API static Query EQ(std::string field, BsonValue value) noexcept;

		// Returns all documents that value are less than value (&lt;)
		LITECPPDB_API static Query LT(std::string field, BsonValue value) noexcept;

		// Returns all documents that value are less than or equals value (&lt;=)
		LITECPPDB_API static Query LTE(std::string field, BsonValue value) noexcept;

		// Returns all document that value are greater than value (&gt;)
		LITECPPDB_API static Query GT(std::string field, BsonValue value) noexcept;

		// Returns all documents that value are greater than or equals value (&gt;=)
		LITECPPDB_API static Query GTE(std::string field, BsonValue value) noexcept;

		// Returns all document that values are between "start" and "end" values (BETWEEN)
		LITECPPDB_API static Query Between(std::string field, BsonValue start, BsonValue end) noexcept;

		// Returns all documents that starts with value (LIKE)
		LITECPPDB_API static Query StartsWith(std::string field, std::string value) noexcept;

		// Returns all documents that contains value (CONTAINS)
		LITECPPDB_API static Query Contains(std::string field, std::string value) noexcept;

		// Returns all documents that are not equals to value (not equals)
		LITECPPDB_API static Query Not(std::string field, BsonValue value) noexcept;

		// Returns all documents that in query result (not result)
		LITECPPDB_API static Query Not(Query query, int32_t order = Query::Ascending) noexcept;

		// Returns all documents that has value in values list (IN)
		LITECPPDB_API static Query In(std::string field, BsonArray value) noexcept;

		//// Returns all documents that has value in values list (IN)
		//static Query In(std::string field, params std::vector<BsonValue> values);

		//// Apply a predicate function in an index result. Execute full index scan but it's faster then runs over deserialized document.
		//static Query Where(std::string field, Func<BsonValue, bool> predicate, int32_t order = Query.Ascending);

		// Returns document that exists in BOTH queries results (Intersect).
		LITECPPDB_API static Query And(Query left, Query right) noexcept;

		// Returns documents that exists in ANY queries results (Union).
		LITECPPDB_API static Query Or(Query left, Query right) noexcept;

#pragma endregion Static Methods

#pragma region Execute Query

		// Abstract method that must be implement for index seek/scan - Returns IndexNodes that match with index
		LITECPPDB_API virtual std::vector<IndexNode> ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept;

		// Find witch index will be used and run Execute method
		LITECPPDB_API virtual std::vector<IndexNode> Run(CollectionPage col, IndexService indexer) noexcept;

#pragma endregion Execute Query
	};
}