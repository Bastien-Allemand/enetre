#pragma once
#include "../includes.h"
#include "Entity.h"

class Player : public Entity
{
	
public:
	sf::Vector2f m_direction;

	Player(sf::Vector2f _position, sf::Texture _texture);
	virtual void Update(float deltaTime) override;
};

