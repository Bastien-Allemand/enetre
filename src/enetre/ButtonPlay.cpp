#include "ButtonPlay.h"
#include "GameManager.h"   
#include "SceneManager.h"
ButtonPlay::ButtonPlay( sf::Vector2f buttonPosition) : Button( buttonPosition)
{
	this->buttonTexture.loadFromFile("../../../res/ButtonPlay.png");
	this->buttonSprite.setTexture(buttonTexture);
	this->buttonSprite.setTextureRect(sf::IntRect(446, 252, 221, 95));
																		   
}
void ButtonPlay::update(float dt)
{
	if (this->buttonSprite.getGlobalBounds().contains(this->mMousePosition))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->mButtonState = PRESSED;
			GameManager::GetInstance()->GetSceneManager()->ChangeScene(3);
		}
	}
	else
	{
		this->mButtonState = IDLE;
	}
}
