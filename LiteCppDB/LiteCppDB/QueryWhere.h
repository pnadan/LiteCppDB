#pragma once

#include "Query.h"
#include "IndexNode.h"
#include "IndexService.h"

namespace LiteCppDB
{
	// Execute an index scan passing a Func as where
	class QueryWhere : Query
	{
	private:
		/*Func<BsonValue, bool> _func;*/
		int32_t _order;

	public:
		/*QueryWhere(std::string field, Func<BsonValue, bool> func, int order) : base(field);*/

		std::vector<IndexNode> ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept;
	};
}