#include "stdafx.h"

#include "BsonTest.h"

#include <iomanip>

#include "..\LiteCppDB\BsonArray.h"
#include "..\LiteCppDB\BsonSerializer.h"
#include "..\LiteCppDB\JsonSerializer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LiteCppDB_Tests
{
	LiteCppDB::BsonDocument BsonTest::CreateDoc(std::stringstream& ss)
	{
		// create same object, but using BsonDocument
		auto doc = LiteCppDB::BsonDocument();

		doc.setFieldForDoc("_id", LiteCppDB::BsonDocument::BsonValue(123));
		doc.setFieldForDoc("FirstString", LiteCppDB::BsonDocument::BsonValue("BEGIN this string \" has \" \t and this \f \n\r END"));
		doc.setFieldForDoc("SecondString", LiteCppDB::BsonDocument::BsonValue("This is the second string"));

		std::chrono::time_point<std::chrono::system_clock> valueClock = std::chrono::system_clock::now();
		const auto in_time_t = std::chrono::system_clock::to_time_t(valueClock);
		struct tm timeinfo;
		::localtime_s(&timeinfo, &in_time_t);
		ss << std::put_time(&timeinfo, "%d-%m-%Y %H:%M:%S");
		doc.setFieldForDoc("Date", LiteCppDB::BsonDocument::BsonValue(valueClock));

		return doc;
	}

	TEST_CLASS(BsonTest_Test)
	{
	public:

		TEST_METHOD(Document___Bson_Test)
		{
			std::stringstream ss;

			LiteCppDB_Tests::BsonTest bt;
			auto o = bt.CreateDoc(ss);

			auto bson = LiteCppDB::BsonSerializer().Serialize(o);
			auto json = LiteCppDB::JsonSerializer().Serialize(o);

			auto doc = LiteCppDB::BsonSerializer().Deserialize(bson);
			
			Assert::AreEqual((int32_t)123, doc.TryGetValue("_id").AsInt32());

			Assert::AreEqual(o.TryGetValue("FirstString").AsString(), (std::string)"BEGIN this string \" has \" \t and this \f \n\r END");
			Assert::AreEqual(doc.TryGetValue("FirstString").AsString(), (std::string)"BEGIN this string \" has \" \t and this \f \n\r END");
			Assert::AreEqual(o.TryGetValue("FirstString").AsString(), doc.TryGetValue("FirstString").AsString());

			Assert::AreEqual(o.TryGetValue("SecondString").AsString(), (std::string)"This is the second string");
			Assert::AreEqual(doc.TryGetValue("SecondString").AsString(), (std::string)"This is the second string");
			Assert::AreEqual(o.TryGetValue("SecondString").AsString(), doc.TryGetValue("SecondString").AsString());

			Assert::AreEqual(o.TryGetValue("Date").AsString(), ss.str());
		}
	};
}