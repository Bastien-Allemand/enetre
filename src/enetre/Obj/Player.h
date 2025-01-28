#pragma once
#include "includes.h"

class Player : public Entity
{
	float m_speed;
	sf::Vector2f m_position;
	float attackSpeed;
public:
	Player();
	~Player();
	void Init() override;
	void Update() override;
	void Render() override;
	void Destroy() override;
};

