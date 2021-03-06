#pragma once

#include "PageAddress.h"
#include "BsonValue.h"
#include "CollectionIndex.h"

#include <vector>

namespace LiteCppDB
{
	// Represent a index node inside a Index Page
	class IndexNode
	{
	private:
		LiteCppDB::PageAddress mPosition;
		uint64_t mSlot;
		LiteCppDB::PageAddress mPrevNode;
		LiteCppDB::PageAddress mNextNode;
		std::vector<LiteCppDB::PageAddress> mPrev;
		std::vector<LiteCppDB::PageAddress> mNext;
		uint16_t mKeyLength;
		LiteCppDB::BsonValue mKey;
		LiteCppDB::PageAddress mDataBlock;

	public:
		const int32_t INDEX_NODE_FIXED_SIZE =   2 + // Position.Index (ushort)
												1 + // Levels (byte)
												2 + // ValueLength (ushort)
												1 + // BsonType (byte)
												1 + // Slot (1 byte)
												(PageAddress::SIZE * 2) + // Prev/Next Node (6 bytes)
												PageAddress::SIZE; // DataBlock

		// Max level used on skip list
		const int32_t MAX_LEVEL_LENGTH = 32;

		// Position of this node inside a IndexPage - Store only Position.Index
		PageAddress getPosition() noexcept;
		void setPosition(PageAddress position) noexcept;

		// Slot position of index in data block
		uint64_t getSlot() noexcept;
		void setSlot(uint64_t slot) noexcept;

		// Prev node in same document list index nodes
		PageAddress getPrevNode() noexcept;
		void setPrevNode(PageAddress prevNode) noexcept;

		// Next node in same document list index nodes
		PageAddress getNextNode() noexcept;
		void setNextNode(PageAddress nextNode) noexcept;

		// Link to prev value (used in skip lists - Prev.Length = Next.Length)
		std::vector<PageAddress> getPrev();
		void setPrev(int32_t index, PageAddress prev);

		// Link to next value (used in skip lists - Prev.Length = Next.Length)
		std::vector<PageAddress> getNext();
		void setNext(int32_t index, PageAddress next);

		// Length of key - used for calculate Node size
		uint16_t getKeyLength() noexcept;
		void setKeyLength(uint16_t keyLength) noexcept;

		// The object value that was indexed
		BsonValue getKey() noexcept;
		void setKey(BsonValue key) noexcept;

		// Reference for a datablock - the value
		PageAddress getDataBlock() noexcept;
		void setDataBlock(PageAddress dataBlock) noexcept;

		// Returns Next (order == 1) OR Prev (order == -1)
		PageAddress NextPrev(int32_t index, int32_t order) noexcept;

		// Returns if this node is header or tail from collection Index
		bool IsHeadTail(CollectionIndex index);

		// Get the length size of this node in disk - not persistable
		int32_t getLength();

		IndexNode(uint8_t level);
	};

	class IndexNodeComparer : public IndexNode
	{
	public:
		bool Equals(IndexNode x, IndexNode y);

		int32_t GetHashCode(IndexNode obj);
	};
}