#include "../pch.h"
#include "SFML/Graphics.hpp"
#include "Entity.h"

Entity::Entity(sf::Vector2f _position,sf::Texture _texture)
{
	m_sprite.setTexture(_texture);
	m_sprite.setPosition(_position);
}



