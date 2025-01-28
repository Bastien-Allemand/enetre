// Bullet.cpp
#include "Bullet.h"
#include "GameManager.h"

Hitbox Bullet::GetHitbox()
{
	return* mhitbox;
}

// Classe représentant une balle tirée par un joueur ou un ennemi
Bullet::Bullet(sf::Vector2f playerposition, sf::Texture* texture, float dirX, float dirY, float spd) : Entity( playerposition)
{
	mhitbox = new Hitbox(&(this->msprite));
	this->msprite.setTexture(*texture);
	this->msprite.setScale(0.5f, 0.5f);
	
	this->msprite.setOrigin(msprite.getLocalBounds().width / 2, msprite.getLocalBounds().height / 2);
	this->msprite.rotate(270);
	//this->msprite.setPosition(playerposition);
	this->mdirection.x = dirX;
	this->mdirection.y = dirY;
	this->mMovementSpeed = spd;
	//mofPlayer = isPlayer;
}

// Met à jour la position de la balle
void Bullet::update(float dt)
{
	//Movement
    msprite.move(this->mMovementSpeed * this->mdirection * dt);
	sf::FloatRect h = msprite.getGlobalBounds();
	h.height = h.height / 5;
	h.width = h.width / 5 ;
	h.left += (h.width / 2)*4;
	h.top += (h.height / 2) * 3;
	this->mhitbox->setHitbox(h);
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->msprite, states);
	
}

// Vérifie si la balle est hors de l'écran
bool Bullet::isOffScreen(const sf::RenderWindow& window) const
{
    sf::Vector2f position = msprite.getPosition();
    return (position.x < 0 || position.x > window.getSize().x || position.y < 0 || position.y > window.getSize().y);
}

// Vérifie si la balle a été tirée par le joueur
bool Bullet::isFromPlayer() const
{
    return mofPlayer;
}
