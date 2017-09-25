#pragma once

#ifdef LITECPPDB_EXPORTS
#define LITECPPDB_API __declspec(dllexport)
#else
#define LITECPPDB_API __declspec(dllimport)
#endif

namespace LiteCppDB
{
	// All supported BsonTypes in sort order
	enum class LITECPPDB_API BsonType
	{
		Null = 0,			// Null

		Int8 = 1,			// int32_t (INT8_MIN, INT8_MAX)
		Int16 = 2,			// int32_t (INT16_MIN, INT16_MAX)
		Int32 = 3,			// int32_t (INT32_MIN, INT32_MAX)
		Int64 = 4,			// int64_t (INT64_MIN, INT64_MAX)

		UInt8 = 5,			// uint32_t (UINT8_MIN, UINT8_MAX)
		UInt16 = 6,			// uint32_t (UINT16_MIN, UINT16_MAX)
		UInt32 = 7,			// uint32_t (UINT32_MIN, UINT32_MAX)
		UInt64 = 8,			// uint64_t (UINT64_MIN, UINT64_MAX)

		String = 9,			// std::string
		Double = 9,

		Guid = 10,

		Boolean = 11,		// int64_t
		DateTime = 12,		// Not implemented

		Document = 13,

		MinValue = 14,
		MaxValue = 15,

		ObjectId = 16
	};
}