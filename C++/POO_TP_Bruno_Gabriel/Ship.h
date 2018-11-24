#ifndef SHIP_H
#define SHIP_H

#include "headers.h"

#define PRICE_SAILBOAT 100
#define PRICE_GALEON 100
#define PRICE_SCHOONER 100
#define PRICE_FRIGATE 100
#define PRICE_SPECIAL 9001  //IT'S OVER NINE THOUSAAAAAAAAAAAAAAAND!!!!

class Player;

class Ship
{
    const int id; //Ship's id number
    const char type; //Ship's type
    const int *maxwater, *maxcrew, *maxtons, *move; //implement price later if needed (defines are already up there);
    int water, crew, load, fish;
    int x, y;
    const Player *owner;
    
public:
    
    Ship(int i, char t, const Player& player);
    Ship(const Ship& orig);
    
    int getId() const;
    char getType() const;
    string getCoord() const;
    string getInfo() const;
    const string getOwnerName() const;
    
    void setCoord(int yy, int xx);
    void setOwner(const Player &player);
    
    Ship& operator=(const Ship& orig);
    ~Ship();
};

#endif