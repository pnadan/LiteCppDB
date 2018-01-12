#include "stdafx.h"

#include "CollectionIndex.h"

namespace LiteCppDB
{
	CollectionIndex::CollectionIndex(const CollectionIndex& src) noexcept
	{
		this->mField = src.mField;
		this->mFreeIndexPageID = src.mFreeIndexPageID;
		this->mHeadNode = src.mHeadNode;
		this->mSlot = src.mSlot;
		this->mTailNode = src.mTailNode;
		this->mUnique = src.mUnique;
	}

	CollectionIndex& CollectionIndex::operator=(const CollectionIndex& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		this->mField = rhs.mField;
		this->mFreeIndexPageID = rhs.mFreeIndexPageID;
		this->mHeadNode = rhs.mHeadNode;
		this->mSlot = rhs.mSlot;
		this->mTailNode = rhs.mTailNode;
		this->mUnique = rhs.mUnique;
		return *this;
	}

	CollectionIndex::CollectionIndex(const CollectionIndex&& src) noexcept
	{
		this->mField = src.mField;
		this->mFreeIndexPageID = src.mFreeIndexPageID;
		this->mHeadNode = src.mHeadNode;
		this->mSlot = src.mSlot;
		this->mTailNode = src.mTailNode;
		this->mUnique = src.mUnique;
	}

	CollectionIndex& CollectionIndex::operator=(CollectionIndex&& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		this->mField = rhs.mField;
		this->mFreeIndexPageID = rhs.mFreeIndexPageID;
		this->mHeadNode = rhs.mHeadNode;
		this->mSlot = rhs.mSlot;
		this->mTailNode = rhs.mTailNode;
		this->mUnique = rhs.mUnique;
		return *this;
	}

	// Represent slot position on index array on dataBlock/collection indexes - non-persistable
	int32_t CollectionIndex::getSlot() noexcept
	{
		return this->mSlot;
	}
	void CollectionIndex::setSlot(int32_t slot) noexcept
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
	bool CollectionIndex::getUnique() noexcept
	{
		return this->mUnique;
	}
	void CollectionIndex::setUnique(bool unique) noexcept
	{
		this->mUnique = unique;
	}

	// Head page address for this index
	PageAddress CollectionIndex::getHeadNode() noexcept
	{
		return this->mHeadNode;
	}
	void CollectionIndex::setHeadNode(PageAddress headNode) noexcept
	{
		this->mHeadNode = headNode;
	}

	// A link pointer to tail node
	PageAddress CollectionIndex::getTailNode() noexcept
	{
		return this->mTailNode;
	}
	void CollectionIndex::setTailNode(PageAddress tailNode) noexcept
	{
		this->mTailNode = tailNode;
	}

	/// Get a reference for the free list index page - its private list per collection/index (must be a Field to be used as reference parameter)
	uint32_t CollectionIndex::getFreeIndexPageID() noexcept
	{
		return this->mFreeIndexPageID;
	}
	void CollectionIndex::setFreeIndexPageID(uint32_t freeIndexPageID) noexcept
	{
		this->mFreeIndexPageID = freeIndexPageID;
	}

	/// Returns if this index slot is empty and can be used as new index
	bool CollectionIndex::getIsEmpty() noexcept
	{
		return this->mField.empty();
	}

	CollectionIndex::CollectionIndex() noexcept
	{
		this->mFreeIndexPageID = 0;
		this->mUnique = false;
		this->mSlot = 0;
		this->Clear();
	}

	// Clear all index information
	void CollectionIndex::Clear()
	{
		this->mField = std::string();
		this->mUnique = false;
		this->mHeadNode = PageAddress::getEmpty();
		this->mFreeIndexPageID = UINT32_MAX;
		this->mSlot = 0;
	}
}