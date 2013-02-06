// GSP420MainCore.cpp : Defines the entry point for the console application
//

#include "stdafx.h"
#include "StateManager.h"
#include <iostream> // Only being used because of reporting errors to console. Delete this line when fixed up better.

using namespace std;


int _tmain(int argc, _TCHAR* argv[]) //Entry point of application
{
	StateManager stateManager; // Makes our StateManager class
	try //If any error we haven't handled further in occurs, we want to properly log what the error was to a text file or such.
	{
		stateManager.Run();
	}
	catch (...)
	{
		//TODO: Properly log whatever occurred.
		cout << "An error occurred, but we haven't yet figured out how to properly log it. Press enter to throw the exception to the debugger.";
		throw;
	}

	return 0;
}

