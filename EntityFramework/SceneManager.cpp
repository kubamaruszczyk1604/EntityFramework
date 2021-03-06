#include "SceneManager.h"
#include "InputSystem.h"
#include "EntityManager.h"

//#include "ResourceManager.h"

namespace KLM_FRAMEWORK
{
	SceneUniquePtr SceneManager::m_upCurrentScene;

	void SceneManager::Initialize()
	{
		InputSystem::SetKeyboardCallback(SceneManager::OnKeyPressed);
		InputSystem::SetMouseButtonCallback(SceneManager::OnMouseButtonUp, SceneManager::OnMouseButtonDown);
		InputSystem::SetMouseMoveCallback(SceneManager::OnMouseMove);
	}

	void SceneManager::Load(Scene* scene)
	{

		if (m_upCurrentScene)
		{
			m_upCurrentScene.get()->OnExit();
		}
		m_upCurrentScene = std::unique_ptr<Scene>(scene);
		m_upCurrentScene->OnStart();

	}

	void SceneManager::Update(const float deltaTime, const float totalTime)
	{
		if (m_upCurrentScene)
		{
			m_upCurrentScene->Update(deltaTime, totalTime);
			m_upCurrentScene->GetEntityManager()->Update(deltaTime, totalTime);


			ListOfEntities* list = m_upCurrentScene->GetEntityManager()->GetListOfEntities();

			for (int i = 0; i < list->size(); ++i)
			{
				Entity* e = (*list)[i].get();
				//PRINTL("ENTITY: " + e->GetName() + " is at position: " + ToString(e->GetTransform()->GetWorldPosition()));

			}

			//TODO: SYSTEMS ACT ON ENTITIES HERE
			//DXRenderer::Update(deltaTime, totalTime);
			m_upCurrentScene->PostUpdate();

		}
	}

	void SceneManager::ShutDown()
	{
		if (m_upCurrentScene)
		{
			m_upCurrentScene->OnExit();
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
}