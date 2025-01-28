#pragma once
#include "Bouton.h"
class ButtonQuit  :	public 	Button
{
public:

	ButtonQuit(sf::Vector2f buttonPosition);

	virtual void update(float dt);  
};

