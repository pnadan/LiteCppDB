#include "stdafx.h"
#include "ICommand.h"


using namespace std;

namespace LiteCppDB_Console
{
	ICommand::ICommand(const ICommand& src) noexcept
	{
	}

	ICommand& ICommand::operator=(const ICommand& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		return *this;
	}

	ICommand::ICommand(const ICommand&& src) noexcept
	{
	}

	ICommand& ICommand::operator=(ICommand&& rhs) noexcept
	{
		if (this == &rhs)
		{
			return *this;
		}

		return *this;
	}
}