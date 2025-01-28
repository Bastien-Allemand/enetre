#pragma once
#include "Scene.h"
#include "Bouton.h"
class Menue : public Scene
{
	sf::Texture texture;
	std::vector<Button*> Buttons;
	sf::Vector2f mMousePosition;
public:

	void UpdateMousePosition(const sf::RenderWindow& window);
	virtual void InitBackGroundTexture();
	virtual void update(float dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual void Unit();


};

