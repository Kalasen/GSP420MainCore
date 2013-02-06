/*
	This file defines the StateManager class. When running, we do a game loop, passing control to specific methods to handle each loop's processing, while we can
switch states at any time. The time elapsed since the last processing cycle is passed in, so that the new cycle will know how much real time has passed to account for.
We will be replacing most of the console filler with the use of the cores. At first I thought a whole CoreManager class would be necessary, but on second thought, all we need
are includes for each other core's interface class. A CoreManager class is redundant if the cores are already offering up public methods through an interface to use what we 
need from them.
*/

#include "StdAfx.h" // Standard library... I think
#include "StateManager.h" // Our StateManager class
#include <iostream> // Now we can work with I/O

using namespace std; // Standard namespace in standard library

StateManager::StateManager(void) // Constructor
{
	currentState = STARTUP; // Default our current state to startup

	cout << "StateManager Created\n"; // Write success to console	
}

void StateManager::Run() // Tell the StateManager to start processing the state of the game
{
	bool running = true; // The game is running

	DWORD startTime = GetTickCount(); // Returns the amount of milliseconds since system startup, effectively the current time
	DWORD elapsedTime = startTime; // No time has passed since the last cycle, on the first cycle

	while (running) //Loop each processing cycle until time to shut down StateManager
	{
		switch (currentState)
		{
			case STARTUP:
				StartUp(elapsedTime);
				break;

			case TITLE:
				Title(elapsedTime);
				break;

			case MAINMENU:
				MainMenu(elapsedTime);
				break;

			case INGAME:
				InGame(elapsedTime);
				break;

			case PAUSE:
				Pause(elapsedTime);

			case SHUTDOWN:
				ShutDown(elapsedTime);
				running = false;
				break;

			default:
				cout << "Error: In unrecognized game state. This is likely caused by a coder adding a new state to the currentState enum without putting a corresponding case in the main game loop.";
				cin.ignore(1);
				running = false;
				break;
		}

		elapsedTime = GetTickCount() - startTime; // Elapsed time in last cycle is the current time, minus the time when we started
	}
}

void StateManager::StartUp(DWORD elapsedTime)
{
	//cout << "Elapsed time since last cycle: " + (int) elapsedTime; //TODO: Fix this. I can't currently figure out how to print it out, simple boxing attempts just lead to memory access violations. It's fine in the debugger though, showing like 16 ms to iterate once through start up.
	cout << "\nStarting up...\n";

	//STUB: We need to load in any resources we'll need here, using CoreManager

	cout << "Startup complete.\n";

	currentState = TITLE;
}

void StateManager::Title(DWORD elapsedTime)
{
	cout << "Title screen displaying.\n";

	//STUB: We need to actually draw the title screen and use the proper I/O

	cout << "Press enter to simulate pressing the button to move on to main menu.";

	cin.ignore(1);

	currentState = MAINMENU;
}

void StateManager::MainMenu(DWORD elapsedTime)
{
	cout << "Main menu displaying.\n";

	//STUB: We need to actually draw the title screen and use the proper I/O

	cout << "Press enter to simulate choosing new game.";

	cin.ignore(1);

	currentState = INGAME;
}

void StateManager::InGame(DWORD elapsedTime)
{
	cout << "Game is running.\n";

	//STUB: We need to actually draw the game, run physics, AI and use the proper I/O. Likely biggest part of code will be happening from here.

	cout << "Press enter to simulate opening pause menu.";

	cin.ignore(1);

	currentState = PAUSE;
}

void StateManager::Pause(DWORD elapsedTime)
{
	cout << "Game is paused.\n";

	//STUB: We need to draw the pause menu, use the proper I/O.

	cout << "Press any key to simulate choosing to quit to desktop.";

	cin.ignore(1);

	currentState = SHUTDOWN;
}

void StateManager::ShutDown(DWORD elapsedTime)
{
	cout << "Shutting down...\n";

	//STUB: Prepare to shut down the program.

	cout << "Shut down procedures complete. Press any key to close.\n";
	cin.ignore(1); // Wait for key
}

StateManager::~StateManager(void) // Destructs the StateManager class
{
	//TODO: Insert any needed cleanup code here

	cout << "StateManager Destroyed"; //Report success
}
