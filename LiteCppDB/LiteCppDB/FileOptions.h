#pragma once

#include <stdint.h>

namespace LiteCppDB
{
	enum FileMode
	{
		Shared,
		Exclusive,
		ReadOnly
	};

	// Datafile open options (for FileDiskService)
	class FileOptions
	{
	private:
		bool _Journal;
		int64_t _InitialSize;
		int64_t _LimitSize;
		FileMode _FileMode;
		bool _Async;

	public:
		bool getJournal() noexcept;
		void setJournal(bool Journal) noexcept;

		int64_t getInitialSize() noexcept;
		void setInitialSize(int64_t InitialSize) noexcept;

		int64_t getLimitSize() noexcept;
		void setLimitSize(int64_t LimitSize) noexcept;

		FileMode getFileMode() noexcept;
		void setFileMode(FileMode FileMode) noexcept;

		bool getAsync() noexcept;
		void setAsync(bool Async) noexcept;

		FileOptions() noexcept;
	};
}
