#include "Hitbox.h"


Hitbox::Hitbox(sf::Transformable* parent)
{
    this->parent = parent;
}

void Hitbox::setHitbox(const sf::FloatRect& hitbox)
{
	this->hitbox = hitbox;
}

void Hitbox::ShowHitbox(sf::RenderWindow& window)
{
    sf::RectangleShape hitboxShape;
    hitboxShape.setSize(sf::Vector2f(this->hitbox.width, this->hitbox.height));
    hitboxShape.setPosition(this->hitbox.left, this->hitbox.top);
    hitboxShape.setFillColor(sf::Color::Black); 
    hitboxShape.setOutlineColor(sf::Color::Red); 
    hitboxShape.setOutlineThickness(2.f);  

    // Dessiner la hitbox dans la fenêtre
    window.draw(hitboxShape);
}

sf::FloatRect Hitbox::getGlobalHitbox() const
{
    return  this->hitbox;
}
