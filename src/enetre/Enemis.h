#pragma once
#include "Character.h"
#include "SFML/Graphics.hpp"
class Enemis : public Character
{
protected:
	float mSpawnTime;
public:

	Enemis(sf::Texture& texture, sf::Vector2f startPosition, int damage, int Maxhealth, float spawnTime);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual void update(float dt) = 0;

	bool IsAlive();

	void TakeDammage(int dmg);
};

