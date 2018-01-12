#pragma once

#ifdef LITECPPDB_EXPORTS
#define LITECPPDB_API __declspec(dllexport)
#else
#define LITECPPDB_API __declspec(dllimport)
#endif

#include "BsonDocument.h"
#include "BsonArray.h"
#include "BsonValue.h"

#include <string>
#include <vector>
#include <map>

namespace LiteCppDB
{
	class LITECPPDB_API BsonMapper
	{
	public:
		/// Deserialize a BsonDocument to entity class
//		object ToObject(Type type, BsonDocument doc);
//
//		/// Deserialize a BsonDocument to entity class
//		struct ToObject<struct>(BsonDocument doc);
//
//	private:
//		/// Deserialize an BsonValue to .NET object typed in T
//		T Deserialize<T>(BsonValue value);
//
//#pragma region Basic direct.NET convert types
//
//		// direct bson types
//		HashSet<Type> _bsonTypes = HashSet<Type>
//		{
//			typeof(String),
//			typeof(Int32),
//			typeof(Int64),
//			typeof(Boolean),
//			typeof(Guid),
//			typeof(DateTime),
//			typeof(Byte[]),
//			typeof(ObjectId),
//			typeof(Double),
//			typeof(Decimal)
//		};
//
//		// simple convert types
//		HashSet<Type> _basicTypes = new HashSet<Type>
//		{
//			typeof(Int16),
//			typeof(UInt16),
//			typeof(UInt32),
//			typeof(Single),
//			typeof(Char),
//			typeof(Byte),
//			typeof(SByte)
//		};
//
//#pragma endregion
//
//		object Deserialize(std::any type, BsonValue value);
//
//		object DeserializeArray(std::any type, BsonArray array);
//
//		object DeserializeList(std::any type, BsonArray value);
//
//		void DeserializeDictionary(std::any K, std::any T, std::map dict, BsonDocument value);
//
//		void DeserializeObject(std::any type, std::any obj, BsonDocument value);
	};
}