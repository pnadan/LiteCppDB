#pragma once

#include "BsonValue.h"
#include "BasePage.h"

#include <string>
#include <vector>
#include <map>

#ifdef LITECPPDB_EXPORTS
#define LITECPPDB_API __declspec(dllexport)
#else
#define LITECPPDB_API __declspec(dllimport)
#endif

namespace LiteCppDB
{
	class BsonDocument : public BsonValue
	{
	private:

	public:
		const int32_t MAX_DOCUMENT_SIZE = 256 * BasePage::PAGE_AVAILABLE_BYTES; 

		LITECPPDB_API BsonDocument();

		LITECPPDB_API BsonDocument(std::map<std::string, BsonValue> dict);

		// Get/Set a field for document. Fields are case sensitive
		LITECPPDB_API BsonValue getFieldForDoc(std::string name);

		LITECPPDB_API void setFieldForDoc(std::string name, LiteCppDB::BsonDocument::BsonValue bsonValue);

		// Test if field name is a valid string: only [\w$]+(\w-$)*
		LITECPPDB_API static bool IsValidFieldName(std::string field);

#pragma region Get / Set methods

		// Set value to a path - supports dotted path like: Customer.Address.Street - Fluent API (returns same BsonDocument)
		LITECPPDB_API BsonDocument Set(std::string path, BsonValue value);

#pragma endregion

#pragma region CompareTo / ToString

		LITECPPDB_API int32_t CompareTo(BsonValue other) override;

#pragma endregion

#pragma region IDictionary

		std::vector<std::string> getKeys();

		std::vector<BsonValue> getValues();

		int32_t getCount();

		bool getIsReadOnly();

		bool ContainsKey(std::string key);

		void Add(std::string key, BsonValue value);

		bool Remove(std::string key);

		LITECPPDB_API BsonValue TryGetValue(std::string key);

		void Add(std::map<std::string, BsonValue> item);

		void Clear();

		bool Contains(std::map<std::string, BsonValue> item);

		bool Remove(std::map<std::string, BsonValue> item);

#pragma endregion
	};
}