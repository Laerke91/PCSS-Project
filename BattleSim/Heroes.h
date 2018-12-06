#ifndef Hero_H
#define Hero_H

#include "Unit.h"

class Hero : public Unit
{
private:

public:
    //wis, res and mp will not be used for now! And will not have an effect in versus mode.
    //Default constructor and constructor - no new variables
    Hero();
    Hero(string name, int lvl, int hp, int mp, int str, int def, int spd, int wis, int res);

    //Enum list of attack types - program will check for these when running combat.
    //Strong attack beats quick attack, quick attack beats defending, defending beats strong attack
    enum AttackType {strong, quick, defend};

    //Has the player chosen an attack
    bool actionDecided = false;
    //Check value for attack type
    AttackType chosenAttack;
    //Functions - These will be used for attacking in versus mode
    void attack();

};

#endif // Hero_H
