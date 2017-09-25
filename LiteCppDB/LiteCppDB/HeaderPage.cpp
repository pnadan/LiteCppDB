#include "stdafx.h"

#include "HeaderPage.h"

namespace LiteCppDB
{
	// Page type = Header
	PageType HeaderPage::getPageType()
	{
		return PageType::Header;
	}

	/// Last modified transaction. Used to detect when other process change datafile and cache are not valid anymore
	uint16_t HeaderPage::getChangeID()
	{
		return this->mChangeID;
	}
	void HeaderPage::setChangeID(uint16_t changeID)
	{
		this->mChangeID = changeID;
	}

	/// Get/Set the pageID that start sequence with a complete empty pages (can be used as a new page)
	/// Must be a field to be used as "ref"
	uint32_t HeaderPage::getFreeEmptyPageID()
	{
		return this->mFreeEmptyPageID;
	}
	void HeaderPage::getFreeEmptyPageID(uint32_t freeEmptyPageID)
	{
		this->mFreeEmptyPageID = freeEmptyPageID;
	}

	/// Last created page - Used when there is no free page inside file
	uint32_t HeaderPage::getLastPageID()
	{
		return this->mLastPageID;
	}
	void HeaderPage::setLastPageID(uint32_t lastPageID)
	{
		this->mLastPageID = lastPageID;
	}

	/// Database user version [2 bytes]
	uint16_t HeaderPage::getUserVersion()
	{
		return this->mUserVersion;
	}
	void HeaderPage::setUserVersion(uint16_t UserVersion)
	{
		this->mUserVersion = UserVersion;
	}

	// Password hash in SHA1 [20 bytes]
	std::array<uint8_t, 20> HeaderPage::getPassword()
	{
		return this->mPassword;
	}
	void HeaderPage::setPassword(std::array<uint8_t, 20> password)
	{
		this->mPassword = password;
	}

	// When using encryption, store salt for password
	std::array<uint8_t, 16> HeaderPage::getSalt()
	{
		return this->mSalt;
	}
	void HeaderPage::setSalt(std::array<uint8_t, 16> salt)
	{
		this->mSalt = salt;
	}

	// Get a dictionary with all collection pages with pageID link
	std::map<std::string, uint32_t> HeaderPage::getCollectionPages()
	{
		return this->mCollectionPages;
	}
	void HeaderPage::setCollectionPages(std::map<std::string, uint32_t> collectionPages)
	{
		this->mCollectionPages = collectionPages;
	}

	HeaderPage::HeaderPage() : BasePage(0)
	{
		this->mChangeID = 0;
		this->mFreeEmptyPageID = UINT32_MAX;
		this->mLastPageID = 0;
		this->setItemCount(1); // fixed for header
		this->setFreeBytes(0); // no free bytes on header
		this->mUserVersion = 0;
		this->mPassword = std::array<uint8_t, 20>(); /*new byte[20];*/
		this->mSalt = std::array<uint8_t, 16>();
		this->mCollectionPages = std::map<std::string, uint32_t>();
	}

	// Update freebytes + items count
	void HeaderPage::UpdateItemCount()
	{
		this->setItemCount(1); // fixed for header
		this->setFreeBytes(0); // no free bytes on header
	}

#pragma region Read / Write pages

	void HeaderPage::ReadContent(ByteReader reader)
	{
		auto info = reader.ReadString(std::any_cast<int32_t>(HEADER_INFO.size()));
		auto ver = reader.ReadByte();

		if (info != HEADER_INFO) throw std::exception("LiteException.InvalidDatabase()");
		if (ver != FILE_VERSION) throw std::exception("LiteException.InvalidDatabaseVersion(ver)");

		this->mChangeID = reader.ReadUInt16();
		this->mFreeEmptyPageID = reader.ReadUInt32();
		this->mLastPageID = reader.ReadUInt32();
		this->mUserVersion = reader.ReadUInt16();

		// read page collections references (position on end of page)
		auto cols = reader.ReadByte();
		for (auto i = 0; i < cols; i++)
		{
			this->mCollectionPages.insert(std::pair<std::string, uint32_t>(reader.ReadString(), reader.ReadUInt32()));
		}
	}

	void HeaderPage::WriteContent(ByteWriter writer)
	{
		writer.Write(HEADER_INFO, std::any_cast<int32_t>(HEADER_INFO.size()));
		writer.Write(FILE_VERSION);
		writer.Write(this->mChangeID);
		writer.Write(this->mFreeEmptyPageID);
		writer.Write(this->mLastPageID);
		writer.Write(this->mUserVersion);

		writer.Write((uint8_t)this->mCollectionPages.size());

		for_each(cbegin(this->mCollectionPages), cend(this->mCollectionPages), [&writer](std::pair<std::string, uint32_t>(cp))
		{
			writer.Write(cp.first);
			writer.Write(cp.second);
		});
	}

#pragma endregion Read / Write pages
}