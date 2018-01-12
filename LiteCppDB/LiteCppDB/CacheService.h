#pragma once

#include "BasePage.h"

#include "IDiskService.h"

namespace LiteCppDB
{
	class CacheService
	{
	private:
		// Collection to store clean only pages in cache
		std::map<uint32_t, BasePage> _clean = std::map<uint32_t, BasePage>();

		// Collection to store dirty only pages in cache. If page was in _clean, remove from there and insert here
		std::map<uint32_t, BasePage> _dirty = std::map<uint32_t, BasePage>();

		IDiskService _disk;

	public:
		CacheService() noexcept;

		CacheService(IDiskService disk);

		// Get a page from cache or from disk (and put on cache)
		// [ThreadSafe]
		BasePage GetPage(uint32_t pageID) noexcept;

		// Add page to cache
		// [ThreadSafe]
		void AddPage(BasePage page) noexcept;

		// Set a page as dirty and ensure page are in cache. Should be used after any change on page 
		// Do not use on end of method because page can be deleted/change type
		// Always remove from clean list and add in dirty list
		// [ThreadSafe]
		void SetDirty(BasePage page) noexcept;

		// Return all dirty pages
		// [ThreadSafe]
		std::vector<BasePage> GetDirtyPages() noexcept;

		// Get how many pages are in clean cache
		int32_t getCleanUsed();// { return gsl::narrow_cast<int32_t>(_clean.count(1)); };

		// Get how many pages are in dirty cache
		int32_t getDirtyUsed();// { return gsl::narrow_cast<int32_t>(_dirty.count(1)); };

		// Discard only dirty pages
		// [ThreadSafe]
		void DiscardDirtyPages() noexcept;

		// Mark all dirty pages now as clean pages and transfer to clean collection
		// [ThreadSafe]
		void MarkDirtyAsClean() noexcept;

		// Remove from cache all clean pages
		// [Non - ThreadSafe]
		void ClearPages() noexcept;
	};
}