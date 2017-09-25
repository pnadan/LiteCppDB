#include "stdafx.h"

#include "BsonTest.h"

#include "..\LiteCppDB\BsonArray.h"
#include "..\LiteCppDB\BsonSerializer.h"
#include "..\LiteCppDB\JsonSerializer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LiteCppDB_Tests
{
	LiteCppDB::BsonDocument BsonTest::CreateDoc()
	{
		// create same object, but using BsonDocument
		auto doc = LiteCppDB::BsonDocument();

		doc.setFieldForDoc("_id", LiteCppDB::BsonDocument::BsonValue(123));
		doc.setFieldForDoc("FirstString", LiteCppDB::BsonDocument::BsonValue("BEGIN this string \" has \" \t and this \f \n\r END"));

		return doc;
	}

	TEST_CLASS(BsonTest_Test)
	{
	public:

		TEST_METHOD(Document___Bson_Test)
		{
			LiteCppDB_Tests::BsonTest bt;
			auto o = bt.CreateDoc();

			auto bson = LiteCppDB::BsonSerializer().Serialize(o);
			auto json = LiteCppDB::JsonSerializer().Serialize(o);

			auto doc = LiteCppDB::BsonSerializer().Deserialize(bson);

			Assert::AreEqual((int32_t)123, doc.TryGetValue("_id").AsInt32());

			Assert::AreEqual(o.TryGetValue("FirstString").AsString(), doc.TryGetValue("FirstString").AsString());
		}
	};
}