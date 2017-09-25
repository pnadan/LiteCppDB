#include "stdafx.h"

#include "EmptyPage.h"

namespace LiteCppDB
{
	/// Page type = Empty
	PageType EmptyPage::getPageType()
	{
		return PageType::Empty;
	}

	EmptyPage::EmptyPage(uint32_t pageID) /*: setPageID(pageID)*/
	{
		this->setItemCount(0);
		this->setFreeBytes(PAGE_AVAILABLE_BYTES);
	}

	EmptyPage::EmptyPage(BasePage page) : BasePage(page.getPageID())/*: page.setPageID(page)*/
	{
		if (page.getDiskData().size() > 0)
		{
			this->setDiskData(std::vector<uint8_t>(BasePage::PAGE_SIZE));
		}
	}

	/// Update freebytes + items count
	void EmptyPage::UpdateItemCount()
	{
		this->setItemCount(0);
		this->setFreeBytes(PAGE_AVAILABLE_BYTES);
	}

#pragma region Read / Write pages

	void EmptyPage::ReadContent(ByteReader reader)
	{
	}

	void EmptyPage::WriteContent(ByteWriter writer)
	{
	}

#pragma endregion Read / Write pages
}