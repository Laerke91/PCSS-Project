#include <stdlib.h>
#include "unistd.h"

Hero::Hero():
    {

    }

void attack(){
    switch (chosenAttack)
    {
    case strong:
        //Calculate with strength
        break;
    case quick:
        //Calculate with speed
        break;
    case defend:
        //Calculate with defense
        break;
    default:
        //Error handling - do nothing!
        cout << "Error." << endl;
        break;
    }

}

