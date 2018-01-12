#pragma once

#include "Query.h"
#include "IndexNode.h"
#include "CollectionIndex.h"
#include "CollectionService.h"

namespace LiteCppDB
{
	// Placeholder query for returning no values from a collection.
	class QueryEmpty : Query
	{
	public:
		// Initializes a new instance of the <see cref="QueryEmpty" /> class.
		QueryEmpty() noexcept;// : base("");

	private:
		std::vector<IndexNode> ExecuteIndex(IndexService indexer, CollectionIndex index) noexcept;
	};
}