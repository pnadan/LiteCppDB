// LiteCppDBConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Display.h"
#include "InputCommand.h"
#include "ConsoleProgram.h"

#include "..\LiteCppDB\LiteCppDB.h"  

#include "..\LiteCppDB\StringScanner.h"  

#include <iostream>  

using namespace std;
using namespace LiteCppDB_Console;

int main()
{
	InputCommand input;
	const Display display;

	SetConsoleTitle(L"LiteCppDB");

	ConsoleProgram cp;
	cp.Start(input, display);

	auto sc = LiteCppDB::StringScanner::StringScanner("");
	auto s = sc.getSource();
}

