#pragma once
#include "../includes.h"
#include "../Scenes/Scene.h"

class SceneManager
{
	std::vector<Scene*> m_scenes;
	int m_currentScene;
	int m_numberOfScenes;

public:

	SceneManager();
	~SceneManager();
	template<class T>
	bool checkScene(T _scene);
	template<class T>
	T* Get();
	template<class T>
	T* Add();
	template<class T>
	std::vector<T*> getScenes();


};



