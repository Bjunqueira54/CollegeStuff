#ifndef MAP_H
#define MAP_H

#include "headers.h"
#include "Harbor.h"

class Map
{
    static vector<string> g_Map;
    vector<vector<int>> pos_fish;
    static vector<Harbor> ports;
    
public:
    Map();
    Map(ifstream &file);
    Map& operator=(const Map &orig);
    
    void CreateHarborVector();
    
    vector<Harbor> getFriendlyHarbors() const;
    //string getHarborCoord() const;
    vector<string> getMap() const;
};

#endif