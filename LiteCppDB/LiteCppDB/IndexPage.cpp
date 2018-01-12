#include "stdafx.h"

#include "IndexPage.h"
#include <gsl\gsl>

namespace LiteCppDB
{
	// Page type = Index
	PageType IndexPage::getPageType() noexcept
	{
		return PageType::Index;
	}

	std::map<uint16_t, IndexNode> IndexPage::getNodes()
	{
		return this->mNodes;
	}
	void IndexPage::setNodes(std::map<uint16_t, IndexNode> nodes)
	{
		this->mNodes = nodes;
	}

	IndexPage::IndexPage(uint32_t pageID)
	{
		this->mNodes = std::map<uint16_t, IndexNode>();
	}

	// Update freebytes + items count
	void IndexPage::UpdateItemCount() noexcept
	{
		this->setItemCount(std::any_cast<int32_t>(this->mNodes.size()));
	}

#pragma region Read / Write pages

	void IndexPage::ReadContent(ByteReader reader) noexcept
	{
		this->mNodes = std::map<uint16_t, IndexNode>();

		for (auto i = 0; i < this->getItemCount(); i++)
		{
			const auto index = reader.ReadUInt16();
			const auto levels = reader.ReadByte();

			auto node = IndexNode(levels);

			//node->setPage(*this);
			node.setPosition(PageAddress(this->getPageID(), index));
			node.setSlot(reader.ReadByte());
			node.setPrevNode(reader.ReadPageAddress());
			node.setNextNode(reader.ReadPageAddress());
			node.setKeyLength(reader.ReadUInt16());
			node.setKey(reader.ReadBsonValue(node.getKeyLength()));
			node.setDataBlock(reader.ReadPageAddress());
			
			for (int32_t j = 0; j < static_cast<int32_t>(node.getPrev().size()); j++)
			{
				node.setPrev(j, reader.ReadPageAddress());
				node.setNext(j, reader.ReadPageAddress());
			}

			this->mNodes.insert(std::pair<uint16_t, IndexNode>(node.getPosition().getIndex(), node));
		}
	}

	void IndexPage::WriteContent(ByteWriter writer) noexcept
	{
		for_each(cbegin(this->mNodes), cend(this->mNodes), [&writer](std::pair<uint16_t, IndexNode>(n))
		{
			writer.Write(n.second.getPosition().getIndex()); // node Index on this page
			writer.Write(gsl::narrow_cast<int32_t>(n.second.getPrev().size())); // level length
			writer.Write(n.second.getSlot()); // index slot
			writer.Write(n.second.getPrevNode()); // prev node list
			writer.Write(n.second.getNextNode()); // next node list
			writer.Write(n.second.getKeyLength()); // valueLength
			writer.WriteBsonValue(n.second.getKey(), n.second.getKeyLength()); // value
			writer.Write(n.second.getDataBlock()); // data block reference

			for (auto j = 0; j < n.second.getPrev().size(); j++)
			{
				writer.Write(n.second.getPrev().at(j));
				writer.Write(n.second.getNext().at(j));
			}
		});
	}

#pragma endregion Read / Write pages
}