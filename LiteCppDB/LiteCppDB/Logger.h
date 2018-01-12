#pragma once

#include <cstddef>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

namespace LiteCppDB
{
#define DEBUG_MODE

#ifdef DEBUG_MODE
	class Logger
	{
	public:
		template<typename... Args>
		static void log(const Args&... args)
		{
			ofstream ofs(msDebugFileName, ios_base::app);
			if (ofs.fail()) {
				cerr << "Unable to open debug file!" << endl;
				return;
			}
			logHelper(ofs, args...);
			ofs << endl;
		}

	private:
		template<typename T1>
		static void logHelper(ofstream& ofs, const T1& t1)
		{
			ofs << t1;
		}

		template<typename T1, typename... Tn>
		static void logHelper(ofstream& ofs, const T1& t1, const Tn&... args)
		{
			ofs << t1;
			logHelper(ofs, args...);
		}

		//static const char* msDebugFileName;
		static const char* msDebugFileName;
		static bool msLoggingEnabled;
	};

	//const char* Logger::msDebugFileName = "debugfile.out";
	//bool Logger::msLoggingEnabled = false;

	#define log(...) Logger::log(__func__, "(): ", __VA_ARGS__)
#else
	#define log(...)
#endif
}

//const char* LiteCppDB::Logger::msDebugFileName = "debugfile.out";
//bool LiteCppDB::Logger::msLoggingEnabled = false;