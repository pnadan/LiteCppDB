#include "stdafx.h"

#include "DataPage.h"

namespace LiteCppDB
{
	// Page type = Extend
	PageType DataPage::getPageType()
	{
		return PageType::Data;
	}

	// Returns all data blocks - Each block has one object
	std::map<uint16_t, DataBlock> DataPage::getDataBlocks()
	{
		return this->mDataBlocks;
	}
	void DataPage::setDataBlocks(std::map<uint16_t, DataBlock> dataBlocks)
	{
		std::map<uint16_t, DataBlock>::iterator it = dataBlocks.begin();

		for (it = dataBlocks.begin(); it != dataBlocks.end(); it++)
		{
			this->mDataBlocks.insert(std::pair<uint16_t, DataBlock>(it->first, it->second));
		}
	}

	DataPage::DataPage()
	{
	}

	DataPage::DataPage(uint32_t pageID) : BasePage(pageID)
	{
	}

	// Update freebytes + items count
	void DataPage::UpdateItemCount()
	{
		this->setItemCount((uint16_t)this->mDataBlocks.size());
	}

#pragma region Read / Write pages

	void DataPage::ReadContent(ByteReader reader)
	{
		for (auto i = 0; i < this->getItemCount(); i++)
		{
			auto block = DataBlock();

			block.setPosition(PageAddress(this->getPageID(), reader.ReadUInt16()));
			block.setExtendPageID(reader.ReadUInt32());
			auto size = reader.ReadUInt16();
			block.setData(reader.ReadBytes(size));

			this->mDataBlocks.insert(std::pair<uint16_t, DataBlock>(block.getPosition().getIndex(), block));
		}
	}

	void DataPage::WriteContent(ByteWriter writer)
	{
		for_each(cbegin(this->mDataBlocks), cend(this->mDataBlocks), [&writer](std::pair<uint16_t, DataBlock>(dbs))
		{
			writer.Write(dbs.second.getPosition().getIndex());
			writer.Write(dbs.second.getExtendPageID());
			writer.Write(static_cast<uint16_t>(dbs.second.getData().size()));
			writer.Write(dbs.second.getData());
		});
	}

#pragma endregion
}