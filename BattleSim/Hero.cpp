#include <stdlib.h>
#include <iostream>
#include "Hero.h"

Hero::Hero():
    Unit()
{
    chosenAttack = noType;
}

Hero::Hero(string name, int lvl, int hp, int mp, int str, int def, int spd, int wis, int res):
    Unit(name, lvl, hp, mp, str, def, spd, wis, res)
{
    chosenAttack = noType;
}


string Hero::getStatusMessage()
{
    string result = "";
    result = getName() + ": Hp: " + std::to_string(getHp()) + " | Strength: " + std::to_string(getStr()) + " | Speed: " + std::to_string(getSpd()) + " | Defense: " + std::to_string(getDef());
    cout << result << endl;

    return result;
}

AttackType Hero::getAT()
{
    return chosenAttack;
}

void Hero::setAT(AttackType inputAt)
{
    chosenAttack = inputAt;
}

string Hero::attackTypeToString()
{

    switch(chosenAttack)
    {
    case strong:
        return "strong!";

    case quick:
        return "quick!";

    case defend:
        return "defense!";

    default:
        return "system error!";
    }
}
