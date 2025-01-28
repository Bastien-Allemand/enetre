#pragma once
#include "SFML/Graphics.hpp"

class Entity
{
	sf::Texture m_texture;

public:
	sf::Sprite m_sprite;
	sf::Texture _texture;
	
	Entity(sf::Vector2f _position);
	virtual void SetTexture(std::string _path, sf::IntRect _rect = sf::IntRect(32, 32, 32, 32));
	virtual void Draw(sf::RenderTarget& target, sf::RenderStates states) = 0;
	virtual void Update(float deltaTime) = 0;
};

