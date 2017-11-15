#pragma once

#include "..\LiteCppDB\BsonMapper.h"

namespace LiteCppDB_Tests
{
#pragma region AttributeMapperTest
	class AttributeMapperTest
	{
	public:
	};
#pragma endregion

#pragma region AttrAddress
	class AttrAddress
	{
	public:
		int32_t getAddressPK();
		void setAddressPK(int32_t addressPK);

		std::string getStreet();
		void setStreet(std::string street);
	};
#pragma endregion

#pragma region AttrCustomer
	class AttrCustomer
	{
	public:
		int32_t getMyPK();
		void setMyPK(int32_t myPK);

		std::string getNameCustomer();
		void setNameCustomer(std::string nameCustomer);

		bool getIgnore();
		void setIgnore(bool ignore);

		AttrAddress getAddress();
		void setAddress(AttrAddress address);

		std::vector<LiteCppDB_Tests::AttrAddress> getAddresses();
		void setAddresses(std::vector<LiteCppDB_Tests::AttrAddress> addresses);
	};
#pragma endregion


}