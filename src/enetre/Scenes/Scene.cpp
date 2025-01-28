#include "../pch.h"
#include "Scene.h"

template<class T>
T* Scene::GetEntity()
{
	for (int i = 0; i < m_entities.size(); i++)
	{
		if (T* s = dynamic_cast<T*>(m_entities[i])
		{
			return s
		}
	}
	return nullptr;
}

template<class T>
inline void Scene::AddEntity()
{
	T* newEntity = new T();
	m_entities.push_back(newEntity);
}
