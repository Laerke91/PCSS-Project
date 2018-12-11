#include <stdlib.h>
#include <iostream>
#include "GameManager.h"

//using namespace std;

GameManager::GameManager()
    {}
//GameManager::GameManager(Hero player1, Hero player2)

Hero GameManager::getPlayer1()
{
    return player1;
}
void GameManager::setPlayer1(Hero newPlayer1)
{
    player1 = newPlayer1;
}
Hero GameManager::getPlayer2()
{
    return player2;
}
void GameManager::setPlayer2(Hero newPlayer2)
{
    player2 = newPlayer2;
}

int GameManager::determineStat(Hero hero){

    switch (hero.chosenAttack)
    {
    case strong:
        //Use with strength
        cout << "Strong attack!" << endl;
        return hero.getStr();
    case quick:
        //Use with speed
        cout << "Quick attack!" << endl;
        return hero.getSpd();
    case defend:
        //Use with defense
        cout << "Defend" << endl;
        hero.getDef();
    default:
        //Error handling - do nothing!
        std::cout << "Error." << endl;
        return 0;
    }

}

void GameManager::startVersusMatch()
{

}
