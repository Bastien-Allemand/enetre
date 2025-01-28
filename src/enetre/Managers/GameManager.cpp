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

Player* GameManager::GetPlayer()
{
	return m_player;
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

template<class T>
void GameManager::UpdatePlayerInput(float dt)
{
	if (m_scenemanager->checkScene(m_scenemanager->Get()) != nullptr)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{

			m_player->m_direction.x = -1;
			// player goes up
		}
		else
		{
			m_player->m_direction.x = 0;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
		{
			m_player->m_direction.y = -1;
			// player goes left
		}
		else
		{
			m_player->m_direction.y = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			m_player->m_direction.x = 1;
		}
		else
		{
			m_player->m_direction.x = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			m_player->m_direction.y = 1;
		}
		else
		{
			m_player->m_direction.y = 0;
		}
	}
	m_player->Update(dt);

}


void GameManager::render()
{
	m_window->clear(sf::Color::Black);
	m_window->draw(m_player->m_sprite);
	m_window->display();

}