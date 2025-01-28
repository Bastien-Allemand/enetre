#include "ButtonQuit.h"
#include "GameManager.h"   
#include "SceneManager.h"
#include <cstdlib>

ButtonQuit::ButtonQuit(sf::Vector2f buttonPosition) : Button(buttonPosition)
{
	this->buttonTexture.loadFromFile("../../../res/ButtonQuit.png");
	this->buttonSprite.setTexture(buttonTexture);
	this->buttonSprite.setTextureRect(sf::IntRect(446, 252, 221, 95));
}
void ButtonQuit::update(float dt)
{
	if (this->buttonSprite.getGlobalBounds().contains(this->mMousePosition))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->mButtonState = PRESSED;
			exit(0);
		}
	}
	else
	{
		this->mButtonState = IDLE;
	}
}
