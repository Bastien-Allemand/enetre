#include "Character.h"
#include "Entity.h"


Character::Character( sf::Vector2f startPosition, int damage, int Maxhealth) : Entity(startPosition)
{
	mhealth = Maxhealth;
	mMaxhealth = Maxhealth;
	mDamage = damage;
}



bool Character::isdead()
{
	if (mhealth > 0){return false;}
	else { return true; }
}

int Character::fetchhealth()
{
	return mhealth;
}

int Character::fetchmaxhealh()
{
	return mMaxhealth;
}

int Character::fetchdmg()
{
	return mDamage;
}

void Character::changehealth(int New)
{
	mhealth = New;
}

void Character::changemaxhealth(int New)
{
	mMaxhealth = New;
}

void Character::changedmg(int New)
{
	mDamage = New;
}

int Character::Getdammage()
{
	return mDamage;
}
