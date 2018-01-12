#include "stdafx.h"

#include "IndexNode.h"

namespace LiteCppDB
{
	// Position of this node inside a IndexPage - Store only Position.Index
	PageAddress IndexNode::getPosition() noexcept
	{
		return this->mPosition;
	}
	void IndexNode::setPosition(PageAddress position) noexcept
	{
		this->mPosition = position;
	}

	/// Slot position of index in data block
	uint64_t IndexNode::getSlot() noexcept
	{
		return this->mSlot;
	}
	void IndexNode::setSlot(uint64_t slot) noexcept
	{
		this->mSlot = slot;
	}

	// Prev node in same document list index nodes
	PageAddress IndexNode::getPrevNode() noexcept
	{
		return this->mPrevNode;
	}
	void IndexNode::setPrevNode(PageAddress prevNode) noexcept
	{
		this->mPrevNode = prevNode;
	}

	// Next node in same document list index nodes
	PageAddress IndexNode::getNextNode() noexcept
	{
		return this->mNextNode;
	}
	void IndexNode::setNextNode(PageAddress nextNode) noexcept
	{
		this->mNextNode = nextNode;
	}

	// Link to prev value (used in skip lists - Prev.Length = Next.Length)
	std::vector<PageAddress> IndexNode::getPrev()
	{
		return this->mPrev;
	}
	void IndexNode::setPrev(int32_t index, PageAddress prev)
	{
		this->mPrev.at(index) = prev;
	}

	// Link to next value (used in skip lists - Prev.Length = Next.Length)
	std::vector<PageAddress> IndexNode::getNext()
	{
		return this->mNext;
	}
	void IndexNode::setNext(int32_t index, PageAddress next)
	{
		this->mNext.at(index) = next;
	}

	// Length of key - used for calculate Node size
	uint16_t IndexNode::getKeyLength() noexcept
	{
		return this->mKeyLength;
	}
	void IndexNode::setKeyLength(uint16_t keyLength) noexcept
	{
		this->mKeyLength = keyLength;
	}

	// The object value that was indexed
	BsonValue IndexNode::getKey() noexcept
	{
		return this->mKey;
	}
	void IndexNode::setKey(BsonValue key) noexcept
	{
		this->mKey = key;
	}

	// Reference for a datablock - the value
	PageAddress IndexNode::getDataBlock() noexcept
	{
		return this->mDataBlock;
	}
	void IndexNode::setDataBlock(PageAddress dataBlock) noexcept
	{
		this->mDataBlock = dataBlock;
	}

	// Returns Next (order == 1) OR Prev (order == -1)
	PageAddress IndexNode::NextPrev(int32_t index, int32_t order) noexcept
	{
		PageAddress pa;
		return pa;// order == Query.Ascending ? this.Next[index] : this.Prev[index];
	}

	// Returns if this node is header or tail from collection Index
	bool IndexNode::IsHeadTail(CollectionIndex index)
	{
		return this->mPosition.Equals(index.getHeadNode()) || this->mPosition.Equals(index.getTailNode());
	}

	/// Get the length size of this node in disk - not persistable
	int32_t IndexNode::getLength()
	{
		return IndexNode::INDEX_NODE_FIXED_SIZE +
			(std::any_cast<int32_t>(this->mPrev.size()) * PageAddress::SIZE * 2) + // Prev + Next
			this->mKeyLength; // bytes count in BsonValue
	}

	IndexNode::IndexNode(uint8_t level)
	{
		this->mKeyLength = 0;
		this->mSlot = 0;
		this->mPosition = PageAddress::getEmpty();
		this->mPrevNode = PageAddress::getEmpty();
		this->mNextNode = PageAddress::getEmpty();
		this->mDataBlock = PageAddress::getEmpty();

		for (auto i = 0; i < level; i++)
		{
			this->mPrev[i] = PageAddress::getEmpty();
			this->mNext[i] = PageAddress::getEmpty();
		}
	}

	bool IndexNodeComparer::Equals(IndexNode x, IndexNode y)
	{
		if (&x == nullptr || &y == nullptr)
			return false;

		return x.getDataBlock().Equals(y.getDataBlock());
	}

	int32_t IndexNodeComparer::GetHashCode(IndexNode obj)
	{
		return obj.getDataBlock().GetHashCode();
	}
}