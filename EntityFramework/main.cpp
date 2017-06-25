// BasicWinApi.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"


#include "WindowsApp.h"
using namespace UTILITY;
int main()
{

	// Create application in 1280x720 window
	WindowsApp::Create(1280, 720, "EMPTY WINDOW KUBA");


	// Run the app (start the message pump/loop)
	const int appState = WindowsApp::Run();

	// Clear a few lines on the stdout and wait for a key press

	WaitForKeypress();
	return appState;
}

