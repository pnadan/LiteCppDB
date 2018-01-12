#pragma once

#include "Query.h"
#include "IndexNode.h"
#include "IndexService.h"
#include "CollectionIndex.h"
#include "CollectionPage.h"

namespace LiteCppDB
{
	class QueryOr : Query
	{
	private:
		Query _left;
		Query _right;

	public:
		QueryOr(Query left, Query right) noexcept;// : base(null);

	private:
		//void IndexFactory(Action<std::string, std::string> createIndex);

		std::vector<IndexNode> ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept;

		std::vector<IndexNode> Run(CollectionPage col, IndexService indexer) noexcept;
	};
}