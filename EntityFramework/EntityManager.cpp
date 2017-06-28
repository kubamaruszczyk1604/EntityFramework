#include "EntityManager.h"


namespace KLM_FRAMEWORK
{
	//#include "BehaviourManager.h"



	EntityManager::EntityManager()
	{
	}

	EntityManager::~EntityManager()
	{
	}

	void EntityManager::AddEntity(EntityUnique entity)
	{
		m_pEntities.push_back(std::move(entity));
	}

	void EntityManager::UpdateXForms(float const deltaTime, float const totalTime)
	{
		for (int i = 0; i < m_pEntities.size(); ++i)
		{
			m_pEntities[i]->CalculateTransform();
		}
		//PRINTL("UPDATING X FORMS..");

	}

	void EntityManager::Clear()
	{
		m_pEntities.clear();
	}
}