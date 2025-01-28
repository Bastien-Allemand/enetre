#pragma once
#include "Entity.h"

class Character : public Entity
{
protected:
    int mDamage;
    int mhealth;
    int mMaxhealth;
    

public:
    Character( sf::Vector2f startPosition, int damage, int Maxhealth);
    virtual ~Character() = default;
    virtual void update(float dt) = 0;
    bool isdead();
    int fetchhealth();
    int fetchmaxhealh();
    int fetchdmg();
    void changehealth(int New);
    void changemaxhealth(int New);
    void changedmg(int New);
    int Getdammage();

};
