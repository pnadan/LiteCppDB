#pragma once

#include "PageService.h"
#include "Logger.h"

#include "CollectionPage.h"
#include "IndexNode.h"

namespace LiteCppDB
{
	// Implement a Index service - Add/Remove index nodes on SkipList
	// Based on: http://igoro.com/archive/skip-lists-are-fascinating/
	class IndexService
	{
	private:
		PageService _pager;
		Logger _log;
		//Random _rand = Random();

	public:
		// Max size of a index entry - usde for string, binary, array and documents
		const int32_t MAX_INDEX_LENGTH = 512;

		IndexService() noexcept;
		virtual ~IndexService() noexcept {};

		IndexService(const IndexService& src) noexcept;
		virtual IndexService& operator=(const IndexService& rhs) noexcept;

		IndexService(const IndexService&& src) noexcept;
		virtual IndexService& operator=(IndexService&& rhs) noexcept;

		IndexService(PageService pager, Logger log) noexcept;

		// Create a new index and returns head page address (skip list)
		CollectionIndex CreateIndex(CollectionPage col) noexcept;

		// Insert a new node index inside an collection index. Flip coin to know level
		IndexNode AddNode(CollectionIndex index, BsonValue key, IndexNode last);

	private:
		// Insert a new node index inside an collection index.
		IndexNode AddNode(CollectionIndex index, BsonValue key, uint8_t level, IndexNode last);

		// Gets all node list from any index node (go forward and backward)
		std::vector<IndexNode> GetNodeList(IndexNode node, bool includeInitial) noexcept;

		// Deletes an indexNode from a Index and adjust Next/Prev nodes
		void Delete(CollectionIndex index, PageAddress nodeAddress) noexcept;

		// Drop all indexes pages. Each index use a single page sequence
		void DropIndex(CollectionIndex index) noexcept;

		// Get a node inside a page using PageAddress - Returns null if address IsEmpty
		IndexNode GetNode(PageAddress address);

		// Flip coin - skip list - returns level node (start in 1)
		uint8_t FlipCoin() noexcept;

	public:

#pragma region Find

		std::vector<IndexNode> FindAll(CollectionIndex index, int order) noexcept;

		// Find first node that index match with value. If not found but sibling = true, returns near node (only non-unique index)
		// Before find, value must be normalized
		IndexNode Find(CollectionIndex index, BsonValue value, bool sibling, int order);

	private:
		// Goto the first/last occurrence of this index value
		IndexNode FindBoundary(CollectionIndex index, IndexNode cur, BsonValue value, int order, int level);

#pragma endregion Find
	};
}