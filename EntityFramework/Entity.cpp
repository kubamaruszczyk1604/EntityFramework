#include "Entity.h"


namespace KLM_FRAMEWORK
{

	Entity::Entity(const std::string& ID) :
		m_ID{ ID },
		m_pParent{ nullptr }
	{
	}


	Entity::~Entity()
	{
	}


	void Entity::AddComponent(ComponentUnique component)
	{
		component.get()->SetParent(this);
		m_pComponents.push_back(std::move(component));

	}

	Component * Entity::GetComponentFirst(ComponentType const type)
	{
		for (int i = 0; i < m_pComponents.size(); ++i)
		{
			if (m_pComponents[i]->GetType() == type) return m_pComponents[i].get();
		}

		return nullptr;
	}

	void Entity::CalculateTransform()
	{

		//WORLD TRANSFORM CALCULATION
		m_Transform.SetWorld(m_Transform.GetParentTransformStack() *
			glm::translate(m_Identity, m_Transform.GetPosition()));


		const Vec3& rotation = m_Transform.GetRotation();
		m_Transform.SetWorld(glm::rotate(m_Transform.GetWorldMat(), rotation.x, glm::vec3(1, 0, 0)));
		m_Transform.SetWorld(glm::rotate(m_Transform.GetWorldMat(), rotation.y, glm::vec3(0, 1, 0)));
		m_Transform.SetWorld(glm::rotate(m_Transform.GetWorldMat(), rotation.z, glm::vec3(0, 0, 1)));
		m_Transform.SetWorld(glm::scale(m_Transform.GetWorldMat(), m_Transform.GetScale()));



		for (int i = 0; i < m_pChildren.size(); ++i)
		{
			m_pChildren[i]->GetTransform()->SetParentTransformStack(m_Transform.GetWorldMat());
		}


	}
}