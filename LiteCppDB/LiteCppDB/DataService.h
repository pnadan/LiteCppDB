#pragma once

#include "PageService.h"
#include "CollectionPage.h"
#include "DataBlock.h"
#include "ExtendPage.h"

namespace LiteCppDB
{
	class DataService
	{
	private:
		PageService _pager;
		Logger _log;

	public:
		DataService() noexcept;

		DataService(PageService pager, Logger log) noexcept;

		// Insert data inside a datapage. Returns dataPageID that indicates the first page
		DataBlock Insert(CollectionPage col, std::vector<uint8_t> data) noexcept;

		// Update data inside a datapage. If new data can be used in same datapage, just update. Otherwise, copy content to a new ExtendedPage
		DataBlock Update(CollectionPage col, PageAddress blockAddress, std::vector<uint8_t> data) noexcept;

		// Read all data from datafile using a pageID as reference. If data is not in DataPage, read from ExtendPage.
		std::vector<uint8_t> Read(PageAddress blockAddress);

		// Get a data block from a DataPage using address
		DataBlock GetBlock(PageAddress blockAddress) noexcept;

		// Read all data from a extended page with all subsequences pages if exits
		std::vector<uint8_t> ReadExtendData(uint32_t extendPageID);

		// Delete one dataBlock
		DataBlock Delete(CollectionPage col, PageAddress blockAddress) noexcept;

		// Store all bytes in one extended page. If data ir bigger than a page, store in more pages and make all in sequence
		void StoreExtendData(ExtendPage page, std::vector<uint8_t> data) noexcept;
	};
}