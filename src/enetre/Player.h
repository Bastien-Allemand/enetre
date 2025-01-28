#pragma once
#include "Character.h"
#include "Bullet.h"

#include "SFML/Graphics.hpp"
#include "vector"
class Bullet;
// Classe repr�sentant un joueur dans le jeu
class Player : public Character
{
private:
    // Attributs priv�s de la classe Player
    int mmaxLife; // Vie maximale du joueur
    int mLife; // Vie actuelle du joueur
     // Vecteur de pointeurs vers les balles du joueur
    float mAttackCouldown;
    float mAttackCouldownMax;
    
public:
   
    std::vector<Bullet*> bullets;

    void InitTexture();
    void SetHp(int pHp);       
    void InitSprite();
    const bool canAttack()  ;
    void updateAttack();
    // Constructeur de la classe Player
    Player( sf::Vector2f startPosition, int maxlife, int damage, int Maxhealth);

    // M�thode pour dessiner le joueur sur la cible de rendu
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    // M�thode pour mettre � jour l'�tat du joueur
    void update(float dt) ;

    // M�thode pour v�rifier si le joueur est en vie
    bool IsAlive();

    int Getdammage();

    int GetHp();

    int GetHpMax();

    // M�thode pour infliger des d�g�ts au joueur
    void TakeDammage(int dmg);

    // M�thode pour faire appara�tre une balle
    void spawnBullet(sf::Texture* bulletTexture, sf::Vector2f position, sf::Vector2f direction, float speed, bool fromPlayer);

   
};
