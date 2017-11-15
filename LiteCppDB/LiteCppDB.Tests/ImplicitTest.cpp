#include "stdafx.h"

#include "ImplicitTest.h"

#include <cstdint>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LiteCppDB_Tests
{
	TEST_CLASS(ImplicitTest_Test)
	{
	public:

		TEST_METHOD(Document___Implicit_Test)
		{
			int32_t i = INT32_MAX;
			int64_t l = INT64_MAX;
			uint64_t u = UINT64_MAX;

			auto bi = LiteCppDB::BsonDocument::BsonValue(i);
			auto bl = LiteCppDB::BsonDocument::BsonValue(l);
			auto bu = LiteCppDB::BsonDocument::BsonValue(u);

			Assert::IsTrue(bi.IsInt32());
			Assert::IsTrue(bl.IsInt64());
			Assert::IsTrue(bu.IsUInt64());

			Assert::AreEqual(i, bi.AsInt32());
			//Assert::AreEqual(l, bl.AsInt64());
			Assert::AreEqual(u, bu.AsUInt64());
		}
	};
}