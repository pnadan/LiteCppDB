#include "stdafx.h"

#include "HeaderPage.h"
#include <gsl\gsl>

namespace LiteCppDB
{
	// Page type = Header
	PageType HeaderPage::getPageType() noexcept
	{
		return PageType::Header;
	}

	/// Last modified transaction. Used to detect when other process change datafile and cache are not valid anymore
	uint16_t HeaderPage::getChangeID() noexcept
	{
		return this->mChangeID;
	}
	void HeaderPage::setChangeID(uint16_t changeID) noexcept
	{
		this->mChangeID = changeID;
	}

	/// Get/Set the pageID that start sequence with a complete empty pages (can be used as a new page)
	/// Must be a field to be used as "ref"
	uint32_t HeaderPage::getFreeEmptyPageID() noexcept
	{
		return this->mFreeEmptyPageID;
	}
	void HeaderPage::getFreeEmptyPageID(uint32_t freeEmptyPageID) noexcept
	{
		this->mFreeEmptyPageID = freeEmptyPageID;
	}

	/// Last created page - Used when there is no free page inside file
	uint32_t HeaderPage::getLastPageID() noexcept
	{
		return this->mLastPageID;
	}
	void HeaderPage::setLastPageID(uint32_t lastPageID) noexcept
	{
		this->mLastPageID = lastPageID;
	}

	/// Database user version [2 bytes]
	uint16_t HeaderPage::getUserVersion() noexcept
	{
		return this->mUserVersion;
	}
	void HeaderPage::setUserVersion(uint16_t UserVersion) noexcept
	{
		this->mUserVersion = UserVersion;
	}

	// Password hash in SHA1 [20 bytes]
	std::array<uint8_t, 20> HeaderPage::getPassword() noexcept
	{
		return this->mPassword;
	}
	void HeaderPage::setPassword(std::array<uint8_t, 20> password) noexcept
	{
		this->mPassword = password;
	}

	// When using encryption, store salt for password
	std::array<uint8_t, 16> HeaderPage::getSalt() noexcept
	{
		return this->mSalt;
	}
	void HeaderPage::setSalt(std::array<uint8_t, 16> salt) noexcept
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

	HeaderPage::HeaderPage() noexcept : BasePage(0) 
	{
		this->mPageType = PageType::Empty;
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
	void HeaderPage::UpdateItemCount() noexcept
	{
		this->setItemCount(1); // fixed for header
		this->setFreeBytes(0); // no free bytes on header
	}

#pragma region Read / Write pages

	void HeaderPage::ReadContent(ByteReader reader) noexcept
	{
		auto info = reader.ReadString(std::any_cast<int32_t>(HEADER_INFO.size()));
		const auto ver = reader.ReadByte();

		//if (info != HEADER_INFO) throw std::exception("LiteException.InvalidDatabase()");
		//if (ver != FILE_VERSION) throw std::exception("LiteException.InvalidDatabaseVersion(ver)");
		if (info != HEADER_INFO)
		{
			//throw std::exception("LiteException.InvalidDatabase()");
			// TODO PNA write to log.
			return;
		}
		if (ver != FILE_VERSION)
		{
			//throw std::exception("LiteException.InvalidDatabaseVersion(ver)");
			// TODO PNA write to log.
			return;
		}


		this->mChangeID = reader.ReadUInt16();
		this->mFreeEmptyPageID = reader.ReadUInt32();
		this->mLastPageID = reader.ReadUInt32();
		this->mUserVersion = reader.ReadUInt16();

		// read page collections references (position on end of page)
		const auto cols = reader.ReadByte();
		for (auto i = 0; i < cols; i++)
		{
			this->mCollectionPages.insert(std::pair<std::string, uint32_t>(reader.ReadString(), reader.ReadUInt32()));
		}
	}

	void HeaderPage::WriteContent(ByteWriter writer) noexcept
	{
		writer.Write(HEADER_INFO, std::any_cast<int32_t>(HEADER_INFO.size()));
		writer.Write(FILE_VERSION);
		writer.Write(this->mChangeID);
		writer.Write(this->mFreeEmptyPageID);
		writer.Write(this->mLastPageID);
		writer.Write(this->mUserVersion);

		writer.Write(gsl::narrow_cast<uint8_t>(this->mCollectionPages.size()));

		for_each(cbegin(this->mCollectionPages), cend(this->mCollectionPages), [&writer](std::pair<std::string, uint32_t>(cp))
		{
			writer.Write(cp.first);
			writer.Write(cp.second);
		});
	}

#pragma endregion Read / Write pages
}