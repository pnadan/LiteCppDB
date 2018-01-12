#include "stdafx.h"

#include "BsonArray.h"

namespace LiteCppDB
{
	BsonArray::BsonArray() noexcept
	{
	}

	BsonArray::BsonArray(const BsonArray& src) noexcept
	{
		this->mBsonArray = src.mBsonArray;
	}

	BsonArray& BsonArray::operator=(const BsonArray& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		this->mBsonArray = rhs.mBsonArray;
		return *this;
	}

	BsonArray::BsonArray(const BsonArray&& src) noexcept
	{
		this->mBsonArray = src.mBsonArray;
	}

	BsonArray& BsonArray::operator=(BsonArray&& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		this->mBsonArray = rhs.mBsonArray;
		return *this;
	}




	BsonArray::BsonArray(std::vector<BsonValue> array)
	{
		if (array.empty()) throw std::exception("ArgumentNullException array");
	}
	std::vector<BsonValue> BsonArray::getValue() const
	{
		return this->mBsonArray;
	}

	BsonValue BsonArray::getValueAt(int32_t index)
	{
		return this->mBsonArray.at(index);
	}

	void BsonArray::setValueAt(int32_t index, const BsonValue& value)
	{
		if (this->mBsonArray.size() > index)
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

	bool BsonArray::getIsReadOnly() noexcept
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

	void BsonArray::Clear() noexcept
	{
		this->mBsonArray.clear();
	}

	bool BsonArray::Contains(BsonValue item) noexcept
	{
		return false;
	}

	void BsonArray::CopyTo(std::vector<BsonValue> array, int32_t arrayIndex)
	{
		if (array.size() == 0) throw std::exception("ArgumentNullException(array)");

		if (this->mBsonArray.size() > arrayIndex)
		{
			this->mBsonArray.insert(this->mBsonArray.begin() + arrayIndex, array.begin(), array.end());
		}
		else
			throw std::exception("The specifyed index was out of range: BsonArray::setValueAt(int index, BsonValue value)");
	}

	int32_t BsonArray::IndexOf(BsonValue item) noexcept
	{
		return 0;
	}

	void BsonArray::Insert(int32_t index, BsonValue item) noexcept
	{
	}

	bool BsonArray::Remove(BsonValue item) noexcept
	{
		return false;
	}

	void BsonArray::RemoveAt(int32_t index) noexcept
	{
	}

	int32_t BsonArray::CompareTo(BsonValue other) noexcept
	{
		return -1;
	}
}