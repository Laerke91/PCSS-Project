#ifndef CPU_H
#define CPU_H

#include "Hero.h"

//This will be the CPU "player" class that will play the game against the user
//It inherits from the Hero-class
class CPU : public Hero
{
private:

public:

    CPU();
    CPU(string name, int lvl, int hp, int mp, int str, int def, int spd, int wis, int res);

    int randomNumber(int maxVal);
    void getRandomAttack();
};

#endif // CPU_H
