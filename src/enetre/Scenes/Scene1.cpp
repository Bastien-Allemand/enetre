#include "../pch.h"
#include "Scene1.h"
#include "../includes.h"

Scene1::Scene1()
{
}

void Scene1::addEntity(Entity* _entity)
{
	m_entities.push_back(_entity);
}

void Scene1::Init()
{
	Player* player = new Player();
	player->Init();
	addEntity(player);

}

void Scene1::Update()
{
	for (Entity* entity : m_entities)
	{
		entity->Update();
	}

}

void Scene1::Render()
{
	for (Entity* entity : m_entities)
	{
		entity->Render();
	}
}

void Scene1::Destroy()
{
	for (Entity* entity : m_entities)
	{
		entity->Destroy();
	}
}

template<class T>
std::vector<T*> Scene1::GetAllEntity()
{
	std::vector<T*> entities;
	for (Entity* entity : m_entities)
	{
		if (T* s = dynamic_cast<T*>(entity))
		{
			entities.push_back(s);
		}
	}
	return entities;
}

template<class T>
inline void Scene1::removeEntitybytype()
{
	for (int i = 0; i < m_entities.size(); i++)
	{
		if (T* s = dynamic_cast<T*>(m_entities[i]))
		{
			delete s;
			m_entities.erase(m_entities.begin() + i);
		}
	}
}
