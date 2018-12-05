#ifndef Hero_H
#define Hero_H

#include "Unit.h"

class Hero : public Unit
{
private:

public:
    //wis, res and mp will not be used for now! And will not have an effect in versus mode.
    Hero();
    Hero(string name, int lvl, int hp, int mp, int str, int def, int spd, int wis, int res);

    //Functions - These will be used for attacking in versus mode
    //Strong attack beats quick attack, quick attack beats defending, defending beats strong attack
    int strongAttack(int str);
    int quickAttack(int spd);
    int defend(int def);
};

#endif // Hero_H
