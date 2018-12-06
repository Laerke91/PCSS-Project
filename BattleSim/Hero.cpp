#include <stdlib.h>
#include "Hero.h"

Hero::Hero():
    Unit() {}

Hero::Hero(string name, int lvl, int hp, int mp, int str, int def, int spd, int wis, int res):
    Unit(name, lvl, hp, mp, str, def, spd, wis, res) {}

