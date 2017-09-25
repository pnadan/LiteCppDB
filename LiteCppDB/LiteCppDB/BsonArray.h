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
		BsonArray();

		BsonArray(std::vector<BsonValue> array);

		std::vector<BsonValue> getValue();

		BsonValue getValueAt(int32_t index);
		void setValueAt(int32_t index, BsonValue& value);

		int32_t getCount();

		bool getIsReadOnly();

		void Add(BsonValue item);

		void AddRange(std::vector<BsonValue> array);

		void Clear();

		bool Contains(BsonValue item);

		void CopyTo(std::vector<BsonValue> array, int32_t arrayIndex);

		int32_t IndexOf(BsonValue item);

		void Insert(int32_t index, BsonValue item);

		bool Remove(BsonValue item);

		void RemoveAt(int32_t index);

		int32_t CompareTo(BsonValue other) override;
	};
}