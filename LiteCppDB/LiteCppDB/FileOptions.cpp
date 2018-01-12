#include "stdafx.h"

#include "FileOptions.h"

#include "BasePage.h"

namespace LiteCppDB
{
	bool FileOptions::getJournal() noexcept
	{
		return this->_Journal;
	}
	void FileOptions::setJournal(bool Journal) noexcept
	{
		this->_Journal = Journal;
	}

	int64_t FileOptions::getInitialSize() noexcept
	{
		return this->_InitialSize;
	}
	void FileOptions::setInitialSize(int64_t InitialSize) noexcept
	{
		this->_InitialSize = InitialSize;
	}

	int64_t FileOptions::getLimitSize() noexcept
	{
		return this->_LimitSize;
	}
	void FileOptions::setLimitSize(int64_t LimitSize) noexcept
	{
		this->_LimitSize = LimitSize;
	}

	FileMode FileOptions::getFileMode() noexcept
	{
		return this->_FileMode;
	}
	void FileOptions::setFileMode(FileMode FileMode) noexcept
	{
		this->_FileMode = FileMode;
	}

	bool FileOptions::getAsync() noexcept
	{
		return this->_Async;
	}
	void FileOptions::setAsync(bool Async) noexcept
	{
		this->_Async = Async;
	}

	FileOptions::FileOptions() noexcept
	{
		this->_Journal = true;
		this->_InitialSize = BasePage::PAGE_SIZE;
		this->_LimitSize = INT64_MAX;
		this->_FileMode = FileMode::Shared;
		this->_Async = false;
	}
}