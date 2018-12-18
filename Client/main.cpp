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

int main()
{
    //Clientside sockets
    SOCKET clientSock;
    SOCKADDR_IN address;

    //Message setup
    long ok;
    char MESSAGE[200];

    WSAData WSD;
    WORD dllVersion;
    dllVersion = MAKEWORD(2,1);
    ok = WSAStartup(dllVersion, &WSD);

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

        //Convert message from char to string
        const char* s = msg.c_str();
        ok = send(clientSock, s, 1024, NULL);

        //Receive message
        string reply = "";
        //while (true)
        //{
            ok = recv(clientSock, MESSAGE, sizeof(MESSAGE), NULL);
            string received = MESSAGE;
            //if(received == MESSAGE_END)
            //{
            //    break;
            //}
            reply += received + " ";
        //}


        //reply = MESSAGE;
        cout << "Server says:\t" << reply << endl;
    }
}
