#include "stdafx.h"

#include "CacheService.h"
#include <gsl\gsl>

namespace LiteCppDB
{
	CacheService::CacheService() noexcept
	{
		log("CacheService()");
	}

	CacheService::CacheService(IDiskService disk)
	{
		log("CacheService(IDiskService disk)");
		disk = this->_disk;
		
	}

	BasePage CacheService::GetPage(uint32_t pageID) noexcept
	{
		return BasePage();
	}

	void CacheService::AddPage(BasePage page) noexcept
	{
	}

	void CacheService::SetDirty(BasePage page) noexcept
	{
	}

	std::vector<BasePage> CacheService::GetDirtyPages() noexcept
	{
		return std::vector<BasePage>();
	}

	int32_t CacheService::getCleanUsed()
	{
		return gsl::narrow_cast<int32_t>(_clean.count(1));
	}

	int32_t CacheService::getDirtyUsed()
	{
		return gsl::narrow_cast<int32_t>(_dirty.count(1));
	}

	void CacheService::DiscardDirtyPages() noexcept
	{
	}

	void CacheService::MarkDirtyAsClean() noexcept
	{
	}

	void CacheService::ClearPages() noexcept
	{
	}

	void DiscardDirtyPages() noexcept
	{
	}

	void MarkDirtyAsClean() noexcept
	{
	}

	void ClearPages() noexcept
	{
	}
}