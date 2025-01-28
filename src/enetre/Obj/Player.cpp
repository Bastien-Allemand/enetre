#include "../pch.h"
#include "Player.h"
#include "../includes.h"

Player::Player() : Entity()
{
	m_speed = 5;
	attackSpeed = 0.5;
}

void Player::Init()
{
	m_position = sf::Vector2f(100, 100);
	m_sprite.setPosition(m_position);
	m_sprite.setTexture(*GameManager::GetInstance()->GetTexture("player"));

}

void Player::Update()
{
}

void Player::Render()
{
}

void Player::Destroy()
{
}
