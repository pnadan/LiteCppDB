#include "stdafx.h"
#include "PageAddress.h"

#include <limits>
#include <functional>

namespace LiteCppDB
{
	const PageAddress PageAddress::getEmpty()
	{
		return PageAddress(UINT32_MAX, UINT16_MAX);
	}
	// PageID (4 bytes)
	uint32_t PageAddress::getPageID()
	{
		return this->mPageID;
	}
	void PageAddress::setPageID(uint32_t pageID)
	{
		this->mPageID = pageID;
	}

	// Index inside page (2 bytes)
	uint16_t PageAddress::getIndex()
	{
		return this->mIndex;
	}
	void PageAddress::setIndex(uint16_t index)
	{
		this->mIndex = index;
	}

	bool PageAddress::getIsEmpty()
	{
		return this->mIsEmpty;
	}

	bool PageAddress::Equals(std::any obj)
	{
		const auto other = std::any_cast<PageAddress>(obj);
		return this->mPageID == other.mPageID && this->mIndex == other.mIndex;
	}

	int32_t PageAddress::GetHashCode()
	{
		return std::any_cast<int32_t>(std::hash<int32_t>{}(this->mPageID + this->mIndex));
	}

	PageAddress::PageAddress()
	{
		this->mIsEmpty = true;
		this->mPageID = 0;
		this->mIndex = 0;
	}

	PageAddress::PageAddress(uint32_t pageID, uint16_t index)
	{
		this->mIsEmpty = true;
		this->mPageID = pageID;
		this->mIndex = index;
	}

	std::string PageAddress::ToString()
	{
		return this->getIsEmpty() ? "----" : std::to_string(this->mPageID) + ":" + std::to_string(this->mIndex);
	}
}