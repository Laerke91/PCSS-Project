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
    //Setup for the socket
    SOCKET conSock1;
    SOCKET conSock2;
    SOCKET listenSock;
    SOCKADDR_IN address;
    int addrsize = sizeof(address);

    //Message setup
    long ok;
    char MESSAGE[200];

    WSAData WSD;
    WORD dllVersion;
    dllVersion = MAKEWORD(2,1);
    ok = WSAStartup(dllVersion, &WSD);

    //Create socket
    //Connection socket
    conSock1 = socket(AF_INET, SOCK_STREAM, NULL);
    conSock2 = socket(AF_INET, SOCK_STREAM, NULL);

    //Address setup
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_family = AF_INET;
    address.sin_port = htons(10102);

    //Listening socket
    listenSock = socket(AF_INET, SOCK_STREAM, NULL);
    bind(listenSock, (SOCKADDR*)&address, sizeof(address));
    listen(listenSock, SOMAXCONN);

    //Connection
    cout << "Server waiting for connection"<< endl;

    //Run server
    while (true)
    {
        //Accept connection
        if(conSock1 = accept(listenSock, (SOCKADDR*)&address, &addrsize))
        {
            //Receive message
            ok = recv(conSock1, MESSAGE, sizeof(MESSAGE), NULL);
            //Convert message from char to string
            string msg;
            msg = MESSAGE;
            cout << "Client says: \t" << msg << endl;


            //create reply
            char reply[512];
            cout << "Enter reply:\t" << endl;
            cin.getline(reply,sizeof(reply));

            ok = send(conSock1, reply, (int)sizeof(reply), NULL);
        }
    }

}
