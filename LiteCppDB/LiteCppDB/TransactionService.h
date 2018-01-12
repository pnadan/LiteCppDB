#pragma once

#include "IDiskService.h"
#include "AesEncryption.h"
#include "LockService.h"
#include "PageService.h"

namespace LiteCppDB
{
	// Manages all transactions and grantees concurrency and recovery
	class TransactionService
	{
	private:
		IDiskService _disk;
		AesEncryption _crypto;
		LockService _locker;
		PageService _pager;
		CacheService _cache;
		Logger _log;
		int32_t _cacheSize;

	public:
		TransactionService() noexcept;

		TransactionService(IDiskService disk, AesEncryption crypto, PageService pager, LockService locker, CacheService cache, int cacheSize, Logger log) noexcept;

		// Checkpoint is a safe point to clear cache pages without loose pages references.
		// Is called after each document insert/update/deleted/indexed/fetch from query
		// Clear only clean pages - do not clear dirty pages (transaction)
		void CheckPoint() noexcept;

		// Save all dirty pages to disk
		void Commit() noexcept;

		// Clear cache, discard journal file
		void Rollback() noexcept;

		// Try recovery journal file (if exists). Restore original datafile
		// Journal file are NOT encrypted (even when datafile are encrypted)
		void Recovery() noexcept;
	};
}