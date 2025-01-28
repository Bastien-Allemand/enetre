#include "../pch.h"
#include "GameManager.h"
#include "../Obj/Player.h"
#include "SceneManager.h"
#include "../Scenes/Scene.h"
#include "../Obj/Entity.h"


sf::Texture* GameManager::GetTexture(std::string id)
{
	return 
}

GameManager::GameManager()
{
	m_player = nullptr;
	m_scenemanager = nullptr;
	m_window = nullptr;
	paused = false;
}

GameManager* GameManager::GetInstance()
{
	GameManager* instance = new GameManager();
	return instance;
}
