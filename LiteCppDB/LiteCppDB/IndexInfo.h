#pragma once

#include "CollectionIndex.h"

namespace LiteCppDB
{
	// Represent a index information
	class IndexInfo
	{
	private:
		int32_t _Slot;
		std::string _Field;
		bool _Unique;

		IndexInfo(CollectionIndex index);

		void setSlot(int32_t slot) noexcept;

		void setField(std::string field) noexcept;

		void setUnique(bool unique) noexcept;

	public:
		// Slot number of index
		int32_t getSlot() noexcept;

		/// Field index name
		std::string getField() noexcept;

		/// Index is Unique?
		bool getUnique() noexcept;
	};
}