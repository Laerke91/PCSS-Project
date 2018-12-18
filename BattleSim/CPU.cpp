#include <stdlib.h>
#include <iostream>

#include "CPU.h"

CPU::CPU():
    Hero(){}

CPU::CPU(string name, int lvl, int hp, int mp, int str, int def, int spd, int wis, int res):
    Hero(name, lvl, hp, mp, str, def, spd, wis, res) {}


int CPU::randomNumber(int maxVal)
{
    return rand() % maxVal;

}

void CPU::getRandomAttack()
{
    chosenAttack = (AttackType)randomNumber(3);
}
