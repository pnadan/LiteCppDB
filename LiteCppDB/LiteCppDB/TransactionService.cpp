#include "stdafx.h"
#include "TransactionService.h"

namespace LiteCppDB
{
	TransactionService::TransactionService() noexcept
	{
		this->_cacheSize = 0;
	}

	TransactionService::TransactionService(IDiskService disk, AesEncryption crypto, PageService pager, LockService locker, CacheService cache, int cacheSize, Logger log) noexcept
	{
		this->_cacheSize = cacheSize;
	}

	void TransactionService::CheckPoint() noexcept
	{
	}

	void TransactionService::Commit() noexcept
	{
	}

	void TransactionService::Rollback() noexcept
	{
	}

	void TransactionService::Recovery() noexcept
	{
	}
}