#pragma once
#include "../includes.h"

class GameManager : public sf::Drawable, public sf::Transformable
{
	Player* m_player;
	SceneManager* m_scenemanager;
	sf::RenderWindow* m_window;
	sf::Event m_event;
	sf::VideoMode m_videomode;
	sf::Texture* GetTexture(std::string id);
	bool paused;
public:
	GameManager();
	static GameManager* GetInstance();

	void InitWindow();
	void InitTimer();

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

