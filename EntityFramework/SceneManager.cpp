#include "SceneManager.h"
#include "InputSystem.h"
//#include "EntityManager.h"
//#include "ResourceManager.h"
Scene* SceneManager::m_pCurrentScene{ nullptr };

void SceneManager::Initialize()
{
	InputSystem::SetKeyboardCallback(SceneManager::OnKeyPressed);
	InputSystem::SetMouseButtonCallback(SceneManager::OnMouseButtonUp, SceneManager::OnMouseButtonDown);
	InputSystem::SetMouseMoveCallback(SceneManager::OnMouseMove);
}

void SceneManager::Load(Scene * const scene)
{
	{
		if (m_pCurrentScene)
		{
			m_pCurrentScene->OnExit();
			delete m_pCurrentScene;
			//EntityManager::Reset();
		}
		m_pCurrentScene = scene;
		m_pCurrentScene->OnStart();
	}

}

void SceneManager::Update(const float deltaTime, const float totalTime)
{
	if (m_pCurrentScene) {
		m_pCurrentScene->Update(deltaTime, totalTime);
		//EntityManager::Update(deltaTime, totalTime);
		//DXRenderer::Update(deltaTime, totalTime);
		m_pCurrentScene->PostUpdate();
	}
}

void SceneManager::ShutDown()
{
	if (m_pCurrentScene)
	{
		m_pCurrentScene->OnExit();
		//EntityManager::ShutDown();
	}

	//ResourceManager::ReleaseResources();

}

void SceneManager::OnKeyPressed(const int key, const KeyState state)
{
	if (m_pCurrentScene)
	{
		m_pCurrentScene->OnKeyPressed(key, state);
	}
}

void SceneManager::OnMouseMove(const int x, const int y)
{
	if (m_pCurrentScene)
	{
		m_pCurrentScene->OnMouseMove(x, y);
	}
}

void SceneManager::OnMouseButtonUp(const MouseButton button)
{
	if (m_pCurrentScene)
	{
		m_pCurrentScene->OnMouseButtonUp(button);
	}
}

void SceneManager::OnMouseButtonDown(const MouseButton button)
{
	if (m_pCurrentScene)
	{
		m_pCurrentScene->OnMouseButtonDown(button);
	}
}