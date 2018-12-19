#include <iostream>
#include <conio.h>
#include <stdio.h>

#include <winsock2.h>
#include <windows.h>
#include <sstream>
#include <string>
#include <conio.h>
#include <algorithm>

#include "GameManager.h"

#pragma comment(lib, "Ws2_32.lib")

#define SCK_VERSION 0x0202
#define MESSAGE_END "<EOL>"

using namespace std;

//Global variables
//Setup for the socket and server
SOCKET conSock1;
SOCKET listenSock;
SOCKADDR_IN address;
int addrsize = sizeof(address);
WSAData WSD;
WORD dllVersion = MAKEWORD(2,1);
long ok = WSAStartup(dllVersion, &WSD);
//Game setup
string userIn;
bool gameIsRunning = true;
bool versusCombatRunning = false;
menuNav nav = undefined;

//Receive, translate and return message from client
string receiveMsg()
{
    cout << "Listening..." << endl;
    char MESSAGE[512];
    //Receive message
    ok = recv(conSock1, MESSAGE, sizeof(MESSAGE), NULL);
    //Convert message from char to string
    string received = MESSAGE;
    cout << "Client says: \t" << received << endl;
    return received;
}

//Translate and send message to client through a char array
void sendMsg(string msg)
{
    cout << "Sending: \t" << msg << endl;
    char reply[512];
    strcpy(reply, msg.c_str());
    ok = send(conSock1, reply, 512, NULL);
}

//Function converting a user input to lower case
string convertToLowerCase(string input)
{
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    return input;
}

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

//Display diffrent help menus within the game depending on mode - is not relevant for this version of the game as only versus mode is active!
void helpMenu()
{
    char reply[512];        //This stores the converted string messages, up to a maximum of 512 characters

    switch(nav)
    {
    case solo:
    {
        string helpSolo = "Help for solo mode";
        strcpy(reply, helpSolo.c_str());
        sendMsg(reply);
        break;
    }

    case versus:
    {

        string versusHelp = "Help for versus mode: \nType 'strong' for a strong attack.\nType 'quick' for a quick attack.\nType 'defend' to defend against attacks.\nStrong attacks are effective against quick attacks, quick attacks are effective against defending, defending is effective against strong attacks!\nType 'quit' if you wish to quit the game.\n\n";
        strcpy(reply, versusHelp.c_str());
        sendMsg(reply);
        break;
    }

    case help:
    {
        string helpHelp = "Will show help in root menu";
        strcpy(reply, helpHelp.c_str());
        sendMsg(reply);
        break;
    }

    default:
    {
        string helpError = "Error in fetching help menu.";
        strcpy(reply, helpError.c_str());
        sendMsg(reply);
        break;
    }

    }
}

int main()
{
    //Create socket
    //Connection socket
    conSock1 = socket(AF_INET, SOCK_STREAM, NULL);

    //Address setup
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_family = AF_INET;
    address.sin_port = htons(10102);

    //Listening socket
    listenSock = socket(AF_INET, SOCK_STREAM, NULL);
    bind(listenSock, (SOCKADDR*)&address, sizeof(address));
    listen(listenSock, SOMAXCONN);

    //Connection
    //cout << "Server waiting for connection"<< endl;

    //Run server
    while (true)
    {

        //Accept connection
        if(conSock1 = accept(listenSock, (SOCKADDR*)&address, &addrsize))
        {
            string userIn = receiveMsg();
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
                string soloMode = "This is for the single player mode";

                sendMsg(soloMode);
                break;
            }


            case versus:
            {
                //Start versus mode against the CPU
                //Send intro message
                //string versusMode = "This is for the versus player mode";
                //sendMsg(reply);

                versusCombatRunning = true;

                //Setup the player and the CPU
                GameManager GM = GameManager();
                GM.setUpPlayers();

                while(versusCombatRunning)
                {

                    //Player1 loop
                    GM.player1.getStatusMessage();

                    while (true)
                    {
                        //Start message to player 1
                        string pickAttack = "Player 1, pick action - strong, quick or defend!\n";
                        sendMsg(pickAttack);

                        //receive user input for attack
                        string userIn = receiveMsg();
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
                        else    //If the command is not of the two previous, match with attack type
                        {
                            AttackType AT = GM.inputToType(userIn);

                            //If the attack type is NOT noType aka not an invalid command
                            if (AT != noType)
                            {
                                //Valid input - set attacktype of player 1
                                string pickedAttack = "Player 1 has chosen an attack\n";
                                sendMsg(pickedAttack);

                                GM.player1.chosenAttack = AT;
                                break;
                            }
                            else
                            {
                                //Invalid input
                                string invalidAttack = "invalid input. Type 'help' for list of commands.";
                                sendMsg(invalidAttack);

                            }
                        }

                    }
                    GM.player2.getStatusMessage();
                    //CPU turn
                    GM.player2.getRandomAttack();

                    //Input for both players are valid!
                    //Display the chosen attacks of each player
                    //Send message of player 1's attack
                    string p1Pick = GM.player1.getName() + " has chosen: " + GM.player1.attackTypeToString();
                    sendMsg(p1Pick);
                    //P2/CPU's picked attack
                    string p2Pick = GM.player2.getName() + " has chosen: " + GM.player2.attackTypeToString() + "\n";
                    sendMsg(p2Pick);

                    //Check if an attack is super effective
                    GM.checkAttackEffectiveness();

                    //If the attacks are not the same, display an effectiveness message
                    if(!GM.getAttacksAreEqual())
                    {
                        string effectiveMsg = GM.attackEffectiveMessage() + "\n";
                        sendMsg(effectiveMsg);
                    }

                    //Resolve and apply damage
                    GM.calcIncomingDamage();
                    //Damage done to player 1
                    string p1dmg = GM.player1.getDmgMessage();
                    sendMsg(p1dmg);

                    //Damage done to player 2/CPU
                    string p2dmg = GM.player2.getDmgMessage() + "\n";
                    sendMsg(p2dmg);

                    //Resolve combat
                    GM.resolveCombat();

                    //Check for a conclusion of the game, if there is no winner yet, continue the combat loop
                    if(GM.isGameConcluded())
                    {
                        //If game is concluded, announce winner and return to main menu
                        string winner = GM.announceWinnerMsg() + "\n";
                        sendMsg(winner);
                        break;

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
                //Invalid command message.
                string invalidCommand = "Invalid command. Type 'help' to bring up the help menu.";
                sendMsg(invalidCommand);
                break;

            }


            //create reply
            //char reply[512];
            //cout << "Enter reply:\t" << endl;
            //cin.getline(reply,sizeof(reply));
            //sendMsg(reply);

        }
    }
QUIT:
    string exitMsg = "Thanks for playing! Press enter to exit";
    //char reply[512];
    //strcpy(reply, exitMsg.c_str());
    sendMsg(exitMsg);

    //cin.clear();
    //cin.ignore();
    //cin.get();
    //getch();
    return 0;
}
