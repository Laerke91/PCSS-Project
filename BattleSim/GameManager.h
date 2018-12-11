#ifndef gameManager_H
#define gameManager_H

#include "Hero.h"
#include "Enums.h"

using namespace std;

class GameManager
{
private:
    Hero player1;
    Hero player2;
    //Bools to check whether or not a player has given an attack command
    bool p1ChosenAttack = false;
    bool p2ChosenAttack = false;

public:
    //Constructor
    GameManager();

    Hero getPlayer1();
    void setPlayer1(Hero newPlayer1);
    Hero getPlayer2();
    void setPlayer2(Hero newPlayer2);

    //Function for starting the game
    void startVersusMatch();
    //Use the chosen attack type from the hero to determine what stat should be used in the combat resolution
    int determineStat(Hero hero);
};

#endif // match_H
