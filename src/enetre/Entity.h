#pragma once
#include "SFML/Graphics.hpp"
#include "Hitbox.h"
class Entity : public sf::Drawable
{
protected:
	Hitbox* mHitbox;
	sf::Vector2f mposition;
	bool isActive;
public:
	
	sf::Texture mtexture;
	sf::Sprite msprite;
	Entity();
	Entity( sf::Vector2f startPosition);

	bool GetEntityIsActive();
	Hitbox* GetHitbox();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0 ;
	virtual void update(float deltaTime) = 0;
	sf::FloatRect getBounds() const;
	const sf::Vector2f& getPosition() const;    // Getter for position
	void setPosition(const sf::Vector2f& pos);  // Setter for position

	
};
