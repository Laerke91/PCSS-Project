#include "Unit.h"

//Constructor
Unit::Unit(string name, int lvl, int hp, int mp, int str, int def, int spd, int wis, int res):
    name(name),
    level(lvl),
    health (hp),
    mana(mp),
    strength(str),
    defense(def),
    speed(spd),
    wisdom(wis),
    resistance(res) {}

//Getter and setter functions
//Get/set name
void Unit::setName(string newName){
    name=newName;
}
string Unit::getName(){
    return name;
}
//Get/set level
void Unit::setLvl(int newLvl) {
    level = newLvl;
}
int Unit::getLvl(){
    return level;
}
//Get/set health
void Unit::setHp(int newHp){
    health = newHp;
}
int Unit::getHp(){
    return health;
}
//Get/set mana
void Unit::setMp(int newMp){
    mana = newMp;
}
int Unit::getMp(){
    return mana;
}
//Get/set strength
void Unit::setStr(int newStr){
    strength = newStr;
}
int getStr(){
    return strength;
}
//Get/set defense
void Unit::setDef(int newDef){
    defense = newDef;
}
int getDef(){
    return defense;
}
//Get/set speed
void Unit::setSpd(int newSpd){
    speed = newSpd;
}
int getSpd(){
    return speed;
}
//Get/set wisdom
void Unit::setWis(int newWis){
    wisdom = newWis;
}
int getWis(){
    return wisdom;
}
//Get/set resistance
void Unit::setRes(int newRes){
    resistance = newRes;
}
int getRes(){
    return resistance;
}
