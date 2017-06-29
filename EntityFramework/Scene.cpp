#include "Scene.h"


namespace KLM_FRAMEWORK
{

	Scene::Scene() :m_pEntityManager{ new EntityManager() }
	{
	}

	Scene::~Scene()
	{
		m_pEntityManager->Clear();//not needed really
		delete m_pEntityManager;
		m_pEntityManager = nullptr;
	}



	void Scene::AddEntity(Entity* entity)
	{
		m_pEntityManager->AddEntity(std::unique_ptr<Entity>(entity));
	}

	void Scene::RemoveEntity(const std::string & ID)
	{
	}

	void Scene::RemoveEntity(Entity * entity)
	{

	}



	void Scene::OnKeyPressed(const int key, const KeyState state)
	{
	}

	void Scene::OnMouseMove(const int x, const int y)
	{
	}

	void Scene::OnMouseButtonUp(MouseButton const button)
	{
	}

	void Scene::OnMouseButtonDown(MouseButton const button)
	{
	}
}