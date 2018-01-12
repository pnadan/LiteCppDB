#pragma once

#include "Logger.h"

#include <vector>

#ifdef LITECPPDB_EXPORTS
#define LITECPPDB_API __declspec(dllexport)
#else
#define LITECPPDB_API __declspec(dllimport)
#endif

namespace LiteCppDB
{
	class IDiskService
	{
	public:
		LITECPPDB_API IDiskService() noexcept {};
		LITECPPDB_API virtual ~IDiskService() {};

		LITECPPDB_API IDiskService(const IDiskService& src) noexcept;
		LITECPPDB_API virtual IDiskService& operator=(const IDiskService& rhs) noexcept;

		LITECPPDB_API IDiskService(const IDiskService&& src) noexcept;
		LITECPPDB_API virtual IDiskService& operator=(IDiskService&& rhs) noexcept;

		// Open data file (creating if doest exists) and validate header
		LITECPPDB_API virtual void Initialize(Logger log, std::string password) noexcept;

		// Read a page from disk datafile
		LITECPPDB_API virtual std::vector<uint32_t> ReadPage(uint32_t pageID) noexcept;

		// Write a page in disk datafile
		LITECPPDB_API virtual void WritePage(uint32_t pageID, std::vector<uint8_t> buffer) noexcept;

		// Set datafile length before start writing in disk
		LITECPPDB_API virtual void SetLength(int64_t fileSize) noexcept;

		// Gets file length in bytes
		LITECPPDB_API virtual int64_t getFileLength() noexcept;

		// Indicate that disk/instance are data access exclusive (no other process can access)
		LITECPPDB_API virtual bool getIsExclusive() noexcept;

		// Read journal file returning IEnumerable of pages
		LITECPPDB_API virtual std::vector<uint8_t> ReadJournal() noexcept;

		// Write original bytes page in a journal file (in sequence) - if journal not exists, create.
		LITECPPDB_API virtual void WriteJournal(std::vector<uint8_t> pages) noexcept;

		// Clear journal file
		LITECPPDB_API virtual void ClearJournal() noexcept;

		// Ensures all pages from the OS cache are persisted on medium
		LITECPPDB_API virtual void Flush() noexcept;

		//// Lock datafile returning lock position
		//void Lock(LockState state, TimeSpan timeout);

		//// Unlock datafile based on last state
		//void Unlock(LockState state);
	};
}