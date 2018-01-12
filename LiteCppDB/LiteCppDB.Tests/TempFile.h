#pragma once

#include "..\LiteCppDB\IDiskService.h"
#include "..\LiteCppDB\FileOptions.h"

#include <string>

namespace LiteCppDB_Tests
{
	class TempFile
	{
	private:
		std::string mFileName;

	public:
		TempFile();

		std::string getFileName();
		void setFileName(std::string fileName);

		void setTempFile(std::string ext = "db");

		void CreateDataFile();

		LiteCppDB::IDiskService Disk(bool journal = true);

		LiteCppDB::IDiskService Disk(LiteCppDB::FileOptions options);

		std::string Conn(std::string connectionString);

		int64_t getSize();

		std::string ReadAsText();

#pragma region LoremIpsum Generator
		static std::string LoremIpsum(int32_t minWords, int32_t maxWords, int32_t minSentences, int32_t maxSentences, int32_t numParagraphs);
#pragma endregion

	};
}