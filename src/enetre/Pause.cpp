#include "Pause.h"
#include "Bouton.h"
#include "Sprite.h"
#include "ButtonQuit.h"
#include "GameManager.h"   
#include "SceneManager.h"
void Pause::UpdateMousePosition(const sf::RenderWindow& window)
{
	this->mMousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

}
void Pause::InitBackGroundTexture()
{
	this->textureDecor.loadFromFile("../../../res/BackGround-Menue.png");
	this->decor.setScale(GameManager::GetInstance()->GetWindow()->getSize().x / 800.f, GameManager::GetInstance()->GetWindow()->getSize().y / 600.5f);
	this->decor.setTexture(textureDecor);

}
void Pause::Unit()
{
	this->InitBackGroundTexture();
	this->background.setSize(sf::Vector2f(GameManager::GetInstance()->GetWindow()->getSize().x, GameManager::GetInstance()->GetWindow()->getSize().y));
	this->background.setFillColor(sf::Color(20, 20, 20, 100));
	this->container.setSize(sf::Vector2f(GameManager::GetInstance()->GetWindow()->getSize().x/4, GameManager::GetInstance()->GetWindow()->getSize().y));
	this->container.setFillColor(sf::Color(20, 20, 20, 200));
	this->container.setPosition(GameManager::GetInstance()->GetWindow()->getSize().x / 2.f - this->container.getSize().x / 2.f,0.f);	
	this->LoadFont();
	this->menuetexture.setFont(font);
	this->menuetexture.setFillColor(sf::Color(255, 255, 255, 200));
	this->menuetexture.setCharacterSize(50);
	this->menuetexture.setString("Paused");
	this->menuetexture.setPosition(this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuetexture.getGlobalBounds().width/2.f , this->container.getPosition().y + 20.f);
	Buttons.push_back(new ButtonQuit(sf::Vector2f(this->container.getPosition().x + this->container.getSize().x / 2.f - this->menuetexture.getGlobalBounds().width / 2.f, this->container.getPosition().y + 500.f)));
}
void Pause::update(float dt)
{
	UpdateMousePosition(*(GameManager::GetInstance()->GetWindow()));
	for (int i = 0; i < Buttons.size(); i++)
	{
		Buttons[i]->GetMousePosition(mMousePosition);
		Buttons[i]->update(dt);

	}
}

void Pause::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.combine(this->getTransform());

	target.draw(this->background, states);
	target.draw(this->container, states);
	target.draw(this->menuetexture, states);

	for (int i = 0; i < this->Buttons.size(); i++)
	{
		target.draw(*this->Buttons[i], states);
	}
}
