#include "Ship.h"

using namespace std;

Ship::Ship(int i, int p, int t, int w, int c, int l, int f): id(i), price(p), type(t), max_water(w), max_crew(c), max_load(l), max_fish(f)
{
    if(type == 0) //Sailboat
        cout << "You have bought a Sailboat!";
    else if(type == 1) // Galeon
        cout << "You have bought a Galeon!";
    else if(type == 2)  //Schooner
        cout << "You have bought a Schooner!";
    else if(type == 3) //Frigate
        cout << "You have bought a Frigate!";
    else
        cout << "You filthy cheater!";
}

Ship::~Ship()
{
    cout << "You've sold a ship";
}