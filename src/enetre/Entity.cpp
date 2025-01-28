#include "Entity.h"


Entity::Entity()
{
}

Entity::Entity( sf::Vector2f startPosition)
{
    isActive = true;
    
    msprite.setPosition(startPosition);


    mposition = startPosition;

}

bool Entity::GetEntityIsActive()
{
    return isActive;
}

Hitbox* Entity::GetHitbox()
{
     return mHitbox;
}

sf::FloatRect Entity::getBounds() const
{
	return msprite.getGlobalBounds();
}

const sf::Vector2f& Entity::getPosition() const
{
    return msprite.getPosition();
}

void Entity::setPosition(const sf::Vector2f& pos)
{
    mposition = pos;
    msprite.setPosition(mposition);
}