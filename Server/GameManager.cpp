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
CPU GameManager::getPlayer2()
{
    return player2;
}
void GameManager::setPlayer2(CPU newPlayer2)
{
    player2 = newPlayer2;
}

bool GameManager::getIsP1Effective()
{
    return isP1Effective;
}

bool GameManager::getAttacksAreEqual()
{
    return attacksAreEqual;
}

void GameManager::setDmgBonus(int damage)
{
    dmgBonus = damage;
}

int GameManager::getDmgBonus()
{
    return dmgBonus;
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
    setPlayer1(Hero("Player1", 1, 10, 100, 10, 15, 5, 5, 10));
    setPlayer2(CPU("CPU", 1, 10, 100, 10, 15, 5, 5, 10));
}

//Compares chosen attacktypes from players, checks if they are the same
bool GameManager::checkAttacksAreEqual()
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

//Display message for when a players attack is more effective against the others
string GameManager::attackEffectiveMessage()
{
    if(isP1Effective)
    {
        return player1.getName() + "'s attack is effective!";
    }
    return player2.getName() + "'s attack is effective!";
}

//Check effectiveness of attack
void GameManager::checkAttackEffectiveness()
{
    attacksAreEqual = checkAttacksAreEqual();
    if(!attacksAreEqual)
    {
        isP1Effective = attackIsEffective(player1.chosenAttack, player2.chosenAttack);
    }
}

//Calculate incoming damage for a player
void GameManager::calcIncomingDamage()
{
    //If the attacks are same type, deal raw damage
    if(attacksAreEqual)
    {
        player1.setIncommingDmg(player2.getAttackStat());
        player2.setIncommingDmg(player1.getAttackStat());
    } else
    {
        //If attacks are different, apply bonus damage
        if(isP1Effective)
        {
            player1.setIncommingDmg(player2.getAttackStat() - dmgBonus);
            player2.setIncommingDmg(player1.getAttackStat() + dmgBonus);
        } else
        {
            player1.setIncommingDmg(player2.getAttackStat() + dmgBonus);
            player2.setIncommingDmg(player1.getAttackStat() - dmgBonus);
        }
    }

}

//Function called to resolve combat between the two players
void GameManager::resolveCombat()
{
    player1.applyDmg();
    player2.applyDmg();
}

//Is the game finished?
//The game finishes if any one player reaches 0 hp
bool GameManager::isGameConcluded()
{
    if(player1.getHp() <= 0 || player2.getHp() <= 0)
    {
        return true;
    }
    return false;
}

//Check both players HP, if they both are equal to or lower than 0, it's a draw
bool GameManager::isGameDraw()
{
    if(player1.getHp() <= 0 && player2.getHp() <= 0)
    {
        return true;
    }
    return false;
}

string GameManager::announceWinnerMsg()
{
    if(isGameDraw())
    {
        //It's a draw
        return "Game is a draw, no winner!";
    }
    else if(player1.isAlive())
    {
        //Player 1 is the winner!
        return player1.getName() +  " is the winner!";
    }
    else
    {
        //Player 2 is the winner!
        return player2.getName() + " is the winner!";
    }
}
