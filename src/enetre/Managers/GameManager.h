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
	
	bool paused;
public:
	GameManager();
	static GameManager* GetInstance();

	void InitWindow();
	void InitTimer();
	sf::Texture* GetTexture(std::string id);
	Player GetPlayer();
	void Run();
	void Update();
	void Draw(sf::RenderTarget& target, sf::RenderStates states);

	void setPlayer(Player* player);
	void setSceneManager(SceneManager* scenemanager);
	void setWindow(sf::RenderWindow* window);
	void setVideoMode(sf::VideoMode videomode);
	void setEvent(sf::Event event);
	void setPaused(bool paused);
	void setTexture(std::string id, std::string path);
};

