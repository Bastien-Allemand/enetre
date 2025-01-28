#include "../pch.h"
#include "GameManager.h"
#include "../Obj/Player.h"
#include "SceneManager.h"
#include "SFML/Graphics.hpp"
#include "../Scenes/Scene.h"
#include "../Obj/Entity.h"


void GameManager::InitGameManager()
{
	m_videomode = sf::VideoMode(800, 600);
	m_window = new sf::RenderWindow(m_videomode, "Game", sf::Style::Close | sf::Style::Titlebar);

}

void GameManager::Draw()
{
}

GameManager::GameManager()
{

}

GameManager::~GameManager()
{
	delete this->m_window;
	delete this->m_player;
}

GameManager* GameManager::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new GameManager();
	}
	return m_instance;
}

void GameManager::Run()
{
	this->InitGameManager();
	sf::Clock clock;

	while (m_window->isOpen())
	{

		float dt = clock.restart().asSeconds();

		render();

	}
}

void GameManager::UpdatePlayerInput(float dt)
{
	if (m_scenemanager.> 0)
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
	if (this->KeyTime < this->m_key_time_max)
		this->KeyTime += 100.f * dt;
}

SceneManager* GameManager::GetSceneManager()
{
	return mSceneManager;
}

void GameManager::UpdateGuI()
{

	float hpPercent = static_cast <float>(this->player->GetHp()) / this->player->GetHpMax();
	this->m_player_hp_bar.setSize(sf::Vector2f(500 * hpPercent, this->m_player_hp_bar.getSize().y));

}

bool GameManager::GetKetTime()
{
	if (this->KeyTime >= this->m_key_time_max)
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
	if (this->m_paused)
	{
		this->window->draw(*(this->mSceneManager->ChangeScene(2)));
	}
	else
	{

		this->window->draw(*(this->mSceneManager->GetCurrentScene()));

		if (this->mSceneManager->GetCurrentSceneIndice() > 2)
		{
			this->window->draw(this->m_player_hp_bar_back);
			this->window->draw(this->m_player_hp_bar);
			this->window->draw(*this->player);
			for (int i = 0; i < this->player->bullets.size(); i++)
			{
				this->window->draw(*this->player->bullets[i]);
			}
		}
	}
	this->window->display();
}