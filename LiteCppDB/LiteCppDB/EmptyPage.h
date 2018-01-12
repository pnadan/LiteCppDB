#pragma once

#include "BasePage.h"

namespace LiteCppDB
{
	// Represent a empty page (reused)
	class EmptyPage : public BasePage
	{
	public:
		// Page type = Empty
		PageType getPageType() noexcept override;

		EmptyPage(uint32_t pageID) noexcept;

		EmptyPage(BasePage page);

		// Update freebytes + items count
		void UpdateItemCount() noexcept override;

#pragma region Read / Write pages

	protected:
		void ReadContent(ByteReader reader) noexcept override;

		void WriteContent(ByteWriter writer) noexcept override;

#pragma endregion Read / Write pages
	};
}