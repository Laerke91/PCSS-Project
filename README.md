# Battle Simulator
## PCSS mini-project
### By Lærke Marie Øvlisen

### Overview
This small project is a very simple combat simulator where the user plays a 'rock, paper, scissors'-esque game against a CPU. The game takes inputs from the player through a client and the game itself along with the CPU is managed on a server. 
The game works through input commands from the player, any help for these commands can be displayed to the user by typing in the command 'help' anywhere. 
The command 'quit' will shut down the program. 
The program is coded to not be case sensitive and will accept accepted commands in any combination of upper and lower case. 
The server should be started up before the client!

### How to play
When starting, the game will give the user instructions on which commands are accepted. 
Since the scope of this game have been scaled down significantly since its inception (read more in the wiki), typing 'versus' will start a game in the versus mode. 
There are 3 different types of attack; strong, quick and defend. 
Strong beats quick, quick beats defending, defending beats strong. 
If a player uses an attack which follows this, the player will receive a bonus to damage. 
If any party reaches 0 hp, the game will announce a winner. 

