#include "stdafx.h"

#include "DecimalTest.h"

//#include <cfloat>
#include "float.h"

#include "..\LiteCppDB\BsonArray.h"
#include "..\LiteCppDB\BsonSerializer.h"
#include "..\LiteCppDB\JsonSerializer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LiteCppDB_Tests
{
	TEST_CLASS(DecimalTest_Test)
	{
	public:

		TEST_METHOD(Document___BsonValueDecimal_Test)
		{
			auto d0 = static_cast<double>(0);
			auto d1 = static_cast<double>(1);
			auto dmin = LiteCppDB::BsonDocument::BsonValue(-static_cast<double>(DBL_MIN));
			auto dmax = LiteCppDB::BsonDocument::BsonValue(static_cast<double>(DBL_MAX));

			auto test = dmin.AsDouble();

			Assert::AreEqual(static_cast<std::string>("{\"0.0########\":\"0.000000\"}"), LiteCppDB::JsonSerializer::Serialize(d0));
			Assert::AreEqual(static_cast<std::string>("{\"0.0########\":\"1.000000\"}"), LiteCppDB::JsonSerializer::Serialize(d1));
			Assert::AreEqual(static_cast<std::string>("{\"0.0########\":\"-0.000000\"}"), LiteCppDB::JsonSerializer::Serialize(dmin));
			Assert::AreEqual(static_cast<std::string>("{\"0.0########\":\"179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000\"}"), LiteCppDB::JsonSerializer::Serialize(dmax));

			auto test_0 = dmin.AsDouble();

			auto doc_1 = LiteCppDB::BsonDocument();
			doc_1.setFieldForDoc("A", LiteCppDB::BsonDocument::BsonValue(d0));
			auto b0 = LiteCppDB::BsonSerializer().Serialize(doc_1);

			auto doc_2 = LiteCppDB::BsonDocument();
			doc_2.setFieldForDoc("A", LiteCppDB::BsonDocument::BsonValue(d1));
			auto b1 = LiteCppDB::BsonSerializer().Serialize(doc_2);

			auto doc_3 = LiteCppDB::BsonDocument();
			//doc_3.setFieldForDoc("A", LiteCppDB::BsonDocument::BsonValue(dmin));
			doc_3.setFieldForDoc("A", dmin);
			auto bmin = LiteCppDB::BsonSerializer().Serialize(doc_3);

			auto doc_4 = LiteCppDB::BsonDocument();
			//doc_4.setFieldForDoc("A", LiteCppDB::BsonDocument::BsonValue(dmax));
			doc_4.setFieldForDoc("A", dmax);
			auto bmax = LiteCppDB::BsonSerializer().Serialize(doc_4);

			auto x0 = LiteCppDB::BsonSerializer::Deserialize(b0);
			auto x1 = LiteCppDB::BsonSerializer::Deserialize(b1);
			auto xmin = LiteCppDB::BsonSerializer::Deserialize(bmin);
			auto xmax = LiteCppDB::BsonSerializer::Deserialize(bmax);

			Assert::AreEqual(d0, x0.TryGetValue("A").AsDouble());
			Assert::AreEqual(d1, x1.TryGetValue("A").AsDouble());
			Assert::AreEqual(dmin.AsDouble(), xmin.TryGetValue("A").AsDouble());
			Assert::AreEqual(dmax.AsDouble(), xmax.TryGetValue("A").AsDouble());
		}
	};
}