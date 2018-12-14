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

//Function used to figure out the attack type based on the user input
AttackType inputToType(string input)
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
            solo,       //id 0 = 1
            versus,     //id 1 = 2
            help,       //id 2 = 3
            quitGame    //id 3 = 4
        } menuNav;

        int navId;
        cin >> navId;
        navId -= 1;

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
            cout << "Pick your action - strong, quick or defend" << endl;
            //Do NOT write 'new' when initiating a new object of a class. The program will take it is a pointer
            GameManager GM = GameManager();
            GM.setPlayer1(Hero("Player1", 1, 100, 100, 10, 15, 5, 5, 10));
            GM.setPlayer2(Hero("Player2", 1, 100, 100, 10, 15, 5, 5, 10));

            GM.player1.getStatusMessage();
            //String used for the attack type chosen by the user
            string userIn;

            cin >> userIn;
            userIn = convertToLowerCase(userIn);

            AttackType AT = inputToType(userIn);

            if (AT != noType)
            {
                //Valid input
                cout << "valid input - calculations will be done."<< endl;
            }else
            {
                //Invalid input
                cout << "invalid input. Type 'help' for list of commands. " << endl;
            }


            //Run function to determine if input matches an attack type


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
        cout << "Loop" << endl;
    }


    //cout << "Hello world!" << endl;
    cin.clear();
    cin.ignore();
    cin.get();
    //getch();
    return 0;

}



