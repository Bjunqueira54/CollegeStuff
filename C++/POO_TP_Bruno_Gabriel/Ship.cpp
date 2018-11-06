#include "Ship.h"

using namespace std;

Ship::Ship(int i, char t): id(i), type(t)
{
    if(type == 'V') //Sailboat
        cout << "You have bought a Sailboat!";
    else if(type == 'G') // Galeon
        cout << "You have bought a Galeon!";
    else if(type == 'E')  //Schooner
        cout << "You have bought a Schooner!";
    else if(type == 'F') //Frigate
        cout << "You have bought a Frigate!";
    else if(type == 'S') //Special
        cout << "You filthy cheater!";
}

Ship::~Ship()
{
    cout << "You've sold a ship";
}