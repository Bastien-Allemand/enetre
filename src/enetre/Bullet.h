#pragma once

#include "Entity.h"
#include "SFML/Graphics.hpp"
#include "Hitbox.h"
// Classe représentant une balle tirée par un joueur ou un ennemi
class Bullet: public Entity
{
protected:
	
	sf::Vector2f mdirection;
	float mMovementSpeed;
	bool mofPlayer;
public:
	Hitbox* mhitbox;
	Hitbox GetHitbox();
	Bullet(sf::Vector2f playerposition, sf::Texture* texture,float dirX, float dirY, float spd);
	void update(float dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const ;
	bool isOffScreen(const sf::RenderWindow& window) const;
	bool isFromPlayer() const;


};

