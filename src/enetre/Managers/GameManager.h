#pragma once
#include "../Obj/Player.h"
#include "SceneManager.h"
#include "../Obj/Player.h"
#include "SFML/Graphics.hpp"

class GameManager
{
	Player* m_player;
	SceneManager* m_scenemanager;
	sf::RenderWindow* m_window;
	sf::Event m_event;
	sf::VideoMode m_videomode;
	static GameManager* m_instance;

public:
	GameManager();
	~GameManager();
	static GameManager* GetInstance();

	void InitGameManager();

	Player* GetPlayer();

	void Draw();

	void Run();

	template<class T>
	void UpdatePlayerInput(float dt);

	void render();
};

