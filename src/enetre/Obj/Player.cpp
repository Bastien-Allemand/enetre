#include "../pch.h"
#include "Player.h"
#include "../includes.h"

Player::Player(sf::Vector2f _position, sf::Texture _texture) : Entity(_position, _texture)
{
	m_direction = sf::Vector2f(0, 0);
	m_sprite.setScale(2.f, 2.f);
}


void Player::Update(float deltaTime)
{
	m_sprite.move(m_direction*deltaTime);
}