#include "stdafx.h"

#include "MemberMapper.h"

namespace LiteCppDB
{
	bool MemberMapper::getAutoId() noexcept
	{
		return this->mAutoId;
	}
	void MemberMapper::setAutoId(bool autoId) noexcept
	{
		this->mAutoId = autoId;
	}

	// Member name
	std::string MemberMapper::getMemberName()
	{
		return this->mMemberName;
	}
	void MemberMapper::getMemberName(std::string memberName)
	{
		this->mMemberName = memberName;
	}

	// Member returns data type
	std::any MemberMapper::getDataType()
	{
		return this->mDataType;
	}
	void MemberMapper::getDataType(std::any dataType)
	{
		this->mDataType = dataType;
	}

	// Converted document field name
	std::string MemberMapper::getFieldName()
	{
		return this->mFieldName;
	}
	void MemberMapper::getFieldName(std::string fieldName)
	{
		this->mFieldName = fieldName;
	}
}