#include <iostream>
#include <conio.h>
#include <stdio.h>

#include <winsock2.h>
#include <windows.h>
#include <sstream>
#include <string>

#pragma comment(lib, "Ws2_32.lib")

#define SCK_VERSION 0x0202
#define MESSAGE_END "<EOL>"

using namespace std;

//Global client variables
//Clientside sockets
SOCKET clientSock;
SOCKADDR_IN address;
WSAData WSD;
WORD dllVersion = MAKEWORD(2,1);
long ok = WSAStartup(dllVersion, &WSD);


//Make a switch in the main function later and use cases for the "state" of the game to control text prompts
void mainMenu()
{
    cout << "Hello and welcome to this game!" << endl;
    cout << "This is a small battle simulator between two players." << endl;
    cout << "The goal is to get the other player to 0 hp by using commands." << endl;
    cout << "Please type one of the following commands to navigate the menu: " << endl << endl;
    //cout << "Type 'solo' for solo mode." << endl;
    cout << "Type 'versus' to start a versus game." << endl;
    cout << "Type 'help' for help." << endl;
    cout << "Type 'quit' to quit the game. " << endl << endl;
}

string recieveMsg()
{
    char MESSAGE[512];
    ok = recv(clientSock, MESSAGE, sizeof(MESSAGE), NULL);
    string received = MESSAGE;
    return received;
}

void sendMsg(string msg)
{
    //Convert message from char to string
    char reply[512];
    strcpy(reply, msg.c_str());
    ok = send(clientSock, reply, 512, NULL);
}

int main()
{
    //Run the introduction menu
    mainMenu();

    //Run client
    while (true)
    {
        clientSock = socket(AF_INET, SOCK_STREAM, NULL);

        //Address setup - use same address and port as the server!
        address.sin_addr.s_addr = inet_addr("127.0.0.1");
        address.sin_family = AF_INET;
        address.sin_port = htons(10102);

        //Create connection
        connect(clientSock, (SOCKADDR*)&address, sizeof(address));

        //Create message
        string msg;
        cout << "Enter message: \t" << endl;
        cin >> msg;

        sendMsg(msg);
        //Receive message
        //string reply = "";
        //while (true)
        //{
        //ok = recv(clientSock, MESSAGE, sizeof(MESSAGE), NULL);
        string received = recieveMsg();
        //if(received == MESSAGE_END)
        //{
        //    break;
        //}
        //reply += received + " ";
        //}


        //reply = MESSAGE;
        cout << "Server says:\t" << received << endl;
    }
}
