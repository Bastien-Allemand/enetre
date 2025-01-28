#include "../pch.h"
#include "Player.h"
#include "../includes.h"

Player::Player(sf::Vector2f _position) : Entity(_position)
{
	m_direction = sf::Vector2f(0, 0);
	m_sprite.setScale(2.f, 2.f);
}

void Player::Draw(sf::RenderTarget& target, sf::RenderStates states){
	target.draw(m_sprite, states);
}

void Player::SetTexture(std::string _path, sf::IntRect _rect)
{
	Entity::SetTexture(_path, _rect);
}

void Player::Update(float deltaTime)
{
	m_sprite.move(m_direction*deltaTime);
}