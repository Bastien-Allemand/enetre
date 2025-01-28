#pragma once
#include <SFML/Graphics.hpp>

#include <map>

class Player;
class SceneManager;
// Classe gérant le cycle de vie du jeu
class GameManager
{

	Player* player;

	SceneManager* mSceneManager;

	sf::RenderWindow* window;

	sf::VideoMode videoMode;

	sf::Event event;

	std::map<std::string, sf::Texture*> mTextures;

	static GameManager* mInstance;

	int currentScene;
	sf::RectangleShape PlayerHpBar;
	sf::RectangleShape PlayerHpBarBack;
	bool paused;
	float KeyTimeMax;
	float KeyTime;

private:

	void InitWindow();

	void InitVariable();

public:
	
	void InitGameManager();

	void InitPlayer();
	void PauseState();
	void UnPauseState();
	GameManager();

	~GameManager();
	
	Player GetPlayer();

	static GameManager* GetInstance();

	sf::RenderWindow* GetWindow();

	void UpdateBullet(float dt);

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

