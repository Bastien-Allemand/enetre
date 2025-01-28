// Player.cpp
#include "Player.h"
#include "Bullet.h"
#include "Character.h"
#include "SFML/Graphics.hpp"
#include "vector"
#include "Sprite.h"
#include "GameManager.h"   
#include "SceneManager.h" 
void Player::InitTexture()
{
	Playersprite(mtexture, 1, 1);
}

void Player::SetHp(int pHp)
{
	mhealth = pHp;
}

void Player::InitSprite()
{
	this->msprite.setTexture(mtexture); 
}

const bool Player::canAttack()
{
	if (this->mAttackCouldown >= this->mAttackCouldownMax)
	{
		this->mAttackCouldown = 0.f;
		return true;
	}
	return false;
}

void Player::updateAttack()
{
	if (this->mAttackCouldown < this->mAttackCouldownMax)
		this->mAttackCouldown += 2.0f;
}

// Classe représentant un joueur dans le jeu
Player::Player( sf::Vector2f startPosition, int maxlife, int damage, int Maxhealth) : 
	Character( startPosition, damage, Maxhealth)
{
	this->mHitbox = new Hitbox(&(this->msprite));
	this->InitTexture();
	this->InitSprite();
	this->msprite.setOrigin(msprite.getLocalBounds().width / 2, msprite.getLocalBounds().height / 2);
	this->mAttackCouldownMax = 200.f;
	this->mAttackCouldown = this->mAttackCouldownMax;
	mmaxLife = maxlife;
	mLife = mmaxLife;
}

// Dessine le joueur sur la cible de rendu
void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//states.transform.combine(this->getTransform());

	target.draw(msprite, states);
	
}

// Met à jour la position du joueur
void Player::update(float dt)
{
	this->updateAttack();
	sf::FloatRect h = msprite.getGlobalBounds();

	h.height = h.height / 2;
	h.width = h.width / 2;
	h.left += h.width / 2;
	h.top += h.height / 2;
	this->mHitbox->setHitbox(h);
	
	//msprite.move(50 * dt, 0); 
}

// Vérifie si le joueur est en vie
bool Player::IsAlive()
{
	if (mhealth <= 0)	return false;
	else return true;
}

int Player::Getdammage()
{
	return mDamage;
}

int Player::GetHp()
{
	return this->mhealth;
}

int Player::GetHpMax()
{
	return this->mMaxhealth;
}


// Applique des dégâts au joueur
void Player::TakeDammage(int dmg)
{
	mhealth -= dmg;
	if (!IsAlive())
	{
""		GameManager::GetInstance()->GetSceneManager()->ChangeScene(1);
	}
}


// Fait apparaître une nouvelle balle tirée par le joueur
void Player::spawnBullet(sf::Texture* bulletTexture, sf::Vector2f position, sf::Vector2f direction, float speed, bool fromPlayer)
{
	Bullet* newBullet = new Bullet(position, bulletTexture, direction.x, direction.y, speed);
	bullets.push_back(newBullet);
}