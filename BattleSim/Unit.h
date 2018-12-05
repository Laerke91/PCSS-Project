#ifndef unit_H
#define unit_H

#include <string>

using namespace std;

Class Unit(){
private:
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
    unit(string name, int lvl, int hp, int mp, int str, int def, int spe, int wis, int res);

    void setName(string newName);
    string getName();
}

#endif // unit_H
