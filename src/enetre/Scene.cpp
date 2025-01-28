#include "Scene.h"
#include "Player.h"
#include "SFML/Graphics.hpp"
#include <iostream>
void Scene::InitScoreSquare(sf::RectangleShape ScoreSquare )
{
	this->mScoreSquare = ScoreSquare;
}

void Scene::update(float dt)
{	 
	
	for (int i = 0; i < Entities.size(); i++)
	{
		Entities[i]->update(dt);
	}
}

void Scene::LoadFont()
{
	if (!font.loadFromFile("../../../res/Squareo.ttf"))
	{
		std::cout << "marche pas ";
	}
}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	

	for (int i = 0; i < this->Entities.size(); i++)
	{
		if (this->Entities[i]->GetEntityIsActive())
			target.draw(*this->Entities[i], states);
	}
}

std::vector<Entity*> Scene::GetEntities()
{
	return Entities;
}
	