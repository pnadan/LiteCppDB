#pragma once

#include <cstdint>
#include <vector>

#include "ByteReader.h"
#include "ByteWriter.h"

enum class PageType
{
	Empty = 0,
	Header = 1,
	Collection = 2,
	Index = 3,
	Data = 4,
	Extend = 5
};

namespace LiteCppDB
{
	class BasePage
	{
	private:

		uint32_t mPageID;
		PageType mPageType;
		uint32_t mPrevPageID;
		uint32_t mNextPageID;
		int32_t mItemCount;
		int32_t mFreeBytes;
		bool mIsDirty;
		std::vector<uint8_t> mDiskData;

	public:
#pragma region Page Constants

		// The size of each page in disk - 4096 is NTFS default
		static const int32_t PAGE_SIZE = 4096;

		// This size is used bytes in header pages 17 bytes (+8 reserved to future use) = 25 bytes
		static const int32_t PAGE_HEADER_SIZE = 25;

		// Bytes available to store data removing page header size - 4071 bytes
		static const int32_t PAGE_AVAILABLE_BYTES = PAGE_SIZE - PAGE_HEADER_SIZE;

#pragma endregion Page Constants

		// Represent page number - start in 0 with HeaderPage [4 bytes]
		uint32_t getPageID() noexcept;
		void setPageID(uint32_t pageID) noexcept;

		// Indicate the page type [1 byte] - Must be implemented for each page type
		virtual PageType getPageType() noexcept;

		// Represent the previous page. Used for page-sequences - MaxValue represent that has NO previous page [4 bytes]
		uint32_t getPrevPageID() noexcept;
		void setPrevPageID(uint32_t prevPageID) noexcept;

		//// Represent the next page. Used for page-sequences - MaxValue represent that has NO next page [4 bytes]
		uint32_t getNextPageID() noexcept;
		void setNextPageID(uint32_t nextPageID) noexcept;

		//// Used for all pages to count items inside this page(bytes, nodes, blocks, ...) [2 bytes]
		//// Its Int32 but writes in UInt16
		int32_t getItemCount() noexcept;
		void setItemCount(int32_t itemCount) noexcept;

		//// Used to find a free page using only header search [used in FreeList] [2 bytes]
		//// Its Int32 but writes in UInt16
		//// Its updated when a page modify content length (add/remove items)
		int32_t getFreeBytes() noexcept;
		void setFreeBytes(int32_t freeBytes) noexcept;

		//// Indicate that this page is dirty (was modified) and must persist when committed [not-persistable]
		bool getIsDirty() noexcept;
		void getIsDirty(bool isDirty) noexcept;

		//// This is the data when read first from disk - used to journal operations (IDiskService only will use)
		std::vector<uint8_t> getDiskData();
		void setDiskData(std::vector<uint8_t> diskData);

		BasePage() noexcept;
		virtual ~BasePage() {};

		// Copy constructor.
		BasePage(const BasePage& src) noexcept;
		// Move assigment.
		virtual BasePage& operator=(const BasePage& rhs) noexcept;

		// Move constructor.
		BasePage(const BasePage&& src) noexcept;
		// Move assigment.
		virtual BasePage& operator=(BasePage&& rhs) noexcept;
		
		BasePage(uint32_t pageID);

		//// Every page must implement this ItemCount + FreeBytes
		//// Must be called after Items are updates (insert/deletes) to keep variables ItemCount and FreeBytes synced
		virtual void UpdateItemCount() noexcept;

		//// Returns a size of specified number of pages
		static int64_t GetSizeOfPages(uint32_t pageCount);

		//// Returns a size of specified number of pages
		static int64_t GetSizeOfPages(int32_t pageCount);

#pragma region Read / Write page

		/// Create a new instance of page based on PageType
		static BasePage CreateInstance(uint32_t pageID, PageType pageType);

		/// Read a page with correct instance page object. Checks for pageType
		static BasePage ReadPage(std::vector<uint8_t> buffer);

		/// Write a page to byte array
		std::vector<uint8_t> WritePage();

	private:

		void ReadHeader(ByteReader reader);

		void WriteHeader(ByteWriter writer);

	protected:
		virtual void ReadContent(ByteReader reader) noexcept;

		virtual void WriteContent(ByteWriter writer) noexcept;

#pragma endregion
	};
}