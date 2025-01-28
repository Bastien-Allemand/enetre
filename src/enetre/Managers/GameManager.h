#pragma once
#include "../includes.h"

class GameManager : public sf::Drawable, public sf::Transformable
{
	SceneManager* sceneManager;
	sf::RenderWindow* window;

	GameManager();
};

