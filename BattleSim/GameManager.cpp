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

int GameManager::determineStat(Hero hero)
{

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
        cout << "Error." << endl;
        return 0;
    }

}

//Function used to figure out the attack type based on the user input
AttackType GameManager::inputToType(string input)
{
    string matchAttack[3] = {"strong", "quick", "defend"};
    //Create an array of matching words
    //Run through those words and find a match, then return the matching enum value
    for (int i = 0; i < 3; i++)
    {
        if(input == matchAttack[i])
        {
            return (AttackType)i;
        }
    }
    AttackType result = noType;
    return result;

}

//Function to set up the players when starting versus mode
void GameManager::setUpPlayers()
{
    setPlayer1(Hero("Player1", 1, 100, 100, 10, 15, 5, 5, 10));
    setPlayer2(Hero("Player2", 1, 100, 100, 10, 15, 5, 5, 10));
}

//Compares chosen attacktypes from players, checks if they are the same
bool GameManager::attacksAreEqual()
{
    if(player1.chosenAttack == player2.chosenAttack)
    {
        return true;
    }
    return false;
}

//check if the first attack is effective against second attack
//If the attack type is paired with noType, noType will be weaker
//Strong beats quick, quick beats defend, defend beats strong
//Assumes that equal attacks have been filtered out before, as it otherwise will state those as "strong against"
bool GameManager::attackIsEffective(AttackType at1, AttackType at2)
{
    switch(at1)
    {
    case strong:
        //Strong attacks are effective against quick attacks
        if(at2 != defend)
        {
            return true;
        }
        return false;

    case quick:
        //Quick attacks are effective against defend
        if (at2 != strong)
        {
            return true;
        }
        return false;

    case defend:
        //Defend is effective against strong attacks
        if(at2 != quick)
        {
            return true;
        }
        return false;

    default:
        return false;
    }
}

string GameManager::attackEffectiveMessage()
{
    if(attackIsEffective(player1.chosenAttack, player2.chosenAttack))
    {
        return player1.getName() + "'s attack is effective!";
    }
    return player2.getName() + "'s attack is effective!";
}

void GameManager::resolveCombat()
{

}
