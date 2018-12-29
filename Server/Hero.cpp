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
    //cout << result << endl;

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

void Hero::setIncommingDmg(int damage)
{
    incommingDmg = damage;
}

int Hero::getIncommingDmg()
{
    return incommingDmg;
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

//Determine what stat to fetch for the attach based on chosen attack
int Hero::getAttackStat()
{

    switch (chosenAttack)
    {
    case strong:
        //Use with strength
        cout << "Strong attack!" << endl;
        return strength;
    case quick:
        //Use with speed
        cout << "Quick attack!" << endl;
        return speed;
    case defend:
        //Use with defense
        cout << "Defend" << endl;
        return defense;
    default:
        //Error handling - do nothing!
        cout << "Error." << endl;
        return 0;
    }

}

//Apply damage to hero and reset incoming damage
void Hero::applyDmg()
{
    health -= incommingDmg;
    incommingDmg = 0;
}

//Message saying how much damage a hero takes
string Hero::getDmgMessage()
{
    return name + " takes " + to_string(incommingDmg) + " damage!";
}

//Is the hero still alive? Aka is their hp above 0
bool Hero::isAlive()
{
    if(health <= 0)
    {
        return false;
    }
    return true;
}
