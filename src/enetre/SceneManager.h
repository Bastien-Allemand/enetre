#pragma once
#include <SFML/Graphics.hpp> 
#include "Player.h"
#include "vector"
class Scene;

class SceneManager
{
	std::vector<Scene* > Scenes;
	int currentScene;
public:

	SceneManager(); 

	Scene* GetCurrentScene();

	Scene* ChangeScene(int scene);

	int GetCurrentSceneIndice();
};

