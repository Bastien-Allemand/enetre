#include "../pch.h"
#include "SceneManager.h"


inline SceneManager::SceneManager()
{
	m_currentScene = 0;
	m_numberOfScenes = 0;
}


SceneManager::~SceneManager()
{
	m_scenes.clear();
}

template<class T>
inline T* SceneManager::Get()
{
	for (Scene* scene : m_scenes)
	{
		if (T* s = dynamic_cast<T*>(scene))
		{
			return s;
		}
	}

	return nullptr;
}
template<class T>
inline T* SceneManager::Add()
{
	T* newScene = new T();
	m_scenes.push_back(newScene);
	return newScene;
}

template<class T>
std::vector<T*> SceneManager::getScenes()
{
	return std::vector<T*>();
}
