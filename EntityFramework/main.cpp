// BasicWinApi.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"


#include "WindowsApp.h"
#include "SceneManager.h"


struct AtExit
{
	~AtExit()
	{
		_CrtDumpMemoryLeaks();
	}
} doAtExit;



using namespace UTILITY;

class ExampleScene :public Scene
{
public:
	ExampleScene():Scene()
	{

	}
	~ExampleScene(){}


	void OnStart()
	{
		PRINTL("OnSTart()");

	}
	void Update(float deltaTime, float totalTime = 0)
	{
		//PRINTL("Update(" + ToString(deltaTime) + ", " + ToString(totalTime) + ")");
	}
	void OnExit()
	{
		PRINTL("OnExit()");

	}

	//for any post rendering stuff (and yes, idea nicked from unity :D)
	void PostUpdate() {}

	//InputCallbacks
	void OnKeyPressed(const int key, const KeyState state)
	{
		PRINTL("Key Pressed: " + ToString(key));

		//SceneManager::Load(std::make_unique<ExampleScene>());
	}
	void OnMouseMove(const int x, const int y)
	{
		PRINTL("Mouse Move: " + ToString(x) + ", " + ToString(y));
	}
	void OnMouseButtonUp(MouseButton const button)
	{
		PRINTL("Mouse Button Up: " + ToString(static_cast<int>(button)));
	}
	void OnMouseButtonDown(MouseButton const button)
	{
		PRINTL("Mouse Button Down: " + ToString(static_cast<int>(button)));
	}

};


using namespace UTILITY;
int main()
{
	// Create application in 1280x720 window
	WindowsApp::Create(1280, 720, "EMPTY WINDOW KUBA");
	SceneManager::Load(std::make_unique<ExampleScene>());

	const int appState = WindowsApp::Run();
	WaitForKeypress();

	
	return 0;
}

