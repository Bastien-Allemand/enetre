#pragma once
class Entity : public sf::Drawable
{
	sf::Texture m_texture;

public:
	sf::Sprite m_sprite;

	Entity(sf::Vector2f _position, sf::Texture _texture);
	
	virtual void Draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Destroy() = 0;
};

