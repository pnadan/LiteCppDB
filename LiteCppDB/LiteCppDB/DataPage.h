#pragma once

#include "BasePage.h"
#include "DataBlock.h"

#include <map>

namespace LiteCppDB
{
	// The DataPage thats stores object data.
	class DataPage : public BasePage
	{
	private:
		PageType mPageType;
		std::map<uint16_t, DataBlock> mDataBlocks;

	public:
		// Page type = Extend
		PageType getPageType() override;

		// If a Data Page has less that free space, it's considered full page for new items. Can be used only for update (DataPage) ~ 50% PAGE_AVAILABLE_BYTES
		// This value is used for minimize
		const int DATA_RESERVED_BYTES = PAGE_AVAILABLE_BYTES / 2;

		// Returns all data blocks - Each block has one object
		std::map<uint16_t, DataBlock> getDataBlocks();
		void setDataBlocks(std::map<uint16_t, DataBlock> dataBlocks);

		DataPage();
		DataPage(uint32_t pageID);

		// Update freebytes + items count
		void UpdateItemCount() override;

#pragma region Read / Write pages

	protected:
		void ReadContent(ByteReader reader) override;

		void WriteContent(ByteWriter writer) override;

#pragma endregion
	};
}