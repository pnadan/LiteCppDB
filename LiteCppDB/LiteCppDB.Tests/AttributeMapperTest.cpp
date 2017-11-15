#include "stdafx.h"

#include "AttributeMapperTest.h"

#include "..\LiteCppDB\JsonSerializer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LiteCppDB_Tests
{
#pragma region AttrAddress
	int32_t AttrAddress::getAddressPK()
	{
		return int32_t();
	}
	void AttrAddress::setAddressPK(int32_t addressPK)
	{
	}
	std::string AttrAddress::getStreet()
	{
		return std::string();
	}
	void AttrAddress::setStreet(std::string street)
	{
	}
#pragma endregion

#pragma region AttrCustomer
	int32_t AttrCustomer::getMyPK()
	{
		return int32_t();
	}
	void AttrCustomer::setMyPK(int32_t myPK)
	{
	}
	std::string AttrCustomer::getNameCustomer()
	{
		return std::string();
	}
	void AttrCustomer::setNameCustomer(std::string nameCustomer)
	{
	}
	bool AttrCustomer::getIgnore()
	{
		return false;
	}
	void AttrCustomer::setIgnore(bool ignore)
	{
	}
	LiteCppDB_Tests::AttrAddress AttrCustomer::getAddress()
	{
		return LiteCppDB_Tests::AttrAddress();
	}
	void AttrCustomer::setAddress(LiteCppDB_Tests::AttrAddress address)
	{
	}
	std::vector<LiteCppDB_Tests::AttrAddress> AttrCustomer::getAddresses()
	{
		return std::vector<LiteCppDB_Tests::AttrAddress>();
	}
	void AttrCustomer::setAddresses(std::vector<LiteCppDB_Tests::AttrAddress> addresses)
	{
	}
#pragma endregion

	TEST_CLASS(AttributeMapperTest_Test)
	{
	public:

		TEST_METHOD(Database___AttributeMapper_Test)
		{
			const bool m_TestImplemented = false;
			Assert::IsTrue(m_TestImplemented);

			auto mapper = new LiteCppDB::BsonMapper();

			//auto c0 = AttrCustomer()
			//{
			//	setMyPK(1),
			//	//NameCustomer = "J",
			//	//Address = new AttrAddress{ AddressPK = 5, Street = "R" },
			//	//Ignore = true,
			//	//Addresses = new List<AttrAddress>()
			//	//{
			//	//	new AttrAddress{ AddressPK = 3 },
			//	//		new AttrAddress{ AddressPK = 4 }
			//	//}
			//};

			//auto j0 = LiteCppDB::JsonSerializer().Serialize(mapper.ToDocument(c0));

			//auto c1 = mapper.ToObject<AttrCustomer>(LiteCppDB::JsonSerializer().Deserialize(j0).AsDocument);

			//Assert::AreEqual(c0.getMyPK(), c1.getMyPK());
			//Assert::AreEqual(c0.getNameCustomer(), c1.getNameCustomer());
			//Assert::AreEqual(false, c1.Ignore);
			//Assert::AreEqual(c0.getAddress().getAddressPK(), c1.getAddress().getAddressPK());
			//Assert::AreEqual(c0.getAddresses().at(0).getAddressPK(), c1.getAddresses().at(0).getAddressPK());
			//Assert::AreEqual(c0.getAddresses().at(0).getAddressPK(), c1.getAddresses().at(0).getAddressPK());
		}
	};
}