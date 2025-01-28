#pragma once
#include <SFML/Graphics.hpp>
class Hitbox  
{
	sf::FloatRect hitbox;
	sf::Transformable* parent;

public:

	Hitbox(sf::Transformable* parent);

	virtual void setHitbox(const sf::FloatRect& hitbox);

	void ShowHitbox(sf::RenderWindow& window);

	sf::FloatRect getGlobalHitbox() const;
};

