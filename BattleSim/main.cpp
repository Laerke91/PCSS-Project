#include <iostream>

#include "Unit.h"
#include "Hero.h"
#include "GameManager.h"

using namespace std;

//Don't do anything with this atm..
void mainMenu(){
    cout << "Hello and welcome to this game!" << endl;
    cout << "This is a small battle simulator. You will pick an adventurer and try to defeat 10 monsters." << endl;
    cout << "First off you will have to pick single player or versus another player." << endl;
    cout << "Type 'Single' for single player and 'versus' for a versus match." << endl;
    cout << "Type 'Help' for a list of options." << endl;
}

int main()
{
    GameManager GM = GameManager();
    GM.setPlayer1(Hero("Player1", 1, 100, 100, 10, 15, 5, 5, 10));
    GM.setPlayer2(Hero("Player2", 1, 100, 100, 10, 15, 5, 5, 10));

    cout << GM.getPlayer1().getHp() << endl;

    cout << "Hello world!" << endl;
    //delete GM;
    return 0;
}
