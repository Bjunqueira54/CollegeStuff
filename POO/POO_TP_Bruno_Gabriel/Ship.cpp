#include "Ship.h"

using namespace std;

Ship::Ship(int i, int p, char t, int w, int c, int l, int f): id(i), price(p), type(t), max_water(w), max_crew(c), max_load(l), max_fish(f)
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