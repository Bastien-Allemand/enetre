#include "pch.h"
#include "Sprite.h"
#include "iostream"
#include "SFML/Graphics.hpp"

void roachsprite(sf::Texture& texture, int typex,int typey)
{

	texture.loadFromFile("../../../res/roach.png", sf::IntRect(typex*32, typey*32,32,32));
}
void ratsprite(sf::Texture& texture, int typex, int typey)
{

	texture.loadFromFile("../../../res/Sprite Rat.png", sf::IntRect(typex * 32, typey * 32, 32, 32));
}

void Playersprite(sf::Texture& texture, int typex, int typey)
{
	texture.loadFromFile("../../../res/beetle_player.png", sf::IntRect(34, 70, 31, 30));
}

void LadybugSprite(sf::Texture& texture,int typex)
{
	switch (typex)
	{
	case 0:
		if (!texture.loadFromFile("../../../res/ladybugsprite01.png"))
		{
			std::cout << "error";
		}
		break;
	case 1:
		texture.loadFromFile("../../../res/ladybugsprite02.png");
		break;
	case 2:
		texture.loadFromFile("../../../res/ladybugsprite03.png");
		break;
	case 3:
		texture.loadFromFile("../../../res/ladybugsprite04.png");
		break;
	case 4:
		texture.loadFromFile("../../../res/ladybugsprite05.png");
		break;
	case 5:
		texture.loadFromFile("../../../res/ladybugsprite06.png");
		break;
	case 6:
		texture.loadFromFile("../../../res/ladybugsprite07.png");
		break;
	case 7:
		texture.loadFromFile("../../../res/ladybugsprite08.png");
		break;
	case 8:
		texture.loadFromFile("../../../res/ladybugsprite09.png");
		break;
	case 9:
		texture.loadFromFile("../../../res/ladybugsprite10.png");
		break;
	default:
		break;
	}
}

void BulletSprite(sf::Texture& texture)
{
	texture.loadFromFile("../../../res/Bullet.png");
}
