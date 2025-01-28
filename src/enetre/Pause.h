#pragma once
#include "Scene.h"
#include "Bouton.h"
class Pause : public Scene
{
	
	sf::Text menuetexture;
	sf::Texture texture;
	sf::RectangleShape background;
	sf::RectangleShape container;
	std::vector< Button*> Buttons;
	sf::Vector2f mMousePosition;
public:

	void UpdateMousePosition(const sf::RenderWindow& window);
	virtual void InitBackGroundTexture();
	virtual void update(float dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual void Unit();


};


