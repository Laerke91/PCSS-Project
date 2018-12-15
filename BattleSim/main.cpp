#include <iostream>
#include <conio.h>
#include <algorithm>

#include "Unit.h"
#include "Hero.h"
#include "GameManager.h"

using namespace std;

//Function converting a user input to lower case
string convertToLowerCase(string input)
{
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    return input;
}

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

//Global variables
string userIn;
bool gameIsRunning = true;
bool versusCombatRunning = false;
menuNav nav = undefined;

//Convert input string to menu navigation enum
menuNav inputToNav(string input)
{
    string matchNav[4] = {"solo", "versus", "help", "quit"};
    //Create an array of matching words
    //Run through those words and find a match, then return the matching enum value
    for (int i = 0; i < 4; i++)
    {
        if(input == matchNav[i])
        {
            return (menuNav)i;
        }
    }
    menuNav result = undefined;
    return result;

}

//Display diffrent help menus within the game depending on mode
void helpMenu()
{
    switch(nav)
    {
    case solo:
        cout << "Help for solo mode" << endl;
        break;
    case versus:
        cout << "Help for versus mode" << endl;
        break;
    case help:
        cout << "Will show help in root menu" << endl;
        break;
    default:
        cout << "What?" << endl;
    }
}

int main()
{

    mainMenu();

    while (gameIsRunning)
    {

        cin >> userIn;
        userIn = convertToLowerCase(userIn);
        nav = inputToNav(userIn);

        //Switch using enums to navigate the game
        switch(nav)
        {
        case help:
        {
            helpMenu();
            break;
        }

        case solo:
        {
            cout << "This is for the single player mode" << endl;
            break;
        }


        case versus:
        {
            versusCombatRunning = true;

            cout << "This will be for the versus mode" << endl;

            //Do NOT write 'new' when initiating a new object of a class. The program will take it as a pointer
            GameManager GM = GameManager();
            GM.setUpPlayers();

            while(versusCombatRunning)
            {
                //String used for the attack type chosen by the user
                string userIn;

                //Player1 loop
                GM.player1.getStatusMessage();

                while(true)
                {
                    cout << "Player 1, pick action - strong, quick or defend" << endl;

                    cin >> userIn;
                    userIn = convertToLowerCase(userIn);

                    //Check input for known commands
                    if(userIn == "help")
                    {
                        helpMenu();
                    }
                    else if(userIn == "quit")
                    {

                        goto QUIT;

                    }
                    else
                    {
                        AttackType AT = GM.inputToType(userIn);

                        if (AT != noType)
                        {
                            //Valid input - set attacktype of player 1
                            cout << "Player 1 has chosen an attack"<< endl;
                            GM.player1.chosenAttack = AT;
                            break;
                        }
                        else
                        {
                            //Invalid input
                            cout << "invalid input. Type 'help' for list of commands. " << endl;

                        }
                    }
                }

                cout << endl;

                GM.player2.getStatusMessage();
                //Player2 loop
                while(true)
                {
                    cout << "Player 2, pick action - strong, quick or defend" << endl;

                    cin >> userIn;
                    userIn = convertToLowerCase(userIn);

                    //Check input for known commands
                    if(userIn == "help")
                    {
                        helpMenu();
                    }
                    else if(userIn == "quit")
                    {
                        goto QUIT;
                    }
                    else
                    {
                        AttackType AT = GM.inputToType(userIn);

                        if (AT != noType)
                        {
                            //Valid input - set attacktype of player 1
                            cout << "Player 2 has chosen an attack"<< endl;
                            GM.player2.setAT(AT);
                            break;
                        }
                        else
                        {
                            //Invalid input
                            cout << "invalid input. Type 'help' for list of commands. " << endl;

                        }
                    }
                }
                //Input for both players are valid!
                //Display the chosen attacks of each player
                cout << GM.player1.getName() << " has chosen: " << GM.player1.attackTypeToString() << endl;
                cout << GM.player2.getName() << " has chosen: " << GM.player2.attackTypeToString() << endl;

                if(!GM.attacksAreEqual())
                {
                    cout << GM.attackEffectiveMessage() << endl;
                }


            }
            break;
        }


        case quitGame:
        {
            //Quits the game
            goto QUIT;
        }

        default:
            cout << "Invalid command. Press 3 to bring up the help menu." << endl;
            break;

        }
        cout << "Loop" << endl;
    }
    QUIT:
    cout << "Thanks for playing" << endl << "Press enter to exit" << endl;

    cin.clear();
    cin.ignore();
    cin.get();
    //getch();
    return 0;

}



