#include "stdafx.h"

#include "LiteEngine.h"

namespace LiteCppDB
{
	std::vector<std::string> LiteEngine::GetCollectionNames() noexcept
	{
		return std::vector<std::string>();
	}

	bool LiteEngine::DropCollection(std::string collection) noexcept
	{
		return false;
	}

	bool LiteEngine::RenameCollection(std::string collection, std::string newName) noexcept
	{
		return false;
	}
}