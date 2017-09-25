#include "stdafx.h"

#include "CollectionIndex.h"

namespace LiteCppDB
{
	// Represent slot position on index array on dataBlock/collection indexes - non-persistable
	int32_t CollectionIndex::getSlot()
	{
		return this->mSlot;
	}
	void CollectionIndex::setSlot(int32_t slot)
	{
		this->mSlot = slot;
	}

	// Field name
	std::string CollectionIndex::getField()
	{
		return this->mField;
	}
	void CollectionIndex::setField(std::string field)
	{
		this->mField = field;
	}

	// Indicate if this index has distinct values only
	bool CollectionIndex::getUnique()
	{
		return this->mUnique;
	}
	void CollectionIndex::setUnique(bool unique)
	{
		this->mUnique = unique;
	}

	// Head page address for this index
	PageAddress CollectionIndex::getHeadNode()
	{
		return this->mHeadNode;
	}
	void CollectionIndex::setHeadNode(PageAddress headNode)
	{
		this->mHeadNode = headNode;
	}

	// A link pointer to tail node
	PageAddress CollectionIndex::getTailNode()
	{
		return this->mTailNode;
	}
	void CollectionIndex::setTailNode(PageAddress tailNode)
	{
		this->mTailNode = tailNode;
	}

	/// Get a reference for the free list index page - its private list per collection/index (must be a Field to be used as reference parameter)
	uint32_t CollectionIndex::getFreeIndexPageID()
	{
		return this->mFreeIndexPageID;
	}
	void CollectionIndex::setFreeIndexPageID(uint32_t freeIndexPageID)
	{
		this->mFreeIndexPageID = freeIndexPageID;
	}

	/// Returns if this index slot is empty and can be used as new index
	bool CollectionIndex::getIsEmpty()
	{
		return this->mField.empty();
	}

	CollectionIndex::CollectionIndex()
	{
		this->Clear();
	}

	// Clear all index information
	void CollectionIndex::Clear()
	{
		this->mField = std::string();
		this->mUnique = false;
		this->mHeadNode = PageAddress::getEmpty();
		this->mFreeIndexPageID = UINT32_MAX;
	}
}