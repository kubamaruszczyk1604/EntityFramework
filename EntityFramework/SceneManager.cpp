#include "SceneManager.h"
#include "InputSystem.h"
//#include "EntityManager.h"
//#include "ResourceManager.h"


SceneUniquePtr SceneManager::m_upCurrentScene;


void SceneManager::Initialize()
{
	InputSystem::SetKeyboardCallback(SceneManager::OnKeyPressed);
	InputSystem::SetMouseButtonCallback(SceneManager::OnMouseButtonUp, SceneManager::OnMouseButtonDown);
	InputSystem::SetMouseMoveCallback(SceneManager::OnMouseMove);
}

void SceneManager::Load(SceneUniquePtr scene)
{
	{
		if (m_upCurrentScene)
		{
			m_upCurrentScene.get()->OnExit();
			//upCurrentScene.release();
			//EntityManager::Reset();
		}
		m_upCurrentScene = std::move(scene);
		m_upCurrentScene->OnStart();
	}

}

void SceneManager::Update(const float deltaTime, const float totalTime)
{
	if (m_upCurrentScene) {
		m_upCurrentScene->Update(deltaTime, totalTime);
		//EntityManager::Update(deltaTime, totalTime);
		//DXRenderer::Update(deltaTime, totalTime);
		m_upCurrentScene->PostUpdate();
	}
}

void SceneManager::ShutDown()
{
	if (m_upCurrentScene)
	{
		m_upCurrentScene->OnExit();
		//EntityManager::ShutDown();
	}

	//ResourceManager::ReleaseResources();

}

void SceneManager::OnKeyPressed(const int key, const KeyState state)
{
	if (m_upCurrentScene)
	{
		m_upCurrentScene->OnKeyPressed(key, state);
	}
}

void SceneManager::OnMouseMove(const int x, const int y)
{
	if (m_upCurrentScene)
	{
		m_upCurrentScene->OnMouseMove(x, y);
	}
}

void SceneManager::OnMouseButtonUp(const MouseButton button)
{
	if (m_upCurrentScene)
	{
		m_upCurrentScene->OnMouseButtonUp(button);
	}
}

void SceneManager::OnMouseButtonDown(const MouseButton button)
{
	if (m_upCurrentScene)
	{
		m_upCurrentScene->OnMouseButtonDown(button);
	}
}