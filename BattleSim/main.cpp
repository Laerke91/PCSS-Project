#include <iostream>

using namespace std;

void mainMenu(){
    cout << "Hello and welcome to this game!" <<
         << "This is a small battle simulator. You will pick an adventurer and try to defeat 10 monsters." <<
         << "First off you will have to pick single player or multiplayer." <<
         << "Type 'Single' for single player and 'multi' for multiplayer."
         << "Type 'Help' for a list of options." endl;
}

int main()
{
    player1 = Hero("Player1", 1, 100, 100, 10, 15, 5, 5, 10);
    player2 = Hero("Player2", 1, 100, 100, 10, 15, 5, 5, 10);

    cout << "Hello world!" << endl;
    return 0;
}
