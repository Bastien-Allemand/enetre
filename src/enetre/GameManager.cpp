#include "GameManager.h"
#include "Player.h"
#include "Sprite.h"
#include "SFML/Graphics.hpp"
#include "SceneManager.h"
#include "Scene.h"

GameManager* GameManager::mInstance = nullptr;

void GameManager::InitWindow()
{
	videoMode.height = 900;
	videoMode.width = 1600;
	window = new sf::RenderWindow(videoMode, "minimoys");
}

void GameManager::InitVariable()
{
	this->window = nullptr;
	this->paused = false;
	this->KeyTimeMax = 100.f;
	this->KeyTime = 0.f;
}

void GameManager::InitGameManager()
{
	this->InitVariable();
	this->InitWindow();
	this->InitPlayer();	   
	
	this->mSceneManager = new SceneManager();
	mTextures["bullet"] = new sf::Texture;

	BulletSprite(*mTextures["bullet"]);
	this->PlayerHpBar.setSize(sf::Vector2f(500, 30));
	this->PlayerHpBar.setFillColor(sf::Color::Red);
	
	this->PlayerHpBar.setPosition(sf::Vector2f(20, 20));
	this->PlayerHpBarBack = this->PlayerHpBar;
	this->PlayerHpBarBack.setFillColor(sf::Color(25, 25, 25, 200));
}

void GameManager::InitPlayer()
{

	this->player = new Player(sf::Vector2f(300,300), 20, 1, 5);
	this->player->msprite.setScale(2.f, 2.f);
}

void GameManager::PauseState()
{
	this->paused = true;
}

void GameManager::UnPauseState()
{
	this->paused = false;
}

GameManager::GameManager()
{

}

GameManager::~GameManager()
{
	delete this->window;
	delete this->player;
}

Player GameManager::GetPlayer()
{
	return* player;
}

GameManager* GameManager::GetInstance()
{
	if (mInstance == nullptr)
	{
		mInstance = new GameManager();
	}
	return mInstance;
}

sf::RenderWindow* GameManager::GetWindow()
{
	return window;
}

void GameManager::UpdateBullet(float dt)
{
	for (int i = 0; i < this->player->bullets.size(); i++)
	{
		this->player->bullets[i]->update(dt);
		if (this->player->bullets[i]->isOffScreen(*GetWindow()))
		{
			delete this->player->bullets[i];
			this->player->bullets.erase(this->player->bullets.begin() + i);
			--i;
		}
	}
}

void GameManager::UpdateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && this->GetKetTime())
	{
		if (!this->paused)
		{
			this->PauseState();
			currentScene = this->mSceneManager->GetCurrentSceneIndice();
			this->mSceneManager->ChangeScene(2);
		}
		else
		{
			this->UnPauseState();
			this->mSceneManager->ChangeScene(currentScene);
		}
	}
}

void GameManager::Run()
{
	this->InitGameManager();
	sf::Clock clock;
	
	while (this->window->isOpen())
	{

		float dt = clock.restart().asSeconds();
		poolEvent();
		UpdateInput();
		mSceneManager->GetCurrentScene()->update(dt);
		UpdateGuI();
		UpdateKeyTime(dt);
		if (!this->paused)
		{
			UpdatePlayerInput(dt);
			
			UpdateBullet(dt);
		}

		render();
		
	}
}

void GameManager::UpdatePlayerInput(float dt) 
{
	if (this->mSceneManager->GetCurrentSceneIndice() > 0)
	{
		player->update(dt);
		float speed = 200.0f; // Augmenter la vitesse de déplacement

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
		
			player->msprite.move(sf::Vector2f(0, -speed * dt));
			// player goes up
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
		
			player->msprite.move(sf::Vector2f(-speed * dt, 0));
			// player goes left
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
		
			player->msprite.move(sf::Vector2f(0, speed * dt));
			// player goes down
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
		
			player->msprite.move(sf::Vector2f(speed * dt, 0));
			// player goes right
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->player->canAttack())
		{
			this->player->spawnBullet(mTextures["bullet"], this->player->getPosition(), sf::Vector2f(0, -1), 300.f, true);
		}
	}
	
}

void GameManager::poolEvent()
{
	while (window->pollEvent(event))  
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		}

	}
}

void GameManager::UpdateKeyTime(float dt)
{
	if (this->KeyTime < this->KeyTimeMax)
		this->KeyTime += 100.f * dt;
}

SceneManager* GameManager::GetSceneManager()
{
	return mSceneManager;
}

void GameManager::UpdateGuI()
{
	
	float hpPercent = static_cast <float>(this->player->GetHp())/ this->player->GetHpMax();
	this->PlayerHpBar.setSize(sf::Vector2f(500 * hpPercent, this->PlayerHpBar.getSize().y));
	
}

bool GameManager::GetKetTime()
{
	if (this->KeyTime >= this->KeyTimeMax)
	{
		this->KeyTime = 0;
		return true;
	}
		return false;
}

sf::Texture* GameManager::GetTexture(std::string id)
{
	return mTextures[id];
}

void GameManager::render()
{
	this->window->clear(sf::Color::Black);
	if (this->paused)
	{
		this->window->draw(*(this->mSceneManager->ChangeScene(2)));
	}
	else
	{

		this->window->draw(*(this->mSceneManager->GetCurrentScene()));
		
		if (this->mSceneManager->GetCurrentSceneIndice() > 2)
		{
			this->window->draw(this->PlayerHpBarBack);
			this->window->draw(this->PlayerHpBar);
			this->window->draw(*this->player);
			for (int i = 0; i < this->player->bullets.size(); i++)
			{
				this->window->draw(*this->player->bullets[i]);
			}
		}
	}
	this->window->display();
}
