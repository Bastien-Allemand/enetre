#include "GameOver.h"
#include "Bouton.h"
#include "Sprite.h"
#include "ButtonQuit.h"
#include "GameManager.h"   
#include "SceneManager.h"
void GameOver::UpdateMousePosition(const sf::RenderWindow& window)
{
	this->mMousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));

}
void GameOver::InitBackGroundTexture()
{
	this->textureDecor.loadFromFile("../../../res/BackGround-Menue.png");
	this->decor.setScale(GameManager::GetInstance()->GetWindow()->getSize().x / 800.f, GameManager::GetInstance()->GetWindow()->getSize().y / 600.5f);
	this->decor.setTexture(textureDecor);

}
void GameOver::Unit()
{
	this->InitBackGroundTexture();

	Buttons.push_back(new ButtonQuit(sf::Vector2f(600, 500)));
}
void GameOver::update(float dt)
{
	UpdateMousePosition(*(GameManager::GetInstance()->GetWindow()));
	for (int i = 0; i < Buttons.size(); i++)
	{
		Buttons[i]->GetMousePosition(mMousePosition);
		Buttons[i]->update(dt);

	}
}

void GameOver::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform.combine(this->getTransform());

	target.draw(this->decor, states);

	for (int i = 0; i < this->Buttons.size(); i++)
	{
		target.draw(*this->Buttons[i], states);
	}
}
