#pragma once
#include "StdIncludes.h"
#include "Component.h"
#include "Transform.h"


class Entity
{

private:
	std::vector<Entity*> m_pChildren;
	std::vector<ComponentUnique> m_pComponents;
	std::string m_ID;
	Entity* m_pParent;

	Transform m_Transform;

	Entity() = default;
	Entity(const Entity&) = delete;
	Entity& operator=(const Entity&) = delete;
	Mat4 m_Identity;
public:
	explicit Entity(const std::string& ID);
	virtual ~Entity();

	void AddChild(Entity* const child) {
		child->SetParent(this);
		m_pChildren.push_back(child);
	}

	void AddComponent(ComponentUnique component);

	void SetParent(Entity* const entity) { m_pParent = entity; }
	Entity* const GetParent() const { return m_pParent; }

	const std::string& GetID() const { return m_ID; }

	const int GetComponentCount() const { return m_pComponents.size(); }

	Component* GetComponent(int const index) { m_pComponents[index]; }

	Component* GetComponentFirst(ComponentType type);

	Transform* GetTransform() { return &m_Transform; }

	void CalculateTransform();

};

using EntityUnique = std::unique_ptr<Entity>;

