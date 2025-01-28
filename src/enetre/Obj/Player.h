#pragma once
#include "../includes.h"
#include "Entity.h"

class Player : public Entity
{
	
public:
	sf::Vector2f m_direction;

	Player(sf::Vector2f _position);
	virtual void SetTexture(std::string _path,sf::IntRect _rect = sf::IntRect(32, 32, 32, 32)) override;
	virtual void Draw(sf::RenderTarget& target, sf::RenderStates states) override;
	virtual void Update(float deltaTime) override;
};

