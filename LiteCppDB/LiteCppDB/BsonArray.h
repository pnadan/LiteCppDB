#pragma once

#include "BsonValue.h"

#include <vector>

namespace LiteCppDB
{
	class BsonArray : public BsonValue
	{
	private:
		std::vector<BsonValue> mBsonArray;

	public:
		BsonArray() noexcept;
		virtual ~BsonArray() noexcept {};

		BsonArray(const BsonArray& src) noexcept;
		virtual BsonArray& operator=(const BsonArray& rhs) noexcept;

		BsonArray(const BsonArray&& src) noexcept;
		virtual BsonArray& operator=(BsonArray&& rhs) noexcept;

		BsonArray(std::vector<BsonValue> array);

		std::vector<BsonValue> getValue() const;

		BsonValue getValueAt(int32_t index);
		void setValueAt(int32_t index, const BsonValue& value);

		int32_t getCount();

		bool getIsReadOnly() noexcept;

		void Add(BsonValue item);

		void AddRange(std::vector<BsonValue> array);

		void Clear() noexcept;

		bool Contains(BsonValue item) noexcept;

		void CopyTo(std::vector<BsonValue> array, int32_t arrayIndex);

		int32_t IndexOf(BsonValue item) noexcept;

		void Insert(int32_t index, BsonValue item) noexcept;

		bool Remove(BsonValue item) noexcept;

		void RemoveAt(int32_t index) noexcept;

		int32_t CompareTo(BsonValue other) noexcept override;
	};
}