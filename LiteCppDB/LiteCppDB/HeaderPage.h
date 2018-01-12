#pragma once

#include "BasePage.h"

#include <array>
#include <string>
#include <vector>
#include <map>

namespace LiteCppDB
{
	class HeaderPage : public BasePage
	{
	private:
		PageType mPageType;
		uint16_t mChangeID = 0;
		uint32_t mFreeEmptyPageID = UINT32_MAX;
		uint32_t mLastPageID = 0;
		uint16_t mUserVersion = 0;
		std::array<uint8_t, 20> mPassword = { 0 };
		std::array<uint8_t, 16> mSalt = { 0 };
		std::map<std::string, uint32_t> mCollectionPages;

		// Header info the validate that datafile is a LiteDB file (27 bytes)
		const std::string HEADER_INFO = "** This is a LiteDB file **";

		// Datafile specification version
		const uint8_t FILE_VERSION = 7;

	public:
		// Page type = Header
		PageType getPageType() noexcept override;

		// Last modified transaction. Used to detect when other process change datafile and cache are not valid anymore
		uint16_t getChangeID() noexcept;
		void setChangeID(uint16_t changeID) noexcept;

		// Get/Set the pageID that start sequence with a complete empty pages (can be used as a new page)
		// Must be a field to be used as "ref"
		uint32_t getFreeEmptyPageID() noexcept;
		void getFreeEmptyPageID(uint32_t freeEmptyPageID) noexcept;

		// Last created page - Used when there is no free page inside file
		uint32_t getLastPageID() noexcept;
		void setLastPageID(uint32_t lastPageID) noexcept;

		// Database user version [2 bytes]
		uint16_t getUserVersion() noexcept;
		void setUserVersion(uint16_t UserVersion) noexcept;

		// Password hash in SHA1 [20 bytes]
		std::array<uint8_t, 20> getPassword() noexcept;
		void setPassword(std::array<uint8_t, 20> password) noexcept;

		// When using encryption, store salt for password
		std::array<uint8_t, 16> getSalt() noexcept;
		void setSalt(std::array<uint8_t, 16> salt) noexcept;

		// Get a dictionary with all collection pages with pageID link
		std::map<std::string, uint32_t> getCollectionPages();
		void setCollectionPages(std::map<std::string, uint32_t> collectionPages);

		HeaderPage() noexcept;

		// Update freebytes + items count
		void UpdateItemCount()  noexcept;

#pragma region Read / Write pages

	protected:
		void ReadContent(ByteReader reader) noexcept;

		void WriteContent(ByteWriter writer) noexcept;

#pragma endregion Read / Write pages
	};
}