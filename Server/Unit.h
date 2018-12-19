#ifndef unit_H
#define unit_H

#include <string>

using namespace std;

class Unit
{
protected:
    //General info on unit
    string name;
    int level;
    int health;
    int mana;
    //Actual stats
    int strength;
    int defense;
    int speed;
    int wisdom;
    int resistance;

public:
    //Constructor
    //All types of stats are going to be used for both heroes and monsters. Not all stats will be used in versus mode.
    Unit();
    Unit(string name, int lvl, int hp, int mp, int str, int def, int spd, int wis, int res);

    //Getters/Setters
    void setName(string newName);
    string getName();

    void setLvl(int newLvl);
    int getLvl();

    void setHp(int newHp);
    int getHp();

    void setMp(int newMp);
    int getMp();

    void setStr(int newStr);
    int getStr();

    void setDef(int newDef);
    int getDef();

    void setSpd(int newSpd);
    int getSpd();

    void setWis(int newWis);
    int getWis();

    void setRes(int newRes);
    int getRes();

};

#endif // unit_H
