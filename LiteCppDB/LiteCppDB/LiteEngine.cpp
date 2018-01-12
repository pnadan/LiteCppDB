#include "stdafx.h"

#include "LiteEngine.h"
#include "FileDiskService.h"

namespace LiteCppDB
{
	LiteEngine::LiteEngine() noexcept
	{
		this->_UserVersion = 0;
	}

	LiteEngine::LiteEngine(std::string filename, bool journal) noexcept
	{
		LiteEngine();
		FileDiskService(filename, FileOptions());
	}

	LiteEngine::LiteEngine(const LiteEngine& src) noexcept
	{
		this->_log = src._log;
		this->_locker = src._locker;
		this->_disk = src._disk;
		this->_cache = src._cache;
		this->_pager = src._pager;
		this->_trans = src._trans;
		this->_indexer = src._indexer;
		this->_data = src._data;
		this->_collection = src._collection;
		this->_crypto = src._crypto;
		this->_UserVersion = src._UserVersion;
	}

	LiteEngine& LiteEngine::operator=(const LiteEngine& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		this->_log = rhs._log;
		this->_locker = rhs._locker;
		this->_disk = rhs._disk;
		this->_cache = rhs._cache;
		this->_pager = rhs._pager;
		this->_trans = rhs._trans;
		this->_indexer = rhs._indexer;
		this->_data = rhs._data;
		this->_collection = rhs._collection;
		this->_crypto = rhs._crypto;
		this->_UserVersion = rhs._UserVersion;
		return *this;
	}

	LiteEngine::LiteEngine(const LiteEngine&& src) noexcept
	{
		this->_log = src._log;
		this->_locker = src._locker;
		this->_disk = src._disk;
		this->_cache = src._cache;
		this->_pager = src._pager;
		this->_trans = src._trans;
		this->_indexer = src._indexer;
		this->_data = src._data;
		this->_collection = src._collection;
		this->_crypto = src._crypto;
		this->_UserVersion = src._UserVersion;
	}

	LiteEngine& LiteEngine::operator=(LiteEngine&& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		this->_log = rhs._log;
		this->_locker = rhs._locker;
		this->_disk = rhs._disk;
		this->_cache = rhs._cache;
		this->_pager = rhs._pager;
		this->_trans = rhs._trans;
		this->_indexer = rhs._indexer;
		this->_data = rhs._data;
		this->_collection = rhs._collection;
		this->_crypto = rhs._crypto;
		this->_UserVersion = rhs._UserVersion;
		return *this;
	}
}
