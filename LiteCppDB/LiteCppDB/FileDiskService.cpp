#include "stdafx.h"
#include "FileDiskService.h"

namespace LiteCppDB
{
	FileDiskService::FileDiskService(std::string filename, FileOptions options)
	{
	}

	void FileDiskService::Initialize(Logger log, std::string password) noexcept
	{
	}

	std::vector<uint32_t> FileDiskService::ReadPage(uint32_t pageID) noexcept
	{
		return std::vector<uint32_t>();
	}

	void FileDiskService::WritePage(uint32_t pageID, std::vector<uint8_t> buffer) noexcept
	{
	}

	void FileDiskService::SetLength(int64_t fileSize) noexcept
	{
	}

	void FileDiskService::WriteJournal(std::vector<uint8_t> pages) noexcept
	{
	}

	std::vector<uint8_t> FileDiskService::ReadJournal() noexcept
	{
		return std::vector<uint8_t>();
	}

	void FileDiskService::Flush() noexcept
	{
	}

	void FileDiskService::ClearJournal() noexcept
	{
	}
}