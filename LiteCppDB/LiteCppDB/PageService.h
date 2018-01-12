#pragma once

#include "CacheService.h"
#include "BasePage.h"
#include "AesEncryption.h"

namespace LiteCppDB
{
	class PageService
	{
	private:
		CacheService _cache;
		IDiskService _disk;
		AesEncryption _crypto;
		Logger _log;

	public:
		PageService() noexcept;

		PageService(IDiskService disk, AesEncryption crypto, CacheService cache, Logger log) noexcept;

		// Get a page from cache or from disk (get from cache or from disk)
		/*T GetPage<T>(uint32_t pageID) where T : BasePage;*/

		// Set a page as dirty and ensure page are in cache. Should be used after any change on page 
		// Do not use on end of method because page can be deleted/change type
		void SetDirty(BasePage page) noexcept;

		// Read all sequences pages from a start pageID (using NextPageID)
		/*std::vector<T> GetSeqPages<T>(uint32_t firstPageID);*/

		// Get a new empty page - can be a reused page (EmptyPage) or a clean one (extend datafile)
		/*T NewPage<T>(BasePage prevPage = null) where T : BasePage;*/

		// Delete an page using pageID - transform them in Empty Page and add to EmptyPageList
		// If you delete a page, you can using same old instance of page - page will be converter to EmptyPage
		// If need deleted page, use GetPage again
		void DeletePage(uint32_t pageID, bool addSequence = false) noexcept;

		// Returns a page that contains space enough to data to insert new object - if one does not exit, creates a new page.
		/*T GetFreePage<T>(uint32_t startPageID, int size) where T : BasePage;*/

#pragma region Add Or Remove do empty list

		// Add or Remove a page in a sequence
		// <param name="add">Indicate that will add or remove from FreeList</param>
		// <param name="page">Page to add or remove from FreeList</param>
		// <param name="startPage">Page reference where start the header list node</param>
		//// <param name="fieldPageID">Field reference, from startPage</param>
		//void AddOrRemoveToFreeList(bool add, BasePage page, BasePage startPage, ref uint fieldPageID);

	private:
		// Add a page in free list in desc free size order
		//void AddToFreeList(BasePage page, BasePage startPage, ref uint fieldPageID);

		//// Remove a page from list - the ease part
		//void RemoveToFreeList(BasePage page, BasePage startPage, ref uint fieldPageID);

		//// When a page is already on a list it's more efficient just move comparing with siblings
		//void MoveToFreeList(BasePage page, BasePage startPage, ref uint fieldPageID);

#pragma endregion
	};
}