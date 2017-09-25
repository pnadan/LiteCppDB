#include "stdafx.h"

#include "DataBlock.h"

namespace LiteCppDB
{
	// Position of this dataBlock inside a page (store only Position.Index)
	PageAddress DataBlock::getPosition()
	{
		return this->mPosition;
	}
	void DataBlock::setPosition(PageAddress position)
	{
		this->mPosition = position;
	}

	// If object is bigger than this page - use a ExtendPage (and do not use Data array)
	uint32_t DataBlock::getExtendPageID()
	{
		return this->mExtendPageID;
	}
	void DataBlock::setExtendPageID(uint32_t extendPageID)
	{
		this->mExtendPageID = extendPageID;
	}

	// Data of a record - could be empty if is used in ExtedPage
	std::vector<uint8_t> DataBlock::getData()
	{
		return this->mData;
	}
	void DataBlock::setData(std::vector<uint8_t> data)
	{
		this->mData = data;
	}

	// Get length of this dataBlock (persist as ushort 2 bytes)
	int32_t DataBlock::getLength()
	{
		return DataBlock::DATA_BLOCK_FIXED_SIZE + std::any_cast<int32_t>(this->getData().size());
	}

	DataBlock::DataBlock()
	{
		this->mPosition = PageAddress::getEmpty();
		this->mExtendPageID = UINT32_MAX;
		this->mData = std::vector<uint8_t>(0);
	}
}