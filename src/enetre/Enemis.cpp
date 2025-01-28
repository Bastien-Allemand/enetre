#include "Enemis.h"
#include "Character.h"
Enemis::Enemis(sf::Texture& texture, sf::Vector2f startPosition, int damage, int Maxhealth,  float spawnTime)	: Character( startPosition, damage, Maxhealth)
{ 

}

void Enemis::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	target.draw(msprite, states);
}

void Enemis::update(float dt)
{
	msprite.move(50 * dt, 0);
}

bool Enemis::IsAlive()
{
	if (mhealth <= 0)	return false;
	else return true;
}

void Enemis::TakeDammage(int dmg)
{
	mhealth -= dmg;
}
