#pragma once

#include "Scene.h"

class SceneManager
{

public:
	SceneManager() = delete;
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;

private:
	static Scene* m_pCurrentScene;

public:
	//InputCallbacks
	static  void OnKeyPressed(const int key, const KeyState state);
	static void OnMouseMove(const int x, const int y);
	static void OnMouseButtonUp(const MouseButton button);
	static void OnMouseButtonDown(const MouseButton button);
	static void Update(const float deltaTime, const float totalTime = 0);

public:
	static  void Initialize();
	static  void Load(Scene* const scene);
	static  void ShutDown();

};