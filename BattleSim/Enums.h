#ifndef ENUM_H
#define ENUM_H

//Enum list of attack types - program will check for these when running combat.
//Strong attack beats quick attack, quick attack beats defending, defending beats strong attack

enum AttackType
{
    strong,
    quick,
    defend,
    noType
};

enum menuNav
{
    solo,       //id 0 = 1
    versus,     //id 1 = 2
    help,       //id 2 = 3
    quitGame,   //id 3 = 4
    undefined
};

#endif // ENUM_H
