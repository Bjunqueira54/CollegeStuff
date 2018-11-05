#ifndef SHIP_H
#define SHIP_H

#include "headers.h"

#define PRICE_SAILBOAT 100
#define PRICE_GALEON 100
#define PRICE_SCHOONER 100
#define PRICE_FRIGATE 100
#define PRICE_SPECIAL 9001

class Ship
{
    const int id; //Nº de identificacao do navio
    const int type; //Preco do navio
    int price;
    const int max_water, max_crew, max_load, max_fish;
    int water, crew, cargo, fish;
    
    
public:
    
    Ship(int i, int p, int t, int w, int c, int l, int f);
    ~Ship();
};

#endif /* SHIP_H */

