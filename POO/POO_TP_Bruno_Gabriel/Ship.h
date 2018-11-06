#ifndef SHIP_H
#define SHIP_H

#include "headers.h"

#define PRICE_SAILBOAT 100
#define PRICE_GALEON 100
#define PRICE_SCHOONER 100
#define PRICE_FRIGATE 100
#define PRICE_SPECIAL 9001

class Galeon
{
    int price;
    const int max_water, max_crew, max_load, max_fish;
};

class Frigate
{
    int price;
    const int max_water, max_crew, max_load, max_fish;
};

class Schooner
{
    int price;
    const int max_water, max_crew, max_load, max_fish;
};

class Sailboat
{
    int price;
    const int max_water, max_crew, max_load, max_fish;
};

class Special
{
    int price;
    const int max_water, max_crew, max_load, max_fish;
};

class Ship
{
    const int id; //Nº de identificacao do navio
    const char type; //Preco do navio
    int water, crew, load, fish;

    union shiptype
    {
        Galeon galeon;
        Frigate frigate;
        Schooner schooner;
        Sailboat sailboat;
        Special special;
    };
    
    
public:

    Ship(int i, char t);
    ~Ship();
};

#endif /* SHIP_H */

