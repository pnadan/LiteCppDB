#pragma once

#include <chrono>
#include <string>

#ifdef LITECPPDB_EXPORTS
#define LITECPPDB_API __declspec(dllexport)
#else
#define LITECPPDB_API __declspec(dllimport)
#endif

namespace LiteCppDB
{
	// Manage ConnectionString to connect and create databases. Connection string are NameValue using Name1=Value1; Name2=Value2
	class ConnectionString
	{
	private:
		std::string mFilename;
		bool mJournal;
		std::string mPassword;
		int32_t mCacheSize;
		int64_t mInitialSize;
		int64_t mLimitSize;
		uint8_t mLog;
		bool mUpgrade;
		bool mAsync;

	public:
		// Initialize empty connection string
		LITECPPDB_API ConnectionString() noexcept;
		LITECPPDB_API virtual ~ConnectionString();

		LITECPPDB_API ConnectionString(const ConnectionString& src) noexcept;
		LITECPPDB_API virtual ConnectionString& operator=(const ConnectionString& rhs) noexcept;

		LITECPPDB_API ConnectionString(const ConnectionString&& src) noexcept;
		LITECPPDB_API virtual ConnectionString& operator=(ConnectionString&& rhs) noexcept;

		// Initialize connection string parsing string in "key1=value1;key2=value2;...." format or only "filename" as default (when no ; char found)
		LITECPPDB_API ConnectionString(std::string connectionString);

		// "filename": Full path or relative path from DLL directory
		LITECPPDB_API std::string getFilename();
		LITECPPDB_API void setFilename(std::string filename);

		// "journal": Enabled or disable double write check to ensure durability (default: true)
		LITECPPDB_API bool getJournal() noexcept;
		LITECPPDB_API void setJournal(bool journal) noexcept;

		// "password": Encrypt (using AES) your datafile with a password (default: null - no encryption)
		LITECPPDB_API std::string getPassword();
		LITECPPDB_API void setPassword(std::string password);

		// "cache size": Max number of pages in cache. After this size, flush data to disk to avoid too memory usage (default: 5000)
		LITECPPDB_API int32_t getCacheSize() noexcept;
		LITECPPDB_API void setCacheSize(int32_t cacheSize) noexcept;

		// "initial size": If database is new, initialize with allocated space - support KB, MB, GB (default: null)
		LITECPPDB_API int64_t getInitialSize() noexcept;
		LITECPPDB_API void setInitialSize(int64_t initialSize) noexcept;

		// "limit size": Max limit of datafile - support KB, MB, GB (default: null)
		LITECPPDB_API int64_t getLimitSize() noexcept;
		LITECPPDB_API void setLimitSize(int64_t limitSize) noexcept;

		// "log": Debug messages from database - use `LiteDatabase.Log` (default: Logger.NONE)
		LITECPPDB_API uint8_t getLog() noexcept;
		LITECPPDB_API void setLog(uint8_t log) noexcept;

		// "upgrade": Test if database is in old version and update if needed (default: false)
		LITECPPDB_API bool getUpgrade() noexcept;
		LITECPPDB_API void setUpgrade(bool upgrade) noexcept;

		// "async": Use "sync over async" to UWP apps access any directory
		LITECPPDB_API bool getAsync() noexcept;
		LITECPPDB_API void setAsync(bool async) noexcept;

		LITECPPDB_API friend bool operator==(const ConnectionString& lhs, const ConnectionString& rhs) noexcept
		{
			return (lhs.mFilename == rhs.mFilename);
		}
	};
}