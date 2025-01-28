#include "Ladybug.h"
#include <iostream>
#include "GameManager.h"   
#include "SceneManager.h" 
Ladybug::Ladybug(sf::Texture texture, sf::Vector2f startPosition, int damage, int Maxhealth, float spawnTime) : Enemis(texture,startPosition,damage,Maxhealth, spawnTime)
{
    mHitbox = new Hitbox(&(this->msprite));            
	this->mSpawnTime = spawnTime;
	isActive = false;
    directionChangeTimer = 0;                        
	currentDirection = std::rand() % 3;
	timer = 0;
	mtexture = texture;
	Initprite();
}

bool Ladybug::checkColisiton()
{
    for (int i = 0; i < GameManager::GetInstance()->GetPlayer().bullets.size(); i++)
    {
        if (GameManager::GetInstance()->GetPlayer().bullets[i]->mhitbox->getGlobalHitbox().intersects(this->mHitbox->getGlobalHitbox()))
        {
            return true;
        }
    }
    return false;
}

void Ladybug::update(float dt)
{
    timer += dt;
    directionChangeTimer += dt; // Incrémenter le timer pour le changement de direction
	
    if (timer > mSpawnTime)
    {
		timer = 0;
        isActive = true;
    }

    if (isActive) {
        if (directionChangeTimer >= 1.0f)
        { // Changer de direction toutes les 10 secondes
            currentDirection = std::rand() % 3;
            directionChangeTimer = 0; // Réinitialiser le timer pour le changement de direction
        }

        float speed = 90.0f; // Augmenter légèrement la vitesse de déplacement

        switch (currentDirection)
        {
        case 0:
            msprite.move(0, speed * dt); // Move down
            break;
        case 1:
            msprite.move(-speed * dt, 0); // Move left
            break;
        case 2:
            msprite.move(speed * dt, 0); // Move right
            break;
        default:
            break;
        }
    }
   
    sf::FloatRect h = msprite.getGlobalBounds();
    
    h.height = h.height / 2;
    h.width = h.width / 2;
    h.left += h.width/2;
    h.top += h.height/2;
    this->mHitbox->setHitbox(h);

}
bool Ladybug::isOffScreen(const sf::RenderWindow& window) const
{
	sf::FloatRect bounds = msprite.getGlobalBounds();
	return (bounds.left + bounds.width < 0 || bounds.top + bounds.height < 0 ||
		bounds.left > window.getSize().x || bounds.top > window.getSize().y);
}
void Ladybug::Initprite() 
{
	msprite.setTexture(mtexture);
}

void Ladybug::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    Enemis::draw(target, states);
    
}
