#pragma once

#include "IDiskService.h"
#include "BasePage.h"
#include "FileOptions.h"

#include <sstream>

namespace LiteCppDB
{
	// Implement NTFS File disk
	class FileDiskService : IDiskService
	{
	private:
		// Position, on page, about page type
		const int32_t PAGE_TYPE_POSITION = 4;

		// Map lock positions
		const int32_t LOCK_POSITION = BasePage::PAGE_SIZE; // use second page
		const int32_t LOCK_SHARED_LENGTH = 1000;
		const int32_t LOCK_RESERVED_POSITION = LOCK_POSITION + LOCK_SHARED_LENGTH + 1;

		std::ostringstream _stream;
		//FileStream _stream;
		std::string _filename;

		std::ostringstream _journal;
		//FileStream _journal;
		std::string _journalFilename;

		Logger _log; // will be initialize in "Initialize()"
		FileOptions _options;

	public:

#pragma region Initialize / Dispose disk

		FileDiskService(std::string filename, bool journal = true) 
		{ 
		
			FileOptions fo;
			fo.setJournal(journal);
			FileDiskService(filename, fo); }

		FileDiskService(std::string filename, FileOptions options);

		//virtual ~FileDiskService() {};

		void Initialize(Logger log, std::string password) noexcept override;

		//virtual void Dispose();

#pragma endregion

#pragma region Read / Write

		// Read page bytes from disk
		std::vector<uint32_t> ReadPage(uint32_t pageID) noexcept override;

		// Persist single page bytes to disk
		void WritePage(uint32_t pageID, std::vector<uint8_t> buffer) noexcept override;

		// Set datafile length
		void SetLength(int64_t fileSize) noexcept override;

		// Returns file length
		int64_t getFileLength() noexcept override { return 0; };

#pragma endregion

#pragma region Journal file

		// Write original bytes page in a journal file (in sequence) - if journal not exists, create.
		void WriteJournal(std::vector<uint8_t> pages) noexcept override;

		// Read journal file returning IEnumerable of pages
		std::vector<uint8_t> ReadJournal() noexcept override;

		// Ensures all pages from the OS cache are persisted on medium
		void Flush() noexcept override;

		// Clear journal file (set size to 0 length)
		void ClearJournal() noexcept override;

#pragma endregion

#pragma region Lock / Unlock

		// Indicate disk can be access by multiples processes or not
		bool getIsExclusive() noexcept override { return _options.getFileMode() == FileMode::Exclusive; };

		//// Implement datafile lock/unlock
		//void Lock(LockState state, TimeSpan timeout);

		//// Unlock datafile based on state
		//void Unlock(LockState state);

#pragma endregion

	private:
		// Create a new filestream. Can be synced over async task (netstandard)
		//std::ostringstream CreateFileStream(std::string path, std::ostringstream mode, FileAccess access, FileShare share);
	};
}