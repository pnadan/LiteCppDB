#include "stdafx.h"
#include "CollectionService.h"

namespace LiteCppDB
{
	CollectionService::CollectionService() noexcept
	{
	}

	CollectionService::CollectionService(const CollectionService & src) noexcept
	{
		this->_pager = src._pager;
		this->_indexer = src._indexer;
		this->_data = src._data;
		this->_trans = src._trans;
	}

	CollectionService & CollectionService::operator=(const CollectionService & rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		this->_pager = rhs._pager;
		this->_indexer = rhs._indexer;
		this->_data = rhs._data;
		this->_trans = rhs._trans;
		return *this;
	}

	CollectionService::CollectionService(const CollectionService && src) noexcept
	{
		this->_pager = src._pager;
		this->_indexer = src._indexer;
		this->_data = src._data;
		this->_trans = src._trans;
	}

	CollectionService & CollectionService::operator=(CollectionService && rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		this->_pager = rhs._pager;
		this->_indexer = rhs._indexer;
		this->_data = rhs._data;
		this->_trans = rhs._trans;
		return *this;
	}

	CollectionService::CollectionService(PageService pager, IndexService indexer, DataService data, TransactionService trans)
	{
		log("CollectionService(PageService pager, IndexService indexer, DataService data, TransactionService trans)");
		//pager = this._pager;
		//indexer = this._indexer;
		//data = this._data;
		//trans = this._trans;
		//log = this->_log;
	}

	CollectionPage CollectionService::Get(std::string name) noexcept
	{
		return CollectionPage();
	}

	CollectionPage CollectionService::Add(std::string name) noexcept
	{
		return CollectionPage();
	}

	std::vector<CollectionPage> CollectionService::GetAll() noexcept
	{
		return std::vector<CollectionPage>();
	}

	void CollectionService::Drop(CollectionPage col) noexcept
	{
	}
}