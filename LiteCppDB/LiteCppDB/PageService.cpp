#include "stdafx.h"
#include "PageService.h"

LiteCppDB::PageService::PageService() noexcept
{
}

LiteCppDB::PageService::PageService(IDiskService disk, AesEncryption crypto, CacheService cache, Logger log) noexcept
{
}

void LiteCppDB::PageService::SetDirty(BasePage page) noexcept
{
}

void LiteCppDB::PageService::DeletePage(uint32_t pageID, bool addSequence) noexcept
{
}
