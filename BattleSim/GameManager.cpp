#include <stdlib.h>
#include "GameManager.h"

GameManager::GameManager()
    {}
//GameManager::GameManager(Hero player1, Hero player2)

Hero getPlayer1()
{
    return player1;
}
void setPlayer1(Hero newPlayer1)
{
    player1 = newPlayer1;
}
Hero getPlayer2()
{
    return player2;
}
void setPlayer2(Hero newPlayer2)
{
    player2 = newPlayer2;
}

int determineStat(Hero hero){

    switch (hero.chosenAttack)
    {
    case strong:
        //Use with strength
        return hero.getStr();
    case quick:
        //Use with speed
        return hero.getSpd();
    case defend:
        //Use with defense
        hero.getDef();
    default:
        //Error handling - do nothing!
        cout << "Error." << endl;
        return 0;
    }

}

void startVersusMatch(Hero p1, Hero p2)
{

}
