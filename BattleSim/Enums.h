#ifndef ENUM_H
#define ENUM_H

//Enum list of attack types - program will check for these when running combat.
//Strong attack beats quick attack, quick attack beats defending, defending beats strong attack

enum AttackType
{
    strong,
    quick,
    defend
};

#endif // ENUM_H
