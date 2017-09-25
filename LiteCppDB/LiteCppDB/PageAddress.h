#pragma once

#include <any>
#include <limits>
#include <string>

namespace LiteCppDB
{
	// Represents a page address inside a page structure - index could be byte offset position OR index in a list (6 bytes)
	class PageAddress
	{
	private:
		uint32_t mPageID;
		uint16_t mIndex;
		bool mIsEmpty;

	public:
		const static int32_t SIZE = 6;

		const static PageAddress PageAddress::getEmpty();

		// PageID (4 bytes)
		uint32_t getPageID();
		void setPageID(uint32_t pageID);

		// Index inside page (2 bytes)
		uint16_t getIndex();
		void setIndex(uint16_t index);

		bool getIsEmpty();

		bool Equals(std::any obj);

		int32_t GetHashCode();

		PageAddress();
		PageAddress(uint32_t pageID, uint16_t index);

		std::string ToString();
	};
}