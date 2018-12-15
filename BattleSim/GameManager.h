#ifndef gameManager_H
#define gameManager_H

#include "Hero.h"
#include "Enums.h"

using namespace std;

class GameManager
{
private:

public:
    Hero player1;
    Hero player2;

    //Constructor
    GameManager();

    Hero getPlayer1();
    void setPlayer1(Hero newPlayer1);
    Hero getPlayer2();
    void setPlayer2(Hero newPlayer2);

    //Function for starting the game
    void resolveCombat();
    //Use the chosen attack type from the hero to determine what stat should be used in the combat resolution
    int determineStat(Hero hero);

    AttackType inputToType(string input);
    void setUpPlayers();

    //Functions used in attack comparisons
    bool attacksAreEqual();
    string attackEffectiveMessage();
    bool attackIsEffective(AttackType at1, AttackType at2);
};

#endif // match_H
