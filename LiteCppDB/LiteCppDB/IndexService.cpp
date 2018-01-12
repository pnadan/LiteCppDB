#include "stdafx.h"
#include "IndexService.h"

namespace LiteCppDB
{
	IndexService::IndexService() noexcept
	{
	}

	IndexService::IndexService(PageService pager, Logger log) noexcept
	{
	}

	IndexService::IndexService(const IndexService & src) noexcept
	{
		this->_pager = src._pager;
		this->_log = src._log;
	}

	IndexService & IndexService::operator=(const IndexService & rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		this->_pager = rhs._pager;
		this->_log = rhs._log;
		return *this;
	}

	IndexService::IndexService(const IndexService && src) noexcept
	{
		this->_pager = src._pager;
		this->_log = src._log;
	}

	IndexService & IndexService::operator=(IndexService && rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		this->_pager = rhs._pager;
		this->_log = rhs._log;
		return *this;
	}

	CollectionIndex IndexService::CreateIndex(CollectionPage col) noexcept
	{
		return CollectionIndex();
	}

	IndexNode IndexService::AddNode(CollectionIndex index, BsonValue key, IndexNode last)
	{
		return IndexNode(0);
	}

	IndexNode IndexService::AddNode(CollectionIndex index, BsonValue key, uint8_t level, IndexNode last)
	{
		return IndexNode(0);
	}

	std::vector<IndexNode> IndexService::GetNodeList(IndexNode node, bool includeInitial) noexcept
	{
		return std::vector<IndexNode>();
	}

	void IndexService::Delete(CollectionIndex index, PageAddress nodeAddress) noexcept
	{
	}

	void IndexService::DropIndex(CollectionIndex index) noexcept
	{
	}

	IndexNode IndexService::GetNode(PageAddress address)
	{
		return IndexNode(0);
	}

	uint8_t IndexService::FlipCoin() noexcept
	{
		return uint8_t();
	}

	std::vector<IndexNode> IndexService::FindAll(CollectionIndex index, int order) noexcept
	{
		return std::vector<IndexNode>();
	}

	IndexNode IndexService::Find(CollectionIndex index, BsonValue value, bool sibling, int order)
	{
		return IndexNode(0);
	}

	IndexNode IndexService::FindBoundary(CollectionIndex index, IndexNode cur, BsonValue value, int order, int level)
	{
		return IndexNode(0);
	}
}