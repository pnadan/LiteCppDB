#pragma once

#include "Query.h"

#include "IndexNode.h"
#include "IndexService.h"
#include "CollectionPage.h"

namespace LiteCppDB
{
	class QueryAnd : Query
	{
	private:
		Query _left;
		Query _right;

	public:
		QueryAnd(Query left, Query right) noexcept;// : base(null);

		QueryAnd() noexcept {};
		~QueryAnd() {};
		
		QueryAnd(const QueryAnd& src) noexcept;
		virtual QueryAnd& operator=(const QueryAnd& rhs) noexcept;

		QueryAnd(const QueryAnd&& src) noexcept;
		virtual QueryAnd& operator=(QueryAnd&& rhs) noexcept;

		//void IndexFactory(Action<string, string> createIndex);

		std::vector<IndexNode> ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept;

		std::vector<IndexNode> Run(CollectionPage col, IndexService indexer) noexcept;
	};
}