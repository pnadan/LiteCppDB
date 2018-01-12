#pragma once

#include "IDiskService.h"

namespace LiteCppDB
{
	// Implement generic Stream disk service. Used for any read/write/seek stream
	// No journal implemented
	class StreamDiskService : IDiskService
	{
	private:
		// Position, on page, about page type
		const int32_t PAGE_TYPE_POSITION = 4;

		Stream _stream;
		Logger _log; // will be initialize in "Initialize()"

	public:
#pragma region Initialize disk

		StreamDiskService(Stream stream);

		void Initialize(Logger log, string password);

		virtual void Dispose();

#pragma endregion

#pragma region Read / Write

		// Read page bytes from disk
		std::vector<uint8_t> ReadPage(uint32_t pageID);

		// Persist single page bytes to disk
		void WritePage(uint32_t pageID, std::vector<uint8_t> buffer);

		// Set datafile length
		void SetLength(int64_t fileSize);

		// Returns file length
		int64_t getFileLength() { return _stream.Length; };

#pragma endregion

#pragma region Not implemented in Stream

		// Single process only
		bool getIsExclusive() { return true; };

		// No journal implemented
		void WriteJournal(std::vector<uint8_t> pages);

		// No journal implemented
		std::vector<uint8_t> ReadJournal();

		// No journal implemented
		void ClearJournal();

		// No lock implemented
		void Lock(LockState state, TimeSpan timeout);

		// No lock implemented
		void Unlock(LockState state);

		// No flush implemented
		void Flush();

#pragma endregion
	}
}