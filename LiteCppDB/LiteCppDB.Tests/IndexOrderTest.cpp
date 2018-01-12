#include "stdafx.h"

#include "IndexOrderTest.h"
#include "TempFile.h"

#include "..\LiteCppDB\LiteEngine.h"
#include "..\LiteCppDB\BsonDocument.h"

#include <map>
//#include <numeric>
#include <gsl\gsl>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LiteCppDB_Tests
{
	TEST_CLASS(IndexOrderTest_Test)
	{
	public:
		TEST_METHOD(Engine___Index_Order)
		{
			const bool m_TestImplemented = true;
			Assert::IsTrue(m_TestImplemented);

			auto tmp = TempFile();

			auto db = LiteCppDB::LiteEngine(tmp.getFileName());
			
			std::map<std::string, LiteCppDB::BsonValue> Mymap;
			Mymap.insert({ std::string("text"), LiteCppDB::BsonValue("D") });
			db.Insert(std::string("col"), LiteCppDB::BsonDocument(Mymap));

			std::map<std::string, LiteCppDB::BsonValue> Mymap1;
			Mymap1.insert({ std::string("text"), LiteCppDB::BsonValue("A") });
			db.Insert(std::string("col"), LiteCppDB::BsonDocument(Mymap1));

			std::map<std::string, LiteCppDB::BsonValue> Mymap2;
			Mymap2.insert({ std::string("text"), LiteCppDB::BsonValue("E") });
			db.Insert(std::string("col"), LiteCppDB::BsonDocument(Mymap2));

			std::map<std::string, LiteCppDB::BsonValue> Mymap3;
			Mymap3.insert({ std::string("text"), LiteCppDB::BsonValue("C") });
			db.Insert(std::string("col"), LiteCppDB::BsonDocument(Mymap3));

			std::map<std::string, LiteCppDB::BsonValue> Mymap4;
			Mymap4.insert({ std::string("text"), LiteCppDB::BsonValue("B") });
			db.Insert(std::string("col"), LiteCppDB::BsonDocument(Mymap4));

			db.EnsureIndex(std::string("col"), std::string("text"));

			auto asc_v = db.Find(std::string("col"), LiteCppDB::Query::All(std::string("text"), LiteCppDB::Query::Ascending));
			std::string asc;
			//std::string asc(asc_v.begin(), asc_v.end());
			//asc = std::accumulate(begin(asc_v), end(asc_v), asc);

			auto desc_v = db.Find(std::string("col"), LiteCppDB::Query::All(std::string("text"), LiteCppDB::Query::Descending));
			std::string desc;
			//std::string desc(desc_v.begin(), desc_v.end());
			//desc = std::accumulate(begin(desc_v), end(desc_v), desc);

			Assert::AreEqual(std::string("ABCDE"), asc);
			Assert::AreEqual(std::string("EDCBA"), desc);

			auto indexes = db.GetIndexes(std::string("col"));

			Assert::AreEqual(1, gsl::narrow_cast<int32_t>(indexes.size()));
		}
	};
}