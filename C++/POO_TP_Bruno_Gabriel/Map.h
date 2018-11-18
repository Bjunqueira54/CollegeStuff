#ifndef MAP_H
#define MAP_H

#include "headers.h"
#include "Ship.h"
#include "Language.h"

class Map
{
    vector<string> dMap;
    vector<Ship> ships;
    
public:
    Map();
    Map(ifstream &file);
    Map& operator=(const Map &orig);
    vector<string> getMap() const;
};

#endif