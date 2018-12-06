#ifndef Hero_H
#define Hero_H

#include "Unit.h"
#include "Enums.h"

class Hero : public Unit
{
private:

public:
    //wis, res and mp will not be used for now! And will not have an effect in versus mode.
    //Default constructor and constructor - no new variables
    Hero();
    Hero(string name, int lvl, int hp, int mp, int str, int def, int spd, int wis, int res);

    //Check value for attack type
    AttackType chosenAttack;
};

#endif // Hero_H
