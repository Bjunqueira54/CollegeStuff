#ifndef SHIP_H
#define SHIP_H

#include "headers.h"

#define PRICE_SAILBOAT 100
#define PRICE_GALEON 100
#define PRICE_SCHOONER 100
#define PRICE_FRIGATE 100
#define PRICE_SPECIAL 9001  //IT'S OVER NINE THOUSAAAAAAAAAAAAAAAND!!!!

class Ship
{
    const int id; //Ship's id number
    const char type; //Ship's type
    const int *maxwater, *maxcrew, *maxtons, *move /*, *price */; //implement price later;
    int water, crew, load, fish;
    
    int x, y;
    
public:
    
    Ship(int i, char t);
    Ship(const Ship& orig);
    int getId() const;
    char getType() const;
    void setCoord(int yy, int xx);
    string getCoord() const;
    string getInfo() const;
    Ship& operator=(const Ship& orig);
    ~Ship();
};

#endif