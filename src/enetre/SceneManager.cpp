#include "SceneManager.h"
#include "Scene.h"
#include "Stage1.h"
#include "GameOver.h"
#include "Pause.h"
#include "Menue.h"
#include <iostream>
SceneManager::SceneManager()
{
	currentScene = 0;
	Scenes.push_back(new Menue);
	Scenes.push_back(new GameOver);
	Scenes.push_back(new Pause);
	Scenes.push_back(new Stage1);
	
	Scenes[0]->Unit();
	Scenes[1]->Unit();
	Scenes[2]->Unit();
	Scenes[3]->Unit();
}

Scene* SceneManager::GetCurrentScene()
{
	return Scenes[currentScene];    
}

Scene* SceneManager::ChangeScene(int scene)
{
	currentScene = scene;
	return GetCurrentScene();
}

int SceneManager::GetCurrentSceneIndice()
{
	return currentScene;
}
