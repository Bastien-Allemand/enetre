#include "Stage1.h"
#include "SFML/Graphics.hpp"
#include "Sprite.h"
#include  "Ladybug.h"
#include "GameManager.h"   
#include "SceneManager.h"
#include <iostream>
#include <string.h>
#include <sstream >
void Stage1::InitText()
{
    Score = 0;
    this->LoadFont();
    text.setFont(font);
    text.setCharacterSize(50);
    text.setPosition(mScoreSquare.getPosition().x, mScoreSquare.getPosition().y);
}
void Stage1::InitSquareText()
{
    mScoreSquare.setSize(sf::Vector2f(100, 50));
    mScoreSquare.setPosition(sf::Vector2f(1400, 50));
    mScoreSquare.setFillColor(sf::Color::Blue);
}
void Stage1::UpdateScore()
{
    text.setString(std::to_string(Score));
}
void Stage1::Unit()
{
	// load decor 
    InitBackGroundTexture();
    InitSquareText();
    InitText();
    
	sf::Texture texture;
	LadybugSprite(texture,0);
	Entities.push_back(new Ladybug(texture, sf::Vector2f(800,10), 10, 10, 18));
	Entities.push_back(new Ladybug(texture, sf::Vector2f(600, 10), 5, 5,0));
    Entities.push_back(new Ladybug(texture, sf::Vector2f(800, 10), 5, 5, 10));
    Entities.push_back(new Ladybug(texture, sf::Vector2f(500, 10), 6, 5, 0));
    Entities.push_back(new Ladybug(texture, sf::Vector2f(500, 10), 5, 5, 10));
    Entities.push_back(new Ladybug(texture, sf::Vector2f(700, 10), 5, 5, 0));
    Entities.push_back(new Ladybug(texture, sf::Vector2f(800, 10), 5, 5, 21));
    Entities.push_back(new Ladybug(texture, sf::Vector2f(700, 10), 5, 5, 20));
}
void Stage1::InitBackGroundTexture()
{
    if (!this->textureDecor.loadFromFile("../../../res/Background-Level1.png"))
    {
        std::cout << "Rasengan";
    }
    // Obtenir la taille de la fenêtre
    sf::Vector2u windowSize = GameManager::GetInstance()->GetWindow()->getSize();
    // Obtenir la taille de la texture
    sf::Vector2u textureSize = this->textureDecor.getSize();

    // Calculer l'échelle pour remplir l'écran
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

    // Appliquer l'échelle au sprite
    this->decor.setScale(scaleX, scaleY);
    this->decor.setTexture(textureDecor);
}
void Stage1::update(float dt)
{
    UpdateScore();
    for (auto it = Entities.begin(); it != Entities.end(); )
    {
        (*it)->update(dt);
        if (this->CheckCollision(GameManager::GetInstance()->GetPlayer().GetHitbox()->getGlobalHitbox(), dynamic_cast<Ladybug*>(*it)->GetHitbox()->getGlobalHitbox()) )
        {
            GameManager::GetInstance()->GetPlayer().TakeDammage(dynamic_cast<Ladybug*>(*it)->Getdammage());
        }
        else if (dynamic_cast<Ladybug*>(*it)->checkColisiton())
        {
            dynamic_cast<Ladybug*>(*it)->TakeDammage(GameManager::GetInstance()->GetPlayer().Getdammage());
            
        }
        else if (!dynamic_cast<Ladybug*>(*it)->IsAlive())
        {
            Score += 50;
            delete* it;
            it = Entities.erase(it);
        }
        else if (dynamic_cast<Ladybug*>(*it)->isOffScreen(*(GameManager::GetInstance()->GetWindow())))            // *(GameManager::GetInstance()->GetWindow())) cela evite de passer des membre supérieur dans les membres inférieurs , ça sert a sa le singleton https://youtu.be/fLkcxrAlJAQ
        {
            delete* it;
            it = Entities.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

// Dessiner les entités sur la fenêtre
void Stage1::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform.combine(this->getTransform());

    target.draw(this->decor, states);
    target.draw(this->mScoreSquare, states);
    target.draw(this->text, states);

    for (int i = 0; i < this->Entities.size(); i++)
    {
       
        if (this->Entities[i]->GetEntityIsActive())
            target.draw(*this->Entities[i], states);;
    }
}

bool Stage1::CheckCollision(sf::FloatRect hitbox, sf::FloatRect hitbox2)
{
    if (hitbox.intersects(hitbox2))
    {
        return true;
    }
    return false;
}

