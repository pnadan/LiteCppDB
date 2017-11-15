#include "stdafx.h"

#include "DocumentTest.h"

#include "..\LiteCppDB\JsonSerializer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LiteCppDB_Tests
{
	TEST_CLASS(DocumentTest_Test)
	{
	public:

		TEST_METHOD(Document___Document_ImplicitConvert_Test)
		{
			//const bool m_TestImplemented = false;
			//Assert::IsTrue(m_TestImplemented);

			auto obj = std::map<std::string, LiteCppDB::BsonDocument::BsonValue>
			{
				{ "int", 123 },
				/*{ "arr", std::vector<std::any>{ static_cast<std::any>(3.0), static_cast<std::any>(2), static_cast<std::any>(1), static_cast<std::any>("zero"), static_cast<std::any>(false) } },
				{ "doc", std::map<std::string, std::any>
				{
					{ "a", "a" },
					{ "b", std::vector<int32_t>{ 0 } },
				}*/
			};

			auto doc = LiteCppDB::BsonDocument::BsonValue(obj);

			auto json = LiteCppDB::JsonSerializer::Serialize(doc, false, true);

			Assert::AreEqual(static_cast<std::string>("{\"int\":123,\"arr\":[3.0,2,1,\"zero\",false],\"doc\":{\"a\":\"a\",\"b\":[0]}}"), json);
		}

		TEST_METHOD(Document___Document_copies_properties_to_KeyValue_array)
		{
			const bool m_TestImplemented = false;
			Assert::IsTrue(m_TestImplemented);

			// ARRANGE
			// create a Bson document with all possible value types
			auto document = LiteCppDB::BsonDocument();
			document.setFieldForDoc("string", LiteCppDB::BsonDocument::BsonValue("string"));
			document.setFieldForDoc("bool", LiteCppDB::BsonDocument::BsonValue(true));
			document.setFieldForDoc("DateTime", LiteCppDB::BsonDocument::BsonValue(std::chrono::system_clock::now()));
			document.setFieldForDoc("double", LiteCppDB::BsonDocument::BsonValue((double)1.0));
			document.setFieldForDoc("int32_T", LiteCppDB::BsonDocument::BsonValue((int32_t)1));
			document.setFieldForDoc("int64_t", LiteCppDB::BsonDocument::BsonValue((int64_t)1));
			//document.setFieldForDoc("uint8_t", LiteCppDB::BsonDocument::BsonValue(std::vector byte{ (uint8_t)1 }));
			document.setFieldForDoc("bsonDocument", LiteCppDB::BsonDocument());

			// ACT
			// copy all properties to destination array

			auto result = std::map<std::string, LiteCppDB::BsonValue>();
			//document.CopyTo(result, 0);

			// ASSERT
			// all BsonValue instances have been added to the array by reference
			
			//Assert::IsTrue(result.All(kv = > object.ReferenceEquals(document.Get(kv.Key), kv.Value)));
		}
	};
}