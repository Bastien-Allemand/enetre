#pragma once
#include "Enemis.h"
#include "Hitbox.h"
class Hitbox;
class Ladybug :	public Enemis
{
	
	float timer;
	float directionChangeTimer;
	int currentDirection;

public:
	Ladybug(sf::Texture texture, sf::Vector2f startPosition, int damage, int Maxhealth, float spawnTime);

	bool checkColisiton();
	virtual void update(float dt) ;

	bool isOffScreen(const sf::RenderWindow& window) const;

	virtual void Initprite()  ;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

