#include "stdafx.h"
#include "TempFile.h"

namespace LiteCppDB_Tests
{
	TempFile::TempFile()
	{
	}

	std::string TempFile::getFileName()
	{
		return std::string();
	}
	void TempFile::setFileName(std::string fileName)
	{
	}

	void TempFile::setTempFile(std::string ext)
	{
	}

	void TempFile::CreateDataFile()
	{
	}

	LiteCppDB::IDiskService TempFile::Disk(bool journal)
	{
		return LiteCppDB::IDiskService();
	}
	LiteCppDB::IDiskService TempFile::Disk(LiteCppDB::FileOptions options)
	{
		return LiteCppDB::IDiskService();
	}

	std::string TempFile::Conn(std::string connectionString)
	{
		return std::string();
	}

	int64_t TempFile::getSize()
	{
		return int64_t();
	}

	std::string TempFile::ReadAsText()
	{
		return std::string();
	}

	std::string TempFile::LoremIpsum(int32_t minWords, int32_t maxWords, int32_t minSentences, int32_t maxSentences, int32_t numParagraphs)
	{
		return std::string();
	}
}
