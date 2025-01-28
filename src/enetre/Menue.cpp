#include "Menue.h"
#include "Bouton.h"
#include "Sprite.h"
#include "ButtonPlay.h"
#include "GameManager.h"   
#include "SceneManager.h"
void Menue::UpdateMousePosition(const sf::RenderWindow& window)
{
	this->mMousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	
}
void Menue::InitBackGroundTexture()
{
	this->textureDecor.loadFromFile("../../../res/BackGround-Menue.png");
	this->decor.setScale(GameManager::GetInstance()->GetWindow()->getSize().x/800.f, GameManager::GetInstance()->GetWindow()->getSize().y/600.5f); 
	this->decor.setTexture(textureDecor);
	
}
void Menue::Unit()
{
	this->InitBackGroundTexture();
	
	Buttons.push_back(new ButtonPlay( sf::Vector2f(600, 500)));
}
void Menue::update(float dt)
{	 
	UpdateMousePosition(*(GameManager::GetInstance()->GetWindow()));
	for (int i = 0; i < Buttons.size(); i++)
	{
		Buttons[i]->GetMousePosition(mMousePosition);
		Buttons[i]->update(dt);  
		
	}
}

void Menue::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.combine(this->getTransform());

	target.draw(this->decor, states);	    

	for (int i = 0; i < this->Buttons.size(); i++)
	{
		target.draw(*this->Buttons[i], states);
	}
}
