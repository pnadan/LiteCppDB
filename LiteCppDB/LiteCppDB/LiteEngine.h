#pragma once

#ifdef LITECPPDB_EXPORTS
#define LITECPPDB_API __declspec(dllexport)
#else
#define LITECPPDB_API __declspec(dllimport)
#endif

namespace LiteCppDB
{
	class LITECPPDB_API LiteEngine
	{
	public:
		LiteEngine() {};

#pragma region Services instances
#pragma endregion Services instances
	private:
	};
}