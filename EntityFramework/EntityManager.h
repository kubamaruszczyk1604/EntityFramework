#pragma once
#include "Entity.h"

namespace KLM_FRAMEWORK
{
	using EntityUnique = std::unique_ptr<Entity>;
	using ListOfEntities = std::vector<EntityUnique>;

	class EntityManager
	{

	private:

		std::vector<EntityUnique> m_pEntities;

	public:

		EntityManager();
		EntityManager(const EntityManager&) = delete;
		EntityManager& operator=(const EntityManager&) = delete;
		~EntityManager();

		void AddEntity(EntityUnique entity);
		void UpdateXForms(float deltaTime, float totalTime = 0);
		void Clear();

		ListOfEntities* GetListOfEntities() { return &m_pEntities; }


	};
}
