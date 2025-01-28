#pragma once
#include "Scene.h"
class Stage1 : public Scene
{
public:
	void InitText(); 
	void InitSquareText();
	void UpdateScore();
	virtual void Unit() ;
	virtual void InitBackGroundTexture();
	void update(float dt);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	bool CheckCollision(sf::FloatRect hitbox, sf::FloatRect hitbox2);
};

