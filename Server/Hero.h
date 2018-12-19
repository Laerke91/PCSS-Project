#ifndef Hero_H
#define Hero_H

#include "Unit.h"
#include "Enums.h"

class Hero : public Unit
{
private:
    int incommingDmg = 0;

public:
    //wis, res and mp will not be used for now! And will not have an effect in versus mode.
    //Default constructor and constructor - no new variables
    Hero();
    Hero(string name, int lvl, int hp, int mp, int str, int def, int spd, int wis, int res);

    //Check value for attack type
    AttackType chosenAttack;

    //Use the chosen attack type from the hero to determine what stat should be used in the combat resolution
    int getAttackStat();

    //Get set attack type
    AttackType getAT();
    void setAT(AttackType inputAT);
    string attackTypeToString();

    string getStatusMessage();

    //Combat-oriented functions
    void setIncommingDmg(int damage);
    int getIncommingDmg();
    void applyDmg();
    string getDmgMessage();
    bool isAlive();
};

#endif // Hero_H
