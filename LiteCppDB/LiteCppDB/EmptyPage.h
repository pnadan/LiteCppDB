#pragma once

#include "BasePage.h"

namespace LiteCppDB
{
	// Represent a empty page (reused)
	class EmptyPage : public BasePage
	{
	public:
		// Page type = Empty
		PageType getPageType() override;

		EmptyPage(uint32_t pageID);

		EmptyPage(BasePage page);

		// Update freebytes + items count
		void UpdateItemCount() override;

#pragma region Read / Write pages

	protected:
		void ReadContent(ByteReader reader) override;

		void WriteContent(ByteWriter writer) override;

#pragma endregion Read / Write pages
	};
}