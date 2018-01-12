#pragma once

#include "Query.h"
#include "IndexNode.h"
#include "IndexService.h"
#include "CollectionIndex.h"
#include "CollectionPage.h"

namespace LiteCppDB
{
	// Not is an Index Scan operation
	class QueryNot : Query
	{
	private:
		Query _query;
		int32_t _order;

	public:
		QueryNot(Query query, int order) noexcept;// : base("_id");

	private:
		//void IndexFactory(Action<std::string, std::string> createIndex);

		std::vector<IndexNode> ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept;

		std::vector<IndexNode> Run(CollectionPage col, IndexService indexer) noexcept;
	};
}