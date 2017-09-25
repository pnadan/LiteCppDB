#pragma once

#include "BasePage.h"
#include "IndexNode.h"

#include <map>

namespace LiteCppDB
{
	class IndexPage : public BasePage
	{
	private:
		std::map<uint16_t, IndexNode> mNodes;

	public:
		// Page type = Index
		PageType getPageType() override;

		// If a Index Page has less that this free space, it's considered full page for new items.
		const int32_t INDEX_RESERVED_BYTES = 100;

		std::map<uint16_t, IndexNode> getNodes();
		void setNodes(std::map<uint16_t, IndexNode> nodes);

		IndexPage(uint32_t pageID);

		// Update freebytes + items count
		void UpdateItemCount() override;

#pragma region Read / Write pages

	protected:
		void ReadContent(ByteReader reader) override;

		void WriteContent(ByteWriter writer) override;

#pragma endregion Read / Write pages
	};
}