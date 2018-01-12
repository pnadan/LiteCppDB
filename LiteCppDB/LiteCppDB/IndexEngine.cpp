#include "stdafx.h"

#include "LiteEngine.h"

namespace LiteCppDB
{
	// Create a new index (or do nothing if already exists) to a collection/field
	bool LiteEngine::EnsureIndex(std::string collection, std::string field, bool unique) 
	{
		if(collection.empty()) throw std::exception::exception("ArgumentNullException(collection)");
		if (field.empty()) throw std::exception::exception("ArgumentNullException(field)");

		//this.t

		return false;
	}

	// Drop an index from a collection
	bool LiteEngine::DropIndex(std::string collection, std::string field) 
	{
		if (collection.empty()) throw std::exception::exception("ArgumentNullException(collection)");
		if (field.empty()) throw std::exception::exception("ArgumentNullException(field)");

		return false;
	}

	// List all indexes inside a collection
	std::vector<IndexInfo> LiteEngine::GetIndexes(std::string collection)
	{
		if (collection.empty()) throw std::exception::exception("ArgumentNullException(collection)");

		return std::vector<IndexInfo>();
	}
}