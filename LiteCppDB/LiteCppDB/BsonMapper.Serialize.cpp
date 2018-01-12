#include "stdafx.h"
#include "BsonMapper.Serialize.h"

namespace LiteCppDB
{
	BsonMapper::BsonMapper(const BsonMapper& src) noexcept
	{
	}

	BsonMapper& BsonMapper::operator=(const BsonMapper& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		return *this;
	}

	BsonMapper::BsonMapper(const BsonMapper&& src) noexcept
	{
	}

	BsonMapper& BsonMapper::operator=(BsonMapper&& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		return *this;
	}

	BsonDocument BsonMapper::ToDocument(std::any type, std::any entity) noexcept
	{
		return BsonDocument();
	}
	BsonValue BsonMapper::Serialize(std::any type, std::any obj, int32_t depth) noexcept
	{
		return BsonValue();
	}
	BsonDocument BsonMapper::SerializeObject(std::any type, std::any obj, int32_t depth) noexcept
	{
		return BsonDocument();
	}
}