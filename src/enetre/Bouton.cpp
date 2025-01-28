#include "Bouton.h"
#include <iostream>


Button::Button(sf::Vector2f buttonPosition)	 
{
	this->buttonSprite.setPosition(buttonPosition);
	this->colorIdle = sf::Color::White;
	this->colorPressed = sf::Color::Red;
	//this->msprite.setTexture(texture);
	this->mButtonState = IDLE;
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.combine(this->getTransform());

	target.draw(buttonSprite, states);
}

void Button::update(float dt)
{

}

sf::Vector2f Button::GetMousePosition(sf::Vector2f mousePosition)
{
	  return this->mMousePosition = mousePosition;
}

const bool& Button::IsPressed() const
{
	// TODO: insérer une instruction return ici
	return this->mButtonState == PRESSED;
}
