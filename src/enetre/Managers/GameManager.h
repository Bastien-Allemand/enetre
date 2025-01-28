#pragma once
#include "../Obj/Player.h"
#include "SceneManager.h"
#include "SFML/Graphics.hpp"

class GameManager
{
	Player* m_player;
	SceneManager* m_scenemanager;
	sf::RenderWindow* m_window;
	sf::Event m_event;
	sf::VideoMode m_videomode;
	sf::RectangleShape m_player_hp_bar;
	sf::RectangleShape m_player_hp_bar_back;
	bool m_paused;
	float m_key_time_max;
	float KeyTime;
public:
	void InitWindow();
	void InitVariable();
	void InitGameManager();
	void InitPlayer();
	void PauseState();
	void UnPauseState();
	GameManager();

	~GameManager();

	Player GetPlayer();

	static GameManager* GetInstance();

	sf::RenderWindow* GetWindow();

	void UpdateInput();

	void Run();

	void UpdatePlayerInput(float dt);

	void poolEvent();

	void UpdateKeyTime(float dt);

	SceneManager* GetSceneManager();

	void UpdateGuI();

	bool GetKetTime();

	sf::Texture* GetTexture(std::string id);

	void render();
};

