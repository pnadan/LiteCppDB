#pragma once

#include "PageAddress.h"

#include <string>
#include <regex>

namespace LiteCppDB
{
	class CollectionIndex
	{
	private:
		int mSlot;
		std::string mField;
		bool mUnique;
		PageAddress mHeadNode;
		PageAddress mTailNode;
		//CollectionPage mPage;
		uint32_t mFreeIndexPageID;

	public:
		//static std::regex IndexPattern("[\w - $\.] + $");

		// Total indexes per collection - it's fixed because I will used fixed arrays allocations
		static const int INDEX_PER_COLLECTION = 16;

		// Represent slot position on index array on dataBlock/collection indexes - non-persistable
		void setSlot(int32_t slot) noexcept;
		int getSlot() noexcept;

		// Field name
		void setField(std::string field);
		std::string getField();

		// Indicate if this index has distinct values only
		void setUnique(bool unique) noexcept;
		bool getUnique() noexcept;

		// Head page address for this index
		void setHeadNode(PageAddress headNode) noexcept;
		PageAddress getHeadNode() noexcept;

		// A link pointer to tail node
		void setTailNode(PageAddress tailNode) noexcept;
		PageAddress getTailNode() noexcept;

		// Get a reference for the free list index page - its private list per collection/index (must be a Field to be used as reference parameter)
		uint32_t getFreeIndexPageID() noexcept;
		void setFreeIndexPageID(uint32_t freeIndexPageID) noexcept;

		// Returns if this index slot is empty and can be used as new index
		bool getIsEmpty() noexcept;

		CollectionIndex() noexcept;
		virtual ~CollectionIndex() {};

		CollectionIndex(const CollectionIndex& src) noexcept;
		virtual CollectionIndex& operator=(const CollectionIndex& rhs) noexcept;

		CollectionIndex(const CollectionIndex&& src) noexcept;
		virtual CollectionIndex& operator=(CollectionIndex&& rhs) noexcept;

		// Clear all index information
		void Clear();
	};
}