#include "stdafx.h"

#include "BasePage.h"

#include "CollectionPage.h"
#include "IndexPage.h"
#include "DataPage.h"
#include "ExtendPage.h"
#include "EmptyPage.h"
#include "HeaderPage.h"

namespace LiteCppDB
{
	// Represent page number - start in 0 with HeaderPage [4 bytes]
	uint32_t BasePage::getPageID() noexcept
	{
		return this->mPageID;
	}
	void BasePage::setPageID(uint32_t basePage) noexcept
	{
		this->mPageID = basePage;
	}

	// Indicate the page type [1 byte] - Must be implemented for each page type
	PageType BasePage::getPageType() noexcept
	{
		return this->mPageType;
	}

	// Represent the previous page. Used for page-sequences - MaxValue represent that has NO previous page [4 bytes]
	uint32_t BasePage::getPrevPageID() noexcept
	{
		return this->mPrevPageID;
	}
	void BasePage::setPrevPageID(uint32_t prevPageID) noexcept
	{
		this->mPrevPageID = prevPageID;
	}

	// Represent the next page. Used for page-sequences - MaxValue represent that has NO next page [4 bytes]
	uint32_t BasePage::getNextPageID() noexcept
	{
		return this->mNextPageID;
	}
	void BasePage::setNextPageID(uint32_t nextPageID) noexcept
	{
		this->mNextPageID = nextPageID;
	}

	// Used for all pages to count items inside this page(bytes, nodes, blocks, ...) [2 bytes]
	// Its Int32 but writes in UInt16
	int32_t BasePage::getItemCount() noexcept
	{
		return this->mItemCount;
	}
	void BasePage::setItemCount(int32_t itemCount) noexcept
	{
		this->mItemCount = itemCount;
	}


	// Used to find a free page using only header search [used in FreeList] [2 bytes]
	// Its Int32 but writes in UInt16
	// Its updated when a page modify content length (add/remove items)
	int32_t BasePage::getFreeBytes() noexcept
	{
		return this->mFreeBytes;
	}
	void BasePage::setFreeBytes(int32_t freeBytes) noexcept
	{
		this->mFreeBytes = freeBytes;
	}

	// Indicate that this page is dirty (was modified) and must persist when committed [not-persistable]
	bool BasePage::getIsDirty() noexcept
	{
		return this->mIsDirty;
	}
	void BasePage::getIsDirty(bool isDirty) noexcept
	{
		this->mIsDirty = isDirty;
	}

	/// This is the data when read first from disk - used to journal operations (IDiskService only will use)
	std::vector<uint8_t> BasePage::getDiskData()
	{
		return this->mDiskData;
	}
	void BasePage::setDiskData(std::vector<uint8_t> diskData)
	{
		this->mDiskData = diskData;
	}

	BasePage::BasePage() noexcept
	{
		BasePage(0);
	}

	BasePage::BasePage(const BasePage& src) noexcept
	{
		this->mPageID = src.mPageID;
		this->mFreeBytes = src.mFreeBytes;
		this->mDiskData = src.mDiskData;
		this->mIsDirty = src.mIsDirty;
		this->mItemCount = src.mItemCount;
		this->mNextPageID = src.mNextPageID;
		this->mPageType = src.mPageType;
		this->mPrevPageID = src.mPrevPageID;
	}

	BasePage& BasePage::operator=(const BasePage& rhs) noexcept
	{
		// TODO: insert return statement here
		if (this == &rhs)
		{
			return *this;
		}

		this->mPageID = rhs.mPageID;
		this->mFreeBytes = rhs.mFreeBytes;
		this->mDiskData = rhs.mDiskData;
		this->mIsDirty = rhs.mIsDirty;
		this->mItemCount = rhs.mItemCount;
		this->mNextPageID = rhs.mNextPageID;
		this->mPageType = rhs.mPageType;
		this->mPrevPageID = rhs.mPrevPageID;
		return *this;
	}

	BasePage::BasePage(const BasePage&& src) noexcept
	{
		this->mPageID = src.mPageID;
		this->mFreeBytes = src.mFreeBytes;
		this->mDiskData = src.mDiskData;
		this->mIsDirty = src.mIsDirty;
		this->mItemCount = src.mItemCount;
		this->mNextPageID = src.mNextPageID;
		this->mPageType = src.mPageType;
		this->mPrevPageID = src.mPrevPageID;
	}

