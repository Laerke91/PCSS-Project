#ifndef gameManager_H
#define gameManager_H

#include "Hero.h"
#include "Enums.h"

using namespace std;

class GameManager
{
private:
    bool attacksAreEqual;
    bool isP1Effective;
    int dmgBonus = 5;

public:
    Hero player1;
    Hero player2;

    //Constructor
    GameManager();

    //Getters, setters
    bool getAttacksAreEqual();
    bool getIsP1Effective();

    Hero getPlayer1();
    void setPlayer1(Hero newPlayer1);
    Hero getPlayer2();
    void setPlayer2(Hero newPlayer2);

    int getDmgBonus();
    void setDmgBonus(int damage);

    //Function for starting the game
    void resolveCombat();


    AttackType inputToType(string input);
    void setUpPlayers();

    //Functions used in attack comparisons
    bool checkAttacksAreEqual();
    string attackEffectiveMessage();
    bool attackIsEffective(AttackType at1, AttackType at2);
    void checkAttackEffectiveness();

    void calcIncomingDamage();
    bool isGameConcluded();
};

#endif // match_H
