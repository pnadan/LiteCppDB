#pragma once

#include "Query.h"
#include "IndexNode.h"
#include "IndexService.h"
#include "CollectionIndex.h"

namespace LiteCppDB
{
	class QueryStartsWith : Query
	{
	private:
		BsonValue _value;

	public:
		QueryStartsWith(std::string field, BsonValue value) noexcept; //: base(field);

	private:
		std::vector<IndexNode> ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept;
	};
}