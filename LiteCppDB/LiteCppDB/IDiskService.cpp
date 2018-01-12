#include "stdafx.h"
#include "IDiskService.h"

namespace LiteCppDB
{
	IDiskService::IDiskService(const IDiskService& src) noexcept
	{
	}

	IDiskService& IDiskService::operator=(const IDiskService& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		return *this;
	}

	IDiskService::IDiskService(const IDiskService&& src) noexcept
	{
	}

	IDiskService& IDiskService::operator=(IDiskService&& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		return *this;
	}

	void IDiskService::Initialize(Logger log, std::string password) noexcept
	{
	}

	std::vector<uint32_t> IDiskService::ReadPage(uint32_t pageID) noexcept
	{
		return std::vector<uint32_t>();
	}

	void IDiskService::WritePage(uint32_t pageID, std::vector<uint8_t> buffer) noexcept
	{
	}

	void IDiskService::SetLength(int64_t fileSize) noexcept
	{
	}

	int64_t IDiskService::getFileLength() noexcept
	{
		return 0;
	}

	bool IDiskService::getIsExclusive() noexcept
	{
		return false;
	}

	std::vector<uint8_t> IDiskService::ReadJournal() noexcept
	{
		return std::vector<uint8_t>();
	}

	void IDiskService::WriteJournal(std::vector<uint8_t> pages) noexcept
	{
	}

	void IDiskService::ClearJournal() noexcept
	{
	}

	void IDiskService::Flush() noexcept
	{
	}
}