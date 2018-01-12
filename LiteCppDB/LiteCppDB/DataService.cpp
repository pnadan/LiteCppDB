#include "stdafx.h"
#include "DataService.h"

namespace LiteCppDB
{
	DataService::DataService() noexcept
	{
	}

	DataService::DataService(PageService pager, Logger log) noexcept
	{
	}

	DataBlock DataService::Insert(CollectionPage col, std::vector<uint8_t> data) noexcept
	{
		return DataBlock();
	}

	DataBlock DataService::Update(CollectionPage col, PageAddress blockAddress, std::vector<uint8_t> data) noexcept
	{
		return DataBlock();
	}

	std::vector<uint8_t> DataService::Read(PageAddress blockAddress)
	{
		return std::vector<uint8_t>();
	}

	DataBlock DataService::GetBlock(PageAddress blockAddress) noexcept
	{
		return DataBlock();
	}

	std::vector<uint8_t> DataService::ReadExtendData(uint32_t extendPageID)
	{
		return std::vector<uint8_t>();
	}

	DataBlock DataService::Delete(CollectionPage col, PageAddress blockAddress) noexcept
	{
		return DataBlock();
	}

	void DataService::StoreExtendData(ExtendPage page, std::vector<uint8_t> data) noexcept
	{
	}
}