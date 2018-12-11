#include <iostream>
#include <conio.h>

#include "Unit.h"
#include "Hero.h"
#include "GameManager.h"

using namespace std;

//Don't do anything with this atm..
//Make a switch in the main function later and use cases for the "state" of the game to control text prompts
void mainMenu()
{
    cout << "Hello and welcome to this game!" << endl;
    cout << "This is a small battle simulator. You will pick an adventurer and try to defeat 10 monsters." << endl;
    cout << "First off you will have to pick single player or versus another player." << endl;
    cout << "Please type one of the following numbers to navigate the menu: " << endl;
    cout << "Press 1 for solo mode." << endl;
    cout << "Press 2 for versus mode." << endl;
    cout << "Press 3 for help." << endl;
    cout << "Press 4 to quit the game. " << endl;
}

int main()
{
    bool gameIsRunning;

    mainMenu();

    while (gameIsRunning)
    {
        //Controls the input from the user through an enum used in a switch
        typedef enum
        {
            solo,       //id 1
            versus,     //id 2
            help,       //id 3
            quitGame    //id 4
        } menuNav;

        int navId;
        cin >> navId;

        //Switch using enums to navigate the game
        switch(navId)
        {
        case help:
        {
            cout << "This is going to show the help" << endl;
            break;
        }

        case solo:
        {
            cout << "This is for the single player mode" << endl;
            break;
        }


        case versus:
        {
            cout << "This will be for the versus mode" << endl;
            //Do NOT write 'new' when initiating a new object of a class. The program will take it is a pointer
            GameManager GM = GameManager();
            GM.setPlayer1(Hero("Player1", 1, 100, 100, 10, 15, 5, 5, 10));
            GM.setPlayer2(Hero("Player2", 1, 100, 100, 10, 15, 5, 5, 10));

            cout << GM.getPlayer1().getHp() << endl;
            break;
        }


        case quitGame:
        {
            //Quits the game
            cout << "Bye-bye!" << endl;
            gameIsRunning = false;
            break;
        }

        default:
            cout << "Invalid command. Press 3 to bring up the help menu." << endl;
            break;

        }
    }


    //cout << "Hello world!" << endl;
    cin.clear();
    cin.ignore();
    cin.get();
    //getch();
    return 0;

}
