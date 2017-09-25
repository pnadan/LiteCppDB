#pragma once

#include "PageAddress.h"
//#include "DataPage.h"

#include <vector>

namespace LiteCppDB
{
	class DataBlock
	{
	private:
		PageAddress mPosition;
		/*DataPage mPage;*/
		std::vector<uint8_t> mData;
		uint32_t mExtendPageID;
		int32_t mLength;

	public:
		const int DATA_BLOCK_FIXED_SIZE =   2 + // Position.Index (ushort)
											4 + // ExtendedPageID (uint)
											2; // block.Data.Length (ushort)

		// Position of this dataBlock inside a page (store only Position.Index)
		PageAddress getPosition();
		void setPosition(PageAddress position);

		// If object is bigger than this page - use a ExtendPage (and do not use Data array)
		uint32_t getExtendPageID();
		void setExtendPageID(uint32_t extendPageID);

		// Data of a record - could be empty if is used in ExtedPage
		std::vector<uint8_t> getData();
		void setData(std::vector<uint8_t> data);

		// Get length of this dataBlock (persist as ushort 2 bytes)
		int32_t getLength();

		DataBlock();
	};
}