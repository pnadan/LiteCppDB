#pragma once

#ifdef LITECPPDB_EXPORTS
#define LITECPPDB_API __declspec(dllexport)
#else
#define LITECPPDB_API __declspec(dllimport)
#endif

#include "BsonDocument.h"
#include "BsonArray.h"
#include "BsonValue.h"

#include <string>
#include <vector>
#include <map>

namespace LiteCppDB
{
	class BsonMapper
	{
	public:
		BsonMapper() noexcept {};
		virtual ~BsonMapper() noexcept {};

		BsonMapper(const BsonMapper& src) noexcept;
		virtual BsonMapper& operator=(const BsonMapper& rhs) noexcept;

		BsonMapper(const BsonMapper&& src) noexcept;
		virtual BsonMapper& operator=(BsonMapper&& rhs) noexcept;

		/// Serialize a entity class to BsonDocument
		virtual BsonDocument ToDocument(std::any type, std::any entity) noexcept;

		/// Serialize a entity class to BsonDocument
	//	virtual BsonDocument ToDocument<T>(T entity);

		BsonValue Serialize(std::any type, std::any obj, int32_t depth) noexcept;

	private:
	//	BsonArray SerializeArray(std::any type, std::vector<T> array, int32_t depth);

	//	BsonDocument SerializeDictionary(std::any type, std::map<T> dict, int32_t depth);

		BsonDocument SerializeObject(std::any type, std::any obj, int32_t depth) noexcept;
	};
}