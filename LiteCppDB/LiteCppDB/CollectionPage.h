#pragma once

#include "CollectionIndex.h"
#include "BasePage.h"

////#include <string>
////#include <vector>
////#include <regex>

namespace LiteCppDB
{
	// Represents the collection page AND a collection item, because CollectionPage represent a Collection (1 page = 1 collection). All collections pages are linked with Prev/Next links
	class CollectionPage : public BasePage, CollectionIndex
	{
	private:
		std::string mCollectionName;
		int64_t mDocumentCount;
		std::vector<BasePage> mbp;
		std::vector<CollectionIndex> mIndexes;
		uint32_t mFreeDataPageID;

	public:
		// Represent maximum bytes that all collections names can be used in header
		static const int16_t MAX_COLLECTIONS_SIZE = 3000;

		//TODOstatic std::regex NamePattern("\^[\w - ]{ 1,30 }$");

		// Page type = Collection
		PageType getPageType() noexcept override;

		// Name of collection
		std::string getCollectionName();
		void setCollectionName(std::string collectionName);

		// Get a reference for the free list data page - its private list per collection - each DataPage contains only data for 1 collection (no mixing)
		// Must to be a Field to be used as parameter reference
		uint32_t getFreeDataPageID() noexcept;

		// Get the number of documents inside this collection
		int64_t getDocumentCount() noexcept;
		void setDocumentCount(int64_t documentCount) noexcept;

		// Get all indexes from this collection - includes non-used indexes
		std::vector<LiteCppDB::CollectionIndex> getIndexes();
		void setIndexes(std::vector<LiteCppDB::CollectionIndex> indexes);

		CollectionPage() noexcept;
		CollectionPage(uint32_t pageID);

		// Update freebytes + items count
		void UpdateItemCount() noexcept override;

#pragma region Read / Write pages

		void ReadContent(ByteReader reader) noexcept override;

		void WriteContent(ByteWriter writer) noexcept override;

#pragma endregion

#pragma region Methods to work with index array

		// Returns first free index slot to be used
		CollectionIndex getFreeIndex();

		// Get index from field name (index field name is case sensitive) - returns null if not found
		CollectionIndex getIndex(std::string field);

		// Get primary key index (_id index)
		CollectionIndex getPK();

		// Returns all used indexes
		std::vector<CollectionIndex> getIndexes(bool includePK);

#pragma endregion
	};
}