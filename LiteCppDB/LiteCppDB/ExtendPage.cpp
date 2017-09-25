#include "stdafx.h"

#include "ExtendPage.h"

namespace LiteCppDB
{
	// Page type = Extend
	PageType ExtendPage::getPageType()
	{
		return PageType::Extend;
	}

	// Represent the part or full of the object - if this page has NextPageID the object is bigger than this page
	std::vector<uint8_t> ExtendPage::getData()
	{
		return this->mData;
	}
	void ExtendPage::setData(std::vector<uint8_t> data)
	{
		this->mData = data;
	}

	ExtendPage::ExtendPage(uint32_t pageID)	/*: setPageID(pageID)*/
	{
		this->mData = std::vector<uint8_t>(0);
	}

	// Update freebytes + items count
	void ExtendPage::UpdateItemCount()
	{
		this->setItemCount((uint16_t)this->mData.size());
		this->setFreeBytes(PAGE_AVAILABLE_BYTES - std::any_cast<int32_t>(this->mData.size())); // not used on ExtendPage
	}

#pragma region Read / Write pages

	void ExtendPage::ReadContent(ByteReader reader)
	{
		this->mData = reader.ReadBytes(this->getItemCount());
	}

	void ExtendPage::WriteContent(ByteWriter writer)
	{
		writer.Write(this->mData);
	}

#pragma endregion
}