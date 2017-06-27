#pragma once
#include "StdIncludes.h"
#include "InputSystem.h"

class Scene
{
public:
	Scene() = default;
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;

	virtual ~Scene();
	virtual void OnStart() = 0;
	virtual void Update(float deltaTime, float totalTime = 0) = 0;
	virtual void OnExit() = 0;

	//for any post rendering stuff (and yes, idea nicked from unity :D)
	virtual void PostUpdate() {}

	//InputCallbacks
	virtual void OnKeyPressed(const int key, const KeyState state);
	virtual void OnMouseMove(const int x, const int y);
	virtual void OnMouseButtonUp(MouseButton const button);
	virtual void OnMouseButtonDown(MouseButton const button);
};

using SceneUniquePtr = std::unique_ptr<Scene>;