#pragma once

#include "BasePage.h"

namespace LiteCppDB
{
	// Represent a extra data page that contains the object when is not possible store in DataPage (bigger then  PAGE_SIZE or on update has no more space on page)
	// Can be used in sequence of pages to store big objects
	class ExtendPage : public BasePage
	{
	private:
		std::vector<uint8_t> mData;

	public:
		// Page type = Extend
		PageType getPageType() noexcept override;

		// Represent the part or full of the object - if this page has NextPageID the object is bigger than this page
		std::vector<uint8_t> getData()  noexcept;
		void setData(std::vector<uint8_t> data);

		ExtendPage(uint32_t pageID);

		// Update freebytes + items count
		void UpdateItemCount() noexcept override;

#pragma region Read / Write pages

	protected:
		void ReadContent(ByteReader reader) noexcept override;

		void WriteContent(ByteWriter writer) noexcept override;

#pragma endregion
	};
}