	BasePage& BasePage::operator=(BasePage&& rhs) noexcept
	{
		// TODO: insert return statement here
		if (this == &rhs)
		{
			return *this;
		}

		this->mPageID = rhs.mPageID;
		this->mFreeBytes = rhs.mFreeBytes;
		this->mDiskData = rhs.mDiskData;
		this->mIsDirty = rhs.mIsDirty;
		this->mItemCount = rhs.mItemCount;
		this->mNextPageID = rhs.mNextPageID;
		this->mPageType = rhs.mPageType;
		this->mPrevPageID = rhs.mPrevPageID;
		return *this;
	}

	BasePage::BasePage(uint32_t pageID)
	{
		this->mPageID = pageID;
		this->mPrevPageID = UINT32_MAX;
		this->mNextPageID = UINT32_MAX;
		this->mItemCount = 0;
		this->mFreeBytes = PAGE_AVAILABLE_BYTES;
		this->mDiskData = std::vector<uint8_t>{ 0 };
		this->mIsDirty = false;
		this->mPageType = PageType::Empty;
	}

	void BasePage::UpdateItemCount() noexcept
	{
	}

	// Returns a size of specified number of pages
	int64_t BasePage::GetSizeOfPages(uint32_t pageCount)
	{
		if ((double)pageCount <= 1.0 + (std::any_cast<double>(INT64_MAX) / std::any_cast<double>(BasePage::PAGE_SIZE)))
			throw std::exception("OverflowException");
		else
			return (pageCount) * BasePage::PAGE_SIZE;
	}

	// Returns a size of specified number of pages
	int64_t BasePage::GetSizeOfPages(int32_t pageCount)
	{
		if (pageCount < 0) throw std::exception("ArgumentOutOfRangeException(\"pageCount\", \"Could not be less than 0.\")");

		return BasePage::GetSizeOfPages(pageCount);
	}

#pragma region Read / Write page

	/// Create a new instance of page based on PageType
	BasePage BasePage::CreateInstance(uint32_t pageID, PageType pageType)
	{
		switch (pageType)
		{
		case PageType::Collection: return CollectionPage(pageID);
		case PageType::Index: return IndexPage(pageID);
		case PageType::Data: return DataPage(pageID);
		case PageType::Extend: return ExtendPage(pageID);
		case PageType::Empty: return EmptyPage(pageID);
		// use Header as default, because header page will read fixed HEADER_INFO and validate file format (if is not valid datafile)
		default: return HeaderPage();
		}
	}

	/// Read a page with correct instance page object. Checks for pageType
	BasePage BasePage::ReadPage(std::vector<uint8_t> buffer)
	{
		auto reader = ByteReader(buffer);

		const auto pageID = reader.ReadUInt32();
		const auto pageType = static_cast<PageType>(reader.ReadByte());

		if (pageID == 0 && static_cast<int32_t>(pageType) > 5)
		{
			throw std::exception("LiteException.InvalidDatabase()");
		}

		auto page = CreateInstance(pageID, pageType);

		page.ReadHeader(reader);
		page.ReadContent(reader);

		page.setDiskData(buffer);

		return page;
	}

	/// Write a page to byte array
	std::vector<uint8_t> BasePage::WritePage()
	{
		auto writer = ByteWriter(BasePage::PAGE_SIZE);

		this->WriteHeader(writer);

		if (this->mPageType != PageType::Empty)
		{
			this->WriteContent(writer);
		}

		// update data bytes
		this->mDiskData = writer.getBuffer();

		return writer.getBuffer();
	}

	void BasePage::ReadHeader(ByteReader reader)
	{
		// first 5 bytes (pageID + pageType) was readed before class create

		this->mPrevPageID = reader.ReadUInt32();
		this->mNextPageID = reader.ReadUInt32();
		this->mItemCount = reader.ReadUInt16();
		this->mFreeBytes = reader.ReadUInt16();
		reader.Skip(8); // reserved 8 bytes
	}

	void BasePage::WriteHeader(ByteWriter writer)
	{
		writer.Write(this->mPageID);
		writer.Write(static_cast<uint8_t>(this->mPageType));

		writer.Write(this->mPrevPageID);
		writer.Write(this->mNextPageID);
		writer.Write(this->mItemCount);
		writer.Write(this->mFreeBytes);
		writer.Skip(8); // reserved 8 bytes
	}

	void BasePage::ReadContent(ByteReader reader) noexcept
	{
	}

	void BasePage::WriteContent(ByteWriter writer) noexcept
	{
	}

#pragma endregion
}