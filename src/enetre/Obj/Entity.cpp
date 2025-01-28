#include "../pch.h"
#include "SFML/Graphics.hpp"
#include "string"
#include "Entity.h"

Entity::Entity(sf::Vector2f _position): m_sprite()
{
	m_sprite.setPosition(_position);
}

void Entity::SetTexture(std::string _path, sf::IntRect _rect)
{
	_texture.loadFromFile(_path,_rect);
	m_sprite.setTexture(_texture);
}



