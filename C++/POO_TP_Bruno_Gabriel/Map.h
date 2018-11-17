#ifndef MAP_H
#define MAP_H

#include "headers.h"
#include "Functions.h"
#include "Ship.h"
#include "Harbor.h"
#include "Player.h"
#include "Settings.h"

class Map
{
    vector<string> dMap;
    vector<Ship> ships;
    
public:
    Map();

};

#endif