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




using namespace KLM_FRAMEWORK;

class ExampleScene :public Scene
{
public:
	ExampleScene():Scene()
	{

	}
	~ExampleScene(){}


	void OnStart()
	{
		PRINTL("OnStart()");
		Entity* e1 = new Entity("Testuje 1");
		e1->GetTransform()->SetPositionY(10.0f);
		Entity* e2 = new Entity("Testuje 2");
		e1->AddChild(e2);
		AddEntity(e1);
		AddEntity(e2);

	}
	void Update(float deltaTime, float totalTime = 0)
	{
		//PRINTL("Update(" + ToString(deltaTime) + ", " + ToString(totalTime) + ")");
	}
	void OnExit()
	{
		PRINTL("OnExit()");

	}

	void PostUpdate() {}

	//InputCallbacks
	void OnKeyPressed(const int key, const KeyState state)
	{
		PRINTL("Key Pressed: " + ToString(key));

		SceneManager::Load(new ExampleScene());
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



int main()
{
	// Create application in 1280x720 window
	WindowsApp::Create(1280, 720, "EMPTY WINDOW");
	SceneManager::Load(new ExampleScene());

	const int appState = WindowsApp::Run();
	WaitForKeypress();

	
	return 0;
}

