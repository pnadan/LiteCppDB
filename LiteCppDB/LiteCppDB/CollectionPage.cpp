#include "stdafx.h"

#include "CollectionPage.h"
#include <gsl\gsl>

namespace LiteCppDB
{
	// Page type = Collection
	PageType CollectionPage::getPageType() noexcept
	{
		return PageType::Collection;
	}

	// Name of collection
	std::string CollectionPage::getCollectionName()
	{
		return this->mCollectionName;
	}
	void CollectionPage::setCollectionName(std::string collectionName)
	{
		this->mCollectionName = collectionName;
	}

	// Get a reference for the free list data page - its private list per collection - each DataPage contains only data for 1 collection (no mixing)
	// Must to be a Field to be used as parameter reference
	uint32_t CollectionPage::getFreeDataPageID() noexcept
	{
		return this->mFreeDataPageID;
	}

	/// Get the number of documents inside this collection
	int64_t CollectionPage::getDocumentCount() noexcept
	{
		return this->mDocumentCount;
	}
	void CollectionPage::setDocumentCount(int64_t documentCount) noexcept
	{
		this->mDocumentCount = documentCount;
	}

	/// Get all indexes from this collection - includes non-used indexes
	std::vector<CollectionIndex> CollectionPage::getIndexes()
	{
		return this->mIndexes;
	}
	void CollectionPage::setIndexes(std::vector<CollectionIndex> indexes)
	{
		this->mIndexes = indexes;
	}

	CollectionPage::CollectionPage() noexcept
	{
		this->mFreeDataPageID = 0;
		this->mDocumentCount = 0;
	}

	CollectionPage::CollectionPage(uint32_t pageID)
	{
		this->mFreeDataPageID = UINT32_MAX;
		this->mDocumentCount = 0;
		this->setItemCount(1); // fixed for CollectionPage
		this->setFreeBytes(0); // no free bytes on collection-page - only one collection per page

		for (auto i = 0; i < gsl::narrow_cast<int32_t>(this->getIndexes(false).size()); i++)
		{
			auto ci = CollectionIndex();
			ci.setSlot(i);
			this->mIndexes.at(i) = ci;
		}
	}

	/// Update freebytes + items count
	void CollectionPage::UpdateItemCount() noexcept
	{
		this->setItemCount(1); // fixed for CollectionPage
		this->setFreeBytes(0); // no free bytes on collection-page - only one collection per page
	}

#pragma region Read / Write pages

	void CollectionPage::ReadContent(ByteReader reader) noexcept
	{
		this->setCollectionName(reader.ReadString());
		this->setDocumentCount(reader.ReadInt64());
		this->mFreeDataPageID = reader.ReadUInt32();

		for_each(cbegin(this->getIndexes()), cend(this->getIndexes()), [&reader](CollectionIndex ci) {
			ci.setField(reader.ReadString());
			ci.setUnique(reader.ReadBoolean());
			ci.setHeadNode(reader.ReadPageAddress());
			ci.setTailNode(reader.ReadPageAddress());
			ci.setFreeIndexPageID(reader.ReadUInt32());
		});
	}

	void CollectionPage::WriteContent(ByteWriter writer) noexcept
	{
		writer.Write(this->getCollectionName());
		writer.Write(this->getDocumentCount());
		writer.Write(this->getFreeDataPageID());

		for_each(cbegin(this->getIndexes()), cend(this->getIndexes()), [&writer](CollectionIndex ci) {
			writer.Write(ci.getField());
			writer.Write(ci.getUnique());
			writer.Write(ci.getHeadNode());
			writer.Write(ci.getTailNode());
			writer.Write(ci.getFreeIndexPageID());
		});
	}

#pragma endregion

#pragma region Methods to work with index array

	/// Returns first free index slot to be used
	CollectionIndex CollectionPage::getFreeIndex()
	{
		for (int32_t i = 0; i < gsl::narrow_cast<int32_t>(this->mIndexes.size()); i++)
		{
			if (&(this->mIndexes.at(i)) == nullptr) return this->mIndexes.at(i);
		}

		throw std::exception("LiteException.IndexLimitExceeded(this->getCollectionName())");
	}

	/// Get index from field name (index field name is case sensitive) - returns null if not found
	CollectionIndex CollectionPage::getIndex(std::string field)
	{
		return this->mIndexes.at(0);
	}

	/// Get primary key index (_id index)
	CollectionIndex CollectionPage::getPK()
	{
		return this->mIndexes.at(0);
	}

	/// Returns all used indexes
	std::vector<CollectionIndex> CollectionPage::getIndexes(bool includePK)
	{
		return this->mIndexes;
	}

#pragma endregion
}