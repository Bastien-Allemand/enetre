#pragma once

#include <SFML/Graphics.hpp> 
#include "Player.h"

class Scene	: public sf::Drawable ,public sf::Transformable
{
protected:
	sf::RectangleShape mScoreSquare;
	sf::Font font;
	sf::Text text;
	int Score;
	sf::Texture textureDecor;
	sf::Sprite 	decor;
	std::vector<Entity*> Entities;	
public:

	virtual void Unit() = 0;
	virtual void InitBackGroundTexture() = 0 ;
	virtual void InitScoreSquare(sf::RectangleShape ScoreSquare);
	virtual void update(float dt) ;
	void LoadFont();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	std::vector<Entity*> GetEntities();

};

