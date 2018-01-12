#include "stdafx.h"
#include "IndexInfo.h"

void LiteCppDB::IndexInfo::setSlot(int32_t slot) noexcept
{
}

void LiteCppDB::IndexInfo::setField(std::string field) noexcept
{
}

void LiteCppDB::IndexInfo::setUnique(bool unique) noexcept
{
}

int32_t LiteCppDB::IndexInfo::getSlot() noexcept
{
	return int32_t();
}

std::string LiteCppDB::IndexInfo::getField() noexcept
{
	return std::string();
}

bool LiteCppDB::IndexInfo::getUnique() noexcept
{
	return false;
}
