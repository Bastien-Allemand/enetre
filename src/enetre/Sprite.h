// Sprite.h
#pragma once

#include "iostream"
#include "SFML/Graphics.hpp"

// Définit le sprite pour un cafard
void roachsprite(sf::Texture& texture, int typex, int typey);

// Définit le sprite pour un rat
void ratsprite(sf::Texture& texture, int typex, int typey);

// Définit le sprite pour une coccinelle
void LadybugSprite(sf::Texture& texture, int typex);

// Définit le sprite pour un joueur
void Playersprite(sf::Texture& texture, int typex, int typey);

// Définit le sprite pour une balle
void BulletSprite(sf::Texture& texture);

void LadybugSprite(sf::Texture& texture, int typex);
