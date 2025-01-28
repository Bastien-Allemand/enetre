#pragma once
#include "Entity.h"

enum Button_State { IDLE = 0, PRESSED = 1 };


class Button : public sf::Transformable, public sf::Drawable
{
protected:
	sf::Texture buttonTexture;
	sf::Sprite buttonSprite;
	sf::Color colorIdle;
	sf::Color colorPressed;
	int mButtonState;
	sf::Vector2f mMousePosition;	  
public:
	

	Button( sf::Vector2f buttonPosition);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual void update(float dt) = 0;
	
	sf::Vector2f GetMousePosition(sf::Vector2f mousePosition);
	
	const bool& IsPressed() const ;
};

