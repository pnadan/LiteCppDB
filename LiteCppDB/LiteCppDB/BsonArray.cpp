#include "stdafx.h"

#include "BsonArray.h"

namespace LiteCppDB
{
	BsonArray::BsonArray()
	{
	}

	BsonArray::BsonArray(std::vector<BsonValue> array)
	{
		if (array.empty()) throw std::exception("ArgumentNullException array");
	}
	std::vector<BsonValue> BsonArray::getValue()
	{
		return this->mBsonArray;
	}

	BsonValue BsonArray::getValueAt(int32_t index)
	{
		return this->mBsonArray.at(index);
	}

	void BsonArray::setValueAt(int32_t index, BsonValue& value)
	{
		if (static_cast<int32_t>(this->mBsonArray.size()) > index)
		{
			this->mBsonArray.insert(this->mBsonArray.begin() + index, value);
		}
		else
			throw std::exception("The specifyed index was out of range: BsonArray::setValueAt(int index, BsonValue value)");
	}

	int32_t BsonArray::getCount()
	{
		return std::any_cast<int32_t>(this->mBsonArray.size());
	}

	bool BsonArray::getIsReadOnly()
	{
		return false;
	}

	void BsonArray::Add(BsonValue item)
	{
		this->mBsonArray.push_back(item);
	}

	void BsonArray::AddRange(std::vector<BsonValue> array)
	{
		if (array.size() == 0) throw std::exception("ArgumentNullException(array)");

		this->mBsonArray.insert(this->mBsonArray.end(), array.begin(), array.end());
	}

	void BsonArray::Clear()
	{
		this->mBsonArray.clear();
	}

	bool BsonArray::Contains(BsonValue item)
	{
		return false;
	}

	void BsonArray::CopyTo(std::vector<BsonValue> array, int32_t arrayIndex)
	{
		if (array.size() == 0) throw std::exception("ArgumentNullException(array)");

		if (static_cast<int32_t>(this->mBsonArray.size()) > arrayIndex)
		{
			this->mBsonArray.insert(this->mBsonArray.begin() + arrayIndex, array.begin(), array.end());
		}
		else
			throw std::exception("The specifyed index was out of range: BsonArray::setValueAt(int index, BsonValue value)");
	}

	int32_t BsonArray::IndexOf(BsonValue item)
	{
		return 0;
	}

	void BsonArray::Insert(int32_t index, BsonValue item)
	{
	}

	bool BsonArray::Remove(BsonValue item)
	{
		return false;
	}

	void BsonArray::RemoveAt(int32_t index)
	{
	}

	int32_t BsonArray::CompareTo(BsonValue other)
	{
		return -1;
	}
}