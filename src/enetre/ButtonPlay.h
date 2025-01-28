#pragma once
#include "Bouton.h"
class ButtonPlay  : public	Button
{
public:

	ButtonPlay( sf::Vector2f buttonPosition);
	virtual void update(float dt);
	
	
};

