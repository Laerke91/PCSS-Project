#ifndef gameManager_H
#define gameManager_H

#include "Hero.h"
#include "Enums.h"
#include "CPU.h"

using namespace std;

class GameManager
{
private:
    bool attacksAreEqual;
    bool isP1Effective;
    int dmgBonus = 5;

public:
    Hero player1;
    CPU player2;

    //Constructor
    GameManager();

    //Getters, setters
    bool getAttacksAreEqual();
    bool getIsP1Effective();

    Hero getPlayer1();
    void setPlayer1(Hero newPlayer1);
    CPU getPlayer2();
    void setPlayer2(CPU newPlayer2);

    int getDmgBonus();
    void setDmgBonus(int damage);

    //Function for starting the game
    void resolveCombat();


    AttackType inputToType(string input);
    void setUpPlayers();

    //Functions used for resolving the game
    bool checkAttacksAreEqual();                                //Checks if the attacks are of the same type, fx. strong and strong
    string attackEffectiveMessage();                            //Returns a message with which attack is effective
    bool attackIsEffective(AttackType at1, AttackType at2);     //Determines which attack is effective against the other according to the weapon triangle
    void checkAttackEffectiveness();                            //Resolved the attack effectiveness if the attack is effective and not equal
    void calcIncomingDamage();                                  //Calculates the incoming damage to each player
    bool isGameConcluded();                                     //Checks if either player has reached 0 hp
    bool isGameDraw();
    string announceWinnerMsg();
};

#endif // match_H
