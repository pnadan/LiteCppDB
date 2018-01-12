#include "stdafx.h"

#include "BsonDocument.h"

namespace LiteCppDB
{
	BsonDocument::BsonDocument() noexcept : BsonValue::BsonValue(std::map<std::string, BsonValue>())
	{
	}

	BsonDocument::BsonDocument(std::map<std::string, BsonValue> dict) noexcept
	{
		if (dict.empty())
		{
			return;
			//throw std::exception("ArgumentNullException dict");
		}
	}

	LITECPPDB_API BsonValue BsonDocument::getFieldForDoc(std::string name) noexcept
	{
		return BsonValue();
	}

	LITECPPDB_API void BsonDocument::setFieldForDoc(std::string name, LiteCppDB::BsonDocument::BsonValue bsonValue)
	{
		std::string s("Field ");
		s += name;
		s += " has an invalid name.";

		if (!IsValidFieldName(name)) throw std::exception(s.c_str());

		auto rw = this->getRawValueSuperMap();
		if (!rw.insert(std::pair<std::string, BsonValue>(name, bsonValue)).second)
		{
			// Element allready exists.
			if (!IsValidFieldName(name)) throw std::exception("Element allready exists.");
		};

		this->setRawValueSuperMap(rw);

		return void();
	}

	// Test if field name is a valid string: only [\w$]+(\w-$)*
	bool BsonDocument::IsValidFieldName(std::string field)
	{
		if (field.empty()) return false;

		// do not use regex because is too slow
		for (auto i = 0; i < field.length(); i++)
		{
			const auto c = field[i];

			if (isalpha(c) || c == '_' || c == '$')
			{
				continue;
			}
			else if (c == '-' && i > 0)
			{
				continue;
			}
			else
			{
				return false;
			}
		}

		return true;
	}

#pragma region Get / Set methods

	// Set value to a path - supports dotted path like: Customer.Address.Street - Fluent API (returns same BsonDocument)
	BsonDocument BsonDocument::Set(std::string path, BsonValue value) noexcept
	{
		return *this;
	}

#pragma endregion

#pragma region CompareTo / ToString

	int BsonDocument::CompareTo(BsonValue other) noexcept
	{
		return -1;
	}

#pragma endregion

#pragma region IDictionary

	std::vector<std::string> BsonDocument::getKeys()
	{
		auto m = this->getRawValueSuperMap();

		std::vector<std::string> v;
		for (std::map<std::string, BsonValue>::iterator it = m.begin(); it != m.end(); ++it) {
			v.insert(v.begin(),it->first);
		}

		return v;
	}

	std::vector<BsonValue> BsonDocument::getValues() noexcept
	{
		std::vector<BsonValue> b;
		return b;
	}

	int32_t BsonDocument::getCount()
	{
		return static_cast<int32_t>(this->getRawValueSuperMap().size());
	}

	bool BsonDocument::getIsReadOnly() noexcept
	{
		return false;
	}

	bool BsonDocument::ContainsKey(std::string key) noexcept
	{
		return false;
	}

	void BsonDocument::Add(std::string key, BsonValue value) noexcept
	{
	}

	bool BsonDocument::Remove(std::string key) noexcept
	{
		return false;
	}

	BsonValue BsonDocument::TryGetValue(std::string key)
	{
		auto m = this->getRawValueSuperMap();
		const auto count = m.count(key);
		auto result = m.find(key);

		if (result != m.end())
		{
			return result->second;
		}
		else
		{
			BsonValue b;
			return b;
		}
	}

	void BsonDocument::Add(std::map<std::string, BsonValue> item) noexcept
	{
	}

	void BsonDocument::Clear() noexcept
	{
	}

	bool BsonDocument::Contains(std::map<std::string, BsonValue> item) noexcept
	{
		return false;
	}

	bool BsonDocument::Remove(std::map<std::string, BsonValue> item) noexcept
	{
		return false;
	}

#pragma endregion
}