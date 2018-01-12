#include "stdafx.h"

#include "ConnectionString.h"

#include <sstream>
#include <locale>
#include <iostream>
#include <map>

namespace LiteCppDB
{
	// Manage ConnectionString to connect and create databases. Connection string are NameValue using Name1=Value1; Name2=Value2

	// "filename": Full path or relative path from DLL directory
	std::string ConnectionString::getFilename()
	{
		return this->mFilename;
	}
	void ConnectionString::setFilename(std::string filename)
	{
		this->mFilename = filename;
	}

	// "journal": Enabled or disable double write check to ensure durability (default: true)
	bool ConnectionString::getJournal() noexcept
	{
		return this->mJournal;
	}
	void ConnectionString::setJournal(bool journal) noexcept
	{
		this->mJournal = journal;
	}

	// "password": Encrypt (using AES) your datafile with a password (default: null - no encryption)
	std::string ConnectionString::getPassword()
	{
		return this->mPassword;
	}
	void ConnectionString::setPassword(std::string password)
	{
		this->mPassword = password;
	}

	// "cache size": Max number of pages in cache. After this size, flush data to disk to avoid too memory usage (default: 5000)
	int ConnectionString::getCacheSize() noexcept
	{
		return this->mCacheSize;
	}
	void ConnectionString::setCacheSize(int32_t cacheSize) noexcept
	{
		this->mCacheSize = cacheSize;
	}

	// "initial size": If database is new, initialize with allocated space - support KB, MB, GB (default: null)
	int64_t ConnectionString::getInitialSize() noexcept
	{
		return this->mInitialSize;
	}
	void ConnectionString::setInitialSize(int64_t initialSize) noexcept
	{
		this->mInitialSize = initialSize;
	}

	// "limit size": Max limit of datafile - support KB, MB, GB (default: null)
	int64_t ConnectionString::getLimitSize() noexcept
	{
		return this->mLimitSize;
	}
	void ConnectionString::setLimitSize(int64_t limitSize) noexcept
	{
		this->mLimitSize = limitSize;
	}

	// "log": Debug messages from database - use `LiteDatabase.Log` (default: Logger.NONE)
	uint8_t ConnectionString::getLog() noexcept
	{
		return this->mLog;
	}
	void ConnectionString::setLog(uint8_t log) noexcept
	{
		this->mLog = log;
	}

	// "upgrade": Test if database is in old version and update if needed (default: false)
	bool ConnectionString::getUpgrade() noexcept
	{
		return this->mUpgrade;
	}
	void ConnectionString::setUpgrade(bool upgrade) noexcept
	{
		this->mUpgrade = upgrade;
	}

	// "async": Use "sync over async" to UWP apps access any directory
	bool ConnectionString::getAsync() noexcept
	{
		return this->mAsync;
	}
	void ConnectionString::setAsync(bool async) noexcept
	{
		this->mAsync = async;
	}

	// Initialize empty connection string
	ConnectionString::ConnectionString() noexcept
	{
		this->mCacheSize = 0;
		this->mUpgrade = 0;
		this->mInitialSize = 0;
		this->mLog = 0;
		this->mJournal = false;
		this->mAsync = false;

		this->mFilename = std::string();
		this->mPassword = std::string();;
		this->mLimitSize = 0;;
	}
	ConnectionString::~ConnectionString()
	{

	}

	ConnectionString::ConnectionString(const ConnectionString& src) noexcept
	{
		this->mCacheSize = src.mCacheSize;
		this->mUpgrade = src.mUpgrade;
		this->mInitialSize = src.mInitialSize;
		this->mLog = src.mLog;
		this->mJournal = src.mJournal;
		this->mAsync = src.mAsync;
		this->mFilename = src.mFilename;
		this->mPassword = src.mPassword;
		this->mLimitSize = src.mLimitSize;
	}

	ConnectionString& ConnectionString::operator=(const ConnectionString& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		this->mCacheSize = rhs.mCacheSize;
		this->mUpgrade = rhs.mUpgrade;
		this->mInitialSize = rhs.mInitialSize;
		this->mLog = rhs.mLog;
		this->mJournal = rhs.mJournal;
		this->mAsync = rhs.mAsync;
		this->mFilename = rhs.mFilename;
		this->mPassword = rhs.mPassword;
		this->mLimitSize = rhs.mLimitSize;
		return *this;
	}

	ConnectionString::ConnectionString(const ConnectionString&& src) noexcept
	{
		this->mCacheSize = src.mCacheSize;
		this->mUpgrade = src.mUpgrade;
		this->mInitialSize = src.mInitialSize;
		this->mLog = src.mLog;
		this->mJournal = src.mJournal;
		this->mAsync = src.mAsync;
		this->mFilename = src.mFilename;
		this->mPassword = src.mPassword;
		this->mLimitSize = src.mLimitSize;
	}

	ConnectionString& ConnectionString::operator=(ConnectionString&& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		this->mCacheSize = rhs.mCacheSize;
		this->mUpgrade = rhs.mUpgrade;
		this->mInitialSize = rhs.mInitialSize;
		this->mLog = rhs.mLog;
		this->mJournal = rhs.mJournal;
		this->mAsync = rhs.mAsync;
		this->mFilename = rhs.mFilename;
		this->mPassword = rhs.mPassword;
		this->mLimitSize = rhs.mLimitSize;
		return *this;
	}

	// Initialize connection string parsing string in "key1=value1;key2=value2;...." format or only "filename" as default (when no ; char found)
	ConnectionString::ConnectionString(std::string connectionString)
	{
		this->mLog = 0;
		this->mAsync = false;
		this->mInitialSize = 0;

		if (connectionString == std::string() || connectionString.empty())
		{
			throw std::exception("connectionString");
		}

		std::map<std::string, std::string> values;

		// create a map from string name=value collection
		if (connectionString.find("=") == std::string::npos)
		{
			//TODO PNA values.ParseKeyValue(connectionString);
			values["filename"] = connectionString;
		}
		else
		{
			values["filename"] = connectionString;
		}

		// setting values to properties
		auto filename = values.find("filename");
		if (filename != values.end())
			this->mFilename = filename->second;
		else
			this->mFilename = "";

		auto journal = values.find("journal");
		if (journal != values.end())
		{
			bool bjournal;
			std::istringstream is(journal->first);
			is >> std::boolalpha >> bjournal;
			this->mJournal = bjournal;
		}
		else
			this->mJournal = true;

		auto password = values.find("password");
		if (password != values.end())
			this->mPassword = password->first;
		else
			this->mPassword = std::string();

		auto cacheSize = values.find("cache size");
		if (cacheSize != values.end())
			this->mCacheSize = stoi(cacheSize->first);
		else
			this->mCacheSize = 5000;
		auto limitSize = values.find("limit size");

		if (limitSize != values.end())
			this->mLimitSize = stoi(limitSize->first);
		else
			this->mLimitSize = INT64_MAX;

		auto upgrade = values.find("upgrade");
		if (upgrade != values.end())
		{
			bool bupgrade;
			std::istringstream is(upgrade->first);
			is >> std::boolalpha >> bupgrade;
			this->mUpgrade = bupgrade;
		}
		else
			this->mUpgrade = false;
	}
}