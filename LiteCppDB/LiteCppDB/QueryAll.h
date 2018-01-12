#pragma once

#include "Query.h"

#include "IndexNode.h"
#include "IndexService.h"

#ifdef LITECPPDB_EXPORTS
#define LITECPPDB_API __declspec(dllexport)
#else
#define LITECPPDB_API __declspec(dllimport)
#endif

namespace LiteCppDB
{
	// All is an Index Scan operation
	class QueryAll : public Query
	{
	private:
		int32_t _order;

	public:
		LITECPPDB_API QueryAll(std::string field, int32_t order) noexcept;// : base(field);

		LITECPPDB_API std::vector<IndexNode> ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept override;
	};
}