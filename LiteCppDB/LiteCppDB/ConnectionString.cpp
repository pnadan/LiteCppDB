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
	bool ConnectionString::getJournal()
	{
		return this->mJournal;
	}
	void ConnectionString::setJournal(bool journal)
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
	int ConnectionString::getCacheSize()
	{
		return this->mCacheSize;
	}
	void ConnectionString::setCacheSize(int32_t cacheSize)
	{
		this->mCacheSize = cacheSize;
	}

	// "initial size": If database is new, initialize with allocated space - support KB, MB, GB (default: null)
	int64_t ConnectionString::getInitialSize()
	{
		return this->mInitialSize;
	}
	void ConnectionString::setInitialSize(int64_t initialSize)
	{
		this->mInitialSize = initialSize;
	}

	// "limit size": Max limit of datafile - support KB, MB, GB (default: null)
	int64_t ConnectionString::getLimitSize()
	{
		return this->mLimitSize;
	}
	void ConnectionString::setLimitSize(int64_t limitSize)
	{
		this->mLimitSize = limitSize;
	}

	// "log": Debug messages from database - use `LiteDatabase.Log` (default: Logger.NONE)
	uint8_t ConnectionString::getLog()
	{
		return this->mLog;
	}
	void ConnectionString::setLog(uint8_t log)
	{
		this->mLog = log;
	}

	// "upgrade": Test if database is in old version and update if needed (default: false)
	bool ConnectionString::getUpgrade()
	{
		return this->mUpgrade;
	}
	void ConnectionString::setUpgrade(bool upgrade)
	{
		this->mUpgrade = upgrade;
	}

	// "async": Use "sync over async" to UWP apps access any directory
	bool ConnectionString::getAsync()
	{
		return this->mAsync;
	}
	void ConnectionString::setAsync(bool async)
	{
		this->mAsync = async;
	}

	// Initialize empty connection string
	ConnectionString::ConnectionString()
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