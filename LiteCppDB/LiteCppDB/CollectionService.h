#pragma once

#include "PageService.h"
#include "IndexService.h"
#include "DataService.h"
#include "TransactionService.h"

#include "CollectionPage.h"

namespace LiteCppDB
{
	class CollectionService
	{
	private:
		PageService _pager;
		IndexService _indexer;
		DataService _data;
		TransactionService _trans;

	public:

		CollectionService() noexcept;
		virtual ~CollectionService() noexcept {};

		CollectionService(const CollectionService& src) noexcept;
		virtual CollectionService& operator=(const CollectionService& rhs) noexcept;

		CollectionService(const CollectionService&& src) noexcept;
		virtual CollectionService& operator=(CollectionService&& rhs) noexcept;

		CollectionService(PageService pager, IndexService indexer, DataService data, TransactionService trans);

		// Get a exist collection. Returns null if not exists
		CollectionPage Get(std::string name) noexcept;

		// Add a new collection. Check if name the not exists
		CollectionPage Add(std::string name) noexcept;

		// Get all collections pages
		std::vector<CollectionPage> GetAll() noexcept;

		// Drop a collection - remove all data pages + indexes pages
		void Drop(CollectionPage col) noexcept;
	};
}