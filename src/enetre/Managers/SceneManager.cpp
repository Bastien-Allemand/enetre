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
bool SceneManager::checkScene(T _scene)
{
	bool result = false;
	for (int i = 0; i < m_numberOfScenes; i++)
	{
		if (_scene == m_scenes[i])
		{
			result = true;
		}
	}
	return result;
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
