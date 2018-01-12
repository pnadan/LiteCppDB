#pragma once

#include "Reflection.h"

#include <string>

namespace LiteCppDB
{
	// Internal representation for a .NET member mapped to BsonDocument
	class MemberMapper
	{
	private:
		bool mAutoId;
		std::string mMemberName;
		std::any mDataType;
		std::string mFieldName;

	public:
		// If member is Id, indicate that are AutoId
		bool getAutoId() noexcept;
		void setAutoId(bool autoId) noexcept;

		// Member name
		std::string getMemberName();
		void getMemberName(std::string memberName);

		// Member returns data type
		std::any getDataType();
		void getDataType(std::any dataType);

		// Converted document field name
		std::string getFieldName();
		void getFieldName(std::string fieldName);
	};
}